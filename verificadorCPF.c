#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Função para verificar se todos os dígitos são iguais
int todosDigitosIguais(char *cpf) {
    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) return 0;
    }
    return 1;
}

int validarCPF(char *cpf) {
    if (strlen(cpf) != 11) return 0;
    if (todosDigitosIguais(cpf)) return 0;

    int soma = 0, resto;

    // Primeiro dígito
    for (int i = 0; i < 9; i++) {
        if (!isdigit(cpf[i])) return 0;
        soma += (cpf[i] - '0') * (10 - i);
    }

    resto = soma % 11;
    int dig1 = (resto < 2) ? 0 : 11 - resto;

    if (dig1 != (cpf[9] - '0')) return 0;

    // Segundo dígito
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }

    resto = soma % 11;
    int dig2 = (resto < 2) ? 0 : 11 - resto;

    return dig2 == (cpf[10] - '0');
}

int main() {
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");
    char cpf[20];

    if (!entrada || !saida) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    while (fgets(cpf, sizeof(cpf), entrada)) {
        cpf[strcspn(cpf, "\n")] = 0; // Remove o '\n'
        if (validarCPF(cpf)) {
            fprintf(saida, "%s - Valido\n", cpf);
        } else {
            fprintf(saida, "%s - Invalido\n", cpf);
        }
    }

    fclose(entrada);
    fclose(saida);
    printf("Validacao concluida. Verifique o arquivo saida.txt\n");
    return 0;
}
