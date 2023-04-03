#include "main.h"

void continueGame(FILE *);
struct gamePlayer
{
    char *name;
    char *playerFile;
    char *mode;
    long int checkpoint;
    int nameLength;
} player;

int cursor = 0;
int stringPrint(char *, FILE *story);
void progress(char *);

void storyGame(char *userName)
{

    int alt1 = 2885;
    int alt2 = 3829;
    int alt3 = 5185;
    int choice;
    FILE *story = fopen("story.txt", "r");

    continueGame(story);
bk1:
    printf("\n\tWhat do You Do?\n\n");
    printf("\t  1. - Pursue the Case\n");
    printf("\t  2. - Go Home And prepare for your Travel\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        continueGame(story);
    bk2:
        printf("\n\tWhat do You Do?\n\n");
        printf("\t  1. - Take a train to delay some time\n");
        printf("\t  2. - Take a Cab to get there fast\n");
        scanf(" %[^\n]", &choice);
        switch (choice)
        {
        case 1:
            continueGame(story);
        bk3:
            printf("\n\tWhat do You Do?\n\n");
            printf("\t  1. - Do nothing\n");
            printf("\t  2. - Call the police\n");
            scanf(" %[^\n]", &choice);
            switch (choice)
            {
            case 1:
                continueGame(story);
            bk4:
                printf("\n\tWhat do You Do?\n\n");
                printf("\t  1. - Do nothing\n");
                printf("\t  2. - Pull out the gun\n");
                scanf(" %[^\n]", &choice);
                switch (choice)
                {
                case 1:
                    continueGame(story);
                    break;
                case 2:
                    fclose(story);
                    FILE *altstory = fopen("altstory.txt", "r");
                    fseek(altstory, alt3, SEEK_SET);
                    continueGame(altstory);
                    fclose(altstory);
                default:
                    printf("Invalid Input.\tPlease try again\n");
                    goto bk4;
                }
                break;
            case 2:
                fclose(story);
                FILE *altstory = fopen("altstory.txt", "r");
                fseek(altstory, alt2, SEEK_SET);
                continueGame(altstory);
                fclose(altstory);
                break;
            default:
                printf("Invalid Input.\tPlease try again\n");
                goto bk3;
            }
        

        break;
    case 2:
        fclose(story);
        FILE *altstory = fopen("altstory.txt", "r");
        fseek(altstory, alt1, SEEK_SET);
        continueGame(altstory);
        fclose(altstory);
        break;
    default:
        printf("Invalid Input.\tPlease try again\n");
        goto bk2;
    }
    }else if(choice == 2)
    {
        fclose(story);
        FILE *altstory = fopen("altstory.txt", "r");
        continueGame(altstory);
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

int stringPrint(char *string, FILE *story)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '@')
        {
            return 1;
        }
        else if (string[i] == '$')
        {
            printf("\n\n\t\t\t\t\t\t**Press Enter to Continue**");
            scanf("%c");
            player.checkpoint = ftell(story);
        }
        else
        {
            printf("%c", string[i]);
        }
        Sleep(2);
        cursor++;
    }
    return 0;
}
void continueGame(FILE *story)
{
    int returnValue;

    char buffer[100];

    while (fgets(buffer, 100, story) != NULL)
    {
        returnValue = stringPrint(buffer, story);
        if (returnValue == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    }

    // printf("\n&%ld&\n", ftell(story)); pass it to the player struct
}
void progress(char *userName){
    
            char fileName[100] = "";
            char *buffer;
            int i = 0;
            
            
            //char playerInfo[20] ={"nameLength", "name", "mode", "checkpoint"};
            strcpy(fileName, userName);
            
            strcat(fileName, ".txt");
            FILE *userProfile = fopen(fileName, "r");
            while (!feof(userProfile) && !ferror(userProfile))
            {
                fgets(buffer, 50, userProfile); 
                if (i == 0)
                {
                    player.nameLength = atoi(buffer);
                } else if(i == 1)
                {
                    player.name = buffer;

                }else if(i == 1)
                {
                    player.mode = buffer;
                    
                }else if(i == 1)
                {
                    player.checkpoint = atoi(buffer);
                }
                i++;
                }
            
}