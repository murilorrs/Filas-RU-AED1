#include "../include/TADs/bancadas/bancadas.h"
#include "../include/TADs/filas/filas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  iniciaAleatoriedade();
  // teste manual:
  Usuario *usuario1 = criarUsuario(1);
  Usuario *usuario2 = criarUsuario(2);
  Usuario *usuario3 = criarUsuario(3);
  Usuario *usuario4 = criarUsuario(4);
  Usuario *usuario5 = criarUsuario(5);
  Usuario *usuario6 = criarUsuario(6);
  Fila *fila1 = criarFila(1);
  Bancada *bancada1 = criaBancada(1, 0);
  Servente *servente1 = criarServente(1);
  Servente *servente2 = criarServente(2);
  Servente *servente3 = criarServente(3);
  Servente *servente4 = criarServente(4);
  Servente *servente5 = criarServente(5);
  Servente *servente6 = criarServente(6);

  // Enfileirando os usuarios
  Usuario *usuarios[] = {usuario1, usuario2, usuario3, usuario4, usuario5, usuario6};
  for (int i = 0; i < 6; i++) {
    if (usuarios[i] != NULL) {
      addFila(fila1, usuarios[i]);
    } else {
      free(usuarios[i]);
    }
  }

  exibeFila(fila1);
  printf("Bancada antes de chamar usuario:\n");
  exibeBancada(bancada1);

  if (bancada1->estaVazia == 1)
    chamarParaBancada(bancada1, fila1);

  exibeFila(fila1);

  printf("Bancada depois de chamar usuario:\n");
  exibeBancada(bancada1);

  addServenteBancada(bancada1, servente1);
  addServenteBancada(bancada1, servente2);
  addServenteBancada(bancada1, servente3);
  addServenteBancada(bancada1, servente4);
  addServenteBancada(bancada1, servente5);
  addServenteBancada(bancada1, servente6);

  printf("Bancada depois de adicionar serventes:\n");
  exibeBancada(bancada1);

  if (bancada1->estaVazia == 0) {
    servirUsuario(bancada1);
  }

  printf("Bancada depois de servir usuario:\n");
  exibeBancada(bancada1);

  // teste automatico
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

  //   if (bancada1->estaVazia == 1)
  //     chamarParaBancada(bancada1, fila1);

  //   exibeBancada(bancada1);
  //   sleep(1); // Pausa de 1 segundo
  // }

  return 0;
}
