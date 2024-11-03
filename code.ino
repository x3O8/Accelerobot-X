#include <Servo.h>

#define in1 5 // L298n Motor Driver pins.
#define in2 6
#define in3 10
#define in4 11
#define LED 13
#define SERVO_PIN 9 // Define the servo pin
Servo myServo; // Create a Servo object

int command; // Int to store app command state.
int Speed = 204; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; // Set the radius of a turn, 0 - 255
int brakeTime = 45;
int brkonoff = 1; // 1 for the electronic braking system, 0 for normal.
bool frontLightOn = false; // Track the state of the front light

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED, OUTPUT); // Set the LED pin.
  Serial.begin(9600);  // Set the baud rate to your Bluetooth module.
  myServo.attach(SERVO_PIN); // Attach the servo to the defined pin
  myServo.write(0); // Initialize servo arm position (up)
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); // Initialize with motors stopped.
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
      case 'W': // Turn on front light
        digitalWrite(LED, HIGH);
        frontLightOn = true;
        myServo.write(360); // Lower the arm
        break;
      case 'w': // Turn off front light
        digitalWrite(LED, LOW);
        frontLightOn = false;
        myServo.write(120); // Raise the arm
        break;
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

void forward() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speed);
}

void back() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speed);
}

void left() {
  analogWrite(in3, Speed);
  analogWrite(in2, Speed);
}

void right() {
  analogWrite(in4, Speed);
  analogWrite(in1, Speed);
}

void forwardleft() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}

void forwardright() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}

void backright() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}

void backleft() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void brakeOn() {
  buttonState = command;
  if (buttonState != lastButtonState) {
    if (buttonState == 'S') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, HIGH);
      delay(brakeTime);
      Stop();
    }
    lastButtonState = buttonState;
  }
}

void brakeOff() {
}
