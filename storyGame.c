#include "main.h"

void continueGame(FILE *, char *);
int saveProgress(char *);
int stringPrint(char *, FILE *story, char *);
void progressLoad(char *);
void contOrQuit();
struct gamePlayer
{
    char name[100];
    char playerFile[100];
    char mode[100];
    long int checkpoint;
    int nameLength;
} player;

int cursor = 0;

void storyGame(char *userName)
{
    //char userName[100] = "Gido";
    strcpy(player.mode, "new");
    player.checkpoint = 0;
    progressLoad(userName);
    // printf("%d\n", player.nameLength);
    // printf("%s\n", player.name);
    int alt0 = 0;
    int alt1 = 2885;
    int alt2 = 3829;
    int alt3 = 5185;
    int choice;
    FILE *story = fopen("story.txt", "r");
    //printf("num = %d\n", player.nameLength);
    printf("str1 = %s\n", player.name);
    printf("str2 = %s\n", player.mode);
    printf("num2 = %d\n", player.checkpoint);

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
    continueGame(story, userName);
    printf("num = %d\n", player.nameLength);
    printf("str1 = %s\n", player.name);
    printf("str2 = %s\n", player.mode);
    printf("num2 = %d\n", player.checkpoint);
bk1:
    printf("\n\tWhat do You Do?\n\n");
    printf("\t  1. - Pursue the Case\n");
    printf("\t  2. - Go Home And prepare for your Travel\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
    md2:
        strcpy(player.mode, "md2");
        continueGame(story, userName);
        printf("num = %d\n", player.nameLength);
        printf("str1 = %s\n", player.name);
        printf("str2 = %s\n", player.mode);
        printf("num2 = %d\n", player.checkpoint);
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
            continueGame(story, userName);
            printf("num = %d\n", player.nameLength);
            printf("str1 = %s\n", player.name);
            printf("str2 = %s\n", player.mode);
            printf("num2 = %d\n", player.checkpoint);
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
                continueGame(story, userName);
                printf("num = %d\n", player.nameLength);
                printf("str1 = %s\n", player.name);
                printf("str2 = %s\n", player.mode);
                printf("num2 = %d\n", player.checkpoint);
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
                    continueGame(story, userName);
                    printf("num = %d\n", player.nameLength);
                    printf("str1 = %s\n", player.name);
                    printf("str2 = %s\n", player.mode);
                    printf("num2 = %d\n", player.checkpoint);
                    break;
                case 2:
                    strcpy(player.mode, "alt4");
                alt4:
                    fclose(story);
                    FILE *altstory = fopen("altstory.txt", "r");
                    fseek(altstory, alt3, SEEK_SET);
                    continueGame(altstory, userName);
                    printf("str1 = %s\n", player.name);
                    printf("str2 = %s\n", player.mode);
                    printf("num2 = %d\n", player.checkpoint);
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
                continueGame(altstory, userName);
                printf("str1 = %s\n", player.name);
                printf("str2 = %s\n", player.mode);
                printf("num2 = %d\n", player.checkpoint);
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
            continueGame(altstory, userName);
            printf("str1 = %s\n", player.name);
            printf("str2 = %s\n", player.mode);
            printf("num2 = %d\n", player.checkpoint);
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
        continueGame(altstory, userName);

        printf("str1 = %s\n", player.name);
        printf("str2 = %s\n", player.mode);
        printf("num2 = %d\n", player.checkpoint);
        fclose(altstory);
    }
    else
    {
        printf("Invalid Input.\tPlease try again\n");
        goto bk1;
    }
    fclose(story);

    //return 0;
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
            printf("\n\n\t\t\t\t\t\t**Press Enter to Continue**");
            scanf("%c", &save);
            player.checkpoint = ftell(story);
           // printf("\n%d\n", player.checkpoint);
            
            //printf("\n0%c0\n", save);
            if (save == 's')
            {
                saveProgress(userName);
                contOrQuit();
                //printf("\n0%c0\n", save);
            }
        }else if(string[i] == '#')
        {
            
            printf("\n0add0\n");
        }
        else
        {
            printf("%c", string[i]);
        }
        Sleep(4);
        // cursor++;
    }
    /** if (returnVal == 1)
     {
         return 2;
     }*/
    return 0;
}
void continueGame(FILE *story, char *userName)
{
    int returnValue;

    char buffer[100];

    while (fgets(buffer, 100, story) != NULL)
    {
        returnValue = stringPrint(buffer, story, userName);
        if (returnValue == 1)
        {
            break;
        }
        else
        {
            continue;
        }
        player.checkpoint = ftell(story);
    }

    // printf("\n&%ld&\n", ftell(story)); pass it to the player struct
}
void progressLoad(char *userName)
{

    char fileName[100] = "";
    char *buffer;
    // int i = 0;

    // char playerInfo[20] ={"nameLength", "name", "mode", "checkpoint"};
    strcpy(fileName, userName);
    // printf("%sA\n", userName);
    strcat(fileName, ".txt");
    // printf("%sB\n", fileName);
    FILE *userProfile = fopen(fileName, "r");
    //fseek(userProfile, 0, SEEK_SET);
    if (!feof(userProfile) && !ferror(userProfile))
    {
        printf("%dA\n", ftell(userProfile));
        // fscanf(userProfile, "%d", &player.nameLength);
        fscanf(userProfile, "%s", player.name);
        fscanf(userProfile, "%s", player.mode);
        fscanf(userProfile, "%d", &player.checkpoint);

        // printf("%dd\n", ftell(userProfile));
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
    }
    // printf("%dd\n", ftell(userProfile));

    fclose(userProfile);
    return 0;
}
void contOrQuit()
{
    int choice = 0;
re:
    printf("Would you like to \n1 - continue \nor \n2 - quit\n");
    scanf("%d", &choice);
    if (choice == 1)
        return;
    else if (choice == 2)
        exit(1);
    else
    {
        fflush(stdin);
        printf("Invalid Choice\nRetry\n");
        goto re;
    }
}
