#include "../include/TADs/bancadas/bancadas.h"
#include "../include/TADs/filas/filas.h"
#include "../include/TADs/usuarios/usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  iniciaAleatoriedade();
  Fila *fila1 = criarFila(1);
  Bancada *bancada1 = criaBancada(1, 0);
  int i = 0;

  while (1) {
    Usuario *usuario = criarUsuario(i);

    if (usuario != NULL) {
      addFila(fila1, usuario);
      i++;
    } else {
      free(usuario);
    }

    exibeFila(fila1);

    if (bancada1->estaVazia == 1)
      chamarParaBancada(bancada1, fila1);

    exibeBancada(bancada1);
    sleep(1); // Pausa de 1 segundo
  }

  return 0;
}
