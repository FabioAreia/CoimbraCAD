#include <stdio.h>
#include <stdlib.h>


typedef struct linhainput{
	int numInput[10];
}*linhainput;

typedef struct Tabelainput{
	linhainput table[10000000];
}*Tabelainput;

typedef struct ruleinput{
	int numRule[11];
}*ruleinput;

typedef struct TabelaRule{
	ruleinput tablerule[2000000];
}*TabelaRule;