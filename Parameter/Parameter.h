#ifndef __Parameter_H__
#define __Parameter_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../Installieren/Installieren.h"

#define ERROR_NO_INTERNET  -1
#define ERROR_TOO_MANY_PARAMETERS -2
#define ERROR_NO_HELP -3
#define ERROR_HELP -4
#define ERROR_NO_PARAMETERS -5
#define ERROR_PARAMETER_PROMPT_FAILED -6
#define ERROR_WRONG_PARAMETERS -7
#define IGNORE_PARAMETER 2 //1 ist schon für EXIT_FAILURE reserviert

int Parameterabfrage(char Parameter[]);

int Kein_Internet();

int Zu_viele_Parameter();

int Hilfe();

int keineHilfe();

int keine_Parameter();

#endif