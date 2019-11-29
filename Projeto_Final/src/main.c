#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#include "dados.h"

//#define repetir 1

int main()
{
	int i = 0;
    int n_linhas = 0;
    //volatile int i; // pode mudar

    dado_t **dados = ler_dados("CoastalDataSystem.csv", &n_linhas);

    for(i=0; i<n_linhas; i++){
    	imprime_dados(dados[i]);
    }

    liberar_dados(dados, n_linhas);
    //fclose(dados);
    return 0;
}
