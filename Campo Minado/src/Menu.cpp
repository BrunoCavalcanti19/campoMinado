#include "Menu.h"
#include <iostream>
#include "Board.h"
double opcao;
char  voltar;
double largura_player,altura_player,numero_bombas_player;
Board mineField;
Menu::Menu()
{
    //ctor
}
void Menu::instrucoes()
{
 std::cout<<" ------------------------------\n"
            " |        INSTRUCOES          |\n"
            " |  Seu objetivo eh encontrar |\n"
            " |    todas as casas que      |\n"
            " |    nao possuam bombas.     |\n"
            " |                            |\n"
            " |  As casas com numeros sao  |\n"
            " |   suas dicas, elas revelam |\n"
            " |  a quantidade de bombas ao |\n"
            " |         seu redor.         |\n"
            " |                            |\n"
            " |   Voce pode definir o seu  |\n"
            " |   tabuleiro, podendo ter:  |\n"
            " |   Entre 2 e 30 de altura   |\n"
            " |   Entre 2 e 30 de largura  |\n"
            " |   Entre 1 e a quantidade   |\n"
            " |   maxima de casas - 1      |\n"
            " |   de bombas.               |\n"
            " |                            |\n"
            " | Pressione qualquer tecla   |\n"
            " |       para voltar          |\n"
            " ------------------------------\n";
  std::cin>>voltar;
  inicio();
}


void Menu::inicio()
{
   do{
   std::cout << "------------------------------\n"
                "|                            |\n"
                "|        1 - Jogar           |\n"
                "|        2 - Instrucoes      |\n"
                "|        3 - Sair            |\n"
                "|                            |\n"
                "------------------------------\n";
  std::cin >> opcao;

  if(std::cin.fail())
    {
        std::cout << "trying to break the game? better luck next time!\n";
         std::cin.clear();
         std::cin.ignore(100, '\n');
    }
}while(opcao < 1 || opcao > 3);
switch ((int)opcao)
{
 case 1 :
        do{
    std::cout<<"Diga-nos a altura do seu tabuleiro\n";
    std::cin>> altura_player;
    if(std::cin.fail())
        {
         std::cout << "trying to break the game? better luck next time!\n";
         std::cin.clear();
         std::cin.ignore(100, '\n');
        }
    std::cout<<"Diga-nos a largura do seu tabuleiro\n";
    std::cin>>largura_player;
    if(std::cin.fail())
        {
         std::cout << "trying to break the game? better luck next time!\n";
         std::cin.clear();
         std::cin.ignore(100, '\n');
        }
    std::cout<<"Diga-nos a quantidade de bombas\n";
    std::cin>>numero_bombas_player;
    if(std::cin.fail())
        {
         std::cout << "trying to break the game? better luck next time!\n";
         std::cin.clear();
         std::cin.ignore(100, '\n');
        }
}while(altura_player<2 || largura_player <2 || altura_player>30 || largura_player > 30 || numero_bombas_player<=0 ||numero_bombas_player>(altura_player*largura_player)-1);

mineField.zera_Matriz((int)altura_player,(int)largura_player);
mineField.coloca_Bombas((int)altura_player,(int)largura_player,(int)numero_bombas_player);
mineField.coloca_Dicas((int)altura_player,(int)largura_player);
mineField.gera_Tabuleiro((int)altura_player,(int)largura_player);
break;
 case 2 :
        instrucoes();
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
