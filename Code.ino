/*------------------------------------------------------------------------------------------------------------------------------------ 

                                                                    A smart cane codes 

                                            			Prepared by: Dyanatasya Binti Irwansyah 


------------------------------------------------------------------------------------------------------------------------------------*/ 

  

/*------------------------------------------------------------------------------------------------------------------------------------ 

                                           Define pins for ultrasonic, buzzer and motor      

------------------------------------------------------------------------------------------------------------------------------------*/ 

int const trig = 12;                   //attached pin 12 to trigger pin 

int const echo =11;                    //attached pin 11 to echo pin 

int const buzzer = 4;                  //attached pin 4 to buzzer pin 

int const motor = 6;                   //attached pin 6 to motor pin 

  

/*----------------------------------------------------------------------------------------------------------------------------------  

                                         Setting up the pins to be input or the output 

                                          It is called once the program is starting 

------------------------------------------------------------------------------------------------------------------------------------*/ 

void setup() 

{                                      // open curly braces define beginning of void setup 

pinMode(trig, OUTPUT);                 // trig pin will have pulses output 

pinMode(echo, INPUT);                  // echo pin should be input to get pulse width 

pinMode(buzzer, OUTPUT);               // buzz pin is output to control buzzing 

pinMode(motor, OUTPUT);                // Motor pin is the output 

}                                      // close curly braces define the end of void setup 

  

/*----------------------------------------------------------------------------------------------------------------------- 

								Allowing the program to control the Arduino board 

                                            Loops consecutively 

-------------------------------------------------------------------------------------------------------------------------*/ 

void loop() 

{                                                  // open curly braces define beginning of void loop 

int duration, distance;                           // Duration=input pulse width & distance =distance(cm) to the                                                                             obstacle 

digitalWrite(trig, HIGH);                         // Output pulse  

delay(1);                                         // with 1ms width   

digitalWrite(trig, LOW);                          // on trig pin 

duration = pulseIn(echo, HIGH);                  // Measure the pulse input in echo pin 

distance = (duration/2) / 29.1;                  // Distance is half the duration divided by 29.1 (from datasheet) 
if(distance<=50 && distance>=0)
{
int i=0;
  do{
    i++;
    tone(buzzer,450);
    delay(50);
    noTone(buzzer);
    delay(50);
  }while(i<10);
  
  delay(5000);
  digitalWrite(motor,HIGH);
}
  else
  {
    int i=0;
  do{
    i++;
    tone(buzzer,450);
    delay(400);
    noTone(buzzer);
    delay(400);
  }while(i<5);
  
  delay(5000);
  digitalWrite(motor,HIGH);
  }
}
