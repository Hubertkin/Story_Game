#include "main.h"

void genCheckerFile();  // function to generate the checker file
int checkUser(char *);  // function to check if the user profile exists
int stringChecker(int);  // function to check if the user input is a string
int storyGame(char *);   // function to start the game
void printTitle(); // function to print the title of the game

void reset1();  //reset the color of the text to white
void green();   // function to change the color of the text to green
void cyan();    // function to change the color of the text to cyan

int main()
{
    int retn;
    int numRead = 0;  // variable to store return value of scanf
    int playerOpt;   // variable to store the player option
    static int errorNum = 0;  // variable to store the number of errors
    int returnValue = 0;  // variable to store the return value of the storyGame function
    green();
    printTitle();
start:
    playerOpt = 0;
    printf("\t\t\t\t\t\t\t+----------------------------+\n");
    printf("\t\t\t\t\t\t\t|    Select an option        |\n");
    printf("\t\t\t\t\t\t\t|    1 - New Player          |\n");
    printf("\t\t\t\t\t\t\t|    2 - Load Saved Profile  |\n");
    printf("\t\t\t\t\t\t\t|    3 - Quit                |\n");
    printf("\t\t\t\t\t\t\t+----------------------------+\n\n");
    numRead = scanf("%d", &playerOpt);
    if (numRead != 1)
    {
        ++errorNum;
        retn = stringChecker(errorNum); // function to check if the user input is a string
        if (retn == -1)
        {
            return -1;  // return -1 if the user input is a string to print stdin error
        }
        goto start;
    }
    else
    {
        if (playerOpt == 1)
        {

            char userName[100] = ""; //stores the username
            char fileName[100] = ""; //stores the filename
            char userName1[100] = "";  //stores the username to check if the user profile exists
            printf("Enter a username to create your profile\n\n");
            scanf(" %[^\n]", userName);
            strcpy(fileName, userName);
            strcpy(userName1, userName);
            strcat(fileName, ".txt");
            FILE *userProfile = fopen(fileName, "a"); //creates a new file with the username as the filename
            FILE *players = fopen("players.txt", "a");  //opens the players.txt file to store the username

            if (userProfile != NULL)
            {
                if (checkUser(userName1)) //checks if the user profile exists
                {
                    printf("The username already exixts\nUse a new username or load the existing profile\n\n");
                    goto start;
                }
                else
                {
                    printf("Welcome once again %s\n\nYour profile has been successfully created\n\n", userName);
                    fprintf(userProfile, "%s\n", userName);  //writing the username to the file
                    fprintf(players, "%s\n", userName);
                    fclose(players);
                    fclose(userProfile);
                    genCheckerFile(); //generates the checker file
                    printf("\n\t\tInstructions\n\n");
                    printf("\t\t1. You will be given a choice of 2 options to make during gameplay\n");
                    printf("\t\t2. Each option you choose will lead you to a different path of the story\n");
                    printf("\t\t3. To SAVE your progress, type \"s\" when prompted to \"Press Enter to Continue\"\n");
                    printf("\t\t4. To go back to MENU or QUIT the game, type \"m\" when prompted to \"Press Enter to Continue\"\n");
                    sleep(1);
                    printf("\n\n\t\tLoading game");
                    sleep(3);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".");
                    sleep(1);
                    printf(".\n\n");
                    cyan();
                    sleep(1);
                    returnValue = storyGame(userName);    //starts the game 
                    cyan();
                    if (returnValue == 1)  //For the player to return to main menu
                    {
                        goto start;
                    }
                }
            }
            else
            {
                printf("There was an error, please try again\n\n");
                goto start;
            }
        }
        else if (playerOpt == 2)
        {
            int choice = 0;  // variable to store the player choice
            char conCat[50][50];  // array to store the usernames that exists in the players.txt file
            char fileName[100] = "";  // variable to store the filename

            FILE *newFile = fopen("players.txt", "r");
            int line = 0;

            while (!feof(newFile) && !ferror(newFile))  // loop to read the usernames from the players.txt file
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
            printf("\n0 - MENU\n\n");
            work = scanf("%d", &choice);  // reads the player choice to select the username to load the profile
            if (choice != 0 && choice != -1)
            {
                strcpy(fileName, conCat[(choice - 1)]);  //copies the username to the filename variable
                fileName[strlen(fileName) - 1] = '\0';   //removes the newline character from the username
                strcat(fileName, ".txt");
                FILE *login = fopen(fileName, "r");  //opens the file with the username as the filename
                char buffer[20] = "";   
                fseek(login, 0, SEEK_SET);
                fgets(buffer, 20, login); //reads the username from the file
                printf("\nWelcome back, %s\n", buffer);
                buffer[strlen(buffer) - 1] = '\0';
                printf("\n\t\tContinuing game");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".");
                sleep(1);
                printf(".\n\n");
                cyan();
                sleep(1);
                returnValue = storyGame(buffer);  //starts the game
                cyan();
                if (returnValue == 1) //For the player to return to main menu
                {
                    goto start;
                }
            }
            else if (choice == 0)
            {
                goto start;
            }
        }
        else if (playerOpt == 3)
        {
            printf("\t\t\t\t\t\t+------------------------------------------+\n");
            printf("\t\t\t\t\t\t|    Thank You for playing the game        |\n");
            printf("\t\t\t\t\t\t|    SEE YOU SOON........                  |\n");
            printf("\t\t\t\t\t\t+------------------------------------------+\n");
            reset1();
            return 0;
        }
        else
        {
            printf("Invalid input, try again\n\n");
            goto start;
        }
        return 0;
    }
}
//Function to generate the checker file
//copies all the usernames from the players.txt file to the checker.txt file and converts them to lowercase
void genCheckerFile()
{
    char buffer[50];
    FILE *checker = fopen("checker.txt", "w");  //opens the checker.txt file to store the usernames
    FILE *orginalFile = fopen("players.txt", "r");  //opens the players.txt file to read the usernames
    int currentLine = 1;  //print index for the usernames

    while (fgets(buffer, 50, orginalFile))
    {
        strcpy(buffer, strlwr(buffer)); //converts the username to lowercase
        fprintf(checker, "%s", buffer);  //writes the username to the checker.txt file
        currentLine++;
    }
    fclose(orginalFile);
    fclose(checker);
}

int checkUser(char *userName)
{
    char temp[512];  //temporary variable to store the usernames from the checker.txt file
    int counter = 0;    //counter to check if the username exists in the checker.txt file
    strcpy(userName, strlwr(userName));  //converts the username to lowercase
    FILE *checker = fopen("checker.txt", "r");  
    while (fgets(temp, 512, checker) != NULL)
    {
        if ((strstr(temp, userName)) != NULL)
        {
            ++counter;  //increments the counter if the username exists in the checker.txt file
        }
        else
        {
            continue;
        }
    }
    if (counter > 0)  //returns 1 if the username exists in the checker.txt file
        return 1;
    else
        return 0;
}
//Function to check if the user entered a string instead of an integer
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

//reset function to reset the color of the text to white
void reset1()
{
    printf("\033[0;37m");
}

//Function to change the color of the text to cyan
void cyan()
{
    printf("\033[1;36m");
}

//Function to change the color of the text to green
void green()
{
    printf("\033[1;32m");
}
