#ifndef NAVIOS
#define NAVIOS

struct coordenada {
    int x, y;
    int last;
};

struct posicao {
    struct coordenada c1;
    struct coordenada c2;
    int last;
};
struct navios{
    struct posicao posicoes[10];
};


//tipos de navios 
void adiciona_barco(struct mapa *mapa, int tam, struct navios *navios, int num);
void adiciona_porta_avioes(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num);
void adiciona_encouracado(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num);
void adiciona_cruzador(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num);
void adiciona_submarino(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num);

#endif