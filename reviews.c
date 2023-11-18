#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include "reviews.h"
#include "shuffle.h"

//Retorna o tamnanho da review em bytes
int tamanhoRegistroReviews() {
    return sizeof(int) +
           sizeof(char) * 200;
}

//cria review
TReviews *reviews(int id, char *comentario) {
    TReviews *reviews = (TReviews *) malloc(sizeof(TReviews));
    if (reviews) memset(reviews, 0, sizeof(TReviews));
    reviews->id = id;
    strcpy(reviews->comentario, comentario);
    return reviews;
}

// Retorna um ponteiro para o review lido do arquivo
TReviews *leReviews(FILE* in) {
    TReviews *reviews = (TReviews *) malloc(sizeof(TReviews));
    if (0 >= fread(&reviews->id, sizeof(int), 1, in)) {
        free(reviews);
        return NULL;
    }
    fread(reviews->comentario, sizeof(char), sizeof(reviews->comentario), in);
    return reviews;
}

//salva playlist
void salvaReviews(TReviews *reviews, FILE *out) {
    fwrite(&reviews->id, sizeof(int), 1, out);
    fwrite(reviews->comentario, sizeof(char), sizeof(reviews->comentario), out);
}

// Cria a base de dados desordenada
void criarBaseDesordenadaReviews(FILE *out, int tam) {
    int vet[tam];
    TReviews *review;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    shuffle(vet, tam, 0);

    printf("\n\nGerando a base de dados DESORDENADA de REVIEWS...\n");

    for (int i=0;i<tam;i++){
        review = reviews(vet[i], "“Locked Out of Heaven” finds Mars borrowing heavily from the ’80s, thanks...");
        salvaReviews(review, out);
    }

    free(review);
}

// Cria a base de dados ordenada
void criarBaseOrdenadaReviews(FILE *out, int tam) {
    int vet[tam];
    TReviews *review;

    for(int i=0;i<tam;i++)
        vet[i] = i+1;

    printf("\n\nGerando a base de dados ORDENADA de REVIEWS...\n");

    for (int i=0;i<tam;i++){
        review = reviews(vet[i], "Musica com uma linda letra e ritmo cativante!");
        salvaReviews(review, out);
    }

    free(review);
}

// Imprime review
void imprimeReviews(TReviews *reviews) {
    printf("**********************************************");
    printf("\nID Review > %d", reviews->id);
    printf("\nComentario > %s", reviews->comentario);
    printf("\n**********************************************");
}

// Imprime a base de dados
void imprimirBaseReviews(FILE *out) {
    printf("\nImprimindo a base de dados REVIEWS...\n");

    rewind(out);
    TReviews *reviews;

    while ((reviews = leReviews(out)) != NULL) {
        imprimeReviews(reviews);
    }
    free(reviews);

}

//escrever a busca sequencial no log
void logBuscaSequencialReviews(FILE* out, int count, clock_t start_time) {
    sleep(1);
    clock_t end_time = clock();
    fprintf(out, "\n------------------------------");
    fprintf(out, "\nBusca sequencial REVIEWS");
    fprintf(out, "\nNumero de comparações > %d", count);
    fprintf(out, "\nTempo de Busca > %.2f segundos", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    fprintf(out, "\n------------------------------");
    fprintf(out, "\n");
}

//busca sequencial sobre a base
TReviews *buscaSequencialReviews(int chave, FILE *in, FILE* out) {
    TReviews *reviews;
    int achou = 0;
    rewind(in);
    int count = 0;
    clock_t start_time = clock();

    while ((reviews = leReviews(in)) != NULL){
        if(reviews->id == chave){
           achou = 1;
           break;
        }
        count++;
    }

    if(achou == 1) {
        logBuscaSequencialReviews(out, count, start_time);
        return playlist;
    }
    else {
        printf("ERRO! REVIEW nao encontrado.");
        logBuscaSequencialReviews(out, count, start_time);
    }


    free(reviews);
    return NULL;
}

//escrever a busca binária no log
void logBuscaBinariaReviews(FILE* out, int count, clock_t start_time) {
    sleep(1);
    clock_t end_time = clock();
    fprintf(out, "\n------------------------------");
    fprintf(out, "\nBusca binária REVIEWS");
    fprintf(out, "\nNumero de comparações > %d", count);
    fprintf(out, "\nTempo de Busca > %.2f segundos", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    fprintf(out, "\n------------------------------");
    fprintf(out, "\n");
}

//busca binária sobre a base
TReviews *buscaBinariaReviews(int chave, FILE *in, FILE *out, int inicio, int fim) {
    TReviews *reviews = NULL;
    int cod = -1;
    int count = 0;
    clock_t start_time;
    start_time = clock();

    while (inicio <= fim && cod != chave) {
        int meio = trunc((inicio + fim) / 2);
        //printf("\nInicio: %d; Fim: %d; Meio: %d\n", inicio, fim, meio);
        fseek(in, (meio -1) * tamanhoRegistroReviews(), SEEK_SET);
        reviews = leReviews(in);
        cod = &reviews->id;

        if (reviews) {
            if (cod > chave) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }

        count++;
    }

    if (cod == chave) {
        logBuscaBinariaReviews(out, count, start_time);
        return reviews;
    }

    logBuscaBinariaReviews(out, count, start_time);

    return NULL;
}

