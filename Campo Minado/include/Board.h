#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        virtual ~Board();
        void zera_Matriz(int altura, int largura);
        void coloca_Bombas(int altura, int largura, int numero_bombas);
        void coloca_Dicas(int altura, int largura);
        void gera_Tabuleiro(int altura, int largura);

    protected:

    private:
};

#endif // BOARD_H
