#include "../include/TADs/bancadas/bancadas.h"
#include "../include/TADs/filas/filas.h"
#include "../include/TADs/usuarios/usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  iniciaAleatoriedade();
  Fila *fila1 = criarFila(1);

  for (int i = 1; i < 10; i++) {
    Usuario *usuario = criarUsuario(i);

    if (usuario != NULL) {
      addFila(fila1, usuario);
      exibeFila(fila1);
    } else {
      free(usuario);
    }
  }

  rmFila(fila1);

  exibeFila(fila1);

  Bancada *bancada1 = criaBancada(1, 0);

  chamarParaBancada(bancada1, fila1);

  exibeFila(fila1);

  exibeBancada(bancada1);

  // iniciaAleatoriedade();
  // Fila *fila1 = criarFila(1);
  // Bancada *bancada1 = inicializaBancada(1, 0);

  // int i = 0;

  // while (1) {
  //   Usuario *usuario = criarUsuario(i);

  //   if (usuario != NULL) {
  //     addFila(fila1, usuario);
  //     i++;
  //   } else {
  //     free(usuario);
  //   }

  //   exibeFila(fila1);

  //   if (bancada1->estaVazia == 1) {
  //     printf("Bancada 1:\n");
  //     Usuario *usuario = chamarBancada(bancada1, fila1);
  //     if (usuario != NULL) {
  //       printf("Usuario de id %d está na bancada 1\n\n", usuario->id);
  //     } else {
  //       printf("Nenhum usuario para atender na bancada 1\n\n");
  //     }
  //   }
  //   sleep(1); // Pausa de 1 segundo
  // }

  return 0;
}
