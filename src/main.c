#include "../include/filas/filas.h"
#include "../include/usuarios/usuarios.h"
#include <stdio.h>

#define MAX_USERS 10

int main() {

  iniciaAleatoriedade();

  Fila *fila1 = criarFila();

  for (int i = 0; i < MAX_USERS; i++) {
    Usuario *usuario = criarUsuario(i);

    if (usuario != NULL)
      addFila(fila1, usuario);
    else
      free(usuario);
  }

  exibeFila(fila1);

  rmFila(fila1);

  exibeFila(fila1);

  return 0;
}