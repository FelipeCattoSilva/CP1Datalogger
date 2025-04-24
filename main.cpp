#include <LiquidCrystal.h>

// Inicializando o LCD nos pinos especificados
LiquidCrystal LCD(9, 8, 7, 6, 5, 4); // Pinos RS, E, D4, D5, D6, D7

// Array tridimensional para armazenar os 3 frames da animação do cavalo
byte cavalo[3][8][8] = {
  {
    {0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0E, 0x0E},
    {0x00, 0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x1F},
    {0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x1F, 0x1F},
    {0x00, 0x00, 0x05, 0x1F, 0x1D, 0x1F, 0x16, 0x06},
    {0x0C, 0x18, 0x10, 0x00, 0x01, 0x01, 0x01, 0x00},
    {0x1F, 0x1F, 0x1E, 0x17, 0x00, 0x00, 0x10, 0x00},
    {0x1F, 0x1F, 0x03, 0x02, 0x14, 0x04, 0x02, 0x00},
    {0x1C, 0x1C, 0x04, 0x04, 0x08, 0x00, 0x00, 0x00}
  },
  {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x1E},
    {0x00, 0x00, 0x00, 0x00, 0x0E, 0x1F, 0x1F, 0x1F},
    {0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x1F, 0x1F},
    {0x00, 0x05, 0x1F, 0x1D, 0x1F, 0x1B, 0x13, 0x10},
    {0x13, 0x03, 0x06, 0x0C, 0x10, 0x10, 0x00, 0x00},
    {0x1F, 0x17, 0x06, 0x0C, 0x10, 0x10, 0x00, 0x00},
    {0x1F, 0x1F, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00},
    {0x10, 0x18, 0x1C, 0x08, 0x08, 0x00, 0x10, 0x00}
  },
  {
    {0x00, 0x00, 0x00, 0x07, 0x0F, 0x0E, 0x1C, 0x18},
    {0x00, 0x00, 0x00, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F},
    {0x00, 0x00, 0x01, 0x03, 0x1F, 0x1F, 0x1F, 0x1F},
    {0x14, 0x1C, 0x1A, 0x1E, 0x1F, 0x13, 0x10, 0x10},
    {0x13, 0x13, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00},
    {0x1F, 0x07, 0x0E, 0x06, 0x01, 0x00, 0x00, 0x00},
    {0x0F, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00},
    {0x10, 0x18, 0x0C, 0x02, 0x02, 0x11, 0x00, 0x00}
  }
};

// Função que exibe uma animação de carregamento com o cavalo se movendo
void animacaoCarregamento() {
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Carregando...");

  int posicaoCavalo = 0; // Posição inicial do cavalo

  for (int progresso = 0; progresso <= 100; progresso += 10) {
    LCD.setCursor(0, 1);
    LCD.print(progresso);
    LCD.print("%");

    for (int frame = 0; frame < 3; frame++) {
      // Cria os 8 caracteres personalizados para o frame atual
      for (int i = 0; i < 8; i++) {
        LCD.createChar(i, cavalo[frame][i]);
      }
      // Limpa a linha 1 para evitar sobreposição
      LCD.setCursor(0, 1);
      LCD.print("                "); // 16 espaços

      // Escreve os 4 caracteres do cavalo na posição atual
      LCD.setCursor(posicaoCavalo, 1);
      for (int col = 0; col < 4; col++) {
        if (posicaoCavalo + col < 16) {
          LCD.write(byte(col)); // Escreve os caracteres 0 a 3
        }
      }
      delay(150); // Atraso para suavizar a animação

      // Move o cavalo uma coluna para a direita
      posicaoCavalo = (posicaoCavalo + 1) % 13; // De 0 a 12
    }
    delay(200); // Atraso para atualizar a porcentagem
  }

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("UnlimitTech");
  delay(1000);
  LCD.setCursor(0, 1);
  LCD.print("Solution");
  delay(1000);

  for (int i = 0; i < 3; i++) {
    LCD.setCursor(13, 1);
    LCD.print(" ");
    delay(500);
    LCD.setCursor(13, 1);
    LCD.print("<>");
    delay(500);
  }

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Bem-Vindo!");
  delay(2000);
}

// Definição dos pinos
int ledVermelhoPin = 11;
int ledAmareloPin  = 12;
int ledVerdePin    = 13;
int ldrPin         = A1;
int buzzerPin      = 10;
int sensorTempPin  = A2;
int sensorUmidPin  = A0;

// Constantes para os estados
const int ESCURO   = 0;
const int MEIA_LUZ = 1;
const int CLARO    = 2;
int luz = ESCURO;

const int TEMP_OK = 0;
const int FRIO    = 1;
const int QUENTE  = 2;
int temperaturaAmbiente = TEMP_OK;

const int UMID_OK    = 0;
const int UMID_BAIXA = 1;
const int UMID_ALTA  = 2;
int umidadeAmbiente = UMID_OK;

const int tempoMostrarDisplay = 1000;

const int MOSTRA_LUZ  = 0;
const int MOSTRA_TEMP = 1;
const int MOSTRA_UMID = 2;
int estadoDisplay = MOSTRA_LUZ;

// Variáveis para sensores e médias
int   valorLDR    = 0;
float temperatura = 0;
int   umidade     = 0;

unsigned long millisDisplayAgora = 0;
unsigned long millisDisplayAnterior = 0;

int   contadorMedia = 0;
float somaTemperatura = 0;
int   somaUmidade = 0;
float mediaTemperatura = 0;
int   mediaUmidade = 0;

void setup() {
  LCD.begin(16, 2);
  animacaoCarregamento();
  pinMode(ledVermelhoPin, OUTPUT);
  pinMode(ledAmareloPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(sensorUmidPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  ler_sensores();
  verifica_sensores();
  aciona_alarmes();
  mostra_mensagem();
}

void ler_sensores() {
  valorLDR = analogRead(ldrPin);
  Serial.print("LDR: ");
  Serial.println(valorLDR);

  int valorSensorTemp = analogRead(sensorTempPin);
  float tensao = valorSensorTemp * 5.0 / 1024.0;
  temperatura = (tensao - 0.5) * 100.0;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  int valorSensorUmi = analogRead(sensorUmidPin);
  umidade = map(valorSensorUmi, 0, 1023, 0, 100);
  Serial.print("Umidade: ");
  Serial.println(umidade);
}

void verifica_sensores() {
  Serial.print("Ambiente está ");
  if (valorLDR <= 700) {
    luz = ESCURO;
    Serial.println("Escuro");
  } else if (valorLDR > 700 && valorLDR <= 900) {
    luz = MEIA_LUZ;
    Serial.println("Penumbra");
  } else {
    luz = CLARO;
    Serial.println("Claro");
  }

  Serial.print("Temperatura está ");
  if (temperatura < 6) {
    temperaturaAmbiente = FRIO;
    Serial.println("fria");
  } else if (temperatura > 19) {
    temperaturaAmbiente = QUENTE;
    Serial.println("quente");
  } else {
    temperaturaAmbiente = TEMP_OK;
    Serial.println("Ideal");
  }

  Serial.print("Umidade está ");
  if (umidade < 60) {
    umidadeAmbiente = UMID_BAIXA;
    Serial.println("baixa");
  } else if (umidade > 80) {
    umidadeAmbiente = UMID_ALTA;
    Serial.println("alta");
  } else {
    umidadeAmbiente = UMID_OK;
    Serial.println("Ideal");
  }
}

void aciona_alarmes() {
  digitalWrite(ledVerdePin, (luz == ESCURO) ? HIGH : LOW);
  digitalWrite(ledAmareloPin, (luz == MEIA_LUZ || temperaturaAmbiente != TEMP_OK) ? HIGH : LOW);
  digitalWrite(ledVermelhoPin, (luz == CLARO || umidadeAmbiente != UMID_OK || temperatura < 6 || temperatura > 19) ? HIGH : LOW);
  digitalWrite(buzzerPin, (luz == CLARO) ? HIGH : LOW);
}

void mostra_mensagem() {
  millisDisplayAgora = millis();
  somaTemperatura += temperatura;
  somaUmidade += umidade;
  contadorMedia++;

  if (millisDisplayAgora - millisDisplayAnterior > tempoMostrarDisplay) {
    LCD.clear();
    LCD.setCursor(0, 0);

    switch (estadoDisplay) {
      case MOSTRA_LUZ:
        if (luz == ESCURO) {
          LCD.print("Luz Ambiente");
          LCD.setCursor(0, 1);
          LCD.print("Ideal");
        } else if (luz == MEIA_LUZ) {
          LCD.print("Ambiente");
          LCD.setCursor(0, 1);
          LCD.print("penumbra");
        } else {
          LCD.print("Ambiente");
          LCD.setCursor(0, 1);
          LCD.print("muito claro");
        }
        estadoDisplay = MOSTRA_TEMP;
        break;

      case MOSTRA_TEMP:
        mediaTemperatura = somaTemperatura / contadorMedia;
        if (temperaturaAmbiente == TEMP_OK) {
          LCD.print("Temp. Ideal");
          LCD.setCursor(0, 1);
          LCD.print("Temp. = ");
          LCD.print(mediaTemperatura);
          LCD.print("C");
        } else if (temperaturaAmbiente == FRIO) {
          LCD.print("Temp. Baixa");
          LCD.setCursor(0, 1);
          LCD.print("Temp. = ");
          LCD.print(mediaTemperatura);
          LCD.print("C");
        } else {
          LCD.print("Temp. Alta");
          LCD.setCursor(0, 1);
          LCD.print("Temp. = ");
          LCD.print(mediaTemperatura);
          LCD.print("C");
        }
        estadoDisplay = MOSTRA_UMID;
        break;

      case MOSTRA_UMID:
        mediaUmidade = somaUmidade / contadorMedia;
        if (umidadeAmbiente == UMID_OK) {
          LCD.print("Umidade Ideal");
          LCD.setCursor(0, 1);
          LCD.print("Umidade = ");
          LCD.print(mediaUmidade);
          LCD.print("%");
        } else if (umidadeAmbiente == UMID_BAIXA) {
          LCD.print("Umidade Baixa");
          LCD.setCursor(0, 1);
          LCD.print("Umidade = ");
          LCD.print(mediaUmidade);
          LCD.print("%");
        } else {
          LCD.print("Umidade Alta");
          LCD.setCursor(0, 1);
          LCD.print("Umidade = ");
          LCD.print(mediaUmidade);
          LCD.print("%");
        }
        estadoDisplay = MOSTRA_LUZ;
        break;
    }
    millisDisplayAnterior = millisDisplayAgora;
  }
}
