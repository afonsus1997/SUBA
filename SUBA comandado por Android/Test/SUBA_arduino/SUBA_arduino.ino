#include <Servo.h> 

const int led = 10;
const int fwd = 9;
const int bwd = 6;
const int soundx;

#define VEL_MAX 80
#define VEL_MIN 0
#define DIR_MAX 45
#define DIR_MIN 105

float m = 0;
float b = 0;

#define BUFFER_DIM 50
static char buffer0[BUFFER_DIM];
int index0 = 0;

Servo myservo;

void setup() {

	Serial.begin(9600);
	//attachInterrupt(0, turn_on_off, RISING);
	pinMode(fwd, OUTPUT);
	pinMode(bwd, OUTPUT);
	pinMode(led, OUTPUT);


  myservo.attach(9);

	//set freq = 122 Hz
	//setPwmFrequency(fwd, 256);
	//setPwmFrequency(bwd, 256);

	m = (DIR_MAX - DIR_MIN) / 200.0;
	b = DIR_MAX - (m * 100);

	p_warning();
  //setServo(0);
  
}

void loop() {

        char ch;
   
	while (Serial.available() > 0) {

		ch = Serial.read();
		if (ch == 0x0D || ch == '\n') {
			buffer0[index0] = '\0';
			change_values(buffer0);
			index0 = 0;
			break;
		}

		if (index0 >= BUFFER_DIM) {
			while (Serial.available() > 0)	//clear buffer0
				Serial.read();
			index0 = 0;
		}

		buffer0[index0++] = ch;
	}

}

void setPwmFrequency(int pin, int divisor) {
	byte mode;
	if (pin == 5 || pin == 6 || pin == 9 || pin == 10) {
		switch (divisor) {
		case 1:
			mode = 0x01;
			break;
		case 8:
			mode = 0x02;
			break;
		case 64:
			mode = 0x03;
			break;
		case 256:
			mode = 0x04;
			break;
		case 1024:
			mode = 0x05;
			break;
		default:
			return;
		}
		if (pin == 5 || pin == 6) {
			TCCR0B = TCCR0B & 0b11111000 | mode;
		} else {
			TCCR1B = TCCR1B & 0b11111000 | mode;
		}
	} else if (pin == 3 || pin == 11) {
		switch (divisor) {
		case 1:
			mode = 0x01;
			break;
		case 8:
			mode = 0x02;
			break;
		case 32:
			mode = 0x03;
			break;
		case 64:
			mode = 0x04;
			break;
		case 128:
			mode = 0x05;
			break;
		case 256:
			mode = 0x06;
			break;
		case 1024:
			mode = 0x7;
			break;
		default:
			return;
		}
		TCCR2B = TCCR2B & 0b11111000 | mode;
	}
}

void p_warning() {
	//analogWrite(sound, 250);
	delay(100);
	//analogWrite(sound, 0);
}

void change_values(char *buffer) {

	int duty;

	duty = (buffer[6] - '0') + (buffer[5] - '0') * 10 + (buffer[4] - '0') * 100;

	if (buffer[3] == '-')
		setPWM(bwd, duty/2);
	else
		setPWM(fwd, duty/2);

	duty = (buffer[10] - '0') + (buffer[9] - '0') * 10
			+ (buffer[8] - '0') * 100;

	if (buffer[7] != '0')
		duty *= -1;
	 setServo(duty);
   

   

}

void setPWM(int motor, int value) {

	if (value <= VEL_MIN) {
		digitalWrite(fwd, LOW);
		digitalWrite(bwd, LOW);
		return;
	}
	if (value > VEL_MAX)
		value = VEL_MAX;

	value = value * 255 / 100;

	switch (motor) {

	case fwd:
		digitalWrite(bwd, LOW);
		analogWrite(fwd, value);
		break;

	case bwd:
		digitalWrite(fwd, LOW);
		analogWrite(bwd, value);
		break;
	}
}

void setServo(int value) {

	value = (int) ((value * m) + b);
  //Serial.println( value);
	myservo.write(value);  
  delay(15);

}
