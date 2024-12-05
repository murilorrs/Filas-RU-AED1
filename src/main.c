#include "../include/TADs/bancadas.h"
#include "../include/TADs/filas.h"
#include "../include/TADs/ingredientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void embaralharFilas(Fila *filas[], int n);



int main() {
  int tempoTotalEspera = 0, numeroDeUsuariosAtendidos = 0, tempoTotalAtendimento = 0;
  iniciaAleatoriedade();
  printf("\033[1;32mTESTE AUTOMÁTICO DO SOFTWARE\033[0m\n");

  int i = 0;

  Fila *fila1 = criarFila(1, 0);
  Fila *fila2 = criarFila(2, 0);
  Fila *fila3 = criarFila(3, 0);
  Fila *fila4 = criarFila(4, 0);
  Fila *fila5 = criarFila(5, 1);

  Ingrediente *ingrediente1 = criaIngrediente(1, 300);
  Ingrediente *ingrediente2 = criaIngrediente(2, 100);
  Ingrediente *ingrediente3 = criaIngrediente(3, 150);
  Ingrediente *ingrediente4 = criaIngrediente(4, 220);
  Ingrediente *ingrediente5 = criaIngrediente(5, 180);
  Ingrediente *ingrediente6 = criaIngrediente(6, 200);

  Bancada *bancada1 = criaBancada(1, 1, ingrediente1, ingrediente2, ingrediente3, ingrediente4, ingrediente5, ingrediente6);
  Bancada *bancada2 = criaBancada(2, 0, ingrediente1, ingrediente2, ingrediente3, ingrediente4, ingrediente5, ingrediente6);
  Bancada *bancada3 = criaBancada(3, 0, ingrediente1, ingrediente2, ingrediente3, ingrediente4, ingrediente5, ingrediente6);

  Servente *servente1 = criarServente(1);
  Servente *servente2 = criarServente(2);
  Servente *servente3 = criarServente(3);
  Servente *servente4 = criarServente(4);
  Servente *servente5 = criarServente(5);
  Servente *servente6 = criarServente(6);
  Servente *servente7 = criarServente(7);
  Servente *servente8 = criarServente(8);
  Servente *servente9 = criarServente(9);
  Servente *servente10 = criarServente(10);
  Servente *servente11 = criarServente(11);
  Servente *servente12 = criarServente(12);
  Servente *servente13 = criarServente(13);
  Servente *servente14 = criarServente(14);
  Servente *servente15 = criarServente(15);
  Servente *servente16 = criarServente(16);
  Servente *servente17 = criarServente(17);
  Servente *servente18 = criarServente(18);

  while (1) {
    Usuario *usuario = criarUsuario(i);
    i++;

    if (usuario != NULL && usuario->eVegetariano == 1) {
      addFila(fila5, usuario);
      system("clear");
      exibeFila(fila1);
      exibeFila(fila2);
      exibeFila(fila3);
      exibeFila(fila4);
      exibeFila(fila5);
    }

    if (usuario != NULL && usuario->eVegetariano == 0) {
      int filaAleatoria = (rand() % 4) + 1;
      switch (filaAleatoria) {
      case 1:
        addFila(fila1, usuario);
        break;
      case 2:
        addFila(fila2, usuario);
        break;
      case 3:
        addFila(fila3, usuario);
        break;
      case 4:
        addFila(fila4, usuario);
        break;
      }
      system("clear");
      exibeFila(fila1);
      exibeFila(fila2);
      exibeFila(fila3);
      exibeFila(fila4);
      exibeFila(fila5);
    }

    Bancada *bancadas[3] = {bancada1, bancada2, bancada3};
    Fila *filas[5] = {fila1, fila2, fila3, fila4, fila5};

    for (int i = 0; i < 3; i++) {
      Bancada *bancadaAtual = bancadas[i];

      if (bancadaAtual->estaVazia) {
        int usuarioServido = 0;

        for (int j = 0; j < 5; j++) {
          Fila *filaAtual = filas[j];

          if (!filaVazia(filaAtual)) {
            Usuario *primeiroUsuario = filaAtual->frente->dado;

            if (primeiroUsuario->eVegetariano == bancadaAtual->vegetariana) {
              chamarParaBancada(bancadaAtual, filaAtual);
              usuarioServido = 1;
              break;
            }
          }
        }
      }
    }

    Sleep(1000);
  }

  return 0;
}

void embaralharFilas(Fila *filas[], int n) {
  for (int i = 0; i < n; i++) {
    int j = rand() % n;
    Fila *temp = filas[i];
    filas[i] = filas[j];
    filas[j] = temp;
  }
}