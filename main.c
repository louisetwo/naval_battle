#include <stdio.h>
#include <stdlib.h>
#include "utils.c"
#include "navios.c"
#include "jogo.c"
#include "ranking.h"
#include "mapa.h"

int main(void){
    int opcao;

    do{
        mostra_menu();
        printf("Escolha a opção:");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                comecar_jogo();
                break;
            case 2:
                printf("carregar jogo");
                break;
            case 3:
                printf("Ranking");
                break;
        }

    }while(opcao !=4);
    printf("\n");

    return 0;
}