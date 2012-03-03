#include <SoftwareSerial.h>

int BOARD_LED = 13;

SoftwareSerial smirfSerial(2, 3);

bool configured = false;

void setup() {
    smirfSerial.begin(9600);
    Serial.begin(9600);

    delay(2000);
}

char readValue[50];

void loop() {
    if (!configured) {
        //enterCommandMode();
        //changeBaudRate();
        // enterMasterMode();
        // discoverWiimotes();
        //connectToWiimote();
        configured = true;
    }
    
    
		if (smirfSerial.available())
				Serial.print((char)smirfSerial.read());
		if (Serial.available())
				smirfSerial.print((char)Serial.read());
    
//    int ii = 0;
//    
//    while(Serial.available()) {
//        readValue[ii++] = (char)Serial.read();
//    }
//    if (ii > 0) {
//        Serial.println(ii);
//        smirfSerial.print(readValue);
//    }
}

void enterCommandMode() {
    smirfSerial.print("$$$");
    readData();
}

void changeBaudRate() {
    smirfSerial.println("SU,9600");
    readData();
}

void enterMasterMode() {
    smirfSerial.println("SM,1");
    readData();
}

void discoverWiimotes() {
    smirfSerial.println("I,10,000508");
    readData();
}

void connectToWiimote() {
    smirfSerial.println("C");
    readData();
}

void readData() {
    while(!smirfSerial.available());
    digitalWrite(BOARD_LED, HIGH);
    delay(200);
    while(smirfSerial.available()) {
        Serial.println(smirfSerial.read());
    }
    digitalWrite(BOARD_LED, LOW);
    delay(200);
}

