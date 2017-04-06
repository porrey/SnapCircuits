// Copyright © 2015-2017 Daniel Porrey. All Rights Reserved.
//
// This file is part of the Snap Circuits IoT.
// 
// Snap Circuits IoT is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Snap Circuits IoT is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Snap Circuits IoT. If not, 
// see http://www.gnu.org/licenses/.
//
/*
  Snapino IFTTT
  Daniel Porrey
  https://www.hackster.io/snapcircuits
*/
#include <SPI.h>
#include <WiFi101.h>

// *** Your network SSID (name)
// ***
char ssid[] = "yourNetworkSSID";

// ***
// *** Your network password (for WPA)
// ***
char pass[] = "yourNetworkPassword";

// ***
// *** IFTTT Web Service Details
// ***
String _iftttServer = "maker.ifttt.com";
String _iftttKey = "yourIFTTTKey";
String _motionEventName = "motion";
String _noMotionEventName = "nomotion";

// ***
// *** Initialize the Ethernet client library
// *** with the IP address and port of the server
// *** that you want to connect to (port 443 is
// *** default for HTTPS).
// ***
WiFiSSLClient client;

// ***
// *** The pin on which the LED is connected.
// ***
#define LED_PIN 3

// ***
// *** The pin on which the LED is connected.
// ***
#define MOTION_PIN 9

// ***
// *** The last state of the motion detector pin.
// ***
int _previousValue = LOW;

// ***
// *** Controls the minimum amount of time the between motion events.
// ***
uint16_t _minimumTimeInSeconds = 30;
uint32_t _lastEventTime = 0;

void setup()
{
  // ***
  // *** Initialize serial and wait for port to open.
  // ***
  Serial.begin(9600);
  Serial.println(F("Initializing..."));

  // ***
  // *** Start with the LED at the minimum value.
  // ***
  pinMode(LED_PIN, OUTPUT);

  // ***
  // *** Initialize the pin the whistle chip
  // *** is conecte dot and set the mode to
  // *** input with a pullup resistor.
  // ***
  pinMode(MOTION_PIN, INPUT);

  // ***
  // *** This call ensures we have a WiFi shield connected. If
  // *** not the call to IFTTT will not be made but the motion
  // *** sensor will still trigger the LED.
  // ***
  checkForWiFi();

  // ***
  // *** Connect to the WiFi network.
  // ***
  connectWiFi();

  // ***
  // *** Report the end ofinitialization
  // *** to the serial port monitor.
  // ***
  Serial.println(F("Initialization complete."));
}

void loop()
{
  // ***
  // *** Check the WiFi connection.
  // ***
  checkWiFiConnection();

  // ***
  // *** Check for incoming data.
  // ***
  displayHttpsResponse();

  // ***
  // *** Check for motion changes.
  // ***
  checkMotion();

  // ***
  // *** Short delay.
  // ***
  delay(250);
}

void checkMotion()
{
  // ***
  // *** Check if enough time has elapsed to allow another
  // *** event to be triggered.
  // ***
  uint32_t elapsedTime = (millis() - _lastEventTime);

  if (_lastEventTime == 0 || elapsedTime > (1000 * _minimumTimeInSeconds))
  {
    // ***
    // *** Read the motion pin.
    // ***
    int value = digitalRead(MOTION_PIN);

    // ***
    // *** Check it against the previous value to see if
    // *** it changed.
    // ***
    if (_previousValue != value)
    {
      if (value == LOW)
      {
        // ***
        // ***
        // ***
        Serial.println("NO Motion Detected.");
        digitalWrite(LED_PIN, LOW);
        iftttTriggerEvent(_iftttServer, _iftttKey, _noMotionEventName);
      }
      else
      {
        // ***
        // ***
        // ***
        Serial.println("Motion Detected!");
        digitalWrite(LED_PIN, HIGH);
        iftttTriggerEvent(_iftttServer, _iftttKey, _motionEventName);
      }

      // ***
      // *** Record the time of the last event.
      // ***
      _lastEventTime = millis();

      // ***
      // ***
      // ***
      _previousValue = value;
    }
  }
}

void checkForWiFi()
{
  // ***
  // *** Check for the presence of the shield.
  // ***
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println(F("A WiFi shield not present."));
  }
  else
  {
    Serial.println(F("A WiFi shield was found."));
  }
}

void connectWiFi()
{
  int status = WL_IDLE_STATUS;

  if (status != WL_NO_SHIELD)
  {
    // ***
    // *** Attempt to connect to WiFi network.
    // ***
    while (status != WL_CONNECTED)
    {
      Serial.print(F("Attempting to connect to SSID: "));
      Serial.println(ssid);
      status = WiFi.begin(ssid, pass);

      // ***
      // *** Wait 10 seconds for connection.
      // ***
      delay(10000);
    }

    // ***
    // *** If the loop above exits, we are connected.
    // ***
    Serial.println(F("Connected to wifi"));
    printWiFiStatus();
  }
}

// ***
// *** Checks if the WiFi is still connected and
// *** attempts a reconnect if not.
// ***
void checkWiFiConnection()
{
  // ***
  // *** If the client gets disconnected, stop the client
  // *** and try to reconnect.
  // ***
  if (WiFi.status() != WL_NO_SHIELD && WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi disconnected.");

    // ***
    // *** Connect to the WiFi network.
    // ***
    connectWiFi();
  }
}

// ***
// *** Displays the WiFi connection details.
// ***
void printWiFiStatus()
{
  // ***
  // *** Print the SSID of the network you're attached to.
  // ***
  Serial.print(F("SSID: "));
  Serial.println(WiFi.SSID());

  // ***
  // *** Print your WiFi shield's IP address.
  // ***
  IPAddress ip = WiFi.localIP();
  Serial.print(F("IP Address: "));
  Serial.println(ip);

  // ***
  // *** Print the received signal strength.
  // ***
  long rssi = WiFi.RSSI();
  Serial.print(F("Signal strength (RSSI):"));
  Serial.print(rssi);
  Serial.println(F(" dBm"));
}

// ***
// *** Display any data received from IFTTT server.
// ***
void displayHttpsResponse()
{
  if (client.available())
  {
    Serial.println(F("*** Start of HTTPS Response ***"));

    // ***
    // *** If there are incoming bytes available
    // *** from the server, read them and print them.
    // ***
    while (client.available())
    {
      char c = client.read();
      Serial.write(c);
    }

    Serial.println();
    Serial.println(F("*** End of HTTPS Response ***"));
  }
}

// ***
// *** Triggers an event on IFTTT with the given server, key and event name.
// ***
void iftttTriggerEvent(String server, String key, String eventName)
{
  // ***
  // *** Only attempt the call to IFTTT if there is a WiFi sheild
  // *** present and it is connected.
  // ***
  if (WiFi.status() == WL_CONNECTED)
  {
    // ***
    // *** Attempt a connection.
    // ***
    Serial.println(F("Connecting to the IFTTT server..."));

    if (client.connect(server.c_str(), 443))
    {
      Serial.print(F("Using key: '")); Serial.print(key); Serial.println(F("'"));
      String request = "GET /trigger/" + eventName + "/with/key/" + key + " HTTP/1.1";
      Serial.print(F("Request: ")); Serial.println(request);
      client.println(request);
      client.println("Host: " + server);
      client.println("Connection: close");
      client.println();
    }
  }
  else
  {
    Serial.println(F("No WiFi connection; a call to the IFTTT server will not be attempted."));
  }
}

