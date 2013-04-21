#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rule.h"


Tabelainput tabela;
int i;

int main(int argc, char *argv[]) {

#define CHUNK 1024 /* read 1024 bytes at a time */
    char buf[CHUNK];
    size_t nread;
    char texto[CHUNK];

    char string1[CHUNK];
    int blocoin[10];
    int blocorule[11];
    
    Tabelainput tabelainput;

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
        while(!feof(in)){
        fgets(buf, sizeof (buf), in);
        char *texto = strtok(buf, ",");
        printf(texto);
        blocoin[0]=atoi(texto);
        printf("\n");
        texto = strtok(NULL, ",");
        printf(texto);
        printf("\n");
        texto = strtok(NULL, ",");
        printf(texto);
        }

        if (ferror(in)) {
        }
        printf("\n");
        fclose(in);
    }

    if (rule) {
        while ((nread = fread(buf, 1, sizeof buf, rule)) > 0)
            fwrite(buf, 1, nread, stdout);
        if (ferror(rule)) {
        }
        fclose(rule);
    }



    printf("\nO blocoin tem o valor %d" ,blocoin[0]);
    
    return 0;
}


