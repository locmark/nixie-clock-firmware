
#include <NTPClient.h>
#include <WiFiUdp.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void NTP_Init() {
    timeClient.begin();
    timeClient.setTimeOffset(3600 * 1);
}

void NTP_Update() {
    timeClient.update();
}

uint32_t NTP_GetTime() {
    return timeClient.getEpochTime();
}

uint8_t NTP_GetHour() {
    return timeClient.getHours();
}

uint8_t NTP_GetMinute() {
    return timeClient.getMinutes();
}

uint8_t NTP_GetSecond() {
    return timeClient.getSeconds();
}

// Set offset time in seconds to adjust for your timezone, for example:
// GMT +1 = 3600
// GMT +8 = 28800
// GMT -1 = -3600
// GMT 0 = 0