#include "Parameter.h"

void Zu_viele_Parameter() {
    int a;
    srand(time(0));
    a = rand();
    a %= 3;
    if(a == 0) {
        printf("Was willst du von mir?\n");
    }
    else if(a == 1) {
        printf("Ich weiß nicht was du von mir willst.\n");
    }
    else if(a == 2) {
        printf("Du musst mir schon sagen was du von mir willst.\n");
    }
}

void Hilfe() {
    printf("Du kennst dich eh aus.\n");
}

void keineHilfe() {
    printf("Es gibt folgende Parameter\n");
    printf("  --keine-Hilfe\n");
    printf("  --Hilfe\n");
    printf("  --Installieren\n");
    printf("  --Deinstalliern\n");
    printf("\n");
    printf("Bei keinen Parametern wird das Standardverhalten ausgeführt\n");
}

void keine_Parameter() {
    int a;
    srand(time(0));
    a = rand();
    a %= 3;
    if(a == 0) {
        system("curl parrot.live");
    }
    else if (a == 1) {
        system("curl ASCII.live/can-you-hear-me");
    }
    else if(a == 2) {
        system("curl -H \"Accept-Language:de\" wttr.in");
    }
}

void Installieren() {
#ifdef _WIN32
    HKEY hKey;
    LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, AUTOSTART_KEY, 0, KEY_SET_VALUE, &hKey);
    if (result != ERROR_SUCCESS) {
        printf("Fehler beim Öffnen des Registrierungsschlüssels.\n");
        return;
    }

    result = RegDeleteValue(hKey, AUTOSTART_NAME);
    if (result != ERROR_SUCCESS && result != ERROR_FILE_NOT_FOUND) {
        printf("Fehler beim Löschen des Autostart-Eintrags.\n");
        RegCloseKey(hKey);
        return;
    }
    printf("Autostart erfolgreich deaktiviert.\n");

    RegCloseKey(hKey);
#else
    char desktopFilePath[] = AUTOSTART_FILE_PATH;

    if (remove(desktopFilePath) != 0) {
        printf("Fehler beim Löschen der Desktop-Datei.\n");
        return;
    }
    printf("Autostart erfolgreich deaktiviert.\n");
#endif
}

void Deinstallieren() {
#ifdef _WIN32
    char exePath[MAX_PATH];
    DWORD pathLength = GetModuleFileName(NULL, exePath, MAX_PATH);
    if (pathLength == 0) {
        printf("Fehler beim Abrufen des Pfades des ausführbaren Programms.\n");
        return;
    }

    HKEY hKey;
    LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, AUTOSTART_KEY, 0, KEY_SET_VALUE, &hKey);
    if (result != ERROR_SUCCESS) {
        printf("Fehler beim Öffnen des Registrierungsschlüssels.\n");
        return;
    }

    result = RegSetValueEx(hKey, AUTOSTART_NAME, 0, REG_SZ, (BYTE*)exePath, (DWORD)(strlen(exePath) + 1));
    if (result != ERROR_SUCCESS) {
        printf("Fehler beim Festlegen des Autostart-Eintrags.\n");
        RegCloseKey(hKey);
        return;
    }
    printf("Autostart erfolgreich aktiviert.\n");

    RegCloseKey(hKey);
#else
    char desktopFilePath[] = AUTOSTART_FILE_PATH;

    FILE *desktopFile = fopen(desktopFilePath, "w");
    if (desktopFile == NULL) {
        printf("Fehler beim Erstellen der Desktop-Datei.\n");
        return;
    }

    fprintf(desktopFile, "[Desktop Entry]\n");
    fprintf(desktopFile, "Type=Application\n");
    fprintf(desktopFile, "Exec=/pfad/zum/deinem/programm\n");
    fprintf(desktopFile, "Hidden=false\n");
    fprintf(desktopFile, "NoDisplay=false\n");
    fprintf(desktopFile, "X-GNOME-Autostart-enabled=true\n");
    fprintf(desktopFile, "Name=MyProgram\n");

    fclose(desktopFile);
    printf("Autostart erfolgreich aktiviert.\n");
#endif
}