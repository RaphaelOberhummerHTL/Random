#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Parameter/Parameter.h"

#define cls() printf("\33c")
#define set_UTF_8() setlocale(LC_ALL, "de_DE.utf-8")

int main(int argc, char *argv[]) {
    cls();
    set_UTF_8();
    srand(time(0));
    #ifdef _WIN32
        if(argc < 2 && system("ping 8.8.8.8 -n 1") == 1) {
            cls();
            return Kein_Internet();
        }
        cls();
    #else
        if(argc < 2 && system("ping 8.8.8.8 -c 1") == 512) {
            return Kein_Internet();
        }
    #endif
    if(argc < 2) {
        return keine_Parameter();
    }
    else if(argc > 2) {
        return Zu_viele_Parameter();
    }
    return Parameterabfrage(argv[1]);
}