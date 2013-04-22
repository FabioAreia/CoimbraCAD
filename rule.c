#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rule.h"


Tabelainput tabela;
int i;

int main(int argc, char *argv[]) {

#define CHUNK 1024 /* read 1024 bytes at a time */
#define NRCELLSINPUT 10
#define NRCELLSRULES 11

    char buf[CHUNK];
    size_t nread;
    char texto[CHUNK];

    char string1[CHUNK];
    int blocoin[10];
    int blocorule[11];

    struct linhainput tabela[100000];
    struct linhaRule tabelaRules[20000];

    FILE *in = fopen("trans_day_0.csv", "r");
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


    printf("\nUm dos valores da tabela de input é %d", tabela[3].numInput[2]);
    printf("\nUm dos valores da tabela de rules é %d", tabelaRules[0].numRule[4]);

    return 0;
}


