#include <stdio.h>
#include <stdlib.h>

void octalToBinary(int octal, char *binary) {
    int i = 8;
    while (octal > 0) {
        int digit = octal % 10; // extrai o ultimo digito octal
        octal /= 10; // remove o ultimo numero

        // converte para binario (3 bits)
        for (int j = 2; j >= 0; j--) {
            binary[i--] = (digit & 1) + '0';
            digit >>= 1; // move pro proximo bit
        }
    }

    // completa o array de binario com zeros
    while (i >= 0) {
        binary[i--] = '0';
    }

    binary[9] = '\0'; // adiciona o terminador de string
}

void displayPermissions(char *binary) {
    char permissions[10] = "-rwxrwxrwx";

    for (int i = 0; i < 9; i++) {
        if (binary[i] == '0') {
            permissions[i + 1] = '-'; // se o bit for 0, troca a permissão para '-'
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
