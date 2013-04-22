#include <stdio.h>
#include <stdlib.h>


typedef struct linhainput{
	int numInput[10];
}*linhainput;

typedef struct Tabelainput{
	linhainput table[10000000];
}*Tabelainput;

typedef struct linhaRule{
	int numRule[11];
}*linhaRule;

typedef struct TabelaRule{
	linhaRule tablerule[2000000];
}*TabelaRule;
