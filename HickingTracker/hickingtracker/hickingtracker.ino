#define RT0 10000
#define T0 298.15 //273.15 + 25 = 298.15K
#define B 3950

#define R1 10000


float RT, VR, ln, TX, VRT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  VRT = analogRead(A0);
  VRT = (5. / 1023.) * VRT;
  VR = 5. - VRT;
  RT = VRT / (VR / R1);

  ln = log(RT / RT0);
  TX = (1 / ((ln / B) + (1 / T0)));

  TX = TX - 273.15;

  Serial.print("Temperature:");
  Serial.print("\t");
  Serial.print(TX);
  Serial.print("C\t\t");
  Serial.print(TX + 273.15);        //Conversion to Kelvin
  Serial.print("K\t\t");
  Serial.print((TX * 1.8) + 32);    //Conversion to Fahrenheit
  Serial.println("F");
  delay(1000);
}
