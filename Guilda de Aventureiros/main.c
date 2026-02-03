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
    return 0;
};