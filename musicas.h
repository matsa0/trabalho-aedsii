#ifndef MUSICAS_H_INCLUDED
#define MUSICAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Musicas {
    int id;
    //char anoLancamento[10];
    char titulo[50];
    char estilo[20];
    char artista[30];
} TMusicas;

//cria musica
TMusicas *musicas(int id, char *titulo, char *estilo, char *artista);

// Retorna um ponteiro para a musica lida do arquivo
TMusicas *leMusicas(FILE* in);

//salva playlist
void salvaMusicas(TMusicas *musicas, FILE *out);

// Cria a base de dados desordenada
void criarBaseDesordenadaMusicas(FILE *out, int tam);

// Cria a base de dados ordenada
void criarBaseOrdenadaMusicas(FILE* out, int tam);

// Imprime musicas
void imprimeMusicas(TMusicas *musicas);

// Imprime a base de dados
void imprimirBaseMusicas(FILE *out);

//escrever a busca sequencial no log
void logBuscaSequencialMusicas(FILE* out, int count, clock_t start_time);

//busca sequencial sobre a base
TMusicas *buscaSequencialMusicas(int chave, FILE *in, FILE* out);

//escrever a busca binária no log
void logBuscaBinariaPlaylist(FILE* out, int count, clock_t start_time);

//busca binária sobre a base
TMusicas *buscaBinariaMusicas(int chave, FILE *in, FILE *out, int inicio, int fim);

//Retorna o tamnanho da playlist em bytes
int tamanhoRegistroMusicas();

#endif // MUSICAS_H_INCLUDED
