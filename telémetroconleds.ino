/ *
   ################
   # Lab15125 #
   ################
 
   Este codigo tiene como objetivo dar muestra de un uso practico de:
   Sensor de ping ultrasónico (paralaje)
   Según la hoja de datos de Parallax para el PING))), 
   hay 73,746 microsegundos por pulgada o 29,034 microsegundos por centimetro 
   (es decir, el sonido viaja a 1130 pies (o 34442.4cm) por segundo). 
   Este da la distancia recorrida por el ping, ida y vuelta, 
   por lo que dividimos por 2 para obtener la distancia del obstáculo.
   ver: 
   https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf
        [En el PDF: TO_IN = 73_746 'Pulgadas; TO_CM = 29_034 'Centímetros]
   El circuito:
     * + V conectado a sensor PING))) en + 5V
     * GND conectado a sensor PING))) en GND (tierra)
     * SIG conectado a sensor PING))) en pin digital 7
     * LED conectado a pin 9 (PWM)
   Funcion
   readUltrasonicDistance (int triggerPin, int echoPin): Referencia obtenida de sensor ultrasónico tinkercad.com
* /


/ *
Inicio declaracion funcion readUltrasonicDistance
* /
long  readUltrasonicDistance ( int triggerPin, int echoPin)
{
  pinMode (triggerPin, OUTPUT);  // Inicializar LOW para limpiar trigger por 2 microsegundos
  digitalWrite (triggerPin, LOW);
  delayMicroseconds ( 2 );
  // Inicializar trigger en HIGH por 8 microsegundos para comenzar
  digitalWrite (triggerPin, HIGH);
  delayMicroseconds ( 8 );
  digitalWrite (triggerPin, LOW);
  pinMode (echoPin, INPUT);
  // lectura de pin echo con el retorno de la señal
  return  pulseIn (echoPin, HIGH);
}
/ *
Fin declaracion funcion readUltrasonicDistance
* /


/ *
Configuración de la función de inicio
* /
 configuración vacía ()
{
  pinMode ( 8 , SALIDA);
  pinMode ( 5 , SALIDA);
  pinMode ( 2 , SALIDA);
}
/ *
Configuración de la función Fin
* /


/ *
Inicio funcion loop
* /
 bucle vacío ()
{
  int distancia = 0.01723 * readUltrasonicDistance ( 2 , 2 );

  if ((distancia <= 333 ) && (distancia> = 200 )) {
    escritura digital ( 8 , ALTA);
  } 
  else {
    digitalWrite ( 8 , BAJO);
  }
  if ((distancia < 200 ) && (distancia> = 100 )) {
    escritura digital ( 7 , ALTA);
  } 
  else {
    digitalWrite ( 7 , BAJO);
  }
  si (distancia < 100 ) {
    escritura digital ( 4 , ALTA);
  } 
  else {
    digitalWrite ( 4 , BAJO);
  }
   

  retraso ( 10 ); // Retrasa un poco para mejorar el rendimiento de la simulación
}
/ *
Inicio funcion loop
* /

/ *
 #######################
 # Fin de programa #
 #######################
* /
