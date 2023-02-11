// User Interface
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char desenhoParede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoPacman[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhoFantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoPill[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprime_mapa(MAPA* mp){
	// Exibindo o mapa
	for(int i = 0; i<mp->linhas; i++){

        for(int parte=0; parte <4; parte++){

            for(int j=0; j < mp->colunas; j++){
                switch(mp->matriz[i][j]){
                    case VAZIO:
                        imprime_parte(desenhoVazio, parte);
                        break;
                    case PAREDE_HORIZONTAL:
                    case PAREDE_VERTICAL:
                        imprime_parte(desenhoParede, parte);
                        break;
                    case PACMAN:
                        imprime_parte(desenhoPacman, parte);
                        break;
                    case PILL:
                        imprime_parte(desenhoPill, parte);
                        break;
                    case FANTASMA:
                        imprime_parte(desenhoFantasma, parte);
                        break;

                }
            }
            printf("\n");
        }
        
	}
}

void imprime_parte(char desenho[4][7], int parte){
    printf("%s", desenho[parte ]);
}