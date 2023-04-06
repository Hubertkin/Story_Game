#include "main.h"

int continueGame(FILE *, char *);
int saveProgress(char *);
int stringPrint(char *, FILE *story, char *);
void progressLoad(char *);
int contOrQuit();
void gameReset(char *);

struct gamePlayer // struct to hold players details
{
    char name[100];
    char playerFile[100];
    char mode[100];
    long int checkpoint;
} player;

int storyGame(char *userName) // Functions that controls the game Play
{
reset:
    strcpy(player.mode, "new"); // To set for new players
    player.checkpoint = 0;
    progressLoad(userName); // Load progress from players file that was created for the player.
    int alt0 = 0;           // Cursor Location for the  alternative story in the altstory file
    int alt1 = 2885;
    int alt2 = 3829;
    int alt3 = 5185;
    int choice;                            // Choice for the player
    int returnValue = 0;                   // Return value for the continueGame function
    FILE *story = fopen("story.txt", "r"); // Open the story file

    if (!strcmp(player.mode, "md1")) // If else statement to check players progresss when saved profile is opened
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
// Copy the label md1 to the struct member player.mode
    strcpy(player.mode, "md1"); 
    returnValue = continueGame(story, userName);

    // If the player chooses to quit the game, return 1
    if (returnValue == 1)
        return 1;

// label to return to when the player chooses an invalid option
bk1:

    // Prints the options for the player
    printf("\n\tWhat do You Do?\n\n");
    printf("\t  1. - Pursue the Case\n");
    printf("\t  2. - Go Home And prepare for your Travel\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
    // Copy the label md2 to the struct member player.mode
    md2:
        strcpy(player.mode, "md2");
        returnValue = continueGame(story, userName);
        // If the player chooses to quit the game, return 1
        if (returnValue == 1)
            return 1;
     // label to return to when the player chooses an invalid option
    bk2:
        printf("\n\tWhat do You Do?\n\n");
        printf("\t  1. - Take a train to delay some time\n");
        printf("\t  2. - Take a Cab to get there fast\n");
        scanf(" %[^\n]", &choice);
        switch (choice)
        {
        case 1:

        // Copy the label md3 to the struct member player.mode
        md3:
            strcpy(player.mode, "md3");
            returnValue = continueGame(story, userName);

            // If the player chooses to quit the game, return 1
            if (returnValue == 1)
                return 1;
    // label to return to when the player chooses an invalid option
        bk3:
            printf("\n\tWhat do You Do?\n\n");
            printf("\t  1. - Do nothing\n");
            printf("\t  2. - Call the police\n");
            scanf(" %[^\n]", &choice);
            switch (choice)
            {
            case 1:

            // Copy the label md4 to the struct member player.mode
            md4:
                strcpy(player.mode, "md4");
                returnValue = continueGame(story, userName);

                // If the player chooses to quit the game, return 1
                if (returnValue == 1)
                    return 1;

            // label to return to when the player chooses an invalid option
            bk4:
                printf("\n\tWhat do You Do?\n\n");
                printf("\t  1. - Do nothing\n");
                printf("\t  2. - Pull out the gun\n");
                scanf(" %[^\n]", &choice);
                switch (choice)
                {
                case 1:

                // Copy the label md5 to the struct member player.mode
                md5:
                    strcpy(player.mode, "md5");
                    returnValue = continueGame(story, userName);

                    // If the player chooses to quit the game, return 1
                    if (returnValue == 1)
                        return 1;
                    break;
                case 2:

                  // Copy the label alt4 to the struct member player.mode  
                alt4:
                strcpy(player.mode, "alt4");
                    fclose(story);

                    // Open the altstory file
                    FILE *altstory = fopen("altstory.txt", "r");

                    // Set the cursor location to the part of the alternative story that corresponds to the player's choice and progress
                    fseek(altstory, alt3, SEEK_SET);
                    returnValue = continueGame(altstory, userName);

                    // If the player chooses to quit the game, return 1
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
                FILE *altstory = fopen("altstory.txt", "r");// Open the altstory file

                // Set the cursor location to the part of the alternative story that corresponds to the player's choice and progress
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
            FILE *altstory = fopen("altstory.txt", "r");// Open the altstory file

            // Set the cursor location to the part of the alternative story that corresponds to the player's choice and progress
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
        FILE *altstory = fopen("altstory.txt", "r");// Open the altstory file

        // Set the cursor location to the part of the alternative story that corresponds to the player's choice and progress
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
    // Ask the player what they want to do next
    printf("\nYou've reached the end of the Game\nWhat would you like to do Next?\n\n");
    printf("1 - Go to Menu\n\n2 - Restart Game\n\n3 - Quit\n\n");
    scanf("%d", &decision);
    if (decision == 1)
        return 1;
    else if (decision == 2)
    {
        gameReset(userName);// Reset the game
        goto reset;
    }
    return 0;
}
// Function to print the story character by character
int stringPrint(char *string, FILE *story, char *userName)
{
    int returnVal = -1;
    char save;
    for (int i = 0; i < strlen(string); i++)
    {
        //check for character @ and exit the function for the next statement 
        //to be executed in storyGame()
        if (string[i] == '@')
        {
            return 1;
        }
        //check for character $  to pause the game for a nice gameplay 
        //and save or
        else if (string[i] == '$')
        {
            printf("\n\n\t\t\t\t\t\t**Press Enter to Continue**\n");
            scanf("%c", &save);
            if (save == 's')
            {
                saveProgress(userName);
            }
        //show menu the game  per player's choice
            else if (save == 'm')
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

//Function that gets the string from the story file 
//and passes it to the stringPrint function
int continueGame(FILE *story, char *userName)
{
    int returnValue;
    char buffer[100];

    //buffer to store the string from the story file
    while (fgets(buffer, 100, story) != NULL)
    {
        //check return value from stringPrint func to either
        //Quit the game return value 2 
        //or continue the game
        //or exit function return 1
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

//Function to  load Players progress
//in players profile
void progressLoad(char *userName)
{
    char fileName[100] = "";
    char *buffer;

//Computing the right file name per Player's name
    strcpy(fileName, userName);
    strcat(fileName, ".txt");
    FILE *userProfile = fopen(fileName, "r");//Open  player's file
    if (!feof(userProfile) && !ferror(userProfile))
    {//Reading the file and storing the data in the player struct
        fscanf(userProfile, "%s", player.name);
        fscanf(userProfile, "%s", player.mode);
        fscanf(userProfile, "%d", &player.checkpoint);
    }
    fclose(userProfile);
}

//Function to save the player's progress
int saveProgress(char *userName)
{
    char fileName[100] = "";
//Computing the right file name per Player's name
    strcpy(fileName, userName);
    strcat(fileName, ".txt");
    FILE *userProfile = fopen(fileName, "w");
    if (userProfile == NULL)
    {
        printf("Could not open file for writing.\n");
        return -1;
    }

//Creating the file and storing the data to the file from the player struct
    int result = fprintf(userProfile, "%s\n%s\n%d\n", player.name, player.mode, player.checkpoint);
    if (result < 0)
    {
        printf("Failed to write data to file.\n");
        fclose(userProfile);
        return -1;
    }
    else
    {
        printf("\nProgress Saved\n\n");
    }
    fclose(userProfile);
    return 0;
}

//Function to ask the player if they want to continue, quit or go to the main menu
int contOrQuit()
{
    int choice = 0;
re:
    printf("Would you like to \n1 - MainMenu \n\n2 - Continue \n\n3 - Quit\n");
    scanf("%d", &choice);

    //returns values to stringPrint function
    if (choice == 1)
        return 1;
    else if (choice == 3)
        exit(1);
    else if (choice == 2)
        return 0;
    else
    {
        fflush(stdin);//clears the input buffer
        printf("Invalid Choice\nRetry\n");
        goto re;
    }
    return 0;
}

//Function to reset the game for the player
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
//writing the default values to the file
    int result = fprintf(userProfile, "%s\n%s\n%d\n", player.name, "new", 0);
    if (result < 0)
    {
        printf("Failed to write data to file.\n");
        fclose(userProfile);
        return;
    }
    fclose(userProfile);
}
