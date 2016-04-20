
//split commands of the string
void extract(int x,  char* str ){

  switch (x) {

  case 0:
    index = atof(str);
    number = "";
    break;
  case 1:
    l_up_down = atof(str);
    number = "";
    break;
  case 2:
    l_right_left = atof(str); 
    number = "";
    break;
  case 3: 
    r_right_left = atof(str);
    number = "";
    break;
  case 4:
    r_up_down = atof(str); 
    number = "";
    break;             
  }
}

void show(void){
  Serial.print("Arduino Received: ");
  Serial.print(inData);
  Serial.print(index);
  Serial.print(" ");
  Serial.print(l_up_down);
  Serial.print(" ");
  Serial.print(l_right_left);
  Serial.print(" ");
  Serial.print(r_right_left);
  Serial.print(" ");
  Serial.println(r_up_down);
}



