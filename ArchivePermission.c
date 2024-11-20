#include <stdio.h>
#include <stdlib.h>

void octalToBinary(int octal, char *binary) {
    int i;
    for (i = 8; i >= 0; i--) {
        binary[i] = (octal & 1) + '0';  // Extrai o bit menos significativo
        octal >>= 1;  // Desloca para a direita para verificar o próximo bit
    }
    binary[9] = '\0';  // Adiciona o terminador de string
}

void displayPermissions(char *binary) {
    char permissions[10] = "-rwxrwxrwx";

    for (int i = 0; i < 9; i++) {
        if (binary[i] == '0') {
            permissions[i] = '-';  // Se o bit for 0, troca a permissão para '-'
        }
    }

    printf("%s arquivo.txt\n", permissions);
}

int main() {
    int octal;
    char binary[10];

    printf("Digite as permissões do arquivo (formato octal, ex: 764): ");
    scanf("%d", &octal);

    octalToBinary(octal, binary);

    displayPermissions(binary);

    return 0;
}
