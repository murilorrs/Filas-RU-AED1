#include "../include/filas/filas.h"
#include "../include/usuarios/usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  iniciaAleatoriedade();
  Fila *fila1 = criarFila(1);
  Fila *fila2 = criarFila(2);
  int i = 0;

  while (1) {
    Usuario *usuario = criarUsuario(i);

    if (usuario != NULL) {
      int filaEscolhida = rand() % 2;

      if (filaEscolhida == 0) {
        addFila(fila1, usuario);
      } else {
        addFila(fila2, usuario);
      }
      i++;
    } else {
      free(usuario);
    }

    printf("Fila 1:\n");
    exibeFila(fila1);
    printf("Fila 2:\n");
    exibeFila(fila2);

    sleep(1);
  }

  rmFila(fila1);
  rmFila(fila2);
  return 0;
}
