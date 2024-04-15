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
    return EXIT_SUCCESS;
}