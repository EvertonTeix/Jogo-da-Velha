//faça um programa para jogar o jogo da velha. Ao final, imprima o resultado do jogo
//e pergunte se o jogador deseja jogar novamente.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(0, "Portuguese");

    char mat[3][3];
    int linha, coluna, jogador, ganhou, jogadas, opcao;

    do{
        jogador = 1, ganhou = 0, jogadas = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mat[i][j] = ' ';
            }
        }

        do{

            printf("\n\n\t0    1    2\n\n");

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){

                if(j == 0)
                    printf("\t");

                printf(" %c ", mat[i][j]);

                if(j < 2)
                    printf("|");

                if(j == 2)
                    printf("   %d", i);
            }

            if(i < 2){
                printf("\n\t------------");
                printf("\n");
            }
        }

        printf("\n");

                do{

                    printf("\nJOGADOR %d: Digite a linha e a coluna, respectivamente (Ex.: 1 2): ", jogador);
                    scanf("%d%d", &linha, &coluna);

                }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || mat[linha][coluna] != ' ');


            if(jogador == 1){
                mat[linha][coluna] = 'O';
                jogador++;

            }else{

                mat[linha][coluna] = 'X';
                jogador = 1;
            }

            jogadas++;

            if((mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O')||
               (mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O')||
               (mat[2][0] == 'O' && mat[2][1] == 'O' && mat[2][2] == 'O')){

                printf("\nPARABENS! Jogador 1 venceu por linha.\n");
                ganhou = 1;
            }

            if((mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X')||
               (mat[1][0] == 'X' && mat[1][1] == 'X' && mat[1][2] == 'X')||
               (mat[2][0] == 'X' && mat[2][1] == 'X' && mat[2][2] == 'X')){

                printf("\nPARABENS! Jogador 2 venceu por linha.\n");
                ganhou = 1;
            }

            if((mat[0][0] == 'O' && mat[1][0] == 'O' && mat[2][0] == 'O')||
               (mat[0][1] == 'O' && mat[1][1] == 'O' && mat[2][1] == 'O')||
               (mat[0][2] == 'O' && mat[1][2] == 'O' && mat[2][2] == 'O')){

                printf("\nPARABENS! Jogador 1 venceu por coluna.\n");
                ganhou = 1;
            }

            if((mat[0][0] == 'X' && mat[1][0] == 'X' && mat[2][0] == 'X')||
               (mat[0][1] == 'X' && mat[1][1] == 'X' && mat[2][1] == 'X')||
               (mat[0][2] == 'X' && mat[1][2] == 'X' && mat[2][2] == 'X')){

                printf("\nPARABENS! Jogador 2 venceu por coluna.\n");
                ganhou = 1;
            }

            if(mat[0][0] == 'O' && mat[1][1] == 'O' && mat[2][2] == 'O'){
                printf("\nPARABENS! Jogador 1 venceu pela diagonal principal.\n");
                ganhou = 1;
            }

            if(mat[0][0] == 'X' && mat[1][1] == 'X' && mat[2][2] == 'X'){
                printf("\nPARABENS! Jogador 2 venceu pela diagonal principal.\n");
                ganhou = 1;
            }

            if(mat[0][2] == 'O' && mat[1][1] == 'O' && mat[2][0] == 'O'){
                printf("\nPARABENS! Jogador 1 venceu pela diagonal secundária.\n");
                ganhou = 1;
            }

            if(mat[0][2] == 'X' && mat[1][1] == 'X' && mat[2][0] == 'X'){
                printf("\nPARABENS! Jogador 2 venceu pela diagonal secundária.\n");
                ganhou = 1;
            }

        }while(ganhou == 0 && jogadas < 9);

        if(ganhou == 0){
            printf("\nO jogo finalizou sem ganhador!\n");
        }

        printf("\nDIGITE 1 PARA JOGAR NOVAMENTE: \n");
        scanf("%d", &opcao);

    }while(opcao == 1);

    return 0;
}
