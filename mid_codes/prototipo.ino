#include <Servo.h>

#define INIT_SPEED 35
#define STOP_SPEED 90
#define STEP 5

//With the back in fornt of you
Servo r_motor,l_motor,vertical_motor; //; motor 1, 2 and 3 in this order

// Buffer to store incoming commands from serial port
String inData;

double l_up_down, l_right_left, r_up_down, r_right_left = 0;
int index,i = 0;
String number; 

void setup() {
  //starts the serial communication (beagle/nano) 
  Serial.begin(57600);
  
  //Pin the motors 
  r_motor.attach(2); 
  l_motor.attach(5); 
  vertical_motor.attach(8); 
  
  //start the motors 
  arm();  
}

void loop() {

  while (Serial.available() > 0)
  {       
    char recieved = Serial.read();
    inData += recieved; 

    //See if the char received is not one of the marks, if it is not pout the char on the current number.  
    if(recieved != ';' and recieved != '\n'){
      number += recieved;
    }     
    else{ //if it is, extract the number;                

      //string to char[], to use the atof function 
      char buf[number.length()];        
      number.toCharArray(buf,number.length()+1);

      //split commands of the string    
      extract(i,buf);    
      i++;

      // Finish the current message, and send the comands for the thrusters
      if (i == 5) {  

        //print  the commands on the screen 
        show();
        
        //Actuating
        sides_command(r_right_left);
        front_back_command(r_up_down);
        vertical_command(l_up_down);

        // Clear recieved buffer
        number = "";
        inData = ""; 
        i = 0;
      }           
    }          
  }               

}





