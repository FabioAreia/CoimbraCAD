#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rule.h"


int i;
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
/*int compare(struct linhainput *elem1, struct linhainput *elem2){
    int diff1 = (elem1->numInput[0] > elem2->numInput[0]) - (elem1->numInput[0] - elem2->numInput[0]);
    if(diff1 != 0) return diff1;
    return ((elem1->numInput[1] > elem1->numInput[1]) - (elem1->numInput[1] < elem2->numInput[1]));
}*/


int main(int argc, char *argv[]) {

#define CHUNK 1024 /* read 1024 bytes at a time */
#define NRCELLSINPUT 10
#define NRCELLSRULES 11
    
    struct linhainput tabela[100000];
    struct linhaRule tabelaRules[20000];


    char buf[CHUNK];
    size_t nread;
    char texto[CHUNK];

    char string1[CHUNK];
    int blocoin[10];
    int blocorule[11];

    FILE *in = fopen("nome_ficheiro_input.csv", "r");
    FILE *rule = fopen("nome_ficheiro_rules.csv", "r");


    if (in == NULL) {
        perror("File open error");
        printf("Não leu nem o 1");
        exit(EXIT_FAILURE);
    }

    if (rule == NULL) {
        perror("File open error");
        printf("nao leu o 2");
        exit(EXIT_FAILURE);
    }


    /*
        if (in) {
            while ((nread = fread(buf, 1, sizeof buf, in)) > 0)
                fwrite(buf, 1, nread, stdout);
            if (ferror(in)) {
            }
            printf("\n");
            fclose(in);
        }
     */


    if (in) {
        int linhaCSV = 0;
        while (!feof(in)) {
            fgets(buf, sizeof (buf), in);
            char *texto = strtok(buf, ",");

            printf(texto);
            printf("\n");
            blocoin[0] = atoi(texto);
            tabela[linhaCSV].numInput[0] = atoi(texto);

            int i = 0;

            for (i = 1; i < NRCELLSINPUT; i++) {
                texto = strtok(NULL, ",");
                printf(texto);
                tabela[linhaCSV].numInput[i] = atoi(texto);
                printf("\n");
            }
            linhaCSV++;
        }

        if (ferror(in)) {
        }
        /*
                printf("\n");
         */
        fclose(in);
    }

    if (rule) {
        int linhaCSV = 0;
        while (!feof(rule)) {
            fgets(buf, sizeof (buf), rule);
            char *texto = strtok(buf, ",");
            
            printf(texto);
            printf("\n");

            tabelaRules[linhaCSV].numRule[0] = atoi(texto);
            int i = 0;

            for (i = 1; i < NRCELLSRULES; i++) {
                texto = strtok(NULL, ",");
                printf(texto);
                tabelaRules[linhaCSV].numRule[i] = atoi(texto);
                printf("\n");
            }
            linhaCSV++;

        }
        
                if (ferror(in)) {
        }
        /*
                printf("\n");
         */


        fclose(rule);
    }
    printf("cheguei!! \n");
    qsort(tabelaRules, 3, sizeof (linhaRule), (compfn)compare);
    
    int j;
    int x;
    for(x = 0; x < 20001;x++){
        for(j = 0; j < 11; j++){
                if(tabelaRules[x].numRule[j]!= 0){
			printf("ordena: %d \n", tabelaRules[x].numRule[j]);
		}
        }
    }

	
	
	/*for(int u = 0; u < sizeof(tabela); u++){
		for(int i; i < sizeof(tabelaRules);i++){
			for(int z = 0; z < NRCELLSINPUT;z++){
				for(int y = 0; y < NRCELLSRULES;y++){
					if(linhainput[z] == linhaRule[y] || linhainput[i] == 0 || linhaRule[y] == 0){
						if(z == NRCELLSINPUT){
							// escrever no ficheiro de saida a linha + o último caracter da regra e continuar
						}
						else {
							z++;
						}	
					}
					else{
						z = 0;
						y = sizeof(linhaRule);
					}
				}
			}			
		}
	} */
    


    //printf("\nUm dos valores da tabela de input é %d", tabela[0].numInput[1]);
    //printf("\nUm dos valores da tabela de rules é %d", tabelaRules[1].numRule[4]);

    return 0;
}


