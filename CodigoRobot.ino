#include <PID_v1.h>

#define Enc1 34
#define Enc2 35
#define Enb 2
#define Ena 4
#define in3 5
#define in4 18
#define in1 19
#define in2 21



// PIR 
double Setpoint, Input, Output; 
double   Kp=18.8349, Ki=18.8349/4.9763, Kd=18.8349*0.3175;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
const int PPR = 100; //define number of pulses in one round of encoder



float contador1=0;
float contador2=0;
float numVueltas=0;
float contadorTiempo=0;
int contadorBin=1;
float vecVelocidades[20];
int iteraciones=0;
float velPromedio=0;
float velocidadGiro=0;
float velocidadDeseada;
float p;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(Enb,OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(Ena,OUTPUT);
  //turn the PID on
   myPID.SetMode(AUTOMATIC);
   myPID.SetOutputLimits(0,255);


}




void loop() {
  // put your main code here, to run repeatedly:
  velocidadDeseada=130;
  Setpoint=velocidadDeseada;
  Input=velocidadGiro;
  myPID.Compute();
  analogWrite(Ena, Output);
  analogWrite(Enb, Output);

  
  float VoutEncoder1= analogRead(Enc1);
  float VoutEncoder2=analogRead(Enc2);
  //p=(velocidadDeseada-20.43)/0.484;

    if(VoutEncoder1>=1000){

    contador1=contador1+1;

  } 

     if(VoutEncoder2>=1000){

    contador2=contador2+1;

  } 

  numVueltas=contador1;
  //Serial.println(numVueltas);
  velocidadGiro=numVueltas/(contadorTiempo/60000);
  
 
  vecVelocidades[iteraciones]=velocidadGiro;
  iteraciones++;
  Serial.println(velocidadGiro+10);
  if(iteraciones==19){
    float suma=0;
    for(int i=0;i<=19;i++){
      suma=suma+vecVelocidades[i];
    }
    velPromedio=suma/20.0;
    //Serial.println(velPromedio);

    iteraciones=0;
  }

  //Motor derecho  
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  //Motor izquierdo
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  
  /*
  if(contadorBin==2){
    contadorBin=contadorBin-1;
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);

  }
  else if(contadorBin==1){
    contadorBin=contadorBin+1;
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  }

  */

  int Ts=170;
  contadorTiempo=contadorTiempo+Ts;
  


  delay(Ts);


}
