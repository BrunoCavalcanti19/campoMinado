#include "Menu.h"
#include <iostream>
#include "Board.h"
#include <string>
double option,flag_option;
char  go_back;
double width_player,height_player,number_bombs_player,line,column,count_spots;

Board mineField;
Menu::Menu()
{
    //ctor
}
//Function that shows the game instructions
void Menu::instructions()
{
    system("CLS");
    std::cout<<" -------------------------------------------------------\n"
             " |                     INSTRUCTIONS                    |\n"
             " | Hello soldier, let's review your mission, shall we? |\n"
             " |                                                     |\n"
             " |    Today's mission is to identify the places where  |\n"
             " |    the mines are buried. Seems easy? But it is NOT! |\n"
             " | Our superiors left some boards with numbers on them.|\n"
             " |   These boards reveal how many mines are around it. |\n"
             " |                                                     |\n"
             " |  You can determine the size of your work field.     |\n"
             " |  It can have between 4(2x2) and 900(30x30)spots.    |\n"
             " |   Got it?! Nor more, nor less!                      |\n"
             " |                                                     |\n"
             " |  Since you are a newbie you can choose how many     |\n"
             " |  mines you can find today, but remember : the number|\n"
             " |  of mines can never, at any circunstances be bigger |\n"
             " |  than your work field size((Height x Width)-1).     |\n"
             " |                                                     |\n"
             " |  One more thing, i'm giving you some flags every    |\n"
             " |  time you find a mine spot put a flag on it.        |\n"
             " |                                                     |\n"
             " |  And remember, the first spot of your world field   |\n"
             " |  is 0 and the last one is (height-1) or (width-1).  |\n"
             " |                                                     |\n"
             " |  If you manage to find all the bomb spots our team  |\n"
             " |  will get you out of there in safety.               |\n"
             " |  If you don't? Well, let's hope this won't happen...|\n"
             " |                                                     |\n"
             " |                   Good hunt, soldier!               |\n"
             " |                                                     |\n"
             " |           Insert any value to go back...            |\n"
             " -------------------------------------------------------\n";
    std::cin>>go_back;
    first_screen();
}

//Menu function
void Menu::first_screen()
{
    system("CLS");
    do
    {
        std::cout << "------------------------------\n"
                  "|                            |\n"
                  "|   1 - Play                 |\n"
                  "|   2 - Instructions         |\n"
                  "|   3 - Return to windows    |\n"
                  "|                            |\n"
                  "------------------------------\n";
        std::cin >>option;
        //If your input isn't a integer
        if(std::cin.fail())
        {
            std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
    }
    while(option < 1 || option > 3);  //stays in the loop if the input isn't one of the option numbers
    switch ((int)option)
    {
//if you choose  1
    case 1 :
        do
        {
            std::cout<<"What is the height of your work size?\n";
            std::cin>> height_player;
            if(std::cin.fail())
            {
                std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout<<"What is the width of your work size?\n";
            std::cin>>width_player;
            if(std::cin.fail())
            {
                std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout<<"How many mines you will try to find?\n";
            std::cin>>number_bombs_player;
            if(std::cin.fail())
            {
                std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
//Stays in the loop if your height and width input are less than 2 or more than 30, or if the number of mines is less than 1 or more than (height*width)-1
        }
        while(height_player<2 || width_player <2 || height_player>30 || width_player > 30 || number_bombs_player<=0 ||number_bombs_player>(height_player*width_player)-1);

//count_spots = ((height_player * width_player) - number_bombs_player); //variable for win condition, it counts the number of "closed" spots that aren't bombs;

        mineField.zera_Matriz((int)height_player,(int)width_player); //Function that attribute 0 to all elements of the bottom 2D array;
        mineField.coloca_Bombas((int)height_player,(int)width_player,(int)number_bombs_player); //Function that place the mines in random spots
        mineField.coloca_Dicas((int)height_player,(int)width_player);//Function that place the hints on the board;
        mineField.generate_upperBoard((int)height_player,(int)width_player);//Function that generates the gameboard
        mineField.create_upperBoard((int)height_player,(int)width_player);//Function that show the gameboard on the screen
        do
        {
            do
            {
                std::cout<< "Will you use a flag?\n 1 - Yes\n 2 - No\n";
                std::cin>>flag_option;
                if(std::cin.fail())
                {
                    std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                }
            }
            while(flag_option < 1 || flag_option > 2);

            std::cout << "Tell us which line you want:\n";
            std::cin >> line;
            if(std::cin.fail())
            {
                std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Tell us which column you want:\n";
            std::cin >> column;
            if(std::cin.fail())
            {
                std::cout << "trying to break me? this isn't funny \\(T-T)/ !\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }

            mineField.win_Condition((int) height_player,(int)width_player,(int)number_bombs_player);//Function that scan the board for "closed" spots that are mines
            mineField.game_Board((int)line,(int)column,(int)flag_option,(int)height_player,(int)width_player);//Function that make the player move
            mineField.create_upperBoard((int)height_player,(int)width_player);//Function that show the gameboard on the screen
        }
        while(mineField.win_Condition((int) height_player,(int)width_player,(int)number_bombs_player)==0);  //Stays in the loop as long as the win condition is false
        std::cout<<"Good job soldier! ('-')7\n";
        std::cout <<"Insert any value here:\n";
        std::cin>>go_back;
        first_screen();
        break;
// If you choose 2 goes to the instruction screen
    case 2 :
        instructions();
    case 3:
        break;
    default:
        break;
    }

}



Menu::~Menu()
{
    //dtor
}
