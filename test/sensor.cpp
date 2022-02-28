const byte pumpPin = 4;
const byte switchPin = 3;
const byte waterSensor = A0;
bool state;
byte value;

void setup()
{
    pinMode(pumpPin, OUTPUT);
    pinMode(switchPin, INPUT);
    pinMode(waterSensor, INPUT);

    Serial.begin(9600);
}

void loop()
{
    state = digitalRead(switchPin);
    value = analogRead(waterSensor);

    Serial.print("value: ");
    Serial.println(value);
    delay(100);
    if (value <= 25)
    {
        digitalWrite(pumpPin, LOW);
    }
    else if (state == true)
    {
        digitalWrite(pumpPin, HIGH);
    }
    else if (state == false)
    {
        digitalWrite(pumpPin, LOW);
    }
}
