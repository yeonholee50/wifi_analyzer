#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void get_wifi_info() {
    #ifdef __linux__
        // Linux: Using nmcli to get Wi-Fi information
        printf("Fetching Wi-Fi networks on Linux...\n");
        system("nmcli -t -f active,ssid,signal,frequency dev wifi");

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
