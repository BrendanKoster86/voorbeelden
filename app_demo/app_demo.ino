#include <SoftwareSerial.h>
#include <string.h>

#include "info.h"

String sendData(String command);
String sendData(String command, const int timeout, boolean debug);

#define serialCommunicationSpeed 115200

SoftwareSerial wifi(20,21);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialCommunicationSpeed);
  wifi.begin(serialCommunicationSpeed);

  // Verbinding maken met mijn wifi
  sendData("AT+RST\r\n");
  delay(1000);
  sendData("AT+CWJAP=\"" + ssid + "\",\"" + pass + "\"\r\n");
  delay(5000);

  // Het te versturen bericht
  String bericht = "Hallo+wereld!";

  // Gegevens website benoemen
  String host = "api.callmebot.com";
  String url = "/signal/send.php?phone=" + tel_nr + "&apikey=" + tel_key + "&text=";
  
  // Verbinding maken met de website
  sendData("AT+CIPSTART=\"TCP\",\"" + host + "\",80\r\n");        
  delay(2000);
  
  // Sub URL definieren
  String commando = "GET " + url + bericht + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  
  // Vertellen hoelang de opdracht gaat zijn
  sendData("AT+CIPSEND=" + String(commando.length()) + "\r\n");
  delay(500);
  
  // Opdracht versturen
  String response = sendData(commando + "\r\n");
  delay(2000);

  // Verbinding met website verbreken
  sendData("AT+CIPCLOSE=5\r\n");
  
  // Tonen wat de response is
  Serial.println(response);

  // Verbinding met wifi verbreken
  sendData("AT+CWQAP\r\n");


  


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
}
