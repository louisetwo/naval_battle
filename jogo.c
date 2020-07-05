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

    // Player 1

    system("clear");
    //adiciona_porta_avioes(&estado.mapa1, estado.jogador1);
    // adiciona_encouracado(&estado.mapa1, estado.jogador1);
    // adiciona_encouracado(&estado.mapa1, estado.jogador1);
    // adiciona_cruzador(&estado.mapa1, estado.jogador1);
     //adiciona_cruzador(&estado.mapa1, estado.jogador1, &estado.navios1);
    // adiciona_cruzador(&estado.mapa1, estado.jogador1);
    // adiciona_submarino(&estado.mapa1, estado.jogador1);
    // adiciona_submarino(&estado.mapa1, estado.jogador1);
    adiciona_submarino(&estado.mapa1, estado.jogador1, &estado.navios1, 0);
    adiciona_submarino(&estado.mapa1, estado.jogador1, &estado.navios1, 1);



    // Player 2

    system("clear");
    //adiciona_porta_avioes(&estado.mapa2, estado.jogador2);
    // adiciona_encouracado(&estado.mapa2, estado.jogador2);
    // adiciona_encouracado(&estado.mapa2, estado.jogador2);
    // adiciona_cruzador(&estado.mapa2, estado.jogador2);
    // adiciona_cruzador(&estado.mapa2, estado.jogador2);
     //adiciona_cruzador(&estado.mapa2, estado.jogador2);
    adiciona_submarino(&estado.mapa2, estado.jogador2, &estado.navios2, 0);
    adiciona_submarino(&estado.mapa2, estado.jogador2, &estado.navios2, 1);
    // adiciona_submarino(&estado.mapa2, estado.jogador2);
    // adiciona_submarino(&estado.mapa2, estado.jogador2);

    while(1){
        turno(&estado.mapa2, &estado.jogador1, estado.navios2);
        if(checa_fimdejogo(estado.mapa1, estado.mapa2, estado.jogador1, estado.jogador2)) // terminou o turno, checkou
            break;
        turno(&estado.mapa1, &estado.jogador2, estado.navios1);
        if(checa_fimdejogo(estado.mapa1, estado.mapa2, estado.jogador1, estado.jogador2)) // chega se o jogador ganhou primeiro turno
            break;
    }
};

void turno(struct mapa *mapa, struct jogador *jogador, struct navios navios){
    system("clear");
    // for(int i=0; i < 2; i++){
    //     printf("%d - %d // %d - %d", navios.posicoes[i].c1.x, navios.posicoes[i].c1.y, navios.posicoes[i].c2.x, navios.posicoes[i].c2.y );
    // }
    printf("Vez do jogador:  %s", jogador->nickname);
    mostra_mapa_oculto(*mapa);

    char coordenada_char;
    printf("Qual a coordenada de A a J?\n");
    scanf("%c", &coordenada_char);

    int coordenadaX = transforma_coodenada(coordenada_char);

    int coordenadaY;
    printf("Qual a coordenada de 0 a 9?\n");
    scanf("%d", &coordenadaY);
    getchar();

    if(mapa->coordenadas[coordenadaY][coordenadaX] == 'X' || mapa->coordenadas[coordenadaY][coordenadaX] == 'O' || mapa->coordenadas[coordenadaY][coordenadaX] == 'D' ){
        printf("Você já atirou ai, escolha outra coordenada.\n");
        getchar();
        return turno(mapa, jogador, navios);
    }

    if(mapa->coordenadas[coordenadaY][coordenadaX] == 'N'){
        printf("pew pew\n");
        mapa->coordenadas[coordenadaY][coordenadaX] = 'X';
    }else{
        printf("AGUA\n");
        mapa->coordenadas[coordenadaY][coordenadaX] = 'O';
    }

    for(int i=0; i < 2; i++){
        if(verifica_barco_destruido(navios.posicoes[i].c1, navios.posicoes[i].c2, *mapa)){
            desenha_mapa(mapa, navios.posicoes[i].c1, navios.posicoes[i].c2, 'D');
        }
    }


    mostra_mapa_oculto(*mapa);
    printf("Pressione enter para continuar\n");
    getchar();
}