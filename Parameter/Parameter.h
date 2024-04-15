#ifndef __Parameter_H__
#define __Parameter_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    #define AUTOSTART_KEY "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
    #define AUTOSTART_NAME "MyProgram"
#else
    #include <unistd.h>
    #define AUTOSTART_FILE_PATH "~/.config/autostart/MyProgram.desktop"
#endif

void Zu_viele_Parameter();

void Hilfe();

void keineHilfe();

void keine_Parameter();

void Installieren();

void Deinstallieren();

#endif