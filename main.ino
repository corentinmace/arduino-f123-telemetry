#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "wifi.h"
#include "f123_telemetry.h"
#include "f123_parser.h"

#define UDP_PORT 20777
WiFiUDP UDP;

constexpr size_t MAX_PACKET_SIZE = 1460;
constexpr size_t HEADER_SIZE = 29;
char packet[MAX_PACKET_SIZE];
int a = 0;    
int b = 12;      
int c = 2;  
int d = 14;  
int e = 4;    
int f = 5;  
int g = 16; 

int ledPin = 15;

byte LED_DISPLAY[] = { 0, 12, 2, 14, 4, 5, 16};
byte LED_STATUS[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 0, 0, 0, 0, 0, 0, 1 } // 9
};


void setup() {
  // Defining pin modes for 7-segments display
  for (int i = 0; i <= 8; i++) {
    pinMode(LED_DISPLAY[i], OUTPUT);
  }

  pinMode(ledPin, OUTPUT);
  // WIFI Connection handling
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // UDP Connection handling
  UDP.begin(UDP_PORT);
  Serial.print("Listening on UDP port ");
  Serial.println(UDP_PORT);
}

void loop() {
 
  int packetSize = UDP.parsePacket();
  if(packetSize) {
    int len = UDP.read(packet, MAX_PACKET_SIZE);
    PacketHeader header = parseHeader((uint8_t*)packet);
    packetSelector(header.m_packetId);
  }
}

void packetSelector(uint8_t packetId) {
  switch (packetId) {
    case PacketType::CAR_TELEMETRY:
      CarTelemetryData p_telemetry = parseCarTelemetry((uint8_t*)(packet+HEADER_SIZE));
      printNumber(p_telemetry.m_gear);
      p_telemetry.m_drs ?  digitalWrite(ledPin, HIGH) : digitalWrite(ledPin, LOW);
      break;
  }
}

void printNumber(int number) {
  int pin;
  if(number < 0) {
    for (int j = 0; j < 7; j++) {
      pin = LED_DISPLAY[j];
      digitalWrite(pin, LED_STATUS[9][j]);
    }
    return;
  }

  for (int j = 0; j < 7; j++) {
    pin = LED_DISPLAY[j];
    digitalWrite(pin, LED_STATUS[number][j]);
  }
}