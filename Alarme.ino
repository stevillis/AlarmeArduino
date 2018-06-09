//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

// Define o pino para o buzzer
#define pino_buzzer 13
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  pinMode(pino_buzzer, OUTPUT); // Configura pino digital como saída
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{    
  //Le as informacoes do sensor (em cm)
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);  
  
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  
  if (cmMsec < 10) { // Se a distância for menor que 10 cm, dispara o alarme
    Serial.println("Alarme disparado!");
    int cont = 0;
    while(cont < 5) { // Aciona o alarme 5 vezes, com intervalo de meio segundo entre cada bip      
      digitalWrite(pino_buzzer, HIGH); // liga o buzzer
      delay(500);
      digitalWrite(pino_buzzer, LOW); // desliga o buzzer
      delay(500);
      cont++;    
    }  
  }
  delay(200); // Aguarda 200 ms antes de fazer a próxima leitura do sensor ultrassonico.
}
