//8 2 2021 
// This Script automaticly installs ESET NOD32 antivirus on Windows 10 systems via powershell commands and a software packaging installer called chocolately
// 1.0 Initial Write
#include "DigiKeyboard.h"

void setup() {
  
}

void loop() {
  DigiKeyboard.sendKeyStroke(0); // wakes keyboard if necessary
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT); // opens menu
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_A); // selects powershell as admin
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT); // yes
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))");
  DigiKeyboard.delay(15000);
  DigiKeyboard.println("exit");
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT); // opens menu
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_A); // selects powershell as admin
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT); // yes
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("choco install eset-nod32-antivirus --upgrade --ignore-checksums --force -a -y; sleep 3"); //installs ESET NOD32 AntiVirus
  DigiKeyboard.delay(50000);
  DigiKeyboard.println("Set-ExecutionPolicy Restricted"); 
  DigiKeyboard.println("exit");
}
