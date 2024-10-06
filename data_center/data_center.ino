#define BLYNK_TEMPLATE_ID "TSoWX8IBx-ZUX2BHE-uetYs8CfXgWA5Z"
#define BLYNK_TEMPLATE_NAME "Data Center"
#include <PZEM004Tv30.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#define BLYNK_NO_BUILTIN
#include <BlynkSimpleEsp8266.h>

PZEM004Tv30 pzem1(D1, D2); // D1 TX, D2 RX
#define DHTPIN D4
#define DHTTYPE DHT11
#define LED_BIRU D6
#define LED_MERAH D5
#define BUZZER D3

char ssid[] = "wwk"; 
char pass[] = "99999999"; 
char auth[] = "TSoWX8IBx-ZUX2BHE-uetYs8CfXgWA5Z";

float voltage1, current1, power1, energy1, frequency1;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass, "iot.smk2-yk.sch.id", 8080); // Blynk Server and Port
  pinMode(LED_BIRU, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  voltage1 = pzem1.voltage();
  voltage1 = zeroIfNan(voltage1);
  current1 = pzem1.current();
  current1 = zeroIfNan(current1);
  power1 = pzem1.power();
  power1 = zeroIfNan(power1);
  energy1 = pzem1.energy() / 1000; //kwh
  energy1 = zeroIfNan(energy1);
  frequency1 = pzem1.frequency();
  frequency1 = zeroIfNan(frequency1);
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  delay(1000);

  Blynk.run();
  // Send to Blynk
  Blynk.virtualWrite(V1, voltage1);
  Blynk.virtualWrite(V2, current1);
  Blynk.virtualWrite(V3, power1);
  Blynk.virtualWrite(V4, energy1);
  Blynk.virtualWrite(V5, frequency1);
  Blynk.virtualWrite(V6, humidity);
  Blynk.virtualWrite(V7, temperature);

  Serial.println("");
  Serial.print("Temperature    : "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity       : "); Serial.print(humidity); Serial.println(" %RH");
  Serial.print("Voltage        : "); Serial.print(voltage1); Serial.println(" V");
  Serial.print("Current        : "); Serial.print(current1); Serial.println(" A");
  Serial.print("Power Active   : "); Serial.print(power1); Serial.println(" W");
  Serial.print("Energy         : "); Serial.print(energy1); Serial.println(" kWh");
  Serial.print("Frequency      : "); Serial.print(frequency1); Serial.println(" Hz");
  Serial.println("---------- END ----------");
  Serial.println("");

  if (temperature < 25 && humidity < 60) {
    digitalWrite(LED_BIRU, HIGH);
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(BUZZER, LOW);
  } else {
    digitalWrite(LED_BIRU, LOW);
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(BUZZER, HIGH);

    tone(BUZZER, 1000); // Frekuensi bunyi buzzer
    delay(1000); // Durasi bunyi buzzer (dalam milidetik)
    noTone(BUZZER); // Matikan bunyi buzzer
    delay(1000); // Waktu hening sebelum memulai bunyi lagi
  }
}

float zeroIfNan(float v) {
  if (isnan(v)) {
    v = 0;
  }
  return v;
}
