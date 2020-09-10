
  /* ################
   #   Lab15125   #
   ################
 
   Este codigo tiene como objetivo dar muestra de un uso practico de:
   Sensor ultrasonico ping (parallax)

   Según la hoja de datos de Parallax para el PING))), 
   hay 73,746 microsegundos por pulgada o 29,034 microsegundos por centimetro 
   (es decir, el sonido viaja a 1130 pies (o 34442.4cm) por segundo). 
   Este da la distancia recorrida por el ping, ida y vuelta, 
   por lo que dividimos por 2 para obtener la distancia del obstáculo.
   ver: 
   https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf
        [En el PDF: TO_IN = 73_746' Inches ; TO_CM = 29_034' Centimeters ]

   El circuito:
     * +V conectado a sensor PING))) en +5V
     * GND conectado a sensor PING))) en GND (ground)
     * SIG conectado a sensor PING))) en pin digital 7
     * LED conectado a pin 9 (PWM)

   Funcion
   readUltrasonicDistance(int triggerPin, int echoPin): Referencia obtenida de sensor ultrasonico tinkercad.com
*/
int inches = 0;// variables en pulgadas
int cm = 0; // variables en cm

/*Inicio declaracion funcion readUltrasonicDistance de tipo long para aumentar precisión*/

long readUltrasonicDistance(int triggerPin, int echoPin)
{
 
  /* se apaga trig por 2 milisegundos */
  pinMode(triggerPin, OUTPUT);  // entrada trig
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  /*se enciende trig por 10 milisegundos*/
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);//se apaga trig
  pinMode(echoPin, INPUT);//salida eco
  // lectura de pin echo con el retorno de la señal
  return pulseIn(echoPin, HIGH);//función retorna valor distancia
}

void setup()
{
  Serial.begin(9600);// comunicación serial
  pinMode(8, OUTPUT);// salida de led verde
  pinMode(7, OUTPUT); //salida led amarillo
  pinMode(4, OUTPUT); //salida led rojo
}

void loop()  
{
   
  float distancia = 0.01723 * readUltrasonicDistance(2, 2);
 
  /*rango operacional del telémetro 3 cm a 336 cm */
  /*correción 1 : ondición que fuera del rango operacional se apagan los 3 leds*/
  if(distancia > 336) 
   
   {
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(4, LOW);    
  } 
 
/*correcion 2: se intercambia los LED mas cerca verde mas lejo rojo*/
 if((distancia < 336) && (distancia >= 200)) {
 
  digitalWrite(4, HIGH);//enciende led rojo
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  } 
  else {
    digitalWrite(4, LOW); 
  }
  if((distancia < 200) && (distancia >= 100)) {
    digitalWrite(7, HIGH);//enciende led amarillo
  } 
  else {
    digitalWrite(7, LOW); 
  }
  if(distancia < 100) {
    digitalWrite(8, HIGH);//enciende led verde 
  } 
  else {
    digitalWrite(8, LOW); 
  }
                                      
  /*muestra en monitor serial */                                    
  Serial.print("distancia: ");
  Serial.println(distancia+1.8);//correción 2 se calibra para ver lo mismo en monitor serial y en simulaión 
 
  delay(10); // Delay a little bit to improve simulation performance
}
