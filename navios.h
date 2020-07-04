#ifndef NAVIOS
#define NAVIOS

struct coordenada {
    int x, y;
};


//tipos de navios 
void adiciona_porta_avioes(struct mapa *mapa){
    mostra_mapa(*mapa);
    char coordenada_char;
    printf("Qual a coordenada de A a J?\n");
    scanf("%c", &coordenada_char);

    int coordenadaX = transforma_coodenada(coordenada_char);

    int coordenadaY;
    printf("Qual a coordenada de 0 a 9?\n");
    scanf("%d", &coordenadaY);

    if(mapa->coordenadas[coordenadaX][coordenadaY] == 'N'){
        printf("Já existe um navio nessa posição, selecione novamente:\n");
        return adiciona_porta_avioes(mapa);
    }

    struct coordenada coordenada;

    coordenada.x = coordenadaX;
    coordenada.y = coordenadaY;

    struct coordenada *coordenadas_validadas = valida_opcoes(coordenada, 5, *mapa);
    printf("%d - %d", coordenadas_validadas[0].x, coordenadas_validadas[0].y);









}

// void adiciona_encouracado(struct mapa *mapa){
//     system("clear");
//     void mostra_mapa(mapa->coordenadas);

// }

// void adiciona_cruzador(struct mapa *mapa){
//     system("clear");
//     void mostra_mapa(mapa->coordenadas);

// }
// void adiciona_submarino(struct mapa *mapa){
//     system("clear");
//     void mostra_mapa(mapa->coordenadas);
// }

//tipos de navios

#endif