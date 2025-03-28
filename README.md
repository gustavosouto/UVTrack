## Boné Inteligente Monitorador de Exposição Solar

O presente projeto consiste no desenvolvimento de um boné dotado de sensores capazes de realizar o monitoramento contínuo da exposição à radiação ultravioleta (UV), onde o objetivo é fornecer alertas ao usuários - através de sinais vibratórios e visuais - quando os níveis de radiação luminosa ou temperatura estiverem acima dos limites seguros de modo a prevenir riscos à saude humana decorrente da superexposição solar. A finalidade do projeto é incentivar práticas preventivas de saúde, onde seu uso será voltado para atividades ao ar livre, esporte ou como EPI para trabalhadores expostos ao sol.

## Componentes Utilizados

| **Componente Original**     | **Substituto no Tinkercad**             | **Função no Sistema**                                                             |
|----------------------------|-----------------------------------------|-----------------------------------------------------------------------------------|
| Arduino LilyPad            | Arduino Uno R3                          | Microcontrolador responsável pelo controle do sistema.                           |
| Sensor UV ML8511           | Ambient Light Sensor (Fotoresistor)     | Simulação da leitura de níveis de radiação UV.                                   |
| LED LilyPad                | LED comum (com resistor de 220Ω)        | Sinalização visual da intensidade UV.                                            |
| Módulo de Vibração         | Motor CC + Transistor NPN TIP120        | Simulação de alerta vibratório, controlado via PWM.                              |
| Bluetooth HC-05            | Comunicação via Serial Monitor          | Envio de dados para o usuário, simulando conectividade Bluetooth.                |
| Sensor BME280              | Sensor TMP36                            | Simulação de leitura de temperatura ambiente.                                    |
| Resistor de 220Ω           | Resistor de 220Ω                        | Proteção para LED.                                                               |
| Resistor de 10kΩ           | Resistor de 10kΩ                        | Pull-down para fotoresistor.                                                     |
| Resistor de 1kΩ            | Resistor de 1kΩ                         | Controle de corrente na base do transistor NPN.                                  |


## Funcionamento

O boné inteligente desenvolvido visa monitorar em tempo real as condições ambientais relacionadas à exposição solar, fornecendo alertas imediatos ao usuário sobre níveis elevados de radiação e temperatura. O funcionamento do dispositivo baseia-se em três etapas integradas: coleta de dados, processamento e emissão de alertas.

A coleta dos dados ambientais ocorre através de dois sensores principais. A intensidade da radiação ultravioleta é simulada por um fotoresistor LDR (Substituindo Sensor UV), devidamente conectado à porta analógica A0 do Arduino Uno R3 (Substituindo Arduino Lilypad). Este sensor atua medindo a luminosidade do ambiente, servindo como referência para estimar a exposição à radiação solar. Em complemento, a temperatura do ambiente é monitorada por um sensor TMP36, conectado à porta analógica A1, que fornece leituras precisas de temperatura, substituindo, para fins de simulação, o sensor BME280, que originalmente seria utilizado.

Após a coleta, os dados são processados pelo microcontrolador Arduino Uno R3, que analisa os valores de luminosidade e temperatura. Quando algum dos parâmetros ultrapassa o limite seguro previamente estabelecido no código do sistema, são acionados os mecanismos de alerta. A comunicação desses dados ao usuário, que no projeto físico ocorreria via Bluetooth HC-05, é simulada no Tinkercad por meio do Serial Monitor, permitindo visualizar em tempo real os valores medidos e os estados de alerta.

O sistema de alerta é composto por dois elementos. O alerta visual é realizado através de um LED comum, que substitui o LED LilyPad, e está conectado ao pino digital D13 do Arduino Uno R3. Esse LED é protegido por um resistor de 220 ohms, que limita a corrente elétrica, preservando a integridade do componente. Já o alerta tátil é viabilizado por um motor CC, que substitui o módulo de vibração. Este motor é controlado por um transistor NPN TIP120, cuja base está conectada ao pino digital D3 do Arduino por meio de um resistor de 1k ohm, garantindo o acionamento seguro do motor sem sobrecarregar a placa controladora.

A utilização destes componentes substitutos foi necessária devido às limitações da plataforma Tinkercad, que não possui suporte direto para sensores UV ou comunicação Bluetooth. A adaptação com o fotoresistor, TMP36 e Serial Monitor assegura a fidelidade da simulação ao funcionamento real do projeto, permitindo validar sua lógica e resposta em tempo real às condições simuladas de exposição solar. Este dispositivo, portanto, integra tecnologia acessível e programação embarcada com o objetivo de prevenir riscos à saúde em situações de exposição prolongada ao sol, fornecendo dados e alertas que capacitam o usuário a tomar decisões informadas sobre sua segurança.

## Tinkercad Simulation
Você pode acessar uma simulação deste projeto no Tinkercad clicando [aqui](https://www.tinkercad.com/things/cwpPFPqJfvZ-smooth-trug-elzing/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=IRnn-mejee00jDnhUTVhbiRiY1knzX_Q1l7WBOqrC2Q). Esta simulação permite visualizar o funcionamento do boné inteligente em um ambiente virtual antes de implementá-lo fisicamente.

## Instalação
-x-

## Youtube
A apresentação deste projeto foi gravado por videor e publicado no Youtube através do link: [aqui](X)

## Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para propor melhorias, corrigir problemas ou adicionar novos recursos ao projeto.
