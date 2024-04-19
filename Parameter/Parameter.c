#include "Parameter.h"

int Parameterabfrage(char Parameter[]) {
    int a;
    a = rand();
    a %= 3;
    if(strcmp(Parameter, "--Hilfe") != 0 && strcmp(Parameter, "--Installieren") != 0 && strcmp(Parameter, "--Deinstallieren") != 0 && strcmp(Parameter, "--keineHilfe") != 0) {
        switch(a) {
            case 0:
                Zu_viele_Parameter();
            case 1:
                printf("Wenn du den Parameter nicht richtig schreiben kannst, weiß ich nicht was du von mir willst.\n");
            case 2:
                printf("Du musst zurück in den Deutschunterricht.\n");
            default:
                break;
        }
        return ERROR_WRONG_PARAMETERS;
    }
    switch (a){
        case 0:
            return Hilfe();
            break;
        case 1:
            return keineHilfe();
            break;
        case 2:
            printf("Dein Parameter ist zwar richtig geschrieben, dieser ist mir aber egal.\n");
            return IGNORE_PARAMETER;
            break;
        default:
            break;
    }
    return EXIT_FAILURE;
}

int Kein_Internet() {
    int a;
    a = rand();
    a %= 3;
    switch (a) {
    case 0:
        printf("Du hast kein Internet.\n");
        break;
    case 1:
        printf("Wo bist du, dass du kein Internet hast?\n");
        break;
    case 2:
        printf("Verbind dich mit dem Internet, dann kannst du mehr mit dem Rechner machen.\n");
        break;
    default:
        break;
    }
    return ERROR_NO_INTERNET;
}

int Zu_viele_Parameter() {
    int a;
    a = rand();
    a %= 3;
    switch (a) {
    case 0:
        printf("Was willst du von mir?\n");
        break;
    case 1:
        printf("Ich weiß nicht was du von mir willst.\n");
        break;
    case 2:
        printf("Du musst mir schon sagen was du von mir willst.\n");
        break;
    default:
        break;
    }
    return ERROR_TOO_MANY_PARAMETERS;
}

int keineHilfe() {
    printf("Du kennst dich eh aus.\n");
    return ERROR_NO_HELP;
}

int Hilfe() {
    printf("Es gibt folgende Parameter\n");
    printf("  --keine-Hilfe\n");
    printf("  --Hilfe\n");
    printf("  --Installieren\n");
    printf("  --Deinstalliern\n");
    printf("\n");
    printf("Bei keinen Parametern wird das Standardverhalten ausgeführt\n");
    return ERROR_HELP;
}

int keine_Parameter() {
    int a;
    a = rand();
    a %= 3;
    switch (a) {
        case 0:
            system("curl parrot.live");
            break;
        case 1:
            system("curl ASCII.live/can-you-hear-me");
            break;
        case 2:
            system("curl -H \"Accept-Language:de\" wttr.in/salzburg");
            break;
        default:
            printf("Du hast zu wenige Parameter übergeben\n");
            break;
    }
    return ERROR_NO_PARAMETERS;
}
