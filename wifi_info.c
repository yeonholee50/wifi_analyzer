#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void get_wifi_info() {
    #ifdef __linux__
        // Linux: Using nmcli to get Wi-Fi information
        printf("Fetching Wi-Fi networks on Ubuntu/Linux...\n");
        system("nmcli -t -f active,ssid,signal,frequency dev wifi");

    #elif __APPLE__
        // macOS: Using system_profiler or airport for Wi-Fi information
        printf("Fetching Wi-Fi networks on macOS...\n");
        system("system_profiler SPAirPortDataType");

    #elif __ANDROID__
        // Android: This part requires native Android development (Java/Kotlin)
        // You cannot fetch Wi-Fi info directly in a C program on Android
        printf("Android: Wi-Fi information cannot be fetched using C in this context.\n");
        // To get Wi-Fi information on Android, you would need to use Java/Kotlin with WifiManager API.

    #elif _WIN32
        // Windows: Using netsh to get Wi-Fi information
        printf("Fetching Wi-Fi networks on Windows...\n");
        system("netsh wlan show network mode=Bssid");

    #else
        // Unsupported OS
        printf("Unsupported Operating System.\n");
    #endif
}

int main() {
    get_wifi_info();
    return 0;
}

