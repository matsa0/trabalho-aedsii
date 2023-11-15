#ifndef REVIEWS_H_INCLUDED
#define REVIEWS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Reviews {
    int id;
    char comentario[200];
} TReviews;

//cria review
TReviews *reviews(int id, char *comentario);

// Retorna um ponteiro para o review lido do arquivo
TReviews *leReviews(FILE* in);

//salva playlist
void salvaReviews(TReviews *reviews, FILE *out);

// Cria a base de dados desordenada
void criarBaseDesordenadaReviews(FILE *out, int tam);

// Cria a base de dados ordenada
void criarBaseOrdenadaReviews(FILE *out, int tam);

// Imprime review
void imprimeReviews(TReviews *reviews);

// Imprime a base de dados
void imprimirBaseReviews(FILE *out);

//escrever a busca sequencial no log
void logBuscaSequencialReviews(FILE* out, int count, clock_t start_time);

//busca sequencial sobre a base
TReviews *buscaSequencialReviews(int chave, FILE *in, FILE* out);

//escrever a busca binária no log
void logBuscaBinariaReviews(FILE* out, int count, clock_t start_time);

//busca binária sobre a base
TReviews *buscaBinariaReviews(int chave, FILE *in, FILE *out, int inicio, int fim);

//Retorna o tamnanho da review em bytes
int tamanhoRegistroReviews();
#endif // REVIEWS_H_INCLUDED
