//Projeto pessoal para reforçar a logica, não foi passado pela faculdade!

#include <stdio.h>
#include <string.h>

struct Heroi
{
    char nome[30];
    char classe[20];
    int nivel;
};

int main(){
    struct Heroi novos[3];
    int i;

    char busca[20];

    printf("CADASTRO DE HEROIS! \n");
    printf("Escolha seu nome, sua classe (Ex: Mago, Guerreiro ou Arqueiro \n");

    for(i = 0; i < 3; i++){
        printf("DIGITE O NOME DO SEU HEROI %d: ", i + 1);
        scanf(" %29[^\n]", novos[i].nome);

        printf("DIGITE O NOME DA SUA CLASSE: ");
        scanf(" %19s", novos[i].classe);

        printf("NIVEL DE SEU HEROI: ");
        scanf("%d", &novos[i].nivel);

        printf("-------------------------------\n");
    }

    printf("RESUMO\n");
    for(i = 0; i < 3; i++){
        printf("NOME %d: %s | CLASSE: %s | NIVEL: %d\n ",
        i+1,
        novos[i].nome,
        novos[i].classe,
        novos[i].nivel
        );

    }

    printf("\n=== Sistema de busca ===\n");    
    printf("Qual classe deseja filtar? ");
    scanf(" %19s", busca);

    printf("\nProcurando por seu heroi da classe '%s'...\n", busca);
    printf("------------------------------------");

    int encontrou = 0;

    for(i = 0; i < 3; i++){
        
        if(strcmp(novos[i].classe, busca) == 0){
            printf("ACHEI -> Nome: %s | Nivel %d\n",
            novos[i].nome,
            novos[i].nivel
            );
            encontrou = 1;
            /*"Se ( if ) o crachá do herói atual (novos[i].classe) 
        comparado com o que eu procuro (busca) 
        tiver zero diferenças (== 0), então..."*/
        }
        }
        if(encontrou == 0){
            printf("Nenhum heroi dessa classe foi encontrado. \n");
    }

    return 0;
};