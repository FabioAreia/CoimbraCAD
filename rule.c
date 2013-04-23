#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rule.h"



#define CHUNK 1024 /* read 1024 bytes at a time */
char buf[CHUNK];

typedef int (*compfn)(const void*, const void*);

int compare(struct linhainput *elem1, struct linhainput *elem2){
    if(elem1->numInput[0] < elem2->numInput[0]){
        return -1;
    }
    else if(elem1->numInput[0] > elem2->numInput[0]){ 
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char *argv[]) {

    //preencherInstancias();
    //preencherRules();

    //<editor-fold defaultstate="collapsed" desc="Prencher Instancias">

#define NRCELLSINPUT 10

    struct linhainput *tabelaInput;
    tabelaInput = (linhainput) malloc(sizeof (linhainput));

    FILE *in = fopen("nome_ficheiro_input.csv", "r");

    if (in == NULL) {
        perror("File open error");
        printf("Não leu nem o 1");
        exit(EXIT_FAILURE);
    }

    if (in) {

        int linhaCSV = 0;
        while (!feof(in)) {
            fgets(buf, sizeof (buf), in);
            tabelaInput = (linhainput) realloc(tabelaInput, ((1 + linhaCSV) * sizeof (int)*NRCELLSINPUT));
            char *texto = strtok(buf, ",");
            tabelaInput[linhaCSV].numInput[0] = atoi(texto);

            int i = 0;

            for (i = 1; i < NRCELLSINPUT; i++) {
                texto = strtok(NULL, ",");
                tabelaInput[linhaCSV].numInput[i] = atoi(texto);
            }
            linhaCSV++;
        }

        if (ferror(in)) {
        }
        fclose(in);
    }
    printf("\nUm dos valores da tabela de input é %d", tabelaInput[1].numInput[2]);


    //</editor-fold>

    // <editor-fold defaultstate="collapsed" desc=" Prencher rules ">

#define NRCELLSRULES 11
    int nrRules = 0;
    
    struct linhaRule *tabelaRules;


    tabelaRules = (linhaRule) malloc(sizeof (linhaRule));



    FILE *rule = fopen("nome_ficheiro_rules.csv", "r");

    if (rule == NULL) {
        perror("File open error");
        printf("nao leu o 2");
        exit(EXIT_FAILURE);
    }
    
    if (rule) {
        nrRules =0;
        while (!feof(rule)) {
            fgets(buf, sizeof (buf), rule);
            tabelaRules = (linhaRule) realloc(tabelaRules, ((1 + nrRules) * sizeof (int)*NRCELLSRULES));
            char *texto = strtok(buf, ",");
            tabelaRules[nrRules].numRule[0] = atoi(texto);
            int i = 0;

            for (i = 1; i < NRCELLSRULES; i++) {
                texto = strtok(NULL, ",");
                tabelaRules[nrRules].numRule[i] = atoi(texto);
            }
            nrRules++;
        }

        if (ferror(rule)) {
        }

        fclose(rule);
    }
    printf("\nUm dos valores da tabela de rules é %d", tabelaRules[1].numRule[0]);
    // </editor-fold>

    printf("cheguei!! \n");
    qsort(tabelaRules, 4, sizeof (struct linhaRule), (compfn)compare);
    
    int d = nrRules;
    int j;
    int x;
    for(x = 0; x < 4;x++){
        for(j = 0; j < 11; j++){
            if(tabelaRules[x].numRule[j]!= 0){
		printf("ordena: %d \n", tabelaRules[x].numRule[j]);
            }
        }
    }
    
    printf("sizeof: %d \n",d);
    
    int u;
    int z;
    int i;
    int y;
    
/*
    for(u = 0; u < sizeof(tabelaInput)/sizeof(int); u++){
		for(z = 0; z < NRCELLSINPUT;z++){
			for(i = 0; i < sizeof(tabelaRules)/sizeof(int);i++){
				for(y = 0; y < NRCELLSRULES;y++){
					if(tabelaInput->numInput[z] == tabelaRules->numRule[y] || tabelaInput->numInput[i] == 0 || tabelaRules->numRule[y] == 0){
						if(z == NRCELLSINPUT -1){
							// escrever no ficheiro de saida a linha + o último caracter da regra e continuar
						}
						else {
							z++;
						}	
					}
					else{
						z = 0;
						y = NRCELLSRULES;
					}
				}
			}			
		}
	} 
*/
    
    // <editor-fold defaultstate="collapsed" desc="Libertar memória">
    free(tabelaRules);
    free(tabelaInput);
    // </editor-fold>

    return 0;
}

void preencherInstancias() {

}

void preencherRules() {

}