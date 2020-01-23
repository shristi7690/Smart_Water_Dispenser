//initialize pins for ultrasonic sensor

const int trigPin=7; //throw sound wave

const int echoPin=8; //receive sound



//initinalize pin for motor

int motor=9;

int led=13;



float duration, distance;



void setup() {

  // put your setup code here, to run once:

pinMode(trigPin, OUTPUT);


pinMode(echoPin, INPUT);
pinMode(led, INPUT);

pinMode(motor, OUTPUT);



Serial.begin(9600);

}



void loop() {

  // put your main code here, to run repeatedly:



  //use ultrasonic sensor

  digitalWrite(trigPin,LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH); 



  //Calculate Distance

  distance=(duration*.0343)/2;

  Serial.print("Distance:");

  Serial.println(distance);

  delay(100);

  

  //Control Motor

    if(distance < 20){

      digitalWrite(motor,LOW);
      digitalWrite(led,HIGH);

      }

      else if (distance > 20){ 

        digitalWrite(motor,HIGH);
        digitalWrite(led,LOW);

        }

      else{

        digitalWrite(motor,HIGH);
        digitalWrite(led,LOW);

      }  
 }
