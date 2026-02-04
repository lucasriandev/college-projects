#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>   

// --- DEFINIÇÃO DA STRUCT ---
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- PROTÓTIPOS DAS FUNÇÕES ---
void cadastrarTerritorios(struct Territorio* t, int qtd);
void listarTerritorios(struct Territorio* t, int qtd);
void atacar(struct Territorio* atacante, struct Territorio* defensor);
void liberarMemoria(struct Territorio* mapa);

int main() {
    // 1. Inicializa o gerador de números aleatórios
    srand(time(NULL));

    struct Territorio* mapa; // Ponteiro que vai virar nosso vetor dinâmico
    int qtd, i;
    int indexAtk, indexDef;  // Índices para escolher quem ataca e defende
    char continuar;

    printf("=== WAR: SISTEMA ESTRUTURADO (NIVEL AVENTUREIRO) ===\n\n");
    
    // 2. Alocação Dinâmica
    printf("Quantos territorios voce quer no jogo? ");
    scanf("%d", &qtd);

    // CALLOC: Aloca memória para 'qtd' territórios e limpa a memória (zera tudo)
    mapa = (struct Territorio*) calloc(qtd, sizeof(struct Territorio));

    if (mapa == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        return 1; // Encerra com erro
    }

    // 3. Cadastro e Listagem Inicial
    cadastrarTerritorios(mapa, qtd);
    listarTerritorios(mapa, qtd);

    // 4. Loop do Jogo (Ataques)
    do {
        printf("\n--- RODADA DE ATAQUE ---\n");
        printf("Escolha o indice do territorio ATACANTE (1 a %d): ", qtd);
        scanf("%d", &indexAtk);
        
        printf("Escolha o indice do territorio DEFENSOR (1 a %d): ", qtd);
        scanf("%d", &indexDef);

        // Ajuste de índice (usuário digita 1, computador entende 0)
        indexAtk--; 
        indexDef--;

        // Validações básicas
        if (indexAtk < 0 || indexAtk >= qtd || indexDef < 0 || indexDef >= qtd) {
            printf("Erro: Territorio invalido!\n");
        } 
        else if (indexAtk == indexDef) {
            printf("Erro: Voce nao pode atacar a si mesmo!\n");
        }
        else if (strcmp(mapa[indexAtk].cor, mapa[indexDef].cor) == 0) {
            printf("Erro: Fogo amigo! Voce nao pode atacar um territorio da mesma cor (%s)!\n", mapa[indexAtk].cor);
        }
        else {
            atacar(&mapa[indexAtk], &mapa[indexDef]);
            
            listarTerritorios(mapa, qtd);
        }

        printf("\nDeseja realizar outro ataque? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    // 5. Limpeza da Memória
    liberarMemoria(mapa);
    printf("\nJogo encerrado. Memoria liberada.\n");

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

void cadastrarTerritorios(struct Territorio* t, int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        printf("\nCadastro do Territorio %d:\n", i + 1);
        
        printf("Nome: ");
        scanf(" %29[^\n]", t[i].nome); // Acessamos como vetor normal t[i]
        
        printf("Cor do Exercito: ");
        scanf(" %9s", t[i].cor);
        
        printf("Numero de Tropas: ");
        scanf("%d", &t[i].tropas);
    }
}

void listarTerritorios(struct Territorio* t, int qtd) {
    int i;
    printf("\n=== MAPA ATUAL ===\n");
    for (i = 0; i < qtd; i++) {
        printf("%d. %s [%s] - Tropas: %d\n", 
               i + 1, t[i].nome, t[i].cor, t[i].tropas);
    }
    printf("==================\n");
}

// Aqui usamos a seta (->) pois recebemos PONTEIROS de um único território
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    printf("\n>>> BATALHA INICIADA! <<<\n");
    printf("Atacante: %s (%s) vs Defensor: %s (%s)\n", 
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    // Sorteia dados de 1 a 6
    int dadoAtk = (rand() % 6) + 1;
    int dadoDef = (rand() % 6) + 1;

    printf("Dados rolados -> Atacante: %d | Defensor: %d\n", dadoAtk, dadoDef);

    if (dadoAtk > dadoDef) {
        printf("VITORIA DO ATACANTE!\n");
        printf("O territorio %s agora pertence ao exercito %s!\n", defensor->nome, atacante->cor);
        
        // Troca a cor do defensor (Conquista)
        strcpy(defensor->cor, atacante->cor);
        
        // Transfere metade das tropas (Regra do enunciado)
        int tropasMovidas = atacante->tropas / 2;
        defensor->tropas = tropasMovidas;
        atacante->tropas -= tropasMovidas; // Remove do atacante
        
        // Garante que tenha pelo menos 1 tropa em cada lugar
        if (defensor->tropas < 1) defensor->tropas = 1;
        if (atacante->tropas < 1) atacante->tropas = 1;

    } else {
        printf("DEFESA BEM SUCEDIDA!\n");
        printf("O atacante perdeu 1 tropa na batalha.\n");
        
        if (atacante->tropas > 0) {
            atacante->tropas--;
        }
    }
}

void liberarMemoria(struct Territorio* mapa) {
    // Libera o espaço alocado lá no começo com calloc
    free(mapa); 
}