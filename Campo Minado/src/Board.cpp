#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <stdlib.h>
int altura,largura,numero_bombas,altura_random,largura_random,game_count,altura_total,largura_total;
int matriz[30][30];
int upper_Board[30][30];
bool endGame = false;
unsigned seed = time(NULL);
Board::Board()
{
    //ctor
}
//Function that takes all elements in the 2D array and turns them into 0
void Board::zera_Matriz(int altura, int largura)
{
    for(int i = 0;i<altura;i++){
        for(int j = 0;j<largura;j++)
            {
              matriz[i][j]=0;
            }
    }
}

void Board::generate_upperBoard(int altura, int largura)
{
   for(int i = 0; i<altura;i++)
    {
      for(int j = 0; j<largura;j++)
        {
          upper_Board[i][j] = 12;
        }
    }

}
//Coloca as bombas em posições aleatórias da matriz, fazendo uso da função rand()
void Board::coloca_Bombas(int altura, int largura, int numero_bombas)
{
  srand(seed);
    do
    {
        altura_random = rand()%altura; // atribui a variável largura_random um valor aleatório entre 0 e a largura total
        largura_random = rand()%largura; // atribui a variável altura_random um valor aleatório entre 0 e a altura total
        if(matriz[altura_random][largura_random]==9) // condição para checar se a casa já possui uma bomba
            {
                altura_random = rand()%altura;
                largura_random = rand()%largura;

            }else{
                matriz[altura_random][largura_random] =9;
                numero_bombas--;
            }
}while(numero_bombas>0);

}
//Laço para adicionar as dicas ao tabuleiro, ele checa as casas ao redor da escolhida, caso a casa proxima tenha uma bomba o valor da casa incrementa em 1
void Board::coloca_Dicas(int altura, int largura)
{
 for(int i = 0; i<altura;i++)
        {
         for(int j = 0; j<largura;j++)
            {
              if(matriz[i][j]!=9)
                {

                  if(matriz[i-1][j-1] == 9 && (i-1) >= 0 && (j-1) >= 0) //ao checar a casa ele também limita ela a posições existentes no tabuleiro
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
//Imprime o tabuleiro na tela
/*void Board::gera_Tabuleiro(int altura, int largura)
{
for(int i = 0; i< altura;i++)
    {
     for(int j=0;j<largura;j++)
        {
          if(matriz[i][j]==9){ // Caso o valor seja 9 (número atribuido para bomba), ele coloca um X na tela
              std::cout<<" X "<<" ";
            }else
            {
              std::cout<< " " << matriz[i][j] <<" " << " "; // se não for 9 ele coloca o valor armazenado na posição (podendo ir de 0 a 8)

            }

        }
       std::cout<<"\n";
    }
*/

void Board::create_upperBoard(int altura,int largura)
{
  system("CLS");
  for(int i = 0; i<altura;i++)
    {
     for(int j = 0; j<largura;j++)
        {
          if(upper_Board[i][j]==12){
            std::cout << " - ";
          }else if(upper_Board[i][j]==9)
          {
             std::cout <<" X ";

          }

          else{
            std::cout<<" "<< upper_Board[i][j] <<" ";
          }
        }
      std::cout << "\n";
    }
}
void Board::game_Board(int altura,int largura)
{

   if(matriz[altura][largura] == 9)
    {
        upper_Board[altura][largura] = matriz[altura][largura];
        std::cout << "You Lose!\n";

     }else if(matriz[altura][largura] == 0)
            {
             upper_Board[altura][largura] = matriz[largura][altura];

          //if((altura-1) >= 0 && (largura-1) >= 0) //ao checar a casa ele também limita ela a posições existentes no tabuleiro
            // {
               upper_Board[altura-1][largura-1] = matriz[altura-1][largura-1];

           //  }
         //  if((altura-1) >= 0)
         //    {
               upper_Board[altura-1][largura] = matriz[altura-1][largura];


        //     }
        //   if((altura-1) >= 0  && (largura+1)<largura_total)
        //     {
                upper_Board[altura-1][largura+1] = matriz[altura-1][largura+1];

        //     }
        //   if((largura-1) >= 0)
        //     {
                upper_Board[altura][largura-1] = matriz[altura][largura-1];

         //    }
         //  if((largura+1)<largura_total)
          //    {
                upper_Board[altura][largura+1] = matriz[altura][largura+1];

         //     }
         //  if((altura+1) <altura_total && (largura-1) >= 0)
         //      {
                  upper_Board[altura+1][largura-1] = matriz[altura+1][largura-1];

        //       }
        //   if((altura+1) <altura_total)
        //      {
                 upper_Board[altura+1][largura] = matriz[altura+1][largura];

        //      }
        //    if((altura+1) <altura_total && (largura+1)<largura_total)
        //      {
                upper_Board[altura+1][largura+1] = matriz[altura+1][largura+1];

        //      }

    }else{
        upper_Board[altura][largura] = matriz[altura][largura];

    }
}

Board::~Board()
{
    //dtor
}
