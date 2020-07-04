#ifndef JOGO
#define JOGO
#include "estado.h"
#include "utils.h"
#include "navios.h"

void comecar_jogo(){
    struct estado estado;
    printf("Jogador 1, ");  //criar nickname jogador
    estado.jogador1 = cria_jogador();
    printf("Jogador 2, ");
    estado.jogador2 = cria_jogador();

    estado.mapa1 = cria_mapa();
    estado.mapa2 = cria_mapa();

    system("clear");
    adiciona_porta_avioes(&estado.mapa1);



};

#endif