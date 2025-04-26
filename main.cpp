#include <LiquidCrystal.h>

//Inicializando o LCD nos pinos especificados
LiquidCrystal LCD(9, 8, 7, 6, 5, 4); // LCD nos pinos 9, 8, 7, 6, 5, 4

// Declaração de um array tridimensional para armazenar os quadros da animação do cavalo
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

// Aplicando a função que exibe uma animação de carregamento no LCD
void animacaoCarregamento() {
  LCD.clear(); // Limpa o display
  LCD.setCursor(0, 0);
  LCD.print("Carregando..."); // Mensagem inicial de carregamento
  int posicao = 0; // Define a posição inicial no display

   // Animação de carregamento com porcentagem de progresso
  for (int progresso = 0; progresso <= 100; progresso += 10) {
    LCD.setCursor(0, 1);
    LCD.print(progresso);
    LCD.print("%");
    delay(200);

    // Atualiza os frames da animação
    for (int frame = 0; frame < 3; frame++) {
      for (int i = 0; i < 8; i++) {
        LCD.createChar(i, cavalo[frame][i]);
      }
      LCD.setCursor(posicao, 1);
      for (int col = 0; col < 4; col++) {
        if ((posicao + col) < 16) {
          LCD.setCursor(posicao + col, 1);
          LCD.write(byte(col));
        }
      }
      posicao = (posicao + 1) % 16;
      delay(100);
    }
  }
  LCD.clear();
  
  // Exibição mensagens adicionais de inicialização
  LCD.setCursor(0, 0);
  LCD.print("UnlimitTech");
  delay(0);
  LCD.setCursor(0, 1);
  LCD.print("Solution");
  delay(0);
  
  for (int i = 0; i < 3; i++) {
        LCD.setCursor(13, 1);
        LCD.print(" ");
        delay(700);
        LCD.setCursor(13, 1);
        LCD.print("<>");
        delay(900);
  }
  
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Bem-Vindo!"); 
  delay(2000);
}
  
// Define os pinos para LEDs, buzzer e sensores
int ledVermelhoPin = 11;  // LED vermelho no pino 9
int ledAmareloPin  = 12;  // LED amarelo no pino 10
int ledVerdePin    = 13;  // LED verde no pino 11
int ldrPin         = A1;  // LDR no pino A0
int buzzerPin      = 10;   // Buzzer no pino 7
int sensorTempPin  = A2;  // Sensor de temperatura no pino A2
int sensorUmidPin  = A0;  // Sensor de umidade no pino A1

// Definição de constantes para os estados de luz, temperatura e umidade
int ESCURO   = 0;
int MEIA_LUZ = 1;
int CLARO    = 2;
int luz = ESCURO;

int TEMP_OK = 0;
int FRIO    = 1;
int QUENTE  = 2;
int temperaturaAmbiente = TEMP_OK;

int UMID_OK    = 0;
int UMID_BAIXA = 1;
int UMID_ALTA  = 2;
int umidadeAmbiente = UMID_OK;

int tempoMostrarDisplay = 1000;

int const MOSTRA_LUZ  = 0;
int const MOSTRA_TEMP = 1;
int const MOSTRA_UMID = 2;
int estadoDisplay = MOSTRA_LUZ; // Alterna entre luz, temperatura e umidade

int   valorLDR    = 0;
float temperatura = 0;
int   umidade     = 0;

int millisDisplayAgora = 0;
int millisDisplayAnterior = 0;

int   contadorMedia = 0;
float somaTemperatura = 0;
int   somaUmidade = 0;

float mediaTemperatura = 0;
int   mediaUmidade = 0;

void setup() {
  LCD.begin(16, 2); // Configura o LCD para 16 colunas e 2 linhas
  animacaoCarregamento(); // Chama a animação de carregamento
  pinMode (ledVermelhoPin, OUTPUT);  
  pinMode (ledAmareloPin, OUTPUT);
  pinMode (ledVerdePin, OUTPUT);
  pinMode (ldrPin, INPUT);
  pinMode (buzzerPin, OUTPUT);
  pinMode (sensorUmidPin, INPUT);
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop(){
  ler_sensores(); // Lê os valores dos sensores
  verifica_sensores(); // Verifica os estados com base nos valores lidos
  aciona_alarmes(); // Aciona LEDs e buzzer conforme os estados
  mostra_mensagem(); // Exibe informações no LCD
} 

void ler_sensores(){
    valorLDR = analogRead (ldrPin); // Lê o valor do sensor LDR
	Serial.print("LDR: ");   
	Serial.println(valorLDR);
  
	// Lê e converte o valor do sensor de temperatura
	int valorSensorTemp = analogRead (sensorTempPin);

	float tensao = valorSensorTemp * 5;
	tensao /= 1024;

	temperatura = (tensao - 0.5) * 100;

   	Serial.print("Temperatura: ");
	Serial.println(temperatura);

  	// Lê e converte o valor do sensor de umidade
	int valorSensorUmi = analogRead(sensorUmidPin); 

	umidade = map(valorSensorUmi, 0, 1023, 0, 100); 
	Serial.print("Umidade: ");
	Serial.println(umidade);
}

// Verifica os estados com base nos valores lidos dos sensores
void verifica_sensores(){
  	// Verifica estado da luz
	Serial.print("Ambiente está ");
	if(valorLDR <= 700){
		luz = ESCURO;
		Serial.println("Escuro");
	} 
	else if(valorLDR > 700 && valorLDR <= 900){
		luz = MEIA_LUZ;
		Serial.println("Penumbra");
	}
	else if(valorLDR > 900){
		luz = CLARO;
		Serial.println("Claro");
	}
	
  	// Verifica estado da temperatura
	Serial.print("Temperatura está ");
	if(temperatura < 6){
		temperaturaAmbiente = FRIO;
		Serial.println("fria");
	}
	else if(temperatura > 19){
		temperaturaAmbiente = QUENTE;
		Serial.println("quente");
	}
	else {
		temperaturaAmbiente = TEMP_OK;
    	Serial.println("Ideal");
    }
	
  	// Verifica estado da umidade
	Serial.print("Umidade esta ");
	if(umidade < 60){
		umidadeAmbiente = UMID_BAIXA;
		Serial.println("baixa");
	}
	else if(umidade > 80){
		umidadeAmbiente = UMID_ALTA;
		Serial.println("alta");
	}
	else {
		umidadeAmbiente = UMID_OK;
		Serial.println("Ideal");
	}
}
// Aciona LEDs e buzzer com base nos estados
void aciona_alarmes(){
    if(luz == ESCURO){
        digitalWrite(ledVerdePin, HIGH);
    }
    else{
        digitalWrite(ledVerdePin, LOW);
    }

    if(luz == MEIA_LUZ || temperaturaAmbiente != TEMP_OK){
        digitalWrite(ledAmareloPin, HIGH);        
    }
    else{
        digitalWrite(ledAmareloPin, LOW);
    }

    if(luz == CLARO || umidadeAmbiente != UMID_OK || temperatura < 6 || temperatura > 19){
        digitalWrite(ledVermelhoPin, HIGH);
    }
    else{
        digitalWrite(ledVermelhoPin, LOW);
    }

    if(luz == CLARO){
        digitalWrite(buzzerPin, HIGH);
    }
    else{
        digitalWrite(buzzerPin, LOW);
    }
}

// Alterna mensagens no display a cada intervalo de tempo
void mostra_mensagem(){
	millisDisplayAgora = millis();
	somaTemperatura = somaTemperatura + temperatura;
	somaUmidade = somaUmidade + umidade;
	contadorMedia++;

	if(millisDisplayAgora - millisDisplayAnterior > tempoMostrarDisplay){
	    LCD.clear();
		LCD.setCursor(0,0); 

      	// Alterna entre os estados do display
		switch(estadoDisplay){
			case (MOSTRA_LUZ):
				if(luz == ESCURO){
					LCD.print("Luz Ambiente");
                  	LCD.setCursor(0,1);
					LCD.print("Ideal");   
				}
				else if(luz == MEIA_LUZ){
					LCD.print("Ambiente");
					LCD.setCursor(0,1);
					LCD.print("penumbra");
				}
				else{
					LCD.print("Ambiente");
					LCD.setCursor(0,1);
					LCD.print("muito claro");
				}
				estadoDisplay = MOSTRA_TEMP;
				break;

			case(MOSTRA_TEMP):
				mediaTemperatura = somaTemperatura / contadorMedia;

				if(temperaturaAmbiente == TEMP_OK){
					LCD.print("Temp. Ideal");
					LCD.setCursor(0,1);
					LCD.print("Temp. = "); LCD.print(mediaTemperatura); LCD.print("C");
				}
				else if(temperaturaAmbiente == FRIO){
					LCD.print("Temp. Baixa");
					LCD.setCursor(0,1);
					LCD.print("Temp. = "); LCD.print(mediaTemperatura); LCD.print("C");
				}
				else{
					LCD.print("Temp. Alta");
					LCD.setCursor(0,1);
					LCD.print("Temp. = "); LCD.print(mediaTemperatura); LCD.print("C");
				}
				estadoDisplay = MOSTRA_UMID;
				break;

			case(MOSTRA_UMID):
				mediaUmidade = somaUmidade / contadorMedia;

				if(umidadeAmbiente == UMID_OK){
					LCD.print("Umidade Ideal");
					LCD.setCursor(0,1);
					LCD.print("Umidade = "); LCD.print(mediaUmidade); LCD.print("%");
				}
				else if(umidadeAmbiente == UMID_BAIXA){
					LCD.print("Umidade Baixa");
					LCD.setCursor(0,1);
					LCD.print("Umidade = "); LCD.print(mediaUmidade); LCD.print("%");
				}
				else{
					LCD.print("Umidade Alta");
					LCD.setCursor(0,1);
					LCD.print("Umidade = "); LCD.print(mediaUmidade); LCD.print("%");
				}
				estadoDisplay = MOSTRA_LUZ;
				break;
		}
		millisDisplayAnterior = millisDisplayAgora;
	}
}
