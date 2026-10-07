
/*
 * RESPOSTA TEÓRICA:
 * O operador ternário (?:) é mais vantajoso no cálculo do bônus de pontualidade por se tratar
 * de uma atribuição condicional direta e binária ('S' ou 'N'), tornando o código mais conciso
 * e legível em uma única linha sem a verbosidade de blocos if-else. Já o if aninhado tornou-se
 * indispensável na análise do desconto acadêmico, pois a nota de corte e o percentual concedido
 * dependem estritamente do contexto prévio da faixa social do aluno, exigindo uma tomada de
 * decisão hierárquica e estruturada em dois níveis lógicos distintos.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[100];
    int idade;
    float renda;
    float media;
    char pontualidade;

    char faixa_social[10];
    float desconto_base = 0.0f;
    float bonus_pontual = 0.0f;
    float desconto_total = 0.0f;

    // Leitura dos dados de entrada
    printf("Digite o nome completo do aluno: ");
    if (fgets(nome, sizeof(nome), stdin) != NULL) {
        nome[strcspn(nome, "\n")] = '\0'; // Remove o \n capturado pelo fgets
    }

    printf("Digite a idade do aluno: ");
    scanf("%d", &idade);

    printf("Digite a renda familiar mensal (R$): ");
    scanf("%f", &renda);

    printf("Digite a media academica (0.0 a 10.0): ");
    scanf("%f", &media);

    printf("Status de pontualidade no pagamento (S/N): ");
    scanf(" %c", &pontualidade); // Espaço antes de %c ignora quebras de linha pendentes

    // 1. Validação de Entrada (if / if-else)
    if (idade < 16 || renda <= 0.0f) {
        printf("\n========================================\n");
        printf("ERRO: Dados invalidos para analise.\n");
        if (idade < 16) {
            printf("- Idade minima permitida: 16 anos.\n");
        }
        if (renda <= 0.0f) {
            printf("- A renda familiar deve ser maior que zero.\n");
        }
        printf("Analise encerrada.\n");
        printf("========================================\n");
        return 1;
    }

    // 2. Classificação da Faixa Social (if-else-if) e 3. Desconto Acadêmico (if Aninhado)
    if (renda <= 2000.0f) {
        strcpy(faixa_social, "Faixa A");
        if (media >= 8.5f) {
            desconto_base = 50.0f;
        } else {
            desconto_base = 30.0f;
        }
    } else if (renda <= 5000.0f) {
        strcpy(faixa_social, "Faixa B");
        if (media >= 9.0f) {
            desconto_base = 25.0f;
        } else {
            desconto_base = 10.0f;
        }
    } else {
        strcpy(faixa_social, "Faixa C");
        if (media >= 9.5f) {
            desconto_base = 10.0f;
        } else {
            desconto_base = 0.0f;
        }
    }

    // 4. Bônus de Pontualidade (Operador Ternário ?:)
    bonus_pontual = (pontualidade == 'S' || pontualidade == 's') ? 5.0f : 0.0f;

    // 5. Cálculo Final
    desconto_total = desconto_base + bonus_pontual;

    // Exibição dos resultados formatados
    printf("\n========================================\n");
    printf("    SISTEMA DE AVALIACAO DE DESCONTO    \n");
    printf("========================================\n");
    printf("Aluno         : %s\n", nome);
    printf("Faixa Social  : %s\n", faixa_social);
    printf("Media         : %.2f\n", media);
    printf("Desconto Base : %.1f%%\n", desconto_base);
    printf("Bonus Pontual : %.1f%%\n", bonus_pontual);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.1f%%\n", desconto_total);
    printf("Status        : %s\n", (desconto_total > 0.0f) ? "APROVADO PARA BOLSA" : "NAO APROVADO");
    printf("========================================\n");

    return 0;
}
