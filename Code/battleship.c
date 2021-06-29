#include <stdio.h>
#include <time.h>
#include <stdlib.h>


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
            printf("1. vertical  \n2. Horizontal.  ");
            scanf("%d", &direction);
            if(direction == 1 || direction == 2)
                correct = 1;
        }while (correct == 0);
        
        do
        {
            int check = 0;
            char userInput[20];
            printf("Enter the ship position. ");
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
        printf("\nCOMPUTER HIT!!!");
        attak[shoty][shotx] = 'X';
        printBoard(attak);
        getchar();  // wait for user input before going to the next move
        return turn;
    }
    else
    {
        printf("\nCOMPUTER MISSED!!!");
        attak[shoty][shotx] = '~';
        turn = (turn == 1 ? 2 : 1);
    }
    printBoard(attak);
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
        printf("\n enter position ");
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
            printf("Dumm ass, you already played that position ");
            check = 0;
        }

        // ***************MORE CONDITIONS TO CHECK NOT SHOOTING AT THE SAME POSITION ONCE AGAIN*********************//
        if(check == 2)
            correctInput = 1;
    } while (correctInput == 0);
    if(rival[shoty][shotx] == '*')
    {
        printf("\nHIT!!!");
        attak[shoty][shotx] = 'X';
        return turn;
    }
    else
    {
        printf("\nMiss Better luck next time");
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


int main()
{
    srand(time(NULL));
    char boardP1[12][12], boardP2[12][12], boardP1Attac[12][12], boardP2Attac[12][12];
    int shipsizes[10] = {5,4,4,3,3,3,2,2,2,2};
    initalizeBoard(boardP1);
    initalizeBoard(boardP2);
    initalizeBoard(boardP1Attac);
    initalizeBoard(boardP2Attac);
    for(int i = 0; i< 10; i++){
        playerPlaceShip(boardP2, shipsizes[i]);
        printBoard(boardP2);
    }
    printBoard(boardP2);
    for(int i = 0; i< 10; i++)
        placeShipRand(boardP1, shipsizes[i]);
    printBoard(boardP1);
    //playerVsPlayer(boardP1,boardP2, boardP1Attac, boardP2Attac);  //player vs player game
    playerVsAIEasy(boardP1,boardP2, boardP1Attac, boardP2Attac);    //player vs easy (if you don't win here you are a looser)
}