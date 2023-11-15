#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shuffle.c"
#include "playlist.c"
#include "usuario.c"
#include "reviews.c"
#include "musicas.c"

int main()
{
    char imprimir;
    FILE *log;
    FILE *arqPlaylist;

    if((log = fopen("log.txt", "w")) == NULL) {
        printf("ERRO! Não foi possível abrir o LOG!\n");
        exit(1);
    }
    else {
        if((arqPlaylist = fopen("playlist.dat", "w+b")) == NULL) {
            printf("ERRO! Nao foi possivel encontrar o arquivo PLAYLIST!");
            exit(1);
        }
        //BASES DESORDENADAS E ORDENADAS DE PLAYLIST
        else {
            //BASE DE DADOS DESORDENADA
            criarBaseDesordenadaPlaylist(arqPlaylist, 50000);
            printf("Base DESORDENADA(50.000) de PLAYLIST criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBasePlaylist(arqPlaylist);
            }

            fprintf(log, "***Base de dados DESORDENADA (50.000) de PLAYLIST***");
            buscaSequencialPlaylist(47564, arqPlaylist, log);

            fclose(arqPlaylist);
            fflush(stdin);


            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqPlaylist = fopen("playlist.dat", "w+b");

            criarBaseDesordenadaPlaylist(arqPlaylist, 100000);
            printf("Base DESORDENADA(100.000) de PLAYLIST criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBasePlaylist(arqPlaylist);
            }

            fprintf(log, "\n***Base de dados DESORDENADA (100.000) de PLAYLIST***");
            buscaSequencialPlaylist(76894, arqPlaylist, log);

            fclose(arqPlaylist);
            fflush(stdin);


            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqPlaylist = fopen("playlist.dat", "w+b");

            criarBaseDesordenadaPlaylist(arqPlaylist, 500000);
            printf("Base DESORDENADA(500.000) de PLAYLIST criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBasePlaylist(arqPlaylist);
            }

            fprintf(log, "\n***Base de dados DESORDENADA (500.000) de PLAYLIST***");
            buscaSequencialPlaylist(360541, arqPlaylist, log);

            fclose(arqPlaylist);
            fflush(stdin);


            //BASES ORDENADAS DE PLAYLIST
            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqPlaylist = fopen("playlist.dat", "w+b");

            criarBaseOrdenadaPlaylist(arqPlaylist, 50000);
            printf("Base ORDENADA(50.000) de PLAYLIST criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBasePlaylist(arqPlaylist);
            }

            fprintf(log, "\n***Base de dados ORDENADA (50.000) de PLAYLIST***");
            buscaBinariaPlaylist(47564, arqPlaylist, log, 0, 49999);

            fclose(arqPlaylist);
            fflush(stdin);


            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqPlaylist = fopen("playlist.dat", "w+b");

            criarBaseOrdenadaPlaylist(arqPlaylist, 100000);
            printf("Base ORDENADA(100.000) de PLAYLIST criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBasePlaylist(arqPlaylist);
            }

            fprintf(log, "\n***Base de dados ORDENADA (100.000) de PLAYLIST***");
            buscaBinariaPlaylist(76894, arqPlaylist, log, 0, 99999);

            fclose(arqPlaylist);
            fflush(stdin);


            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqPlaylist = fopen("playlist.dat", "w+b");

            criarBaseOrdenadaPlaylist(arqPlaylist, 500000);
            printf("Base ORDENADA(500.000) de PLAYLIST criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBasePlaylist(arqPlaylist);
            }

            fprintf(log, "\n***Base de dados ORDENADA (500.000) de PLAYLIST***");
            buscaBinariaPlaylist(360541, arqPlaylist, log, 0, 499999);

            fclose(arqPlaylist);
            fflush(stdin);
        }




        fflush(stdin);
        printf("\n\n");
        FILE *arqMusicas;




        //BASES DESORDENADAS E ORDENADAS DE MUSICAS
        if((arqMusicas = fopen("musicas.dat", "w+b")) == NULL) {
            printf("ERRO! Nao foi possivel encontrar o arquivo MUSICAS!");
            exit(1);
        }
        else {
            // BASE DE DADOS DESORDENADA
            criarBaseDesordenadaMusicas(arqMusicas, 50000);

            printf("Base DESORDENADA(50.000) de MUSICAS criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseMusicas(arqMusicas);
            }
            fprintf(log, "\n/////////////////////////////////////////////////////////////////////////////");
            fprintf(log, "\n\n***Base de dados DESORDENADA (50.000) de MUSICAS***");
            buscaSequencialMusicas(48561, arqMusicas, log);

            fclose(arqMusicas);
            fflush(stdin);


            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqMusicas = fopen("musicas.dat", "w+b");
            criarBaseDesordenadaMusicas(arqMusicas, 100000);

            printf("Base DESORDENADA(100.000) de MUSICAS criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseMusicas(arqMusicas);
            }

            fprintf(log, "\n\n***Base de dados DESORDENADA (100.000) de MUSICAS***");
            buscaSequencialMusicas(94565, arqMusicas, log);

            fclose(arqMusicas);
            fflush(stdin);


            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqMusicas = fopen("musicas.dat", "w+b");
            criarBaseDesordenadaMusicas(arqMusicas, 500000);

            printf("Base DESORDENADA(500.000) de MUSICAS criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseMusicas(arqMusicas);
            }

            fprintf(log, "\n\n***Base de dados DESORDENADA (500.000) de MUSICAS***");
            buscaSequencialMusicas(475125, arqMusicas, log);

            fclose(arqMusicas);
            fflush(stdin);


            // BASE DE DADOS ORDENADA
            arqMusicas = fopen("musicas.dat", "w+b");
            criarBaseOrdenadaMusicas(arqMusicas, 50000);

            printf("Base ORDENADA(50.000) de MUSICAS criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseMusicas(arqMusicas);
            }

            fprintf(log, "\n\n***Base de dados ORDENADA (50.000) de MUSICAS***");
            buscaSequencialMusicas(48561, arqMusicas, log);

            fclose(arqMusicas);
            fflush(stdin);



            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqMusicas = fopen("musicas.dat", "w+b");
            criarBaseOrdenadaMusicas(arqMusicas, 100000);

            printf("Base ORDENADA(100.000) de MUSICAS criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseMusicas(arqMusicas);
            }

            fprintf(log, "\n\n***Base de dados ORDENADA (100.000) de MUSICAS***");
            buscaSequencialMusicas(94565, arqMusicas, log);

            fclose(arqMusicas);
            fflush(stdin);


            //REABRINDO O ARQUIVO PARA OUTRA BASE DE DADOS
            arqMusicas = fopen("musicas.dat", "w+b");
            criarBaseOrdenadaMusicas(arqMusicas, 500000);

            printf("Base ORDENADA(500.000) de MUSICAS criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseMusicas(arqMusicas);
            }

            fprintf(log, "\n\n***Base de dados ORDENADA (500.000) de MUSICAS***");
            buscaSequencialMusicas(475125, arqMusicas, log);

            fclose(arqMusicas);
            fflush(stdin);
        }



        fflush(stdin);
        printf("\n\n");
        FILE *arqReviews;




        //BASES ORDENADAS E DESORDENADAS DE REVIEWS
        if((arqReviews = fopen("reviews.dat", "w+b")) == NULL) {
            printf("ERRO! Nao foi possivel encontrar o arquivo REVIEWS!");
            exit(1);
        }
        else {
            criarBaseDesordenadaReviews(arqReviews, 10);
            fprintf(log, "\n/////////////////////////////////////////////////////////////////////////////");
            printf("Base DESORDENADA de REVIEWS criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseReviews(arqReviews);
            }
            fclose(arqReviews);
        }



        fflush(stdin);
        printf("\n\n");
        FILE *arqUsuario;




        //BASES ORDENADAS E DESORDENADAS DE USUARIOS
        if((arqUsuario = fopen("usuario.dat", "w+b")) == NULL) {
            printf("ERRO! Nao foi possivel encontrar o arquivo USUARIO!");
            exit(1);
        }
        else {
            criarBaseDesordenadaUsuario(arqUsuario, 10);
            fprintf(log, "\n/////////////////////////////////////////////////////////////////////////////");
            printf("Base DESORDENADA de USUARIO criada, deseja imprimir? (S ou N): ");
            scanf("%c", &imprimir);
            if (imprimir == 's' || imprimir == 'S') {
                imprimirBaseUsuario(arqUsuario);
            }
            fclose(arqUsuario);
        }


        printf("\n\n***RESULTADOS ESCRITOS NO ARQUIVO LOG.TXT***\n");

        fclose(log);
    }

}
