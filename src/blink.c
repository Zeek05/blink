#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// flash.exe
// toggle flashing text


int main(int argc , char *argv[]) {
    // if there is not one argument then exit
    if (argc < 2) {
        printf("Usage: %s <on/off> <opt text>\n", argv[0]);
        return 1;
    }
    // if the first argument is /? or -? then print usage
    if (strcmp(argv[1], "/?") == 0 || strcmp(argv[1], "-?") == 0) {
        printf("Flash.exe - by ZeekHalkyr\n");
        printf("Description: Instant blinking text.\n");
        printf("Usage: %s <on/off> <opt text>\n", argv[0]);
        return 1;
    }

    // enable virtual terminal processing with setconsolemode
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0; 
    GetConsoleMode(hConsole, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, mode);
    // if the first argument is "on" then turn on the blinking
    // if the first argument is "off" then turn off the blinking
    if (strcmp(argv[1], "on") == 0) {
        printf("\x1b[5m");
    } else if (strcmp(argv[1], "off") == 0) {
        printf("\x1b[25m");
    }
    // for each argument after the first one print the argument
    for (int i = 2; i < argc; i++) {
        printf("%s ", argv[i]);
    }
}