//Line follower robot with Arduino

//Motors speed value must be between 0 and 255.
const int motors_speed = 150;

//Change the values according to which digital pins the IR sensors are connected to.
const int left_ir_sensor = 13;
const int central_ir_sensor = 12;
const int right_ir_sensor = 11;

//Change the values according to which Arduino digital pins, the l298n pins are connected to (Enable_A and Enable_B must be connected to digital PWM pins).
//Motor A connectors
const int Enable_A = 10;
const int Input_1 = 9;
const int Input_2 = 8;
//Motor B connectors
const int Enable_B = 5;
const int Input_3 = 7;
const int Input_4 = 6;

void setup() {
  pinMode(left_ir_sensor, INPUT);
  pinMode(central_ir_sensor, INPUT);
  pinMode(right_ir_sensor, INPUT);

  pinMode(Enable_A, OUTPUT);
  pinMode(Input_1, OUTPUT);
  pinMode(Input_2, OUTPUT);
  pinMode(Enable_B, OUTPUT);
  pinMode(Input_3, OUTPUT);
  pinMode(Input_4, OUTPUT);
}

void loop() {
  int left_ir_sensor_value = digitalRead(left_ir_sensor);
  int central_ir_sensor_value = digitalRead(central_ir_sensor);
  int right_ir_sensor_value = digitalRead(right_ir_sensor);
    
  if(left_ir_sensor_value == HIGH && central_ir_sensor_value == LOW && right_ir_sensor_value == HIGH) {
    Forward();
  }

  else if(left_ir_sensor_value == LOW && central_ir_sensor_value == HIGH && right_ir_sensor_value == HIGH) {
    Left();
  }
  
  else if(left_ir_sensor_value == HIGH && central_ir_sensor_value == HIGH && right_ir_sensor_value == LOW) {
    Right();
  }

  else if(left_ir_sensor_value == LOW && central_ir_sensor_value == LOW && right_ir_sensor_value == HIGH) {
    Left();
  }

  else if(left_ir_sensor_value == HIGH && central_ir_sensor_value == LOW && right_ir_sensor_value == LOW) {
    Right();
  }

  else if(left_ir_sensor_value == LOW && central_ir_sensor_value == LOW && right_ir_sensor_value == LOW) {
    Stop();
  }

  else if(left_ir_sensor_value == HIGH && central_ir_sensor_value == HIGH && right_ir_sensor_value == HIGH) {
    Stop();
  }

}

void Forward() {
  analogWrite(Enable_A, motors_speed);
  analogWrite(Enable_B, motors_speed);
  digitalWrite(Input_1, HIGH);
  digitalWrite(Input_2, LOW);
  digitalWrite(Input_3, HIGH);
  digitalWrite(Input_4, LOW);
  delay(1);
  analogWrite(Enable_A, motors_speed);
  analogWrite(Enable_B, motors_speed);
  digitalWrite(Input_1, LOW);
  digitalWrite(Input_2, LOW);
  digitalWrite(Input_3, LOW);
  digitalWrite(Input_4, LOW);
}

void Left() {
  analogWrite(Enable_A, motors_speed);
  analogWrite(Enable_B, motors_speed);
  digitalWrite(Input_1, LOW);
  digitalWrite(Input_2, HIGH);
  digitalWrite(Input_3, HIGH);
  digitalWrite(Input_4, LOW);
  delay(1);
  analogWrite(Enable_A, motors_speed);
  analogWrite(Enable_B, motors_speed);
  digitalWrite(Input_1, LOW);
  digitalWrite(Input_2, LOW);
  digitalWrite(Input_3, LOW);
  digitalWrite(Input_4, LOW);
}

void Right() {
  analogWrite(Enable_A, motors_speed);
  analogWrite(Enable_B, motors_speed);
  digitalWrite(Input_1, HIGH);
  digitalWrite(Input_2, LOW);
  digitalWrite(Input_3, LOW);
  digitalWrite(Input_4, HIGH);
  delay(1);
  analogWrite(Enable_A, motors_speed);
  analogWrite(Enable_B, motors_speed);
  digitalWrite(Input_1, LOW);
  digitalWrite(Input_2, LOW);
  digitalWrite(Input_3, LOW);
  digitalWrite(Input_4, LOW);
}

void Stop() {
  analogWrite(Enable_A, motors_speed);
  analogWrite(Enable_B, motors_speed);
  digitalWrite(Input_1, LOW);
  digitalWrite(Input_2, LOW);
  digitalWrite(Input_3, LOW);
  digitalWrite(Input_4, LOW);
}
