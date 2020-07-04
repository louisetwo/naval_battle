#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "mapa.h"
#include "navios.h"
#include "ranking.h"
#include "jogo.c"


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