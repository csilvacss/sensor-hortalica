#include<stdio.h>

int PinVer = 6;
int PinAzu = 7;
int PinMot = 8;
int PinBuz = 9;

float valorTPM = 0;
float tensao = 0;
float temp = 0;

void setup()
{
    pinMode(PinAzu, OUTPUT);
    pinMode(PinBuz, OUTPUT);
    pinMode(PinVer, OUTPUT);
    pinMode(PinMot, OUTPUT);
    pinMode(A0, INPUT);

    Serial.begin(9600);

    digitalWrite(PinAzu,HIGH);
    digitalWrite(PinBuz,LOW);
    digitalWrite(PinVer,LOW);
    digitalWrite(PinMot,LOW);
}

void loop()
{
    valorTPM = analogRead(A0);
    tensao = valorTPM*(5000/1024);	//Converte a leitura A0 em tensão
    temp = (tensao-500)/10;			// Converte a tensão na temperatura

    Serial.print(" Temperatura: ");
    Serial.print(temp);
    Serial.print(" \xB0"); 	// mostra o símbolo de grau
    Serial.println("C"); 		// mostra a unidade de tempetatura
    
    if(temp <= 30)
    {
        digitalWrite(PinAzu,HIGH);
        digitalWrite(PinBuz,LOW);
        digitalWrite(PinVer,LOW);
        digitalWrite(PinMot,LOW);
    }
    if(temp > 30 and temp <= 50)
    {
        digitalWrite(PinAzu,LOW);
        digitalWrite(PinBuz,LOW);
        digitalWrite(PinVer,LOW);
        digitalWrite(PinMot,HIGH);

    }
    if(temp > 50)
    {
        digitalWrite(PinAzu,LOW);
        digitalWrite(PinBuz,HIGH);
        digitalWrite(PinVer,HIGH);
        digitalWrite(PinMot,HIGH);
    }
    delay(2000);
}