void setup()
{
 Serial.begin(9600);//Set Baud Rate to 9600 bps
}
void loop()
{
 uint16_t val;
 double dat;
 val=analogRead(A0);//Connect Analog pin to A0
 dat = (double) val * 0.47-33.4;
 Serial.print("Position:"); //Display the position on Serial monitor
 Serial.print(dat);
 Serial.println("Degree");
 delay(100);
}
