#define NUM_SENSORS 4

int echoPin1 = 13;
int trigPin1 = 12;

int echoPin2 = 11;
int trigPin2 = 10;

int echoPin3 = 9;
int trigPin3 = 8;

int echoPin4 = 7;
int trigPin4 = 6;

int contador[4] = {0};

#include <Wire.h>

void setup() {
  Wire.begin(2);                
  Wire.onRequest(requestEvent); 

  Serial.begin(9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

}

void loop() {
}


void requestEvent() {
  int i = 0, soma = 0; 
  sensor1();
  sensor2();
  sensor3();
  sensor4();
  for(i; i < 4; i++){
    if(contador[i] == 1) soma += 1;
  }
  Wire.write(soma);
  delay(100);
}

void sensor1() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  long duration = pulseIn(echoPin1, HIGH);
  
  int distance = duration * 0.034/2;

  if (distance < 20) {
    contador[0] = 1;
  } else {
    contador[0] = 0;
  }

  Serial.print("Sensor 1");
  Serial.print(": Objeto detectado. Contagem = ");
  Serial.println(contador[0]);

  delay(1000);
}

void sensor2() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  long duration = pulseIn(echoPin2, HIGH);
  
  int distance = duration * 0.034/2;

  if (distance < 20) {
    contador[1] = 1;
  } else {
    contador[1] = 0;
  }

  Serial.print("Sensor 2");
  Serial.print(": Objeto detectado. Contagem = ");
  Serial.println(contador[1]);

  delay(1000);
}

void sensor3() {
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  long duration = pulseIn(echoPin3, HIGH);
  
  int distance = duration * 0.034/2;

  if (distance < 20) {
    contador[2] = 1;
  } else {
    contador[2] = 0;
  }

  Serial.print("Sensor 3");
  Serial.print(": Objeto detectado. Contagem = ");
  Serial.println(contador[2]);

  delay(1000);
}

void sensor4() {
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);

  long duration = pulseIn(echoPin4, HIGH);
  
  int distance = duration * 0.034/2;

  if (distance < 20) {
    contador[3] = 1;
  } else {
    contador[3] = 0;
  }

  Serial.print("Sensor 4");
  Serial.print(": Objeto detectado. Contagem = ");
  Serial.println(contador[3]);

  delay(1000);
}
