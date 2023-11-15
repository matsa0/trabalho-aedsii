#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Usuario {
    int id;
    char user[30];
    char senha[20];
    char nome[30];
} TUsuario;

//cria usuario
TUsuario *usuario(int id, char *senha, char *nome);

// Retorna um ponteiro para o usuario lido do arquivo
TUsuario *leUsuario(FILE* in);

//salva playlist
void salvaUsuario(TUsuario *usuario, FILE *out);

// Cria a base de dados desordenada
void criarBaseDesordenadaUsuario(FILE *out, int tam);

// Cria a base de dados ordenada
void criarBaseOrdenadaUsuario(FILE *out, int tam);

//imprime usuarios
void imprimeUsuario(TUsuario* usuario);

// Imprime a base de dados
void imprimirBaseUsuario(FILE *out);

//escrever a busca sequencial no log
void logBuscaSequencialUsuario(FILE* out, int count, clock_t start_time);

//busca sequencial sobre a base
TUsuario *buscaSequencialUsuario(int chave, FILE *in, FILE* out);

//escrever a busca binária no log
void logBuscaBinariaUsuario(FILE* out, int count, clock_t start_time);

//busca binária sobre a base
TUsuario *buscaBinariaUsuario(int chave, FILE *in, FILE *out, int inicio, int fim);

//Retorna o tamnanho da review em bytes
int tamanhoRegistroUsuario();

#endif // USUARIO_H_INCLUDED
