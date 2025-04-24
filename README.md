---

# Data Logger Unlimit Tech Solution

## Descrição do Projeto
O **Monitor de Ambiente com Animação de Cavalo** é um sistema desenvolvido para Arduino que monitora as condições ambientais utilizando sensores de luz (LDR), temperatura e umidade. Ele exibe as leituras em um display LCD, aciona LEDs e um buzzer para alertas visuais e sonoros, e apresenta uma animação de um cavalo durante a inicialização.

### Funcionalidades
- Monitoramento em tempo real de luz, temperatura e umidade.
- Alertas visuais por LEDs (verde, amarelo, vermelho) e sonoros via buzzer com base nas condições ambientais.
- Exibição alternada das leituras no display LCD.
- Animação de um cavalo se movendo no LCD durante o carregamento inicial.

---

## Dependências

### Componentes
Para construir este projeto, você precisará dos seguintes itens:
- **Arduino Uno** (ou modelo compatível)
- **Display LCD 16x2**
- **Sensor LDR** (para medir luz)
- **Sensor de temperatura** (exemplo: LM35)
- **Sensor de umidade** (exemplo: DHT11)
- **LEDs**: 1 verde, 1 amarelo, 1 vermelho
- **Buzzer**
- **Resistores** (valores apropriados para LEDs e sensores)
- **Fios de conexão**

### Bibliotecas
Você precisará da seguinte biblioteca no Arduino IDE:
- **`LiquidCrystal`**: Para controle do display LCD.
  - **Instalação**: No Arduino IDE, vá em **Sketch > Incluir Biblioteca > LiquidCrystal**.

---

## Como Reproduzir o Projeto

### Configuração do Hardware
Siga as instruções abaixo para conectar os componentes ao Arduino:

1. **Display LCD**:
   - Pino RS → Pino 9 do Arduino
   - Pino E → Pino 8 do Arduino
   - Pinos D4-D7 → Pinos 7, 6, 5, 4 do Arduino

2. **Sensores**:
   - Sensor LDR → Pino A1
   - Sensor de temperatura → Pino A2
   - Sensor de umidade → Pino A0

3. **LEDs e Buzzer**:
   - LED verde → Pino 13
   - LED amarelo → Pino 12
   - LED vermelho → Pino 11
   - Buzzer → Pino 10

**Nota**: Utilize resistores adequados em série com os LEDs e sensores para limitar a corrente, conforme necessário.

### Configuração do Software
1. **Clone o Repositório**:
   ```bash
   git clone https://github.com/FelipeCattoSilva/CP1Datalogger.git
   ```
   
2. **Abra o Código no Arduino IDE**:
   - Certifique-se de que a biblioteca `LiquidCrystal` está instalada.
   - Abra o arquivo `.ino` do projeto no Arduino IDE.

3. **Carregue o Código no Arduino**:
   - Conecte o Arduino ao computador via cabo USB.
   - No Arduino IDE, selecione a placa correta (ex.: Arduino Uno) e a porta COM correspondente.
   - Clique em **Upload** para carregar o código no Arduino.

### Execução
- Após o upload, o Arduino iniciará automaticamente a animação de carregamento, exibindo um cavalo se movendo no LCD.
- Em seguida, o sistema começará a monitorar o ambiente, exibindo as leituras de luz, temperatura e umidade no display LCD e acionando os LEDs e o buzzer conforme as condições definidas no código.

---

## Personalização
Você pode ajustar o projeto de acordo com suas necessidades:
- **Limites dos Sensores**: Modifique os valores de *threshold* no código para alterar os pontos de acionamento dos alertas.
- **Animação**: Edite os frames do cavalo ou a velocidade da animação no código.
- **Mensagens no LCD**: Altere as mensagens exibidas ajustando a função `mostra_mensagem()` ou equivalente.

---
