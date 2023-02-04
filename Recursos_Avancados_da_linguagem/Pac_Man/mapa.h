struct mapa{
	int linhas;
	int colunas;
	char** matriz; // ponteiro de ponteiros
};

typedef struct mapa MAPA;

void le_mapa(MAPA* mp);
void malloc_mapa(MAPA* mp);
void libera_mapa(MAPA* mp);
void imprime_mapa(MAPA* mp);
