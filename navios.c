#include "mapa.h"
#include "navios.h"
#include "utils.h"

//tipos de navios 
void adiciona_barco(struct mapa *mapa, int tam, struct navios *navios, int num){
    mostra_mapa(*mapa);
    char coordenada_char;
    printf("Qual a coordenada de A a J?\n");
    scanf("%c", &coordenada_char);

    int coordenadaX = transforma_coodenada(coordenada_char);

    int coordenadaY;
    printf("Qual a coordenada de 0 a 9?\n");
    scanf("%d", &coordenadaY);
    getchar();

    if(mapa->coordenadas[coordenadaY][coordenadaX] == 'N'){
        printf("Já existe um navio nessa posição, selecione novamente:\n");
        return adiciona_barco(mapa, tam, navios, num);
    }

    struct coordenada coordenada;

    coordenada.x = coordenadaX;
    coordenada.y = coordenadaY;
    struct coordenada *coordenadas_validadas = valida_opcoes(coordenada, tam, *mapa);
    for(int i = 0; coordenadas_validadas[i].last != 1; i++) {
        printf("%d - %c, %d\n", i, transforma_letra(coordenadas_validadas[i].x), coordenadas_validadas[i].y);
    }
    int opcao;
    printf("Escolha a opção:\n");
    scanf("%d", &opcao);
    getchar();

    desenha_mapa(mapa, coordenada, coordenadas_validadas[opcao], 'N');

    struct posicao posicao;
    posicao.c1 = coordenada;
    posicao.c2 = coordenadas_validadas[opcao];
    navios->posicoes[num] = posicao;

}

void adiciona_porta_avioes(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num){
    printf("%s, adicione um porta aviões!\n", jogador.nickname);
    adiciona_barco(mapa, 5, navios, num);
}

void adiciona_encouracado(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num){
    printf("%s, adicione um encouraçado!\n", jogador.nickname);
    adiciona_barco(mapa, 4, navios, num);
}

void adiciona_cruzador(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num){
    printf("%s, adicione um cruzador!\n", jogador.nickname);
    adiciona_barco(mapa, 3, navios, num);
}
void adiciona_submarino(struct mapa *mapa, struct jogador jogador, struct navios *navios, int num){
    printf("%s, adicione um submarino!\n", jogador.nickname);
    adiciona_barco(mapa, 2, navios, num);
}

