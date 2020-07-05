#ifndef UTILS
#define UTILS

void mostra_menu();
struct jogador cria_jogador();
struct mapa cria_mapa();
void mostra_mapa(struct mapa mapa);
int transforma_coodenada(char letra);
struct coordenada *valida_opcoes(struct coordenada coordenada, int tam, struct mapa mapa);
int verifica_barco(struct coordenada coordenada1, struct coordenada coordenada2, struct mapa mapa, int horizontal);
void desenha_mapa(struct mapa *mapa, struct coordenada coordenada1, struct coordenada coordenada2, char letra);
int checa_fimdejogo(struct mapa mapa1, struct mapa mapa2, struct jogador jogador1, struct jogador jogador2);
int verifica_barco_destruido(struct coordenada coordenada1, struct coordenada coordenada2, struct mapa mapa);

#endif