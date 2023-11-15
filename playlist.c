#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "playlist.h"
#include "shuffle.h"

//Retorna o tamanho da playlist em bytes
int tamanhoRegistroPlaylist() {
    return sizeof(int)  //id
           + sizeof(char) * 100 //nome
           + sizeof(char) * 200; //descrição
}

//cria playlist
TPlaylist *playlist(int id, char *nome, char *descricao) {
    TPlaylist *playlist = (TPlaylist *) malloc(sizeof(TPlaylist));
    //inicializa espaco de memoria com ZEROS
    if (playlist) memset(playlist, 0, sizeof(TPlaylist));
    //copia valores para os campos de func
    playlist->id = id;
    strcpy(playlist->nome, nome); //usado para copiar as strings
    strcpy(playlist->descricao, descricao);
    return playlist;
}

// Retorna um ponteiro para a playlist lida do arquivo
TPlaylist *lePlaylist(FILE* in) {
    TPlaylist *playlist = (TPlaylist *) malloc(sizeof(TPlaylist));
    //O valor retornado por fread é comparado com zero para verificar se a leitura foi bem-sucedida. Se não for, a função libera a memória alocada para a playlist
    if (0 >= fread(&playlist->id, sizeof(int), 1, in)) {
        free(playlist);
        return NULL;
    }
    fread(playlist->nome, sizeof(char), sizeof(playlist->nome), in);
    fread(playlist->descricao, sizeof(char), sizeof(playlist->descricao), in);
    return playlist;
}

//salva playlist no arquivo out
void salvaPlaylist(TPlaylist *playlist, FILE *out) {
    fwrite(&playlist->id, sizeof(int), 1, out); //dado que vai escrever no arquivo, tamanho em bytes do tipo do dado, número de elementos a ser escrito, arquivo
    fwrite(playlist->nome, sizeof(char), sizeof(playlist->nome), out);
    fwrite(playlist->descricao, sizeof(char), sizeof(playlist->descricao), out);
}

// Cria a base de dados desordenada
void criarBaseDesordenadaPlaylist(FILE *out, int tam) {
    int vet[tam];
    TPlaylist *play;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    shuffle(vet, tam, 0);

    printf("\n\nGerando a base de dados DESORDENADA de PLAYLIST...\n");

    for (int i=0;i<tam;i++){
        play = playlist(vet[i], "Hits internacionais", "As melhores e mais ouvidas musicas internacionais do momento!");
        salvaPlaylist(play, out);
    }

    free(play);
}

// Cria a base de dados ordenada
void criarBaseOrdenadaPlaylist(FILE *out, int tam) {
    int vet[tam];
    TPlaylist *play;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    printf("\n\nGerando a base de dados ORDENADA de PLAYLIST...\n");

    for (int i=0;i<tam;i++){
        play = playlist(vet[i], "Hits Brasil", "As mais ouvidas musicas brasileiras de novembro!");
        salvaPlaylist(play, out);
    }

    free(play);
}

// Imprime playlist
void imprimePlaylist(TPlaylist *playlist) {
    printf("**********************************************");
    printf("\nID Playlist > %d", playlist->id);
    printf("\nNome > %s", playlist->nome);
    printf("\nDescricao > %s", playlist->descricao);
    printf("\n**********************************************");
}

// Imprime a base de dados
void imprimirBasePlaylist(FILE *out) {
    printf("\nImprimindo a base de dados PLAYLIST...\n");

    rewind(out);
    TPlaylist *playlist;

    while ((playlist = lePlaylist(out)) != NULL)
        imprimePlaylist(playlist);

    free(playlist);
}

//escrever a busca sequencial no log
void logBuscaSequencialPlaylist(FILE* out, int count, clock_t start_time) {
    sleep(1);
    clock_t end_time = clock();
    fprintf(out, "\n------------------------------");
    fprintf(out, "\nBusca sequencial PLAYLIST");
    fprintf(out, "\nNumero de comparações > %d", count);
    fprintf(out, "\nTempo de Busca > %.2f segundos", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    fprintf(out, "\n------------------------------");
    fprintf(out, "\n");
}

//busca sequencial sobre a base
TPlaylist *buscaSequencialPlaylist(int chave, FILE *in, FILE* out) {
    TPlaylist *playlist;
    int achou = 0;
    rewind(in);
    int count = 0;
    clock_t start_time = clock();

    while ((playlist = lePlaylist(in)) != NULL){
        if(playlist->id == chave){
           //return f;
           achou = 1;
           break;
        }
        count++;
    }

    if(achou == 1) {
        logBuscaSequencialPlaylist(out, count, start_time);
        return playlist;
    }
    else {
        printf("ERRO! PLAYLIST nao encontrada.");
        logBuscaSequencialPlaylist(out, count, start_time);
    }


    free(playlist);
    return NULL;
}

//escrever a busca binária no log
void logBuscaBinariaPlaylist(FILE* out, int count, clock_t start_time) {
    sleep(1);
    clock_t end_time = clock();
    fprintf(out, "\n------------------------------");
    fprintf(out, "\nBusca binária PLAYLIST");
    fprintf(out, "\nNumero de comparações > %d", count);
    fprintf(out, "\nTempo de Busca > %.2f segundos", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    fprintf(out, "\n------------------------------");
    fprintf(out, "\n");
}

//busca binária sobre a base
TPlaylist *buscaBinariaPlaylist(int chave, FILE *in, FILE *out, int inicio, int fim) {
    TPlaylist *playlist = NULL;
    int cod = -1;
    int count = 0;
    clock_t start_time;
    start_time = clock();

    while (inicio <= fim && cod != chave) {
        int meio = trunc((inicio + fim) / 2);
        //printf("\nInicio: %d; Fim: %d; Meio: %d\n", inicio, fim, meio);
        fseek(in, (meio -1) * tamanhoRegistroPlaylist(), SEEK_SET);
        playlist = lePlaylist(in);
        cod = &playlist->id;

        if (playlist) {
            if (cod > chave) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }

        count++;
    }

    if (cod == chave) {
        logBuscaBinariaPlaylist(out, count, start_time);
        return playlist;
    }

    logBuscaBinariaPlaylist(out, count, start_time);

    return NULL;
}
