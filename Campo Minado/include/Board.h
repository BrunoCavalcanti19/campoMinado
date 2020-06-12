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
    void generate_upperBoard(int altura, int largura);
    void create_upperBoard(int altura,int largura);
    void game_Board(int altura,int largura,int flag_check,int altura_total,int largura_total);
    void empty_Space(int posX, int posY,int max_Height, int max_Width);
    int win_Condition(int altura, int largura, int numero_bombas);

protected:

private:
};

#endif // BOARD_H
