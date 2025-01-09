#include <Arduino.h>
#include <WiFi.h>
#include <base64.h>

const char* ssid = "hogehoge-3F";          // WiFi SSID
const char* password = "piyopiyopswd";  // WiFi password
const char* casterHost = "111.111.11.11"; // NTRIP caster host name
const int casterPort = 2101;             // NTRIP caster port number
const char* mountpoint = "mountpoint"; // Mountpoint
const char* ntripUser = "username";      // NTIRP username
const char* ntripPassword = "passwd";  // NTRIP password

WiFiClient client;

void setup() {
  Serial.begin(115200);

  // WiFi setup
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

  // connect to NTRIP caster
  if (client.connect(casterHost, casterPort)) {
    Serial.println("Connected to NTRIP Caster");

    // NTRIP request
    String auth = String(ntripUser) + ":" + ntripPassword;
    String encodedAuth = base64::encode(auth);

    String request =
      "GET /" + String(mountpoint) + " HTTP/1.1\r\n" +
      "Host: " + String(casterHost) + ":" + String(casterPort) + "\r\n" +
      "User-Agent: NTRIP Client/ESP32\r\n" +
      "Authorization: Basic " + encodedAuth + "\r\n" +
      "\r\n";

    client.print(request);
    Serial.println("NTRIP request sent!");
  } else {
    Serial.println("Failed to connect to NTRIP Caster");
  }
}

void loop() {
  if (client.connected() && client.available()) {
    // read RTCM data from NTRIP caster
    while (client.available()) {
      uint8_t data = client.read();
      Serial.write(data); // print RTCM data

      /*
      add your code here
      */
    }
  }

}
