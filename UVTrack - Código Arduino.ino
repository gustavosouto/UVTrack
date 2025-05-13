#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <Ticker.h>
#include <AsyncMqttClient.h>

#define WIFI_SSID "brisa-3357106"
#define WIFI_PASSWORD "iwcroyx9"

#define MQTT_HOST IPAddress(24,144,93,211) //MQTT BROKER IP ADDRESS
//for example:

#define MQTT_PORT 1883
#define BROKER_USER ""
#define BROKER_PASS ""

AsyncMqttClient mqttClient;
Ticker mqttReconnectTimer;

WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;
Ticker wifiReconnectTimer;

// Definimos onde ligamos o pino de saída do sensor
const int pinoSensorUV = A0; // Ligado no A0
unsigned long previousMillis = 0;   // Stores last time a message was published
const long interval = 10000;        // Interval at which to publish values

void connectToWifi() {
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void connectToMqtt() {
  Serial.println("Connecting to MQTT...");
  mqttClient.connect();
}

void onWifiConnect(const WiFiEventStationModeGotIP& event) {
  Serial.println("Connected to Wi-Fi.");
  connectToMqtt();
}

void onWifiDisconnect(const WiFiEventStationModeDisconnected& event) {
  Serial.println("Disconnected from Wi-Fi.");
  mqttReconnectTimer.detach(); // ensure we don't reconnect to MQTT while reconnecting to Wi-Fi
  wifiReconnectTimer.once(2, connectToWifi);
}

void onMqttConnect(bool sessionPresent) {
  Serial.println("Connected to MQTT.");
  Serial.print("Session present: ");
  Serial.println(sessionPresent);

  // Subscribe to topic "uv/sensor" when it connects to the broker
  uint16_t packetIdSub = mqttClient.subscribe("uv/sensor", 2);
  Serial.print("Subscribing at QoS 2, packetId: ");
  Serial.println(packetIdSub);

 // Publish on the "uv/sensor" topic with qos 1
  uint16_t packetIdPub1 = mqttClient.publish("uv/sensor", 1, true, "test 2");
  Serial.print("Publishing at QoS 1, packetId: ");
  Serial.println(packetIdPub1);
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason) {
  Serial.println("Disconnected from MQTT.");

  if (WiFi.isConnected()) {
    mqttReconnectTimer.once(2, connectToMqtt);
  }
}

void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total) {
  // Do whatever you want when you receive a message

  // Save the message in a variable
  String receivedMessage;
  for (int i = 0; i < len; i++) {
    Serial.println((char)payload[i]);
    receivedMessage += (char)payload[i];
  }
  // Turn the uv/sensor on or off accordingly to the message content
  if (strcmp(topic, "uv/sensor") == 0) {
    if (receivedMessage == "true"){
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if (receivedMessage == "false"){
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  Serial.println("Publish received.");
  Serial.print("  topic: ");
  Serial.println(topic);
  Serial.print("  qos: ");
  Serial.println(properties.qos);
  Serial.print("  dup: ");
  Serial.println(properties.dup);
  Serial.print("  retain: ");
  Serial.println(properties.retain);
  Serial.print("  len: ");
  Serial.println(len);
  Serial.print("  index: ");
  Serial.println(index);
  Serial.print("  total: ");
  Serial.println(total);
}

void onMqttPublish(uint16_t packetId) {
  Serial.println("Publish acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
  Serial.println("-------------------------------");
  Serial.println("");
}

void setup() {
  Serial.begin(9600); // Inicializa comunicação serial
  wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
  wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);

  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onMessage(onMqttMessage);
  mqttClient.onPublish(onMqttPublish);
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCredentials(BROKER_USER, BROKER_PASS);


  connectToWifi();
}

void loop() {
  int leitura = analogRead(pinoSensorUV); // Lê valor analógico (0~1023)
  
  // Converte para tensão (em Volts)
  float tensao = leitura * (5.0 / 1023.0);

  // Estimação simples do índice UV (ajuste conforme seu sensor real)
  float indiceUV = tensao * 10.0;

  String classificacao;
  if      (indiceUV <= 2.0) classificacao = "Baixo";
  else if (indiceUV <= 5.0) classificacao = "Moderado";
  else if (indiceUV <= 7.0) classificacao = "Alto";
  else                      classificacao = "Muito Alto";

  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\tTensão: ");
  Serial.print(tensao);
  Serial.print(" V\tÍndice UV: ");
  Serial.println(indiceUV);

  String payload = "{";
  payload += "\"nivel_uv\":" + String(indiceUV, 1) + ",";
  payload += "\"classificacao\":\"" + classificacao + "\"";
  payload += "}";

  // Publish an MQTT message on uv/sensor
  uint16_t packetIdPub1 = mqttClient.publish("uv/sensor", 1, true, payload.c_str());
  Serial.printf("Publishing on topic %s at QoS 1, packetId: %i", "uv/sensor", packetIdPub1);

  delay(4500); // Aguarda 4,5 segundos
}
