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
    char nomeCidade2[50];
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

    //CARTA 2

    printf("\n=== CADASTRO DA CARTA 2 ===\n");
    
    printf("Digite o Estado (uma letra de A-H): ");
    scanf(" %c", &estado2); // Lembre-se do espaço antes do %c
    
    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);
    
    printf("Digite a Area (em km2): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib2);
    
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- EXIBIÇÃO DOS DADOS ---
    printf("\n\n=== CARTAS CADASTRADAS ===\n");
    
    // Exibição Carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1); // %.2f limita a 2 casas decimais
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);

    printf("\n-------------------------\n");

    // Exibição Carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);

    return 0;
}