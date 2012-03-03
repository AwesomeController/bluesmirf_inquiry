int BOARD_LED = 13;

bool configured = false;

void setup() {
    Serial.begin(115200);

    delay(500);
}

void loop() {
    if (!configured) {
        enterCommandMode();
        // enterMasterMode();
        // discoverWiimotes();
        connectToWiimote();
        configured = true;
    }
}

void enterCommandMode() {
    Serial.print("$$$");
    readData();
}

void enterMasterMode() {
    Serial.println("SM,1");
    readData();
}

void discoverWiimotes() {
    Serial.println("I,10,000508");
    readData();
}

void connectToWiimote() {
    Serial.println("C")
    readData();
}

void readData() {
    while(!Serial.available());
    digitalWrite(BOARD_LED, HIGH);
    delay(200);
    while(Serial.available()) {
        Serial.read();
    }
    digitalWrite(BOARD_LED, LOW);
    delay(200);
}

