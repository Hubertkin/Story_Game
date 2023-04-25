#include "main.h"
//prints the title of the game

void stringPrintf(char *);
void printTitle()
{
stringPrintf("\n\nWELCOME TO \n\n");
    stringPrintf("\t /$$$$$$$$ /$$   /$$ /$$$$$$$$          /$$$$$  /$$$$$$  /$$   /$$ /$$$$$$$  /$$   /$$  /$$$$$$  /$$       /$$$$$$  /$$$$$$  /$$$$$$$$      \n");
    stringPrintf("\t|__  $$__/| $$  | $$| $$_____/         |__  $$ /$$__  $$| $$  | $$| $$__  $$| $$$ | $$ /$$__  $$| $$      |_  $$_/ /$$__  $$|__  $$__/      \n");
    stringPrintf("\t   | $$   | $$  | $$| $$                  | $$| $$  \\ $$| $$  | $$| $$  \\ $$| $$$$| $$| $$  \\ $$| $$        | $$  | $$  \\__/   | $$         \n");
    stringPrintf("\t   | $$   | $$$$$$$$| $$$$$               | $$| $$  | $$| $$  | $$| $$$$$$$/| $$ $$ $$| $$$$$$$$| $$        | $$  |  $$$$$$    | $$         \n");
    stringPrintf("\t   | $$   | $$__  $$| $$__/          /$$  | $$| $$  | $$| $$  | $$| $$__  $$| $$  $$$$| $$__  $$| $$        | $$   \\____  $$   | $$         \n");
    stringPrintf("\t   | $$   | $$  | $$| $$            | $$  | $$| $$  | $$| $$  | $$| $$  \\ $$| $$\\  $$$| $$  | $$| $$        | $$   /$$  \\ $$   | $$         \n");
    stringPrintf("\t   | $$   | $$  | $$| $$$$$$$$      |  $$$$$$/|  $$$$$$/|  $$$$$$/| $$  | $$| $$ \\  $$| $$  | $$| $$$$$$$$ /$$$$$$|  $$$$$$/   | $$         \n");
    stringPrintf("\t   |__/   |__/  |__/|________/       \\______/  \\______/  \\______/ |__/  |__/|__/  \\__/|__/  |__/|________/|______/ \\______/    |__/         \n");
    stringPrintf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAmong Us Story Game\n");
}

//prints the string with a delay of 1 millisecond
void stringPrintf(char *string)
{

    for (int i = 0; i < strlen(string); i++)
    {
        printf("%c", string[i]);
        Sleep(1);
    }
}