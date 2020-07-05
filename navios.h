#ifndef NAVIOS
#define NAVIOS

struct coordenada {
    int x, y;
    int last;
};


//tipos de navios 
void adiciona_barco(struct mapa *mapa, int tam);
void adiciona_porta_avioes(struct mapa *mapa, struct jogador jogador);
void adiciona_encouracado(struct mapa *mapa, struct jogador jogador);
void adiciona_cruzador(struct mapa *mapa, struct jogador jogador);
void adiciona_submarino(struct mapa *mapa, struct jogador jogador);

#endif