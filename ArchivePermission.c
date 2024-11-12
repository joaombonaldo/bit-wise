#include <stdio.h>

#define READ  0x1  // 0001
#define WRITE 0x2  // 0010
#define EXECUTE 0x4 // 0100

void addPermission(int *permissions, int flag) {
    *permissions |= flag;
}

void removePermission(int *permissions, int flag) {
    *permissions &= ~flag;
}

int hasPermission(int permissions, int flag) {
    return permissions & flag;
}

int main() {
    int permissions = 0;

    // Adiciona permissões de leitura e escrita
    addPermission(&permissions, READ);
    addPermission(&permissions, WRITE);

    // Verifica as permissões
    printf("Permissão de leitura: %s\n", hasPermission(permissions, READ) ? "SIM" : "NÃO");
    printf("Permissão de escrita: %s\n", hasPermission(permissions, WRITE) ? "SIM" : "NÃO");
    printf("Permissão de execução: %s\n", hasPermission(permissions, EXECUTE) ? "SIM" : "NÃO");

    // Remove permissão de escrita e adiciona execução
    removePermission(&permissions, WRITE);
    addPermission(&permissions, EXECUTE);

    // Verifica as permissões atualizadas
    printf("Permissão de leitura: %s\n", hasPermission(permissions, READ) ? "SIM" : "NÃO");
    printf("Permissão de escrita: %s\n", hasPermission(permissions, WRITE) ? "SIM" : "NÃO");
    printf("Permissão de execução: %s\n", hasPermission(permissions, EXECUTE) ? "SIM" : "NÃO");

    return 0;
}
