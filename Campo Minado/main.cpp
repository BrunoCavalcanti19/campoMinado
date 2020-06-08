#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
unsigned seed = time(NULL);
int largura,altura,numero_bombas,altura_random,largura_random,contador;

int main()
{
    // função utilizada para gerar números aleatórios
    srand(seed);

    cout<<"Diga-nos a largura do seu tabuleiro\n";
    cin>> largura;
    cout<<"Diga-nos a altura do seu tabuleiro\n";
    cin>>altura;
    cout<<"Diga-nos a quantidade de bombas\n";
    cin>>numero_bombas;

    int matriz[largura][altura];

    //Laço que pega todos os elementos da matriz e transforma em 0
    for(int i = 0;i<largura;i++){
        for(int j = 0;j<altura;j++)
            {
              matriz[i][j]=0;
            }
    }

   //Coloca as bombas em posições aleatórias da matriz, fazendo uso da função rand()
    do
    {

        largura_random = rand()%largura; // atribui a variável largura_random um valor aleatório entre 0 e a largura total
        altura_random = rand()%altura; // atribui a variável altura_random um valor aleatório entre 0 e a altura total
        if(matriz[largura_random][altura_random]==9) // condição para checar se a casa já possui uma bomba
            {
                largura_random = rand()%largura;
                altura_random = rand()%altura;

            }else{
                matriz[largura_random][altura_random] =9;
                numero_bombas--;
            }
    }while(numero_bombas>0);

    //Laço para adicionar as dicas ao tabuleiro, ele checa as casas ao redor da escolhida, caso a casa proxima tenha uma bomba o valor da casa incrementa em 1
    for(int i = 0; i<largura;i++)
        {
         for(int j = 0; j<altura;j++)
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
                    if(matriz[i-1][j+1] == 9 && (i-1) >= 0  && (j+1)<altura )
                    {
                      matriz[i][j]++;

                    }
                    if(matriz[i][j-1] == 9 && (j-1) >= 0)
                    {
                      matriz[i][j]++;

                    }
                    if(matriz[i][j+1] == 9 && (j+1)<altura)
                    {
                      matriz[i][j]++;

                    }
                    if(matriz[i+1][j-1] == 9 && (i+1) < largura && (j-1) >= 0)
                    {
                      matriz[i][j]++;

                    }
                    if(matriz[i+1][j] == 9 && (i+1) < largura)
                    {
                      matriz[i][j]++;

                    }
                    if(matriz[i+1][j+1] == 9 && (i+1) < largura && (j+1)<altura)
                    {
                      matriz[i][j]++;

                    }
                }

            }
        }


   //Imprime o tabuleiro na tela
   for(int i = 0; i< largura;i++)
    {
     for(int j=0;j<altura;j++)
        {
          if(matriz[i][j]==9) // Caso o valor seja 9 (número atribuido para bomba), ele coloca um X na tela
             cout<<" X "<<" ";
            }else
            {
              cout<< " " << matriz[i][j] <<" " << " "; // se não for 9 ele coloca o valor armazenado na posição (podendo ir de 0 a 8)

            }

        }
     cout<<"\n";
    }

}
