#include "../include/usuario/usuario.h"
#include <stdio.h>
#define MAX_USERS 100

int main() {

  // printf("Hello, World!\n");

  for (int i = 0; i < MAX_USERS; i++) {
    Usuario *usuario = criarUsuario(i);
    printf("Usuario %d\n", usuario->id);
  }

  // contaTempoFila(usuario);
  // contaTempoFila(usuario);
  // contaTempoFila(usuario);
  // contaTempoFila(usuario);

  return 0;
}