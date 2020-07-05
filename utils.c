#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "jogador.h"
#include "mapa.h"
#include "navios.h"

void mostra_menu(){
    printf("\n   |---------------   Batalha naval   ---------------|\n");
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
    jogador.nickname[strcspn(jogador.nickname, "\n")] = 0;  //achei na internet, primeira solução stackoverflow - https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
    return jogador;
}

struct mapa cria_mapa(){
    struct mapa mapa;
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
void mostra_mapa_oculto(struct mapa mapa){
    printf("  A B C D E F G H I J\n");
    for(int i=0; i< 10; i++){
        printf("%d ", i);
        for(int j=0; j<10; j++){
            if(mapa.coordenadas[i][j] == 'N'){
                printf("%c ", '~');
            }else{
                printf("%c ", mapa.coordenadas[i][j]);
            }
        }
        printf("\n");
    }
    
}

int transforma_coodenada(char letra){
    if(letra == 'a' || letra == 'A')
        return 0;
    if(letra == 'b' || letra == 'B')
        return 1;
    if(letra == 'c' || letra == 'C')
        return 2;
    if(letra == 'd' || letra == 'D')
        return 3;
    if(letra == 'e' || letra == 'E')
        return 4;
    if(letra == 'f' || letra == 'F')
        return 5;
    if(letra == 'g' || letra == 'G')
        return 6;
    if(letra == 'h' || letra == 'H')
        return 7;
    if(letra == 'i' || letra == 'I')
        return 8;
    if(letra == 'j' || letra == 'J')
        return 9;
}

char transforma_letra(int numero){
    if(numero == 0)
        return 'A';
    if(numero == 1)
        return 'B';
    if(numero == 2)
        return 'C';
    if(numero == 3)
        return 'D';
    if(numero == 4)
        return 'E';
    if(numero == 5)
        return 'F';
    if(numero == 6)
        return 'G';
    if(numero == 7)
        return 'H';
    if(numero == 8)
        return 'I';
    if(numero == 9)
        return 'J';
}

struct coordenada *valida_opcoes(struct coordenada coordenada, int tam, struct mapa mapa){
    int count = 0;
    struct coordenada *opcoes =  malloc(sizeof(struct coordenada) * 4); // opções de direção
   // struct coordenada opcoes[4];
    struct coordenada coordenada2;

    coordenada2.x = coordenada.x + tam - 1; 
    coordenada2.y = coordenada.y;
    if(coordenada.x + tam <= 10 && verifica_barco(coordenada, coordenada2, mapa, 1) ){
        opcoes[count] = coordenada2;
        count++;
    }

    coordenada2.x = coordenada.x - tam + 1;
    coordenada2.y = coordenada.y;
    if(coordenada.x - tam > -1 && verifica_barco(coordenada, coordenada2, mapa, 1 ) ){
        opcoes[count] = coordenada2;
        count++;
    }

    coordenada2.x = coordenada.x;
    coordenada2.y = coordenada.y + tam - 1;
    if(coordenada.y + tam <= 10 && verifica_barco(coordenada, coordenada2, mapa, 0) ){ // vertical
        opcoes[count] = coordenada2;
        count++;
    }

    coordenada2.x = coordenada.x;
    coordenada2.y = coordenada.y - tam + 1 ;
    if(coordenada.y - tam > -1 && verifica_barco(coordenada, coordenada2, mapa, 0 ) ){ // vertical
        opcoes[count] = coordenada2;
        count++;
    }
    opcoes[count].last = 1;

    return opcoes;
}

int verifica_barco(struct coordenada coordenada1, struct coordenada coordenada2, struct mapa mapa, int horizontal){  // Verificar a existencia de algum barco entre as coordenadas
    int valido = 1;  // barco pode ser inserido
    if(horizontal == 1){
        if(coordenada1.x < coordenada2.x){
            for(int i=coordenada1.x; i<=coordenada2.x; i++){
                if(mapa.coordenadas[coordenada1.y][i] == 'N'){
                    valido = 0;
                    break;
                }
            }
        }else{
            for(int i=coordenada2.x; i<=coordenada1.x; i++){
                if(mapa.coordenadas[coordenada1.y][i] == 'N'){
                    valido = 0;
                    break;
                }
            }
        }
    }else{
        if(coordenada1.y < coordenada2.y){
            for(int i=coordenada1.y; i<=coordenada2.y; i++){
                if(mapa.coordenadas[i][coordenada1.x] == 'N'){
                    valido = 0;
                    break;
                }
            }    
        }else{
            for(int i=coordenada2.y; i<=coordenada1.y; i++){
                if(mapa.coordenadas[i][coordenada1.x] == 'N'){
                    valido = 0;
                    break;
                }
            }  
        }
    }
    return valido;
}

void desenha_mapa(struct mapa *mapa, struct coordenada coordenada1, struct coordenada coordenada2, char letra){
    if(coordenada1.x == coordenada2.x){ // x igual(reta)
        if(coordenada1.y > coordenada2.y){
            for(int i= coordenada2.y; i <= coordenada1.y; i++){  // Desenha de cima pra baixo
                mapa->coordenadas[i][coordenada1.x] = letra;
            }
        }else{
            for(int i= coordenada1.y; i <= coordenada2.y; i++){ 
                mapa->coordenadas[i][coordenada1.x] = letra;
            }
        }       
    }else{  // y igual reta
        if(coordenada1.x > coordenada2.x){
            for(int i= coordenada2.x; i <= coordenada1.x; i++){
                mapa->coordenadas[coordenada1.y][i] = letra;
            }

        }else{
            for(int i= coordenada1.x; i <= coordenada2.x; i++){
               mapa->coordenadas[coordenada1.y][i] = letra;
            }
        }
    }
}

int checa_fimdejogo(struct mapa mapa1, struct mapa mapa2, struct jogador jogador1, struct jogador jogador2){
    int jogador1WIN = 1;
    int jogador2WIN = 1;
    for(int i=0; i < 10; i++){
        for(int j=0; j<10; j++){
            if(mapa1.coordenadas[i][j] == 'N') //checando se existe algum navio varrendo mapa
                jogador2WIN = 0;
        }
    }
    for(int i=0; i < 10; i++){
        for(int j=0; j<10; j++){
            if(mapa2.coordenadas[i][j] == 'N')
                jogador1WIN = 0;
        }
    }

    if(jogador1WIN){
        printf("PARABÉNS %s ! \n", jogador1.nickname);
        return 1;
    }else if(jogador2WIN){
        printf("PARABÉNS %s ! \n", jogador2.nickname);
        return 1;
    }else{
        return 0;
    }

}

int verifica_barco_destruido(struct coordenada coordenada1, struct coordenada coordenada2, struct mapa mapa){
    int destruido = 1; 
    if(coordenada1.y == coordenada2.y){
        if(coordenada1.x < coordenada2.x){
            for(int i=coordenada1.x; i<=coordenada2.x; i++){
                if(mapa.coordenadas[coordenada1.y][i] != 'X'){
                    destruido = 0;
                    break;
                }
            }
        }else{
            for(int i=coordenada2.x; i<=coordenada1.x; i++){
                if(mapa.coordenadas[coordenada1.y][i] != 'X'){
                    destruido = 0;
                    break;
                }
            }
        }
    }else{
        if(coordenada1.y < coordenada2.y){
            for(int i=coordenada1.y; i<=coordenada2.y; i++){
                if(mapa.coordenadas[i][coordenada1.x] != 'X'){
                    destruido = 0;
                    break;
                }
            }    
        }else{
            for(int i=coordenada2.y; i<=coordenada1.y; i++){
                if(mapa.coordenadas[i][coordenada1.x] != 'X'){
                    destruido = 0;
                    break;
                }
            }  
        }
    }
    return destruido;
}