#include "Installieren.h"

int Deinstallieren() {
    #ifdef _WIN32
        HKEY hKey;
        LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, AUTOSTART_KEY, 0, KEY_SET_VALUE, &hKey);
        if (result != ERROR_SUCCESS) {
            printf("Fehler beim Öffnen des Registrierungsschlüssels.\n");
            return ERROR_REGISTRY_OPEN_FAILED;
        }

        result = RegDeleteValue(hKey, AUTOSTART_NAME);
        if (result != ERROR_SUCCESS && result != ERROR_FILE_NOT_FOUND) {
            printf("Fehler beim Löschen des Autostart-Eintrags.\n");
            RegCloseKey(hKey);
            return ERROR_AUTOSTART_DELETE_FAILED;
        }
        printf("Autostart erfolgreich deaktiviert.\n");

        RegCloseKey(hKey);
    #else
        char desktopFilePath[] = AUTOSTART_FILE_PATH;

        if (remove(desktopFilePath) != 0) {
            printf("Fehler beim Löschen der Desktop-Datei.\n");
            return ERROR_DESKTOP_FILE_DELETE_FAILED;
        }
        printf("Autostart erfolgreich deaktiviert.\n");
    #endif
    return EXIT_SUCCESS;
}

int Installieren() {
    #ifdef _WIN32
        char exePath[MAX_PATH];
        DWORD pathLength = GetModuleFileName(NULL, exePath, MAX_PATH);
        if (pathLength == 0) {
            printf("Fehler beim Abrufen des Pfades des ausführbaren Programms.\n");
            return ERROR_EXECUTABLE_PATH_RETRIEVAL_FAILED;
        }

        HKEY hKey;
        LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, AUTOSTART_KEY, 0, KEY_SET_VALUE, &hKey);
        if (result != ERROR_SUCCESS) {
            printf("Fehler beim Öffnen des Registrierungsschlüssels.\n");
            return ERROR_REGISTRY_OPEN_FAILED;
        }

        result = RegSetValueEx(hKey, AUTOSTART_NAME, 0, REG_SZ, (BYTE*)exePath, (DWORD)(strlen(exePath) + 1));
        if (result != ERROR_SUCCESS) {
            printf("Fehler beim Festlegen des Autostart-Eintrags.\n");
            RegCloseKey(hKey);
            return ERROR_AUTOSTART_SET_FAILED;
        }
        printf("Autostart erfolgreich aktiviert.\n");

        RegCloseKey(hKey);
    #else
        char desktopFilePath[] = AUTOSTART_FILE_PATH;

        FILE *desktopFile = fopen(desktopFilePath, "w");
        if (desktopFile == NULL) {
            printf("Fehler beim Erstellen der Desktop-Datei.\n");
            return ERROR_DESKTOP_FILE_CREATION_FAILED;
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
    return EXIT_SUCCESS;
}
