int pinI1=8;
int pinI2=9;
int speedpin=5;
int pinI3=10;
int pinI4=11;
int speedpin1=6;

int motor_delay = 50;

int ultrasonic_1_trigPin = 7;    // TRIG pin
int ultrasonic_1_echoPin = 4;    // ECHO pin
int ultrasonic_2_trigPin = 3;    // TRIG pin
int ultrasonic_2_echoPin = 2;    // ECHO pin

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
long duration_2; // variable for the duration of sound wave travel
int distance_2; // variable for the distance measurement


void motor_ahead(void);
void motor_back(void);
void get_ultrasonic_1(void);
void get_ultrasonic_2(void);

void setup()
{
    // begin serial port
    Serial.begin (9600);

    // configure the trigger pin to output mode
    pinMode(ultrasonic_1_trigPin, OUTPUT);
    // configure the echo pin to input mode
    pinMode(ultrasonic_1_echoPin, INPUT);
    // configure the trigger pin to output mode
    pinMode(ultrasonic_2_trigPin, OUTPUT);
    // configure the echo pin to input mode
    pinMode(ultrasonic_2_echoPin, INPUT);

    pinMode(pinI1,OUTPUT);
    pinMode(pinI2,OUTPUT);
    pinMode(speedpin,OUTPUT);
    pinMode(pinI3,OUTPUT);
    pinMode(pinI4,OUTPUT);
    pinMode(speedpin1,OUTPUT);
}

void loop()
{
    get_ultrasonic_1();
    while(distance > 5)
    {
        motor_ahead();
        get_ultrasonic_1();
        delay(20);
    }
    motor_back();

    delay(20);

    get_ultrasonic_2();
    while(distance_2 > 5)
    {
        motor_back();
        get_ultrasonic_2();
        delay(20);
    }
    motor_ahead();

    delay(20);
}

void motor_ahead()
{
  for (int i = 0; i < 80; i+=3) {
  analogWrite(speedpin, i);
  analogWrite(speedpin1, i);
  delay(1);
 }
    digitalWrite(pinI4,LOW);
    digitalWrite(pinI3,HIGH);
    digitalWrite(pinI1,HIGH);
    digitalWrite(pinI2,LOW);
    delay(motor_delay);
}

void motor_back()
{
 for (int i = 0; i < 80; i+=3) {
  analogWrite(speedpin, i);
  analogWrite(speedpin1, i);
  delay(1);
 }
    digitalWrite(pinI4,HIGH);
    digitalWrite(pinI3,LOW);
    digitalWrite(pinI1,LOW);
    digitalWrite(pinI2,HIGH);
    delay(motor_delay);
}

void get_ultrasonic_1()
{
    // Clears the ultrasonic_2_trigPin condition
    digitalWrite(ultrasonic_1_trigPin, LOW);
    delayMicroseconds(2);
    // Sets the ultrasonic_2_trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(ultrasonic_1_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonic_1_trigPin, LOW);
    // Reads the ultrasonic_2_echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(ultrasonic_1_echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("Distance 1: ");
    Serial.print(distance);
    Serial.println(" cm");
}

void get_ultrasonic_2()
{
    // Clears the ultrasonic_2_trigPin condition
    digitalWrite(ultrasonic_2_trigPin, LOW);
    delayMicroseconds(2);
    // Sets the ultrasonic_2_trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(ultrasonic_2_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonic_2_trigPin, LOW);
    // Reads the ultrasonic_2_echoPin, returns the sound wave travel time in microseconds
    duration_2 = pulseIn(ultrasonic_2_echoPin, HIGH);
    // Calculating the distance
    distance_2 = duration_2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("Distance 2: ");
    Serial.print(distance_2);
    Serial.println(" cm");
}
