// For this example it is needed a PWM enabled LED

int LEDpin = 10;
int option1 = 2;
int option2 = 3;
int option3 = 4;
unsigned short mode = 0;
unsigned char counter = 0;
unsigned char cycles = 0;
unsigned char fadeValue = 0;

void setup()
{
	Serial.begin(9600);
	Serial.println("Hwdy!!");
	Serial.println("initializing Hardware");
	pinMode(option1, INPUT_PULLUP);
	pinMode(option2, INPUT_PULLUP);
	pinMode(option3, INPUT_PULLUP);
	pinMode(LEDpin, OUTPUT);

	digitalWrite(LEDpin, LOW);			//Turn OFF LED

}

void loop()
{
	if (!digitalRead(option1)) {
		mode = 1;
		
		
	}
	else if (!digitalRead(option2)) {
		mode = 2;
	}

	else if (!digitalRead(option3)) {
		mode = 3;
	}

	else {
		mode = 0;
		delay(250);
	}

	Serial.print("mode: ");
	Serial.println(mode);
	Serial.println(!digitalRead(option1));

	switch (mode) {
	case 1 : 
		// blink mode

		digitalWrite(LEDpin, HIGH);
		delay(250);
		digitalWrite(LEDpin, LOW);
		delay(250);
	break;

	case 2:
		// Strobe mode
		cycles = 3;
		counter = 0;
		do {
			digitalWrite(LEDpin, HIGH);
			delay(10);
			digitalWrite(LEDpin, LOW);
			delay(100);
			counter++;
		} while (counter < cycles);
		delay(750);
	break;

	case 3:
		// fade mode
		fadeValue = 0;
		
		for (fadeValue; fadeValue < 255; fadeValue += 5) {
			analogWrite(LEDpin, fadeValue);
			delay(20);
		}

		for (fadeValue; fadeValue > 0; fadeValue -= 5) {
			analogWrite(LEDpin, fadeValue);
			delay(20);
		}

	}
}
