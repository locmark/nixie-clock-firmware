#pragma once
#include <WiFi.h>

static const char* ssid = "Misiowo";
static const char* password = "zuziauciekla";

void WIFI_Init() {
    Serial.println("[wifi] Starting WiFi");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    Serial.print("[wifi] Connecting to network ssid: ");
    Serial.print(ssid);
    Serial.print(" password: ");
    Serial.println(password);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("[wifi] Waiting for connection...");
        delay(1000);
    }

    Serial.print("[wifi] Connected to network with IP: ");
    Serial.println(WiFi.localIP());
}