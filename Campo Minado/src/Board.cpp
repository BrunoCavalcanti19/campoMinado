#include "Board.h"
#include <cstdlib>
#include "Menu.h"
#include <ctime>
#include <iostream>
#include <string>
#include <stdlib.h>
int altura,largura,numero_bombas,altura_random,largura_random,game_count,altura_total,largura_total,replay;
int matriz[30][30];
int upper_Board[30][30];
int flag_check;
Menu menu;
unsigned seed = time(NULL);
Board::Board()
{
    //ctor
}

//Here Goes all the game logic//


//Function that takes all elements in the bottom 2D array and turns them into 0
void Board::zera_Matriz(int altura, int largura)
{
    for(int i = 0; i<altura; i++)
    {
        for(int j = 0; j<largura; j++)
        {
            matriz[i][j]=0;
        }
    }
}
//Function that takes all the elements in the upper 2D array and turns them into 12
void Board::generate_upperBoard(int altura, int largura)
{
    for(int i = 0; i<altura; i++)
    {
        for(int j = 0; j<largura; j++)
        {
            upper_Board[i][j] = 12;
        }
    }

}
//Insert the mines in random positions, using the rand() function
void Board::coloca_Bombas(int altura, int largura, int numero_bombas)
{
    srand(seed);//Function that generates a random number between 0 and the actual time
    do
    {
        altura_random = rand()%altura; // Attributes a random value between 0 and max Height to the variable -> Using the srand(seed) number as key
        largura_random = rand()%largura; // Attributes a random value between 0 and max Width to the variable -> Using the srand(seed) number as key
        if(matriz[altura_random][largura_random]==9) // Condition to check if this spot is a mine, if true generates another random position
        {
            altura_random = rand()%altura;
            largura_random = rand()%largura;

        }
        else
        {
            matriz[altura_random][largura_random] =9;
            numero_bombas--;
        }
    }
    while(numero_bombas>0);

}
////Function to increment the hints in one if a mine is nearby
void Board::coloca_Dicas(int altura, int largura)
{
    for(int i = 0; i<altura; i++)
    {
        for(int j = 0; j<largura; j++)
        {
            if(matriz[i][j]!=9)
            {

                if(matriz[i-1][j-1] == 9 && (i-1) >= 0 && (j-1) >= 0) //Only check spots that are in the board
                {
                    matriz[i][j]++;

                }
                if(matriz[i-1][j] == 9 && (i-1) >= 0)
                {
                    matriz[i][j]++;

                }
                if(matriz[i-1][j+1] == 9 && (i-1) >= 0  && (j+1)<largura)
                {
                    matriz[i][j]++;

                }
                if(matriz[i][j-1] == 9 && (j-1) >= 0)
                {
                    matriz[i][j]++;

                }
                if(matriz[i][j+1] == 9 && (j+1)<largura)
                {
                    matriz[i][j]++;

                }
                if(matriz[i+1][j-1] == 9 && (i+1) <altura && (j-1) >= 0)
                {
                    matriz[i][j]++;

                }
                if(matriz[i+1][j] == 9 && (i+1) <altura)
                {
                    matriz[i][j]++;

                }
                if(matriz[i+1][j+1] == 9 && (i+1) <altura && (j+1)<largura)
                {
                    matriz[i][j]++;

                }
            }

        }
    }
}

//Function that check and show empty spaces
void Board::empty_Space(int altura, int largura,int altura_total, int largura_total)
{
    int i,j;

    for(i = altura-1; i <=altura + 1; i++) //It starts with the Upper Left position and end in the bottom right
    {
        if(i<0 || i>(altura_total-1)) //Only check spots that are in the gameBoard
        {
            continue;

        }
        for(j=largura-1; j<=largura+1; j++) //It starts with the Upper Left position and end in the bottom right
        {
            if(j<0 || j>(largura_total-1)||matriz[i][j]==-2) //Only check spots that are in the gameBoard and that aren't "open"
            {
                continue;

            }

            if(matriz[i][j]==0 && matriz[i][j]!=9) //Check the spot to see if it's an empty space. If true, calls the function again, until hit a hint
            {

                upper_Board[i][j]=0; //The screen shows an empty space
                matriz[i][j]=-2; //The operation Array spot can no longer be verified
                empty_Space(i,j,altura_total,largura_total);
            }
            if(matriz[i][j]>0 && matriz[i][j] <9)//Check the spot to see if it's a hint
            {

                upper_Board[i][j] = matriz[i][j];//The upper board receives the operation array value
                matriz[i][j]=-2;//The operation Array spot can no longer be verified

            }
        }
    }

}
//Function that shows the board screen
void Board::create_upperBoard(int altura,int largura)
{
    system("CLS");
    for(int i = 0; i<altura; i++)
    {
        for(int j = 0; j<largura; j++)
        {
            if(upper_Board[i][j]==12)  //If the upper board position is a 12, it shows " - " on the screen
            {
                std::cout << " - ";
            }
            else if(upper_Board[i][j]==9)  //If the upper board position is a 9, it shows " X " on the screen
            {
                std::cout <<" X ";

            }
            else if(upper_Board[i][j]==13)
            {
                std::cout << " P ";
            }

            else
            {
                std::cout<<" "<< upper_Board[i][j] <<" ";
            }
        }
        std::cout << "\n";
    }
}
void Board::game_Board(int altura,int largura,int flag_check, int altura_total, int largura_total)
{
    if(flag_check==1)
    {
        if(upper_Board[altura][largura]==12)
        {
            upper_Board[altura][largura]=13;
        }
        else if(upper_Board[altura][largura]==13)
        {
            upper_Board[altura][largura]=12;
        }
    }
    if(flag_check==2)
    {
        if(matriz[altura][largura] == 9) //If the chosen spot is a mine, the game ends

        {
            upper_Board[altura][largura] = matriz[altura][largura];
            system("CLS");
            std::cout << "Stay with me, soldier!\n";

            do
            {
                std::cout << "Play again?:\n 1 - Yes\n 2 - No\n";
                std::cin >> replay;
                if(std::cin.fail())
                {
                    std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                }
            }
            while(replay < 1 || replay >2);
            switch(replay)
            {
            case 1 :
                menu.first_screen();
            case 2:
                exit(1);
            }
        }
        else if(matriz[altura][largura] == 0)   //If the chosen spot is a empty space it calls the function
        {

            empty_Space(altura,largura,altura_total,largura_total);

        }
        else if(matriz[altura][largura]!=-2)
        {
            upper_Board[altura][largura] = matriz[altura][largura]; //If it is a hint, shows the hint on the screen
        }

    }
}
//Function to check the win condition
int Board:: win_Condition(int altura, int largura, int numero_bombas)
{
    int count_bomb=0;
    for(int i =0; i<altura; i++)
    {
        for(int j = 0; j<largura; j++)
        {
            if(upper_Board[i][j]==13 && matriz[i][j] == 9) //Every time the upperBoard spot is a Flag ,and the operation array is a bomb, the bomb counter increments 1
            {
                count_bomb++;
            }
        }
    }
    if(count_bomb == numero_bombas) //if the bomb counters is equal to the mines total, the win condition becomes true
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
Board::~Board()
{
    //dtor
}
