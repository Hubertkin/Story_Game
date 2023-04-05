#include "main.h"

int continueGame(FILE *, char *);
int saveProgress(char *);
int stringPrint(char *, FILE *story, char *);
void progressLoad(char *);
int contOrQuit();
void gameReset(char *);
struct gamePlayer
{
    char name[100];
    char playerFile[100];
    char mode[100];
    long int checkpoint;
} player;

int storyGame(char *userName)
{
reset:
    strcpy(player.mode, "new");
    player.checkpoint = 0;
    progressLoad(userName);
    int alt0 = 0;
    int alt1 = 2885;
    int alt2 = 3829;
    int alt3 = 5185;
    int choice;
    int returnValue = 0;
    FILE *story = fopen("story.txt", "r");

    if (!strcmp(player.mode, "md1"))
    {

        fseek(story, player.checkpoint, SEEK_SET);
        goto md1;
    }
    else if (!strcmp(player.mode, "md2"))
    {
        fseek(story, player.checkpoint, SEEK_SET);
        goto md2;
    }
    else if (!strcmp(player.mode, "md3"))
    {
        fseek(story, player.checkpoint, SEEK_SET);
        goto md3;
    }
    else if (!strcmp(player.mode, "md4"))
    {
        fseek(story, player.checkpoint, SEEK_SET);
        goto md4;
    }
    else if (!strcmp(player.mode, "md5"))
    {
        fseek(story, player.checkpoint, SEEK_SET);
        goto md5;
    }
    else if (!strcmp(player.mode, "alt1"))
    {
        printf("M1\n");
        alt0 = player.checkpoint;
        goto alt1;
    }
    else if (!strcmp(player.mode, "alt2"))
    {
        alt1 = player.checkpoint;
        goto alt2;
    }
    else if (!strcmp(player.mode, "alt3"))
    {
        alt2 = player.checkpoint;
        goto alt3;
    }
    else if (!strcmp(player.mode, "alt4"))
    {
        alt3 = player.checkpoint;
        goto alt4;
    }
md1:
    strcpy(player.mode, "md1");
    returnValue = continueGame(story, userName);
    if (returnValue == 1)
        return 1;
bk1:
    printf("\n\tWhat do You Do?\n\n");
    printf("\t  1. - Pursue the Case\n");
    printf("\t  2. - Go Home And prepare for your Travel\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
    md2:
        strcpy(player.mode, "md2");
        returnValue = continueGame(story, userName);
        if (returnValue == 1)
            return 1;
    bk2:
        printf("\n\tWhat do You Do?\n\n");
        printf("\t  1. - Take a train to delay some time\n");
        printf("\t  2. - Take a Cab to get there fast\n");
        scanf(" %[^\n]", &choice);
        switch (choice)
        {
        case 1:
        md3:
            strcpy(player.mode, "md3");
            returnValue = continueGame(story, userName);
            if (returnValue == 1)
                return 1;
        bk3:
            printf("\n\tWhat do You Do?\n\n");
            printf("\t  1. - Do nothing\n");
            printf("\t  2. - Call the police\n");
            scanf(" %[^\n]", &choice);
            switch (choice)
            {
            case 1:
            md4:
                strcpy(player.mode, "md4");
                returnValue = continueGame(story, userName);
                if (returnValue == 1)
                    return 1;
            bk4:
                printf("\n\tWhat do You Do?\n\n");
                printf("\t  1. - Do nothing\n");
                printf("\t  2. - Pull out the gun\n");
                scanf(" %[^\n]", &choice);
                switch (choice)
                {
                case 1:
                md5:
                    strcpy(player.mode, "md5");
                    returnValue = continueGame(story, userName);
                    if (returnValue == 1)
                        return 1;
                    break;
                case 2:
                    strcpy(player.mode, "alt4");
                alt4:
                    fclose(story);
                    FILE *altstory = fopen("altstory.txt", "r");
                    fseek(altstory, alt3, SEEK_SET);
                    returnValue = continueGame(altstory, userName);
                    if (returnValue == 1)
                        return 1;
                    fclose(altstory);
                default:
                    printf("Invalid Input.\tPlease try again\n");
                    goto bk4;
                }
                break;
            case 2:
            alt3:
                strcpy(player.mode, "alt3");
                fclose(story);
                FILE *altstory = fopen("altstory.txt", "r");
                fseek(altstory, alt2, SEEK_SET);
                returnValue = continueGame(altstory, userName);
                if (returnValue == 1)
                    return 1;
                fclose(altstory);
                break;
            default:
                printf("Invalid Input.\tPlease try again\n");
                goto bk3;
            }
            break;
        case 2:
        alt2:
            strcpy(player.mode, "alt2");
            fclose(story);
            FILE *altstory = fopen("altstory.txt", "r");
            fseek(altstory, alt1, SEEK_SET);
            returnValue = continueGame(altstory, userName);
            if (returnValue == 1)
                return 1;
            fclose(altstory);
            break;
        default:
            printf("Invalid Input.\tPlease try again\n");
            goto bk2;
        }
    }
    else if (choice == 2)
    {
    alt1:
        strcpy(player.mode, "alt1");
        fclose(story);
        FILE *altstory = fopen("altstory.txt", "r");
        fseek(altstory, alt0, SEEK_SET);
        returnValue = continueGame(altstory, userName);
        if (returnValue == 1)
            return 1;
        fclose(altstory);
    }
    else
    {
        printf("Invalid Input.\tPlease try again\n");
        goto bk1;
    }
    fclose(story);
    int decision = 0;
    printf("\nYou've reached the end of the Game\nWhat would you like to do Next?\n\n");
    printf("1 - Go to Menu\n\n2 - Restart Game\n\n3 - Quit\n\n");
    scanf("%d", &decision);
    if (decision == 1)
        return 1;
    else if (decision == 2)
    { 
        gameReset(userName);
        goto reset;
    }
    return 0;
}

int stringPrint(char *string, FILE *story, char *userName)
{
    int returnVal = -1;
    char save;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '@')
        {
            return 1;
        }
        else if (string[i] == '$')
        {
            printf("\n\n\t\t\t\t\t\t**Press Enter to Continue**\n");
            scanf("%c", &save);
            if (save == 's')
            {
                saveProgress(userName);
            }else if( save == 'm')
            {
                returnVal = contOrQuit();
            }
            player.checkpoint = ftell(story);
        }
        else
        {
            printf("%c", string[i]);
        }
        Sleep(4);
    }
    if (returnVal == 1)
    {
        return 2;
    }
    return 0;
}
int continueGame(FILE *story, char *userName)
{
    int returnValue;
    char buffer[100];

    while (fgets(buffer, 100, story) != NULL)
    {
        returnValue = stringPrint(buffer, story, userName);
        if (returnValue == 1)
        {
            return 0;
        }
        else if (returnValue == 2)
            return 1;
        else
        {
            continue;
        }
    }
}
void progressLoad(char *userName)
{
    char fileName[100] = "";
    char *buffer;
   
    strcpy(fileName, userName);
    strcat(fileName, ".txt");
    FILE *userProfile = fopen(fileName, "r");
    if (!feof(userProfile) && !ferror(userProfile))
    {
        fscanf(userProfile, "%s", player.name);
        fscanf(userProfile, "%s", player.mode);
        fscanf(userProfile, "%d", &player.checkpoint);
    }
    fclose(userProfile);
}
int saveProgress(char *userName)
{
    char fileName[100] = "";

    strcpy(fileName, userName);
    strcat(fileName, ".txt");
    FILE *userProfile = fopen(fileName, "w");
    if (userProfile == NULL)
    {
        printf("Could not open file for writing.\n");
        return -1;
    }

    int result = fprintf(userProfile, "%s\n%s\n%d\n", player.name, player.mode, player.checkpoint);
    if (result < 0)
    {
        printf("Failed to write data to file.\n");
        fclose(userProfile);
        return -1;
    }else
    {
        printf("\nProgress Saved\n\n");
    }
    fclose(userProfile);
    return 0;
}
int contOrQuit()
{
    int choice = 0;
re:
    printf("Would you like to \n1 - MainMenu \n\n2 - Continue \n\n3 - Quit\n");
    scanf("%d", &choice);
    if (choice == 1)
        return 1;
    else if (choice == 3)
        exit(1);
    else if (choice == 2)
        return 0;
    else
    {
        fflush(stdin);
        printf("Invalid Choice\nRetry\n");
        goto re;
    }
    return 0;
}
void gameReset(char *userName)
{
    char fileName[100] = "";
    strcpy(fileName, userName);
    strcat(fileName, ".txt");
    FILE *userProfile = fopen(fileName, "w");
    if (userProfile == NULL)
    {
        printf("Could not open file for writing.\n");
        return;
    }

    int result = fprintf(userProfile, "%s\n%s\n%d\n", player.name, "new", 0);
    if (result < 0)
    {
        printf("Failed to write data to file.\n");
        fclose(userProfile);
        return;
    }
    fclose(userProfile);
}
