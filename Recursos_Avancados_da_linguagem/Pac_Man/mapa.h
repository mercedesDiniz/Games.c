struct mapa{
	int linhas;
	int colunas;
	char** matriz; // ponteiro de ponteiros
};
typedef struct mapa MAPA;

struct posicao{
	int x;
	int y;
};
typedef struct posicao POSICAO;

void le_mapa(MAPA* mp);
void malloc_mapa(MAPA* mp);
void libera_mapa(MAPA* mp);
void imprime_mapa(MAPA* mp);
void encontrar_no_mapa(MAPA* mp, POSICAO* p, char c);
int ehvalida(MAPA* mp, int x, int y);
int ehvazia(MAPA* mp, int x, int y);
void andando_no_mapa(MAPA* mp, int x_origem, int y_origem, int x_dest, int y_dest);
