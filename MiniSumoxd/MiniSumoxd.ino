const int Trigger = 11;   //Pin digital 2 para el Trigger del sensor
const int Echo = 10;   //Pin digital 3 para el Echo del sensor

const int Piloto = 13; 

int pos;


Servo myservo; 

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0

 pinMode(Piloto, OUTPUT);
 
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);

    pinMode(8, INPUT);
}

void loop()
{

  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(50);  

 if (digitalRead(8)==LOW){
  
   digitalWrite(2, LOW);
   digitalWrite(3,LOW);
   digitalWrite(4, LOW);
   digitalWrite(5,LOW);
  delay(200);
   digitalWrite(2, LOW);
   digitalWrite(3,HIGH);
   digitalWrite(4, LOW);
   digitalWrite(5,HIGH);
  delay(700);
  }


 if(d<5){
 
 if (digitalRead(8)==LOW){
     digitalWrite(2, LOW);
   digitalWrite(3,LOW);
   digitalWrite(4, LOW);
   digitalWrite(5,LOW);
  delay(200);
   digitalWrite(2, LOW);
   digitalWrite(3,HIGH);
   digitalWrite(4, LOW);
   digitalWrite(5,HIGH);
  delay(700);
  }

 
  digitalWrite(Piloto, HIGH);

   digitalWrite(2, HIGH);
   digitalWrite(3,LOW);
   digitalWrite(4, HIGH);
   digitalWrite(5,LOW);
   delay(10);

   
    
  }
  else{
     digitalWrite(Piloto, LOW);

   digitalWrite(2, HIGH);
   digitalWrite(3,LOW);
   digitalWrite(4, LOW);
   digitalWrite(5,HIGH);
   
      }
