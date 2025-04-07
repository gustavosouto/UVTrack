# UVTrack – Sistema de Monitoramento de Radiação UV

## 📌 Descrição do Projeto

O presente projeto consiste no desenvolvimento de um boné dotado de sensores capazes de realizar o monitoramento contínuo da exposição à radiação ultravioleta (UV), onde o objetivo é fornecer alertas ao usuários – através de sinais vibratórios e visuais – quando os níveis de radiação luminosa ou temperatura estiverem acima dos limites seguros de modo a prevenir riscos à saúde humana decorrente da superexposição solar. A finalidade do projeto é incentivar práticas preventivas de saúde, onde seu uso será voltado para atividades ao ar livre, esporte ou como EPI para trabalhadores expostos ao sol.

---

## ⚙️ Funcionamento do Sistema

O boné inteligente desenvolvido visa monitorar em tempo real as condições ambientais relacionadas à exposição solar, fornecendo alertas imediatos ao usuário sobre níveis elevados de radiação e temperatura. O funcionamento do dispositivo baseia-se em três etapas integradas: coleta de dados, processamento e emissão de alertas. 

A coleta dos dados ambientais ocorre através de dois sensores principais. A intensidade da radiação ultravioleta é simulada por um fotoresistor LDR (Substituindo Sensor UV), devidamente conectado à porta analógica A0 do Arduino Uno R3 (Substituindo Arduino Lilypad). Este sensor atua medindo a luminosidade do ambiente, servindo como referência para estimar a exposição à radiação solar. Em complemento, a temperatura do ambiente é monitorada por um sensor TMP36, conectado à porta analógica A1, que fornece leituras precisas de temperatura, substituindo, para fins de simulação, o sensor BME280, que originalmente seria utilizado.

Após a coleta, os dados são processados pelo microcontrolador Arduino Uno R3, que analisa os valores de luminosidade e temperatura. Quando algum dos parâmetros ultrapassa o limite seguro previamente estabelecido no código do sistema, são acionados os mecanismos de alerta. A comunicação desses dados ao usuário, que no projeto físico ocorreria via Bluetooth HC-05, é simulada no Tinkercad por meio do Serial Monitor, permitindo visualizar em tempo real os valores medidos e os estados de alerta.

O sistema de alerta é composto por dois elementos. O alerta visual é realizado através de um LED comum, que substitui o LED LilyPad, e está conectado ao pino digital D13 do Arduino Uno R3. Esse LED é protegido por um resistor de 220 ohms, que limita a corrente elétrica, preservando a integridade do componente. Já o alerta tátil é viabilizado por um motor CC, que substitui o módulo de vibração. Este motor é controlado por um transistor NPN TIP120, cuja base está conectada ao pino digital D3 do Arduino por meio de um resistor de 1k ohm, garantindo o acionamento seguro do motor sem sobrecarregar a placa controladora.

A utilização destes componentes substitutos foi necessária devido às limitações da plataforma Tinkercad, que não possui suporte direto para sensores UV ou comunicação Bluetooth. A adaptação com o fotoresistor, TMP36 e Serial Monitor assegura a fidelidade da simulação ao funcionamento real do projeto, permitindo validar sua lógica e resposta em tempo real às condições simuladas de exposição solar. Este dispositivo, portanto, integra tecnologia acessível e programação embarcada com o objetivo de prevenir riscos à saúde em situações de exposição prolongada ao sol, fornecendo dados e alertas que capacitam o usuário a tomar decisões informadas sobre sua segurança.

---

## 📋 Tecnologias Utilizadas

| Tecnologia     | Aplicação                                               |
|----------------|----------------------------------------------------------|
| Arduino IDE    | Programação e upload do código para o microcontrolador. |
| Tinkercad      | Simulação do circuito e testes de funcionalidade.       |
| GitHub         | Versionamento e colaboração no projeto.                 |

---

## 🔌 Componentes Originais

| Componente                 | Modelo               | Finalidade no Sistema                                                                 |
|----------------------------|----------------------|----------------------------------------------------------------------------------------|
| Microcontrolador           | Arduino LilyPad      | Controlar os sensores e atuadores com foco em aplicações vestíveis.                   |
| Sensor de temperatura/umidade | BME280           | Medição precisa da temperatura e umidade do ambiente.                                 |
| Sensor de radiação         | Sensor UV            | Captura a intensidade da radiação ultravioleta.                                       |
| Módulo de comunicação      | Módulo Bluetooth HC-05 | Transmissão dos dados via Bluetooth ao usuário.                                      |
| LED indicador              | LED LilyPad          | Alerta visual ao usuário em caso de radiação ou temperatura elevada.                  |
| Alerta tátil               | Módulo de vibração   | Geração de feedback tátil quando limites são excedidos.                               |

---

## 💡 Componentes Utilizados na Simulação

| Componente                 | Modelo               | Justificativa de Uso na Simulação                                                     |
|----------------------------|----------------------|----------------------------------------------------------------------------------------|
| Microcontrolador           | Arduino Uno R3       | Disponível no Tinkercad, funcionalmente equivalente ao LilyPad.                       |
| Sensor de temperatura      | TMP36                | Sensor analógico simples e compatível com o ambiente simulado.                        |
| Sensor de luminosidade     | LDR (Fotoresistor)   | Simula a radiação solar ao medir a luminosidade.                                      |
| Módulo de comunicação      | Monitor Serial       | Substitui o Bluetooth para fins de visualização na simulação.                         |
| LED indicador              | LED Comum            | Simula o alerta visual original com mesma lógica de acionamento.                      |
| Alerta tátil               | Motor CC             | Reproduz o alerta tátil por vibração.                                                 |
| Transistor                 | TIP120               | Necessário para controlar o motor sem sobrecarregar o microcontrolador.               |
| Resistores                 | 220Ω, 1kΩ            | Usados para limitar corrente nos atuadores (LED e base do transistor).                |

---

## 🔁 Tabela de Equivalência

| Componente Original     | Componente Substituto | Justificativa                                           |
|--------------------------|------------------------|----------------------------------------------------------|
| Arduino LilyPad          | Arduino Uno R3         | Disponível no Tinkercad com funcionamento compatível.    |
| Sensor BME280            | Sensor TMP36           | Sensor analógico simples com leitura de temperatura.     |
| Sensor de radiação UV    | LDR (Fotoresistor)     | Simula a intensidade da luz solar.                       |
| LED LilyPad              | LED Comum              | Possui a mesma funcionalidade de alerta visual.          |
| Módulo de vibração       | Motor CC               | Reproduz o alerta tátil por vibração.                    |
| Módulo Bluetooth HC-05   | Serial Monitor         | Utilizado como substituto para transmissão de dados.     |

---

## 🧪 Simulação Tinkercad

A simulação foi realizada na plataforma Tinkercad, onde os componentes foram integrados e testados quanto à lógica de funcionamento e emissão de alertas.

🔗 Link para simulação: [Acesse o projeto no Tinkercad]([https://www.tinkercad.com](https://www.tinkercad.com/things/cwpPFPqJfvZ-uvtrack/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=IRnn-mejee00jDnhUTVhbiRiY1knzX_Q1l7WBOqrC2Q))

---

## 🎬 Demonstração

🔗 Link para vídeo da execução do projeto físico:  
**[Clique aqui para assistir no YouTube](https://www.youtube.com/)**  
*(Atualize com o link oficial assim que disponível)*

---

## 📂 Links Úteis

| Componente         | Datasheet/Especificação Técnica                                      |
|--------------------|---------------------------------------------------------------------------|
| TMP36              | [Datasheet TMP36](https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf) |
| LDR                | [Datasheet LDR](https://cdn.sparkfun.com/datasheets/Sensors/Light/SEN-09088.pdf) |
| Motor CC           | [Datasheet Motor Genérico](https://www.electroschematics.com/wp-content/uploads/2021/07/DC-Motor-Datasheet.pdf) |
| Transistor TIP120  | [Datasheet TIP120](https://www.onsemi.com/pdf/datasheet/tip120-d.pdf) |
| Resistor           | [Tabela de Códigos de Cores](https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code) |

---

## 👥 Equipe de Desenvolvimento

| Nome Completo                            | GitHub                                                              | Responsabilidade Técnica                                                                                                                                                                   |
|-----------------------------------------|---------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Gustavo Souto Silva de Barros Santos**| [@GustavoSouto](https://github.com/GustavoSouto)                    | Responsável pela elicitação, modelagem e rastreabilidade dos RFs e RNFs, bem como pela documentação técnica. Atua como **Analista de Requisitos** e **Product Owner (PO)**.               |
| **João Lucas Camilo**                   | [@joaolucascamilo](https://github.com/joaolucascamilo)              | Responsável pela programação embarcada, testes funcionais e calibração do sistema. Atua como **Engenheiro de Firmware** e **Engenheiro de Testes**.                                       |
| **Luiz Felipe Silva**                   | [@LuizFelipee96](https://github.com/LuizFelipee96)                  | Responsável pela arquitetura do sistema, integração de hardware e supervisão técnica. Atua como **Coordenador Técnico** e **Arquiteto de Sistemas**.                                       |
| **Nicolas Sá Simões**                   | [@NicolasSasi](https://github.com/NicolasSasi)                      | Responsável pelo design físico e interface do produto com o usuário. Atua como **Designer de Produto** e **Engenheiro de Interface**.                                                     |

## 🤝 Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para propor melhorias, corrigir problemas ou adicionar novos recursos ao projeto.
