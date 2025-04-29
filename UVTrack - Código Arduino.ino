// Definimos onde ligamos o pino de saída do sensor
const int pinoSensorUV = A0; // Ligado no A0

// Definimos os pinos dos LEDs
const int ledVerde = 2;   // LED Verde no pino digital 2
const int ledAmarelo = 3; // LED Amarelo no pino digital 3
const int ledVermelho = 4; // LED Vermelho no pino digital 4

void setup() {
  Serial.begin(9600); // Inicializa comunicação serial

  // Define os pinos dos LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  int leitura = analogRead(pinoSensorUV); // Lê valor analógico (0~1023)
  
  // Converte para tensão (em Volts)
  float tensao = leitura * (5.0 / 1023.0);

  // Estimação simples do índice UV (ajuste conforme seu sensor real)
  float indiceUV = tensao * 10.0;

  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\tTensão: ");
  Serial.print(tensao);
  Serial.print(" V\tÍndice UV: ");
  Serial.println(indiceUV);

  // Condições de risco baseadas no índice UV
  if (indiceUV <= 2.0) {
    // Baixo risco → LED verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  else if (indiceUV > 2.0 && indiceUV <= 5.0) {
    // Risco moderado → LED amarelo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  }
  else if (indiceUV > 5.0) {
    // Risco alto, muito alto ou extremo → LED vermelho
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  delay(4500); // Aguarda 4,5 segundos
}
