# Global Solution - Edge

## Integrantes
### Mohamed Afif Smaili RM 554445
### Juan F. Alves Muradas RM 555541
### Ahmad Jaafar RM: 97927

## Link do projeto do Wokwi
https://wokwi.com/projects/399225250407839745

# Projeto de Monitoramento de Qualidade da Água com Arduino

Este projeto utiliza um Arduino para monitorar a qualidade da água em tempo real, exibindo informações em um display LCD e acionando servos de acordo com a leitura dos sensores. O sistema também acende LEDs para indicar se a água está segura ou contaminada.

## Componentes Necessários

- Arduino Uno ou similar
- Sensor de Temperatura DS18B20
- Sensor de Condutividade Elétrica (EC)
- Sensor de pH
- Sensor de Oxigênio Dissolvido (DO)
- Sensor de Luminosidade (LDR)
- Display LCD I2C (16x2)
- Dois servos motores
- LEDs
- Resistor 4.7kΩ (para o DS18B20)
- Protoboard e fios de conexão

## Conexões

### Sensores

- *DS18B20*: Conectar o pino de dados ao pino A0 do Arduino.
- *EC Sensor*: Conectar a saída analógica ao pino A1 do Arduino.
- *pH Sensor*: Conectar a saída analógica ao pino A2 do Arduino.
- *DO Sensor*: Conectar a saída analógica ao pino A3 do Arduino.
- *LDR*: Conectar a saída analógica ao pino A4 do Arduino.

### Servos

- *Servo Esquerdo*: Conectar ao pino 9 do Arduino.
- *Servo Direito*: Conectar ao pino 10 do Arduino.

### LEDs

- *LED1*: Conectar o anodo ao pino 13 do Arduino.
- *LED2*: Conectar o anodo ao pino 12 do Arduino.

### LCD

- Conectar o display LCD aos pinos I2C do Arduino (SDA e SCL).

### Código
- Inclusão de Bibliotecas: O código inclui bibliotecas necessárias para o funcionamento dos sensores, LCD e servos.
- Definição de Pinos: Define os pinos onde os sensores e servos estão conectados.
- Instâncias e Inicializações: Inicializa as instâncias necessárias para os sensores, LCD e servos.
- Variáveis de Controle de Tempo: Define variáveis para controlar o tempo de leitura dos sensores, movimento dos servos e atualização do LCD.
- Função setup: Configura a comunicação serial, inicializa os sensores, LCD, e define a posição inicial dos servos. Também configura os LEDs.
- Função loop:
 - Verifica se é hora de ler os sensores.
 - Atualiza o LCD com os dados dos sensores.
 - Acende os LEDs com base na qualidade da água.
 - Move os servos periodicamente.
 - Função moverServo: Controla o movimento dos servos alternando entre duas posições.
- Funcionamento
 - O código lê os valores dos sensores periodicamente e os exibe no LCD.
 - Dependendo dos valores dos sensores, acende um LED indicando se a água está segura ou contaminada.
 - Os servos são movimentados em intervalos regulares.
 - Os dados dos sensores são enviados para o console serial para monitoramento.
- Ajustes
 - Limites de Qualidade da Água: Os limites de pH, condutividade elétrica e oxigênio dissolvido podem ser ajustados conforme necessário.
 - Intervalos de Tempo: Os intervalos de leitura dos sensores, movimentação dos servos e atualização do LCD podem ser modificados para atender às necessidades específicas do projeto.
 - Este projeto pode ser expandido ou ajustado para incluir mais sensores ou funcionalidades adicionais, dependendo das necessidades do usuário.
