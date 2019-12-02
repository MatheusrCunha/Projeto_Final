#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include "dados.h"

#define repetir 1

int main()
{
	int i;
    int j = 0;
    int n_linhas = 0;
    //volatile int i; // pode mudar

    dado_t **dados = ler_dados("bounding_boxes.csv", &n_linhas);
    clock_t  clock_inicio, clock_final, clock_total = 0;

    for(j = 1; j <= repetir; j++)
    {
        dado_t **dados = ler_dados("bounding_boxes.csv", &n_linhas);

        clock_inicio = clock();

       // quick_sort(dados, 0, n_linhas - 1);
        //counting_sort(dados, n_linhas);

        //for(i = 0; i< 1000000; i++); //colocar para atrasaar tempo

        clock_final = clock();

        clock_total += (clock_final - clock_inicio);

        //printf("inicio: %d --- final: %d\n", (int)clock_inicio, (int)clock_final);

        for(i=0; i<n_linhas; i++)
            imprime_dados(dados[i]);

        liberar_dados(dados, n_linhas);
    }
        double tempo_total = (double)clock_total * 1000 /CLOCKS_PER_SEC;
        for(i=0; i<n_linhas; i++)
            imprime_dados(dados[i]);

        printf("Media Total:  %lf milis\n", tempo_total / repetir);

    //fclose(dados);
    return 0;
}
