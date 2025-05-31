# UVTrack – Sistema Inteligente para Monitoramento de Exposição Solar

Este repositório contém os artefatos relacionados ao desenvolvimento do **UVTrack**, um dispositivo vestível inteligente, acoplado a um boné, projetado para monitorar a exposição do usuário à radiação ultravioleta (UV) em tempo real e fornecer alertas preventivos.

## 🎯 Objetivo

O objetivo principal do UVTrack é mitigar os riscos à saúde associados à superexposição solar, como queimaduras e o desenvolvimento de doenças de pele. O sistema alerta o usuário através de sinais vibratórios quando os níveis de radiação UV atingem patamares considerados inseguros, incentivando práticas preventivas durante atividades ao ar livre, esportes ou como Equipamento de Proteção Individual (EPI) para trabalhadores expostos ao sol.

## ⚙️ Arquitetura e Funcionamento do Sistema

O UVTrack opera com base em uma arquitetura IoT integrada, compreendendo um dispositivo vestível (hardware embarcado) e uma plataforma de software para coleta e visualização de dados.

1.  **Coleta de Dados:** O sensor UV **GUVA-S12SD**, acoplado ao boné, mede continuamente a intensidade da radiação UV ambiente.
2.  **Processamento Embarcado:** O microcontrolador **ESP8266 NodeMCU** lê os dados do sensor, calcula o Índice UV correspondente e compara com limiares pré-definidos.
3.  **Alerta Local:** Caso um limiar de segurança seja ultrapassado, o ESP8266 ativa um **módulo de vibração** para notificar o usuário tátilmente.
4.  **Comunicação:** Os dados processados (Índice UV, classificação de risco) são formatados em **JSON** e transmitidos via **Wi-Fi** utilizando o protocolo **MQTT** para um broker central.
5.  **Processamento Backend:** Um serviço desenvolvido em **Go (Golang)** recebe as mensagens MQTT, valida os dados e os persiste em um banco de dados de séries temporais **InfluxDB**.
6.  **Visualização:** Uma plataforma **Grafana** conectada ao InfluxDB permite ao usuário visualizar o histórico de exposição UV e outras métricas relevantes através de dashboards web interativos.

*(Para uma visão detalhada da arquitetura, consulte o Diagrama de Arquitetura na documentação do projeto.)*

## 🛠️ Hardware

Os principais componentes eletrônicos do dispositivo vestível incluem:

*   **Microcontrolador:** ESP8266 NodeMCU (com Wi-Fi integrado)
*   **Sensor UV:** GUVA-S12SD
*   **Atuador:** Módulo de Vibração
*   **Alimentação:** Bateria LiPo 3.7V com Módulo Carregador (ex: TP4056)

*(Consulte o arquivo `UVTrack - Código.brd` - se disponível e atualizado - ou os diagramas na documentação para detalhes do circuito.)*

## 👨‍💻 Firmware

O firmware embarcado no ESP8266 é desenvolvido em C++ (utilizando o framework Arduino) e é responsável por:

*   Inicializar hardware e conexões (Wi-Fi, MQTT).
*   Realizar leituras periódicas do sensor GUVA-S12SD.
*   Calcular o Índice UV.
*   Comparar o Índice UV com os limiares e ativar o módulo de vibração.
*   Formatar os dados em JSON.
*   Publicar os dados via MQTT.
*   Gerenciar o consumo de energia (ex: modos de sleep).

O código-fonte principal do firmware pode ser encontrado em `UVTrack - Código Arduino.ino`.

## ☁️ Plataforma de Software (Backend e Visualização)

A plataforma de software, responsável pela coleta, armazenamento e visualização dos dados, é composta por:

*   **Broker MQTT:** (Ex: Mosquitto) - Recebe os dados do dispositivo.
*   **Serviço de Ingestão:** Aplicação em Go - Processa e armazena os dados.
*   **Banco de Dados:** InfluxDB - Armazena as séries temporais de dados UV.
*   **Plataforma de Dashboard:** Grafana - Visualiza os dados.

*(O código e a configuração desta plataforma podem estar localizados no repositório complementar `gustavosouto/sensoruv`.)*

## 📋 Tecnologias Utilizadas

*   **Hardware:** ESP8266, GUVA-S12SD, Módulo de Vibração, LiPo.
*   **Firmware:** C++, Arduino Framework.
*   **Comunicação:** Wi-Fi, MQTT, JSON.
*   **Backend:** Go (Golang).
*   **Banco de Dados:** InfluxDB.
*   **Visualização:** Grafana.
*   **Controle de Versão:** Git, GitHub.
*   **(Opcional) Orquestração:** Docker, Docker Compose (para a plataforma backend).

## 🚀 Uso e Configuração

*(Esta seção deve ser detalhada com instruções sobre como compilar e carregar o firmware no ESP8266, configurar as credenciais de Wi-Fi e MQTT, e como acessar a plataforma Grafana, se aplicável.)*

1.  **Configurar Credenciais:** Atualize as definições de `WIFI_SSID`, `WIFI_PASSWORD`, `MQTT_HOST`, `MQTT_PORT`, `BROKER_USER`, `BROKER_PASS` no arquivo `UVTrack - Código Arduino.ino`.
2.  **Compilar e Carregar:** Utilize a Arduino IDE ou PlatformIO para compilar o firmware e carregá-lo no módulo ESP8266 NodeMCU.
3.  **Alimentação:** Conecte a bateria LiPo carregada.
4.  **Monitoramento:** O dispositivo iniciará a leitura do sensor e a publicação dos dados via MQTT. Alertas vibratórios serão acionados conforme os limiares.
5.  **Visualização:** Acesse o dashboard configurado no Grafana para visualizar os dados históricos e em tempo real (consulte a documentação do backend para o endereço do Grafana).

## 📄 Documentação

*   **Documento Principal:** `UVTrack - Projeto Integrador 6.pdf` (Contém detalhes sobre escopo, arquitetura, design, cronograma e orçamento).
*   **Diagramas:** Arquivos `.puml` ou imagens geradas (Casos de Uso, Classes, Arquitetura, Sequência) podem estar na pasta `Documentos` ou similar.

## 👥 Equipe de Desenvolvimento

| Nome Completo                       | GitHub                                   | Responsabilidade Técnica                                    |
| :---------------------------------- | :--------------------------------------- | :---------------------------------------------------------- |
| Gustavo Souto Silva de Barros Santos| [@GustavoSouto](https://github.com/GustavoSouto) | Analista de Requisitos, Documentação Técnica, Montagem Física, Líder |
| João Lucas Camilo                   | [@joaolucascamilo](https://github.com/joaolucascamilo) | Engenheiro de Firmware, Testes Funcionais                     |
| Luiz Felipe Silva                   | [@LuizFelipee96](https://github.com/LuizFelipee96) | Arquiteto de Sistemas, Coordenador Técnico                  |

*(Nota: Verificar se a lista de membros e responsabilidades está atualizada.)*

## 🤝 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir *issues* para reportar problemas ou sugerir melhorias, ou submeter *pull requests* com novas funcionalidades ou correções.

