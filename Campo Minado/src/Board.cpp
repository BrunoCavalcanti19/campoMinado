#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
int altura,largura,numero_bombas,altura_random,largura_random;
int matriz[30][30];
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
//Coloca as bombas em posi��es aleat�rias da matriz, fazendo uso da fun��o rand()
void Board::coloca_Bombas(int altura, int largura, int numero_bombas)
{
  srand(seed);
    do
    {
        largura_random = rand()%largura; // atribui a vari�vel largura_random um valor aleat�rio entre 0 e a largura total
        altura_random = rand()%altura; // atribui a vari�vel altura_random um valor aleat�rio entre 0 e a altura total
        if(matriz[altura_random][largura_random]==9) // condi��o para checar se a casa j� possui uma bomba
            {
                largura_random = rand()%largura;
                altura_random = rand()%altura;

            }else{
                matriz[altura_random][largura_random] =9;
                numero_bombas--;
            }
}while(numero_bombas>0);

}
//La�o para adicionar as dicas ao tabuleiro, ele checa as casas ao redor da escolhida, caso a casa proxima tenha uma bomba o valor da casa incrementa em 1
void Board::coloca_Dicas(int altura, int largura)
{
 for(int i = 0; i<altura;i++)
        {
         for(int j = 0; j<largura;j++)
            {
              if(matriz[i][j]!=9)
                {

                  if(matriz[i-1][j-1] == 9 && (i-1) >= 0 && (j-1) >= 0) //ao checar a casa ele tamb�m limita ela a posi��es existentes no tabuleiro
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
void Board::gera_Tabuleiro(int altura, int largura)
{
for(int i = 0; i< altura;i++)
    {
     for(int j=0;j<largura;j++)
        {
          if(matriz[i][j]==9){ // Caso o valor seja 9 (n�mero atribuido para bomba), ele coloca um X na tela
              std::cout<<" X "<<" ";
            }else
            {
              std::cout<< " " << matriz[i][j] <<" " << " "; // se n�o for 9 ele coloca o valor armazenado na posi��o (podendo ir de 0 a 8)

            }

        }
       std::cout<<"\n";
    }
}


Board::~Board()
{
    //dtor
}
