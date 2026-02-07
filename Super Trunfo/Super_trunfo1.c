//Projeto novo da faculdade

#include <stdio.h>

int main(){
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    char populacao1;
    char area1;
    char pib1;
    char pontosTuristicos1;

    char estado2;
    char codigo2[4];
    char nomeCidade[50];
    char populacao2;
    char area2;
    char pib2;
    char pontosTuristicos2;

    printf("=== CADASTRO DA CARTA 1 ===\n");
    
    printf("Digite o Estado (uma letra de A-H): ");
    // O espaço antes do %c serve para limpar o buffer do teclado
    scanf(" %c", &estado1); 
    
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1); // String não precisa do &
    
    printf("Digite o Nome da Cidade: ");
    // O comando " %[^\n]" lê textos com espaços (ex: Sao Paulo) até o usuário apertar Enter
    scanf(" %[^\n]", nomeCidade1);
    
    printf("Digite a Populacao: ");
    scanf("%d", &populacao1);
    
    printf("Digite a Area (em km2): ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib1);
    
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);
}