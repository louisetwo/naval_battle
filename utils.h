#ifndef UTILS
#define UTILS
#include "jogador.h"
#include "mapa.h"
#include "navios.h"
#include <stdio.h>
#include <stdlib.h>






void mostra_menu(){
    printf("\n   |-------------------   Batalha naval   -------------------|\n");
    printf("\n");
    printf("         |  1. Novo jogo                |\n");
    printf("         |  2. Carregar Jogo            |\n");
    printf("         |  3. Ranking                  |\n");
    printf("         |  4. Sair                     |\n");
    printf("\n   |-------------------------------------------------|\n");
}

struct jogador cria_jogador(){
    struct jogador jogador;
    printf("Digite o nickname:\n");
    fgets(jogador.nickname, 80, stdin);
    return jogador;
}

struct mapa cria_mapa(){
    struct mapa mapa;
    printf("alguma coisa\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
        mapa.coordenadas[i][j] = '~';
    }
  }
  return mapa;
}


void mostra_mapa(struct mapa mapa){
    printf("  A B C D E F G H I J\n");
    for(int i=0; i< 10; i++){
        printf("%d ", i);
        for(int j=0; j<10; j++){
            printf("%c ", mapa.coordenadas[i][j]);
        }
        printf("\n");
    }
    
}

int transforma_coodenada(char letra){
    switch(letra){
        case 'a':
        case 'A':
            return 0;
        case 'b':
        case 'B':
            return 1;
        case 'c':
        case 'C':
            return 2;
        case 'd':
        case 'D':
            return 3;
        case 'e':
        case 'E':
            return 4;
        case 'f':
        case 'F':
            return 5;
        case 'g':
        case 'G':
            return 6;
        case 'h':
        case 'H':
            return 7;
        case 'i':
        case 'I':
            return 8;
        case 'j':
        case 'J':
            return 9;

    }
}

struct coordenada *valida_opcoes(struct coordenada coordenada, int tam, struct mapa mapa){
    int count = 0;
    struct coordenada opcoes[4]; // opções de direção
    struct coordenada coordenada2;

    coordenada2.x = coordenada.x + tam - 1; 
    coordenada2.y = coordenada.y;
    if(coordenada.x + tam < 10 && verifica_barco(coordenada, coordenada2, mapa, 1) ){
        opcoes[count] = coordenada2;
        count++;
    }

    coordenada2.x = coordenada.x - tam - 1;
    coordenada2.y = coordenada.y;
    if(coordenada.x - tam > -1 && verifica_barco(coordenada, coordenada2, mapa, 1 ) ){
        opcoes[count] = coordenada2;
        count++;
    }

    coordenada2.x = coordenada.x;
    coordenada2.y = coordenada.y + tam - 1;
    if(coordenada.y + tam < 10 && verifica_barco(coordenada, coordenada2, mapa, 0) ){ // vertical
        opcoes[count] = coordenada2;
        count++;
    }

    coordenada2.x = coordenada.x;
    coordenada2.y = coordenada.y - tam - 1 ;
    if(coordenada.y - tam > -1 && verifica_barco(coordenada, coordenada2, mapa, 0 ) ){ // vertical
        opcoes[count] = coordenada2;
        count++;
    }
    
    return &opcoes;
}

int verifica_barco(struct coordenada coordenada1, struct coordenada coordenada2, struct mapa mapa, int horizontal){  // Verificar a existencia de algum barco entre as coordenadas
    int valido = 1;  // barco pode ser inserido
    if(horizontal == 1){
        for(int i=coordenada1.x; i<=coordenada2.x; i++){
            if(mapa.coordenadas[i][coordenada1.y] == 'N'){
                valido = 0;
                break;
            }
        }
    }else{
        for(int i=coordenada1.y; i<=coordenada2.y; i++){
            if(mapa.coordenadas[coordenada1.x][i] == 'N'){
                valido = 0;
                break;
            }
        }    
    }
    return valido;
}



#endif