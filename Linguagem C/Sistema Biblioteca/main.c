#include <stdio.h>
#include <string.h>

//Definição da struct Territorio para agrupar os dados
struct Territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

int main(){

    struct Territorio mapa[5];    

    int i;

    printf("=== SISTEMA DE CADASTRO DE TERRITORIO ===\n\n");

    //loop para ler os dados do territorio
    for(i = 0; i < 5; i++){
        printf("Cadastro do territorio %d:\n", i + 1);
        printf("Digite o nome do territorio: ");
        scanf(" %29[^\n]", mapa[i].nome);

        printf("Digite a cor do exercito: ");
        scanf(" %9s", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);

        printf("----------------------\n");
        }

        printf("\n\n=== RESUMO DOS TERRITORIOS ===\n");
        for(i = 0; i < 5; i++){
            printf("Territorio %d: %s | Cor: %s | Tropas: %d\n",
            i+1,
            mapa[i].nome,
            mapa[i].cor,
            mapa[i].tropas
            );
        }
        return 0;
};


