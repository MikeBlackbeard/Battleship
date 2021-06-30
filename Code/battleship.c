#include <stdio.h>
#include <time.h>
#include <stdlib.h>



//All the functions that are being used in the game//


//The function for first phase//
void starting();    //shows start menu
void rulebook();    //shows the rules for the game
void playerTwo();   //this function is being used to store the profile for player two
void selectMode();  //this is where player can choose their desired playing mode "single or multi"
void selectDiff();  //this function is being used to determine the level of difficulties in the game
//End of the first phase//



//Beginning of the gameplay phase//
void initalizeBoard(char board[12][12]);
void printBoard(char board[12][12]);
void placeShipRand(char board[12][12], int shipsize);    // place ships randomly
void playerPlaceShip(char board[12][12], int shipsize);    // place ships manually
int checkGameOver(char p1[12][12]);
int shootAIEasey(char attak[12][12], char rival[12][12], int turn);
int shoot(char attak[12][12], char rival[12][12], int turn);
void playerVsAIEasy(char p1[12][12], char p2[12][12], char p1Attac[12][12], char p2Attac[12][12]);
void playerVsPlayer(char p1[12][12], char p2[12][12], char p1Attac[12][12], char p2Attac[12][12]);
void multiplyerMode();
void singlePlayerModeEasy();


                     //Kinda like main function of 2nd phase,since it contains all the function of 2nd phase and being recall in the main function as "Preparation Phase"//
//End of the gameplay Phase//

int main()
{
  //Phase 1//
  starting();               //Shows the first interface or welcome screen//
  selectMode();             //To select the playing mode either Single or Multi//

  //phase 2//


  return 0;
}


void starting()

{
    int start_button;       //to choose weather to start the game or see rules//
    char playerOne[120];    // To store name of player one//


                                    //WELCOME SCREEN//
   puts("*******************************************************************************");
   puts("*                        Welcome to The warzone                               *");
   puts("*                              Ready your                                     *");
   puts("*-----------------------------------------------------------------------------*");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*         XXXXXX XXXXXX XXXXXX XXXXXX XX     XXXXXX XXXXXX  XX  XX XX XXXXXX  *");
   puts("*         XX  XX XX  XX   XX     XX   XX     XX     XX      XX  XX XX XX  XX  *");
   puts("*         XXXXXX XX  XX   XX     XX   XX     XXXXXX XXXXXX  XXXXXX XX XXXXXX  *");
   puts("*         XX  XX XXXXXX   XX     XX   XX     XX         XX  XX  XX XX XX      *");
   puts("*         XXXXXX XX  XX   XX     XX   XXXXXX XXXXXX XXXXXX  XX  XX XX XX      *");
   puts("*                                                                             *");
   puts("*         XXXXXX XXXXXX XXXXXXXXXX XXXXXX XX                                  *");
   puts("*         XX     XX  XX XX  XX  XX XX     XX                                  *");
   puts("*         XX XXX XX  XX XX  XX  XX XXXXXX XX                                  *");
   puts("*         XX  XX XXXXXX XX  XX  XX XX                                         *");
   puts("*         XXXXXX XX  XX XX  XX  XX XXXXXX XX                                  *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*            _______________________________________________                  *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |            'Press '1' to START'               |                 *");
   puts("*           |       'Press '2' to opem the Rule Book'       |                 *");
   puts("*           |                                               |                 *");
   puts("*           |_______________________________________________|                 *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*******************************************************************************");

    scanf("%d",&start_button);  //input from user to make decision for next action//


                 //Making Decision based on Users input//
   if(start_button==1)
   {
       puts(" ");
       puts(" ");
       printf("****************************************************************************\n");
       printf("*             Please Choose a Name for Player one Here:                    *\n");
       printf("****************************************************************************\n");
       scanf("%s",&playerOne);
         puts(" ____________________________________________________________________________");
         puts("|                                                                            |");
       printf("|                           Hallo '%s'                                       |\n",playerOne);
         puts("|                                                                            |");
         puts("|               'Please choose your desired Playing Mode'                    |");
         puts("|                                                                            |");
         puts("|              'Against the Computer OR Against your Mate?'                  |");
         puts("|                                                                            |");
         puts("|____________________________________________________________________________|");
   }
   else if(start_button==2) //if user enter "2" it will open up the rule books//
   {
       rulebook();      //contains the rules for the game//
       puts("");
       puts("");

   }
   else     //shows an error massage and take back to the strating screen if user put anything other than "1" or "2"//
   {
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck! loser press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");

       starting();  //after showing the error massage it takes back to the "starting phase" again so that the user can choose the right Option//

   }

}
//end of "void starting ()//


void rulebook()     //shows the the rules and regulation for the game//
{

    int back_button;    //variable to store the reply input from user after showing him/her rules//


   puts(" __________________________________________________________________________________________________________________________________________________________");
   puts("|                                                                                                                                                          |");
   puts("|                                                           *************************                                                                      |");
   puts("|                                                           *      Rules Book       *                                                                      |");
   puts("|                                                           *************************                                                                      |");
   puts("|        1. This is a two player game. However, you can choose either to play it as a single player or as a multiple player                                |");
   puts("|           If the you choose to play as a single player, you will be playing against the computer itself                                                  |");
   puts("|           But if you choose to play as a multiple player, you will be playing against another player denoted as Player 2.                                |");
   puts("|        2. The battlefield is a 10x10 grid where you place your ships                                                                                     |");
   puts("|           The horizontal boxes are identified with numbers 1-10 and the vertical boxes are marked with letters a – j.                                    |");
   puts("|        3. You will be prompted to select the formation and position of your ships as you desired.                                                        |");
   puts("|        4. You can place your ships by entering its orientation, which are either horizontal or vertical                                                  |");
   puts("|           For horizontal orientation, type 'h' in the orientation option and type 'v' for vertical.                                                      |");
   puts("|        5. There are 4 types of formations and a total of 10 ships to be placed by using  a coordinate system (x y)                                       |");
   puts("|           You need to place  4 ships over 2 boxes, 3 ships over 3 boxes, 2 ships over 4 boxes, 1 ship over 5 boxes.                                      |");
   puts("|        6. And its x y coordinates(both separated by a space) where x is the row number and y is the column number                                        |");
   puts("|        7. After placing your ships, the game begins as each player tries to guess the location of the enemy's ships and attack them                      |");
   puts("|           To attack a specific area, enter its x y coordinate(separated by a space).                                                                     |");
   puts("|        8. If your attack hits the enemy ship, it will be denoted by an 'H'. You also will get an extra turn. Same rules will be applied to your opponent |");
   puts("|        9. If your attack misses, it will be denoted by a '*' and your turn ends.                                                                         |");
   puts("|       10. First player to guess the location of all ships wins.                                                                                          |");
   puts("|                                                                                                                                                          |");
   puts("|__________________________________________________________________________________________________________________________________________________________|");


   puts("\n\nPlease press '1' to continue");
   scanf("%d",&back_button);
   if(back_button==1)
   {
   starting();      //after showing the rules user can go back to the starting phase again//
   }
   else             //if user choose anything rather than 1, this massage will show up and start from the begining//
   {
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck! loser,press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");


       rulebook();      //after getting wrong input it takes back to the starting//
   }


}
//end of the Void rulebook()//


//beginning of the function SelectMode()//
void selectMode()
{
  int x;    //variable to store input from user which will be used to make decision whether to play single or multiplayer//

  // the interface stored in char which will guide the user to make selection//
  char start_button_mode_reply[]=  "\n****************************************************************************\n"
                                   "*                                                                          *\n"
                                   "*                     -------------------------------                      *\n"
                                   "*                    |                               |                     *\n"
                                   "*                    |          Select Mode          |                     *\n"
                                   "*                    |                               |                     *\n"
                                   "*                 ---------------------------------------                  *\n"
                                   "*                | Press '1' to Select Single PlayerMode |                 *\n"
                                   "*                | Press '2' to Select MultiPlayerMode   |                 *\n"
                                   "*                 ---------------------------------------                  *\n"
                                   "*                                                                          *\n"
                                   "*                                                                          *\n"
                                   "****************************************************************************\n";

  printf("%s",start_button_mode_reply);
  scanf("%d", &x);

  switch (x)    //making decision based on users input//

{
  case 1:       //if user choose "1" it will take him to the next stage, to select the difficulty level of the game//
      selectDiff();
  break;

  case 2:       //if user choose "2"(multiplayer) it will ask for player 2 name and continue with the game//
     playerTwo();
  break;


  default:      //if user put anything else other than what is mentioned in the menu, it will show the error massage and take back to the starting of this function//

       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck loser!,press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");

       selectMode();    //takes back to the beginning of the function after showing the error massage//

}

}
//end of the function "selectMode"//


//Beginning of the function "PlayerTwo"//
void playerTwo()    //This function is used to store 2nd player name in multiplayerMode//
{
    char name2 [100];
    puts(" ");
       puts(" ");
       printf("****************************************************************************\n");
       printf("**********      Please Choose a Name for Player two Here:      *************\n");
       printf("****************************************************************************\n");

  scanf("%s", name2);   //taking input from//

                                        // Greeting PlayerTwo with nice interface //
         puts(" ____________________________________________________________________________");
         puts("|                                                                            |");
         puts("|                                                                            |");
       printf("|                           Hallo '%s'                                      |\n",name2);
         puts("|                                                                            |");
         puts("|               'To Defeat or to be defeated is your choice                  |");
         puts("|                                                                            |");
         puts("|____________________________________________________________________________|");
         multiplyerMode();
}
//End of the function "playerTwo"//



//Beginning of the function "selectDiff"//
void selectDiff()   //This function basically determine the Difficulty level of the game//
{
    int y; //variable to store user's input from given option//

    puts("****************************************************************************");
    puts("*                                    *                                     *");
    puts("*    ____________________________    *     ____________________________    *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |            EASY            |   *    |            HARD            |   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |____________________________|   *    |____________________________|   *");
    puts("*   |                            |   *    |                            |   *");
    puts("*   |         Press '1'          |   *    |         Press '2'          |   *");
    puts("*   |____________________________|   *    |____________________________|   *");
    puts("*                                    *                                     *");
    puts("*                                    *                                     *");
    puts("****************************************************************************");


    scanf("%d", &y);

                    //making decision based on user input using switch case//
switch (y)
{
case 1:                     //output of choosing option "1"//
   puts("*******************************************************************************");
   puts("*                                                                             *");
   puts("*            _______________________________________________                  *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |        ('You're gonna play it easy')          |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |_______________________________________________|                 *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*******************************************************************************");
   puts("");
   singlePlayerModeEasy();

break;

case 2:                     //output of choosing option "2"//
   puts("*******************************************************************************");
   puts("*                                                                             *");
   puts("*            _______________________________________________                  *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |         ('You're gonna play it hard')         |                 *");
   puts("*           |                                               |                 *");
   puts("*           |                                               |                 *");
   puts("*           |_______________________________________________|                 *");
   puts("*                                                                             *");
   puts("*                                                                             *");
   puts("*******************************************************************************");

break;


default:                    //shows user a error massage if they tries something other than "1" or "2" and take back to the beginning of the function again//
       puts(" ");
       puts(" ");
       puts(" ");
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   you suck! loser press the right button   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");
       puts(" ");
       puts(" ");
       puts(" ");

selectDiff();

}
}
//End of the function "SelectDiff"//




//begining of the gameplay phase//
void initalizeBoard(char board[12][12])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            board[i][j] = ' ';
        }
    }
    for (int i = 1; i < 12; i++)
    {
        board[0][i] = '0' + i - 1;
        board[i][0] = 'A' + i - 1;
    }
}

void printBoard(char board[12][12])
{
    printf("\n");
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            printf("%c | ",board[i][j]);
        }
        printf("\n-------------------------------------------\n");
    }
}

void placeShipRand(char board[12][12], int shipsize)    // place ships randomly
{
    int checked = 0;
    int x, y;
    int direction;
    int counter;
    do
    {
        x = (rand()%10) + 1;
        y = (rand()%10) + 1;

        direction = rand()%2;
        counter = 0;

        if(direction == 1)
        {
            if((11 - y) > shipsize)
            {
                for(int i = 0; i < shipsize; i++)
                {
                    if(board[y+i][x] != '*' && board[y+i][x+1] != '*' && board[y+i][x-1] != '*'
                    && board[y+i+1][x] != '*' && board[y+i-1][x] != '*')
                    {
                        counter++;
                    }
                }
            if (counter == shipsize)
                checked = 1;
            }
        }

        if(direction == 0)
        {
            if((11 - x) >= shipsize)
            {
                for(int i = 0; i < shipsize; i++)
                {
                    if(board[y][x+i] != '*' && board[y][x+1+i] != '*' && board[y][x-1+i] != '*'
                    && board[y+1][x+i] != '*' && board[y-1][x+i] != '*')
                    {
                        counter++;
                    }
                }
            if (counter == shipsize)
                checked = 1;
            }
        }
    } while (checked == 0);
    if(direction == 0)
    {
        for (int i = 0; i < shipsize; i++)
        {
            board[y][x + i] = '*';
        }
    }
    if(direction == 1)
    {
        for (int i = 0; i < shipsize; i++)
        {
            board[y + i][x] = '*';
        }
    }
}

void playerPlaceShip(char board[12][12], int shipsize)    // place ships manually
{
    int checked = 0;
    int x, y;
    int direction;
    int counter;
    do
    {
        int correct = 0;
        int correctInput = 0;
        char userInput[20];
        do
        {

            puts("****************************************************************************");
            puts("*                                    *                                     *");
            puts("*    ____________________________    *     ____________________________    *");
            puts("*   |                            |   *    |                            |   *");
            puts("*   |                            |   *    |                            |   *");
            puts("*   |         VERTICAL           |   *    |        HORIZONTAL          |   *");
            puts("*   |                            |   *    |                            |   *");
            puts("*   |____________________________|   *    |____________________________|   *");
            puts("*   |                            |   *    |                            |   *");
            puts("*   |         Press '1'          |   *    |         Press '2'          |   *");
            puts("*   |____________________________|   *    |____________________________|   *");
            puts("*                                    *                                     *");
            puts("*                                    *                                     *");
            puts("****************************************************************************");
            scanf("%d", &direction);
            if(direction == 1 || direction == 2)
                correct = 1;
        }while (correct == 0);

        do
        {
            int check = 0;
            char userInput[20];
            //printf("Enter the ship position. ");
            puts("");
            printf("****************************************************************************\n");
            printf("*                                                                          *\n");
            printf("*                   ENTER SHIP POSITION(ex.'a0/A0')                        *\n");
            printf("*                                                                          *\n");
            printf("****************************************************************************\n");
            scanf("%s", userInput);             // E 5
            if(userInput[0] >= 'A' && userInput[0] <= 'J')
            {
                y = userInput[0] - 'A' + 1 ;
                check ++;
            }
            if(userInput[0] >= 'a' && userInput[0] <= 'j')
            {
                y = userInput[0] - 'a' + 1 ;
                check ++;
            }
            if(userInput[1] >= '0' && userInput[1] <= '9')
            {
                x = userInput[1] - '0' + 1;
                check ++;
            }
            if (check == 2)
                correctInput = 1;
        } while (correctInput == 0);
        int check = 0;

        counter = 0;
        //from here check if not overlaping vertical
        if(direction == 1)
        {
            if((11 - y) > shipsize)
            {
                for(int i = 0; i < shipsize; i++)
                {
                    if(board[y+i][x] != '*' && board[y+i][x+1] != '*' && board[y+i][x-1] != '*'
                    && board[y+i+1][x] != '*' && board[y+i-1][x] != '*')
                    {
                        counter++;
                    }
                }
            if (counter == shipsize)
                checked = 1;
            }
        }
        //from here check if not overlaping horizontal
        if(direction == 2)
        {
            if((11 - x) >= shipsize)
            {
                for(int i = 0; i < shipsize; i++)
                {
                    if(board[y][x+i] != '*' && board[y][x+1+i] != '*' && board[y][x-1+i] != '*'
                    && board[y+1][x+i] != '*' && board[y-1][x+i] != '*')
                    {
                        counter++;
                    }
                }
            if (counter == shipsize)
                checked = 1;
            }
        }
    } while (checked == 0);
    if(direction == 2)
    {
        for (int i = 0; i < shipsize; i++)
        {
            board[y][x + i] = '*';
        }
    }
    if(direction == 1)
    {
        for (int i = 0; i < shipsize; i++)
        {
            board[y + i][x] = '*';
        }
    }
}

int checkGameOver(char p1[12][12])
{
    int nur = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(p1[i][j] == 'X')
                nur++;
        }
    }
    if(nur == 30)
        return 1;   // when you hit 30 places is game over
    return 0;   // otherwise you keep playing
}


int shootAIEasey(char attak[12][12], char rival[12][12], int turn)
{
            puts("");
            puts("");
            puts("");
            puts("");
            puts("");
            puts("");
            printf("****************************************************************************\n");
            printf("***************                                              ***************\n");
            printf("***************           NOW ITS COMPUTERS TURN             ***************\n");
            printf("***************                                              ***************\n");
            printf("****************************************************************************\n");
    printf("press 'enter' to continue");
    getchar();
    int shotx, shoty;
    int correctRand = 0;
    do
    {
        shotx = (rand() % 10) + 1;
        shoty = (rand() % 10) + 1;
        if(attak[shoty][shotx] == ' ')
            correctRand = 1;
    } while (correctRand == 0);
    if(rival[shoty][shotx] == '*')
    {

        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!            _____________________            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |                     |           !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |   !!!BULLSEYE!!!    |           !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |  COMPUTER GOTCH YA  |           !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |_____________________|           !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                             !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        attak[shoty][shotx] = 'X';
        printBoard(attak);
        printf("press 'enter' to contine!");
        getchar();  // wait for user input before going to the next move
        return turn;
    }
    else
    {

        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!         ___________________________         !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!        |                           |        !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!        |        !!!!PHEW!!!!       |        !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!        | COMPUTER MISSED BY A INCH |        !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!        |___________________________|        !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                             !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        attak[shoty][shotx] = 'X';
        attak[shoty][shotx] = '~';
        turn = (turn == 1 ? 2 : 1);
    }
    printBoard(attak);
    printf("press 'enter' to contine!");
    getchar();  // wait for user input before going to the next move
    return turn;
}


int shoot(char attak[12][12], char rival[12][12], int turn)
{
    char userInput[20];
    int correctInput = 0;
    int shotx, shoty;
    if(turn == 1)
        printf("Player 1. \n");
    if(turn == 2)
        printf("player 2. \n");
    printBoard(attak);
    do{

            puts("");
            printf("****************************************************************************\n");
            printf("***************             NOW ITS YOUR TURN                ***************\n");
            printf("***************               ENTER POSITION                 ***************\n");
            printf("****************************************************************************\n");
        scanf("%s", userInput);     //without '&' since is an array
        while (getchar() != '\n');    //clean the input buffer
        int check = 0;
        if(userInput[1] >= '0' && userInput[1] <= '9')
        {
            shotx = userInput[1] - '0' + 1;      //substract '0' to convert into int
            check++;
        }
        if(userInput[0] >= 'A' && userInput[0] <= 'J')
        {
            shoty = userInput[0] - 'A' + 1;
            check++;
        }
        if(userInput[0] >= 'a' && userInput[0] <= 'j')
        {
            shoty = userInput[0] - 'a' + 1;
            check++;
        }
        if(attak[shoty][shotx] == 'X' || attak[shoty][shotx] == '~'){
                puts(" ");
       puts(" ");
       puts(" ");
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!   Dum ass, you already hit that position   !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                  Try again                 !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts(" ");

            check = 0;
        }

        // ***************MORE CONDITIONS TO CHECK NOT SHOOTING AT THE SAME POSITION ONCE AGAIN*********************//
        if(check == 2)
            correctInput = 1;
    } while (correctInput == 0);
    if(rival[shoty][shotx] == '*')
    {
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!            ____________________             !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |                    |            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |   !!!BULLSEYE!!!   |            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |     GOTCH YA       |            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |____________________|            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                             !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        attak[shoty][shotx] = 'X';
        return turn;
    }
    else
    {

        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!            ____________________             !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |                    |            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |    !!!!PHEW!!!!    |            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |   MISSED BY A INCH |            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!           |____________________|            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                             !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        attak[shoty][shotx] = 'X';
        attak[shoty][shotx] = '~';
        turn = (turn == 1 ? 2 : 1);
    }
    return turn;
}


void playerVsAIEasy(char p1[12][12], char p2[12][12], char p1Attac[12][12], char p2Attac[12][12])
{
    int gameOver = 0;
    int turn = 1;
    do{
        switch (turn)
        {
        case 1:
        turn = shoot(p1Attac, p2, turn);
        gameOver = checkGameOver(p1Attac);
            break;
        case 2:
        turn = shootAIEasey(p2Attac, p1, turn);
        gameOver = checkGameOver(p2Attac);
        default:
            break;
        }
        gameOver = checkGameOver(p1Attac);
    }while (gameOver == 0);
    if(turn == 1)
        printf("\nPlayer 1 wins");
    else
        printf("\nplayer 2 wins");
}


void playerVsPlayer(char p1[12][12], char p2[12][12], char p1Attac[12][12], char p2Attac[12][12])
{
    int gameOver = 0;
    int turn = 1;
    do{
        switch (turn)
        {
        case 1:
        turn = shoot(p1Attac, p2, turn);
        gameOver = checkGameOver(p1Attac);
            break;
        case 2:
        turn = shoot(p2Attac, p1, turn);
        gameOver = checkGameOver(p2Attac);
        default:
            break;
        }
        gameOver = checkGameOver(p1Attac);
    }while (gameOver == 0);
    if(turn == 1)
        printf("\nPlayer 1 wins");
    else
        printf("\nplayer 2 wins");
}
void multiplyerMode()
{
    int userInput;
    srand(time(NULL));
    char boardP1[12][12], boardP2[12][12], boardP1Attac[12][12], boardP2Attac[12][12];
    int shipsizes[10] = {5,4,4,3,3,3,2,2,2,2};
    initalizeBoard(boardP1);    //battle ground for player one//
    initalizeBoard(boardP2);
    initalizeBoard(boardP1Attac);
    initalizeBoard(boardP2Attac);
            puts(" ");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
            puts("!!!!!!!!!!!!!!!            LET THE GAME BEGIN              !!!!!!!!!!!!!!!!!");
            puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts(" ");

            puts("****************************************************************************");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*            __________________________________________________            *");
            puts("*           |                                                  |           *");
            puts("*           |                                                  |           *");
            puts("*           |                                                  |           *");
            puts("*           |                  SHIP PLACEMENT                  |           *");
            puts("*           |                                                  |           *");
            puts("*           |                                                  |           *");
            puts("*           |__________________________________________________|           *");
            puts("*                                                                          *");
            puts("*    ____________________________          ____________________________    *");
            puts("*   |                            |        |                            |   *");
            puts("*   |                            |        |                            |   *");
            puts("*   |           MANUAL           |        |         AUTOMATIC          |   *");
            puts("*   |                            |        |                            |   *");
            puts("*   |____________________________|        |____________________________|   *");
            puts("*   |                            |        |                            |   *");
            puts("*   |         Press '1'          |        |         Press '2'          |   *");
            puts("*   |____________________________|        |____________________________|   *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("****************************************************************************");


    scanf("%d",&userInput);

    if(userInput==2)
    {
    for(int i = 0; i< 10; i++)
    {
        //puts("battleground for player 1");
        puts(" ");
        printf("****************************************************************************\n");
        printf("**********          THIS IS YOUR BATTLEGROUND PLAYER 1         *************\n");
        printf("****************************************************************************\n");
        placeShipRand(boardP1, shipsizes[i]);
        printBoard(boardP1);
        puts("");
    }

    puts("");
    puts("");
    puts("");
    for(int i = 0; i< 10; i++)
    {

        puts(" ");
        printf("****************************************************************************\n");
        printf("**********          THIS IS YOUR BATTLEGROUND PLAYER 2         *************\n");
        printf("****************************************************************************\n");
        placeShipRand(boardP2, shipsizes[i]);
        printBoard(boardP2);
    }
    }
    else
    {
        puts("");
       puts("");
       printf("****************************************************************************\n");
       printf("*                            SHIP PLACEMENT                                *\n");
       printf("*__________________________________________________________________________*\n");
       printf("*                                                                          *\n");
       printf("*                                                                          *\n");
       printf("*       PLEASE REMEMBER TO FOLLOW THE ORDER DURING PLACING THE SHIP        *\n");
       printf("*                                                                          *\n");
       printf("*                --------------------------------------                    *\n");
       printf("*               |  >   1st: 1 SHIP  OVER 5 BOXES    <  |                   *\n");
       printf("*               |  > 2nd: ONLY 4 SHIPS OVER 2 BOXES <  |                   *\n");
       printf("*               |  > 3rd: ONLY 3 SHIPS OVER 3 BOXES <  |                   *\n");
       printf("*               |  > 4th: ONLY 2 SHIPS OVER 4 BOXES <  |                   *\n");
       printf("*               |  > 5th: ONLY 1 SHIP  OVER 5 BOXES <  |                   *\n");
       printf("*                --------------------------------------                    *\n");
       printf("*                                                                          *\n");
       printf("****************************************************************************\n");
       puts("");
       puts("");

        for(int i=0; i<10; i++)
        {
        printBoard(boardP1);
        playerPlaceShip(boardP1, shipsizes[i]);
        }
        printBoard(boardP1);
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts(" ");
        printf("****************************************************************************\n");
        printf("**********             NOW ITS YOUR TURN PLAYER 2              *************\n");
        printf("****************************************************************************\n");
        for(int i=0; i<10; i++)
        {
        playerPlaceShip(boardP2, shipsizes[i]);
        printBoard(boardP2);
        }
    }

    puts(" ");
       puts(" ");
       puts(" ");
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!      ! READY !    ! AIM !   ! FIRE !       !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    playerVsPlayer(boardP1,boardP2, boardP1Attac, boardP2Attac);
}

//player vs AI easy
void singlePlayerModeEasy()
{
    int userInput;
    srand(time(NULL));
    char boardP1[12][12], boardP2[12][12], boardP1Attac[12][12], boardP2Attac[12][12];
    int shipsizes[10] = {5,4,4,3,3,3,2,2,2,2};
    initalizeBoard(boardP1);    //battle ground for player one//
    initalizeBoard(boardP2);
    initalizeBoard(boardP1Attac);
    initalizeBoard(boardP2Attac);



            puts("****************************************************************************");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*            __________________________________________________            *");
            puts("*           |                                                  |           *");
            puts("*           |                                                  |           *");
            puts("*           |                                                  |           *");
            puts("*           |      SO, HOW DO YOU WANT TO PLACE YOUR SHIP?     |           *");
            puts("*           |                                                  |           *");
            puts("*           |                                                  |           *");
            puts("*           |__________________________________________________|           *");
            puts("*                                                                          *");
            puts("*    ____________________________          ____________________________    *");
            puts("*   |                            |        |                            |   *");
            puts("*   |                            |        |                            |   *");
            puts("*   |           MANUAL           |        |         AUTOMATIC          |   *");
            puts("*   |                            |        |                            |   *");
            puts("*   |____________________________|        |____________________________|   *");
            puts("*   |                            |        |                            |   *");
            puts("*   |         Press '1'          |        |         Press '2'          |   *");
            puts("*   |____________________________|        |____________________________|   *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("*                                                                          *");
            puts("****************************************************************************");



    scanf("%d",&userInput);

    if(userInput==2)
    {
    for(int i = 0; i< 10; i++)
    {
        //puts("battleground for player 1");
        puts(" ");
        printf("****************************************************************************\n");
        printf("**********          THIS IS YOUR BATTLEGROUND PLAYER 1         *************\n");
        printf("****************************************************************************\n");
        placeShipRand(boardP1, shipsizes[i]);
        printBoard(boardP1);
        puts("");
    }

    puts("");
    puts("");
    puts("");
    for(int i = 0; i< 10; i++)
    {
        //puts("battle ground for player 2");
        puts(" ");
        printf("****************************************************************************\n");
        printf("**********          THIS IS YOUR BATTLEGROUND PLAYER 2         *************\n");
        printf("****************************************************************************\n");
        placeShipRand(boardP2, shipsizes[i]);
        printBoard(boardP2);
    }
    }
    else
    {
       puts("");
       puts("");
       printf("****************************************************************************\n");
       printf("*                            SHIP PLACEMENT                                *\n");
       printf("*__________________________________________________________________________*\n");
       printf("*                                                                          *\n");
       printf("*                                                                          *\n");
       printf("*       PLEASE REMEMBER TO FOLLOW THE ORDER DURING PLACING THE SHIP        *\n");
       printf("*                                                                          *\n");
       printf("*                --------------------------------------                    *\n");
       printf("*               |  >   1st: 1 SHIP  OVER 5 BOXES    <  |                   *\n");
       printf("*               |  > 2nd: ONLY 4 SHIPS OVER 2 BOXES <  |                   *\n");
       printf("*               |  > 3rd: ONLY 3 SHIPS OVER 3 BOXES <  |                   *\n");
       printf("*               |  > 4th: ONLY 2 SHIPS OVER 4 BOXES <  |                   *\n");
       printf("*               |  > 5th: ONLY 1 SHIP  OVER 5 BOXES <  |                   *\n");
       printf("*                --------------------------------------                    *\n");
       printf("*                                                                          *\n");
       printf("****************************************************************************\n");
       puts("");
       puts("");
        for(int i=0; i<10; i++)
        {
        printBoard(boardP1);
        playerPlaceShip(boardP1, shipsizes[i]);
        printBoard(boardP1);
        }

        for(int i=0; i<10; i++)
        {
        placeShipRand(boardP2, shipsizes[i]);
        printBoard(boardP2);
        }
    }

       puts(" ");
       puts(" ");
       puts(" ");
       puts(" ");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!            SHIPS HAS BEEN PLACED           !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                    NOW                     !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!      ! READY !    ! AIM !   ! FIRE !       !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!                                            !!!!!!!!!!!!!!!!!");
       puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    playerVsAIEasy(boardP1,boardP2, boardP1Attac, boardP2Attac);    //player vs easy (if you don't win here you are a looser)

}
