#ifndef __Installieren_H__
#define __Installieren_H__

#include <stdio.h>
#include <stdlib.h>

#define ERROR_EXECUTABLE_PATH_RETRIEVAL_FAILED -8
#define ERROR_AUTOSTART_SET_FAILED -9
#define ERROR_DESKTOP_FILE_CREATION_FAILED -10
#define ERROR_DESKTOP_FILE_DELETE_FAILED -11
#define ERROR_REGISTRY_OPEN_FAILED -12
#define ERROR_AUTOSTART_DELETE_FAILED -13

#ifdef _WIN32
    #include <windows.h>
    #define AUTOSTART_KEY "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
    #define AUTOSTART_NAME "MyProgram"
#else
    #include <unistd.h>
    #define AUTOSTART_FILE_PATH "~/.config/autostart/MyProgram.desktop"
#endif

int Installieren();

int Deinstallieren();

#endif
