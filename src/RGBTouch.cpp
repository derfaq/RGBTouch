/*
  RGBTouch
  Controla el color de un led RGB conectado a los pines 9,10 y 11, acercando o
  alejando la mano a 3 cables conectados a A0, A1 y A2.
  El circuito:
  * 3 cables de 20 cm aprox.
  * 3 resistencias de 220 ohm, para limitar la corriente del led
  * 1 led rgb de 5mm, cátodo común (-)

  Creado el 24 de abril de 2017
  Por derfaq

*/

#include <Arduino.h>
#include <ADCTouch.h>

#define LED_R 9
#define LED_G 10
#define LED_B 11

int refR, refG, refB;

void setup(){

  Serial.begin(9600); //Apertura del puerto serie para debugging

  pinMode(LED_R,OUTPUT); //Configuracion de los pines conectados al led
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);

  refR = ADCTouch.read(A0,500); //Crea el valor de referencia al inicio del programa
  refG = ADCTouch.read(A1,500); //para cada canal, correspondiente a cada color
  refB = ADCTouch.read(A2,500);

}

void loop(){
  int valueR = ADCTouch.read(A0); //Lectura continua de los pines analógicos
  int valueG = ADCTouch.read(A1); //ADCTouch.read() *sin segundo parámetro
  int valueB = ADCTouch.read(A2);

  valueR -= refR; //Remueve el offset, es decir hace la diferencia con el valor al
                  //inicio del programa
  valueG -= refG;
  valueB -= refB;

  Serial.print("R| "); //Envio de los valores
  Serial.print(valueR);
  Serial.print(" G| ");
  Serial.print(valueG);
  Serial.print(" B| ");
  Serial.println(valueB);

  /* En mi Funduino chino viejo y querido, el valor para un trozo de cable
    de par telefónico, aislado, de aproximadamente 10cm, varía aproximadamente
    entre 0 y 200 cuando acerco la mano, y cuando apreto más, alrededor de 270.
    Estos valores resultan muy prácticos para el analogWrite();
    Otra observación, es que se produce interferencia entre los pines. Así,
    a medida que me acerco mas al canal rojo (A0), empiezan a aparecer valores en
    el canal verde (A1) y en menor medida en el canal azul (A2).
  */

  if(valueR<2){valueR = 0;} //Si el valor es menor que 2, considero que no hay cambio
  valueR = constrain(valueR,0,255); //luego restrinjo los valores entre 0..255
  if(valueG<2){valueG = 0;}
  valueG = constrain(valueG,0,255);
  if(valueB<2){valueB = 0;}
  valueB = constrain(valueB,0,255);

  analogWrite(LED_R,valueR); //Enciedo el led rgb con los valores correspondientes
  analogWrite(LED_G,valueG);
  analogWrite(LED_B,valueB);
}
