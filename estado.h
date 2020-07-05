#ifndef ESTADO
#define ESTADO

struct estado {
    struct jogador jogador1;
    struct jogador jogador2;
    struct mapa mapa1;
    struct mapa mapa2;
    struct navios navios1;
    struct navios navios2;
    int turno; // 1 - Jogador 1  || 2 - Jogador 2
};

#endif