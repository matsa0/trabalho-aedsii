#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Playlist {
    int id;
    char nome[100];
    char descricao[200];
} TPlaylist;

//cria playlist
TPlaylist *playlist(int id, char *nome, char *descricao);

// Retorna um ponteiro para a playlist lida do arquivo
TPlaylist *lePlaylist(FILE* in);

//salva playlist
void salvaPlaylist(TPlaylist *playlist, FILE *out);

// Cria a base de dados desordenada
void criarBaseDesordenadaPlaylist(FILE *out, int tam);

// Cria a base de dados ordenada
void criarBaseOrdenadaPlaylist(FILE *out, int tam);

// Imprime playlist
void imprimePlaylist(TPlaylist *playlist);

// Imprime a base de dados
void imprimirBasePlaylist(FILE *out);

//escrever a busca sequencial no log
void logBuscaSequencialPlaylist(FILE* out, int count, clock_t start_time);

//busca sequencial sobre a base
TPlaylist *buscaSequencialPlaylist(int chave, FILE *in, FILE* out);

//escrever a busca binária no log
void logBuscaBinariaPlaylist(FILE* out, int count, clock_t start_time);

//busca binária sobre a base
TPlaylist *buscaBinariaPlaylist(int chave, FILE *in, FILE *out, int inicio, int fim);

//Retorna o tamnanho da playlist em bytes
int tamanhoRegistroPlaylist();


#endif // PLAYLIST_H_INCLUDED
