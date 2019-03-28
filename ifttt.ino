const int sensorPin = A0;
const int threshold = 600;
bool isAboveThreshold = false;
int lightLevel;

void setup() {
    pinMode(sensorPin, INPUT);
}

void loop() {
    lightLevel = analogRead(sensorPin);
    if ((lightLevel > threshold && isAboveThreshold == false) ||
        (lightLevel <= threshold && isAboveThreshold == true))
        publishThresholdSwitch();
    delay(10000);
}

void publishThresholdSwitch() {
    Particle.publish("lightConditionChanged", lightLevel > threshold ? "Above" : "Below");
    isAboveThreshold = !isAboveThreshold;
}
