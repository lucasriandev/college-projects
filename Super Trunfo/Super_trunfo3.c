// nivel mestre faculdade

#include <stdio.h>

int main(){
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1; // Tipo mudado para suportar números gigantes
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1, superPoder1; // Adicionado superPoder

    
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2; // Tipo mudado para suportar números gigantes
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2, superPoder2; // Adicionado superPoder

    printf("=== CADASTRO CARTA 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    
    printf("Codigo (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    
    printf("Populacao: ");
    scanf("%lu", &populacao1); // %lu para unsigned long int
    
    printf("Area (km2): ");
    scanf("%f", &area1);
    
    printf("PIB (bilhoes): ");
    scanf("%f", &pib1);
    
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // LEITURA CARTA 2

    printf("\n=== CADASTRO CARTA 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Codigo (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("Populacao: ");
    scanf("%lu", &populacao2); // %lu aqui também
    
    printf("Area (km2): ");
    scanf("%f", &area2);
    
    printf("PIB (bilhoes): ");
    scanf("%f", &pib2);
    
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    if(area1 > 0) densidade1 = (float)populacao1 / area1;
    else densidade1 = 0;

    // --- Cálculos Básicos ---
    // Precisamos checar se area é > 0 para não dividir por zero
    if (area1 > 0) densidade1 = (float)populacao1 / area1;
    else densidade1 = 0;

    if (populacao1 > 0) pibPerCapita1 = pib1 / (float)populacao1; // PIB per Capita é dinheiro/gente? 
    
    else pibPerCapita1 = 0;

    if (area2 > 0) densidade2 = (float)populacao2 / area2;
    else densidade2 = 0;

    if (populacao2 > 0) pibPerCapita2 = pib2 / (float)populacao2;
    else pibPerCapita2 = 0;

    // --- Cálculo do SUPER PODER ---
    // Soma de tudo + inverso da densidade.
    // Inverso da densidade = 1 / densidade.
    // Castamos (float) na população para garantir precisão na soma.
    
    // Super Poder Carta 1
    float inversoDensidade1 = 0;
    if (densidade1 > 0) inversoDensidade1 = 1.0f / densidade1;
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + inversoDensidade1;

    // Super Poder Carta 2
    float inversoDensidade2 = 0;
    if (densidade2 > 0) inversoDensidade2 = 1.0f / densidade2;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + inversoDensidade2;


    // ==========================================
    // SAÍDA E COMPARAÇÕES
    // ==========================================
    
    printf("\n\n=== COMPARACAO DE CARTAS ===\n");
    printf("Carta 1 - %s (%s): %.2f Super Poder\n", nomeCidade1, codigo1, superPoder1);
    printf("Carta 2 - %s (%s): %.2f Super Poder\n\n", nomeCidade2, codigo2, superPoder2);

    
    printf("Populacao: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    
    printf("Area: Carta 1 venceu (%d)\n", area1 > area2);
    
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2);

    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2);
    
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
    
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);

    return 0;
}