//Projeto novo da faculdade

#include <string.h>
#include <stdio.h>


struct Carta
{
    char estado;
    char codigo[4];
    char cidade[50];
    char populacao;
    char area;
    char pib;
    char pontosTuristicos;
};


int main(){
    struct Carta carta1;
    struct Carta carta2;

    printf("Cadastro da Carta 1\n");

    printf("Estado: ");
    scanf(" %c", &carta1.estado);

    printf("Codigo: ");
    scanf("%s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area: ");
    scanf("%f", &carta1.area);

    printf("PIB: ");
    scanf("%f", &carta1.pib);

    printf("Pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

}