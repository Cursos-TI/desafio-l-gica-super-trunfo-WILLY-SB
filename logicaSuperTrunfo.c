#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta) {
    printf("Estado (sigla): ");
    scanf("%s", carta->estado);

    printf("Código da carta: ");
    scanf("%s", carta->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->cidade); // lê até o \n

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para comparar as cartas por um atributo específico
void compararCartas(struct Carta c1, struct Carta c2) {
    // ---------- CONFIGURAÇÃO: Escolha o atributo para comparar ----------
    // Pode ser: populacao, area, pib, densidadePopulacional ou pibPerCapita
    char atributo[] = "populacao"; // <<< TROQUE AQUI SE DESEJAR OUTRO ATRIBUTO
    // -------------------------------------------------------------------

    printf("\nComparação de cartas (Atributo: %s):\n\n", atributo);

    float valor1, valor2;
    int menorVence = 0;

    if (strcmp(atributo, "populacao") == 0) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (strcmp(atributo, "densidadePopulacional") == 0) {
        valor1 = c1.densidadePopulacional;
        valor2 = c2.densidadePopulacional;
        menorVence = 1; // nesse caso, quem tem menor vence
    } else if (strcmp(atributo, "pibPerCapita") == 0) {
        valor1 = c1.pibPerCapita;
        valor2 = c2.pibPerCapita;
    } else {
        printf("Atributo inválido!\n");
        return;
    }

    printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, valor2);

    if ((valor1 > valor2 && !menorVence) || (valor1 < valor2 && menorVence)) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", c1.cidade);
    } else if (valor1 == valor2) {
        printf("\nResultado: Empate!\n");
    } else {
        printf("\nResultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
}

int main() {
    struct Carta carta1, carta2;

    printf("=== Cadastro da Carta 1 ===\n");
    cadastrarCarta(&carta1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    cadastrarCarta(&carta2);

    compararCartas(carta1, carta2);

    return 0;
}






   
    
  