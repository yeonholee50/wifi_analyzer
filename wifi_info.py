import subprocess
import platform

def get_wifi_info():
    system_os = platform.system()

    try:
        if system_os == "Linux":
            # Get Wi-Fi info using `nmcli` or `iwconfig`
            result = subprocess.check_output(["nmcli", "-t", "-f", "active,ssid,signal,frequency", "dev", "wifi"], universal_newlines=True)
            print("Available Wi-Fi Networks:\n")
            print(result)

        elif system_os == "Windows":
            # Get Wi-Fi info using `netsh wlan`
            result = subprocess.check_output(["netsh", "wlan", "show", "network", "mode=Bssid"], universal_newlines=True)
            print("Available Wi-Fi Networks:\n")
            print(result)

        else:
            print(f"Unsupported Operating System: {system_os}")

    except subprocess.CalledProcessError as e:
        print("Error while fetching Wi-Fi information.")
        print(e)

if __name__ == "__main__":
    get_wifi_info()
