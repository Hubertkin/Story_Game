#include "main.h"

struct gamePlayer
{
    char *name;
    char *playerFile;
    int checkpoint;
} player;

void lineNum();
int checkUser(char *);
int stringChecker(int);

int main()
{
    int retn;
    int numRead = 0;
    int playerOpt;
    static int errorNum = 0;
    printf("Hello there\nWelcome to Chapters Story Game\n");
start:
    playerOpt = 0;
    printf("Select an option\n1. New Player\n2. Load Saved Player profile\n");
    numRead = scanf("%d", &playerOpt);
    if (numRead != 1)
    {
        ++errorNum;
        retn = stringChecker(errorNum);
        if (retn == -1)
        {
            return -1;
        }
        goto start;
    }
    else
    {
        if (playerOpt == 1)
        {

            char userName[100] = "";
            char fileName[100] = "";
            char userName1[100] ="";
            printf("Enter a username to create your profile\n");
            scanf(" %[^\n]", userName);
            strcpy(fileName, userName);
            strcpy(userName1, userName);
            strcat(fileName, ".txt");
            FILE *userProfile = fopen(fileName, "a");
            FILE *players = fopen("players.txt", "a");

            // printf("%s", fileName);
            

            if (userProfile != NULL)
            {
                if (checkUser(userName1))
                {
                    printf("The username already exixts\nUse a new username or load the existing profile\n");
                    goto start;
                }
                else
                {
                    printf("Welcome once again %s\nYour profile has been successfully created\n", userName);
                    if (strlen(userName) > 9)
                        fprintf(userProfile, "%d\n", strlen(userName) + 2);
                    else if(strlen(userName) > 99)
                        fprintf(userProfile, "%d\n", strlen(userName) + 3);
                    else
                        fprintf(userProfile, "%d\n", strlen(userName) + 1);
                    fprintf(userProfile, "%s\n", userName);
                    fprintf(players, "%s\n", userName);
                    fclose(players);
                    fclose(userProfile);
                    lineNum();
                    // storyGame(userName);
                    goto start;
                }
            }
            else
            {
                printf("There was an error, please try again\n");
                goto start;
            }
        }
        else if (playerOpt == 2)
        {
            int choice = 0;
            char conCat[50][50];
            char fileName[100] = "";

            FILE *newFile = fopen("players.txt", "r");
            int line = 0;

            while (!feof(newFile) && !ferror(newFile))
            {
                if (fgets(conCat[line], 50, newFile) != NULL)
                {
                    printf("%d ", (line + 1));
                    printf("%s", conCat[line]);
                    line++;
                }
            }
            fclose(newFile);
            int work = 0;
            choice = -1;
            printf("\nOr type \"0\" to go back to the main page\n");
            printf("0 - MENU\n");
            work = scanf("%d", &choice);
            if (choice != 0 && choice != -1)
            {
                // printf("1\n");
                strcpy(fileName, conCat[(choice - 1)]);
                fileName[strlen(fileName) - 1] = '\0';
                strcat(fileName, ".txt");
                FILE *login = fopen(fileName, "r");
                char buffer[20];
                // printf("%s2\n", fileName);
                // printf("%d3\n", ferror(login));
                fseek(login, 0, SEEK_SET);
                fgets(buffer, 20, login);
                printf("%s4\n", buffer);
                // printf("%s5\n", conCat[choice - 1]);
            }
            else if (choice == 0)
            {
                goto start;
            }
        }
        else
        {
            printf("Invalid input, try again\n");
            goto start;
        }
        return 0;
    }
}

void lineNum()
{
    char buffer[50];
    FILE *checker = fopen("checker.txt", "w");
    FILE *orginalFile = fopen("players.txt", "r");
    // FILE *newFile = fopen("playersNewFile.txt", "w");
    int currentLine = 1;

    while (fgets(buffer, 50, orginalFile))
    {
        // fprintf(newFile, "%d %s", currentLine, buffer);
        strcpy(buffer, strlwr(buffer));
        fprintf(checker, "%s", buffer);
        // printf("%s", buffer);
        currentLine++;
    }
    fclose(orginalFile);
    // fclose(newFile);
    fclose(checker);
}
int checkUser(char *userName)
{
    char temp[512];
    int counter = 0;
    //char userN[100];
    // printf("1-%s\n", userName);
    strcpy(userName, strlwr(userName));
    // printf("2-%s\n", userName);
    FILE *checker = fopen("checker.txt", "r");
    while (fgets(temp, 512, checker) != NULL)
    {
        if ((strstr(temp, userName)) != NULL)
        {
            // printf("3-%s\n", userName);
            ++counter;
        }
        else
        {
            // printf("4-%s\n", userName);
            continue;
        }
    }
    if (counter > 0)
        return 1;
    else
        return 0;
}
int stringChecker(int errorNum)
{
    printf("You entered a string instead of an integer\nPlease try again\n");
    fflush(stdin);
    printf("Error number: %d\n", errorNum);
    if (errorNum == 4)
    {
        printf("You typed a string for 4 consecutive time\nPlease contact Our Team for assistance\n");
        return -1;
    }
    return 0;
}

// void typeS(char* string)