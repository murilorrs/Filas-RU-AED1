#include "../include/TADs/bancadas.h"
#include "../include/TADs/filas.h"
#include "../include/TADs/ingredientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void embaralharFilas(Fila *filas[], int n);
void verificaEChamaUsuarioBancada(Bancada *bancada, Fila *filas[], int *tempoTotalEspera, int *numeroDeUsuariosAtendidos, int *tempoTotalAtendimento);

int main() {
  int tempoTotalEspera = 0, numeroDeUsuariosAtendidos = 0, tempoTotalAtendimento = 0;
  int ciclo = 0;
  iniciaAleatoriedade();
  printf("\033[1;32mTESTE AUTOMÁTICO DO SOFTWARE\033[0m\n");

  Fila *fila1Cm = criarFila(1, 0);
  Fila *fila2Cm = criarFila(2, 0);
  Fila *fila3Cm = criarFila(3, 0);
  Fila *fila4Cm = criarFila(4, 0);
  Fila *fila5Cm = criarFila(5, 1);

  Ingrediente *ingrediente1Cm = criaIngrediente(1, 300);
  Ingrediente *ingrediente2Cm = criaIngrediente(2, 100);
  Ingrediente *ingrediente3Cm = criaIngrediente(3, 150);
  Ingrediente *ingrediente4Cm = criaIngrediente(4, 220);
  Ingrediente *ingrediente5Cm = criaIngrediente(5, 180);
  Ingrediente *ingrediente6Cm = criaIngrediente(6, 200);

  Bancada *bancada1Cm = criaBancada(1, 1, ingrediente1Cm, ingrediente2Cm, ingrediente3Cm, ingrediente4Cm, ingrediente5Cm, ingrediente6Cm);
  Bancada *bancada2Cm = criaBancada(2, 0, ingrediente1Cm, ingrediente2Cm, ingrediente3Cm, ingrediente4Cm, ingrediente5Cm, ingrediente6Cm);
  Bancada *bancada3Cm = criaBancada(3, 0, ingrediente1Cm, ingrediente2Cm, ingrediente3Cm, ingrediente4Cm, ingrediente5Cm, ingrediente6Cm);

  Servente *servente1Cm = criarServente(1);
  Servente *servente2Cm = criarServente(2);
  Servente *servente3Cm = criarServente(3);
  Servente *servente4Cm = criarServente(4);
  Servente *servente5Cm = criarServente(5);
  Servente *servente6Cm = criarServente(6);
  Servente *servente7Cm = criarServente(7);
  Servente *servente8Cm = criarServente(8);
  Servente *servente9Cm = criarServente(9);
  Servente *servente10Cm = criarServente(10);
  Servente *servente11Cm = criarServente(11);
  Servente *servente12Cm = criarServente(12);
  Servente *servente13Cm = criarServente(13);
  Servente *servente14Cm = criarServente(14);
  Servente *servente15Cm = criarServente(15);
  Servente *servente16Cm = criarServente(16);
  Servente *servente17Cm = criarServente(17);
  Servente *servente18Cm = criarServente(18);

  for (int i = 0; i < 150; i++) {
    Usuario *usuario = criarUsuario(i);

    if (usuario != NULL && usuario->eVegetariano == 1) {
      addFila(fila5Cm, usuario);
      system("clear");
      exibeFila(fila1Cm);
      exibeFila(fila2Cm);
      exibeFila(fila3Cm);
      exibeFila(fila4Cm);
      exibeFila(fila5Cm);
    }

    if (usuario != NULL && usuario->eVegetariano == 0) {
      int filaAleatoria = (rand() % 4) + 1;
      switch (filaAleatoria) {
      case 1:
        addFila(fila1Cm, usuario);
        break;
      case 2:
        addFila(fila2Cm, usuario);
        break;
      case 3:
        addFila(fila3Cm, usuario);
        break;
      case 4:
        addFila(fila4Cm, usuario);
        break;
      }
      system("clear");
      exibeFila(fila1Cm);
      exibeFila(fila2Cm);
      exibeFila(fila3Cm);
      exibeFila(fila4Cm);
      exibeFila(fila5Cm);
    }

    Bancada *bancadas[3] = {bancada1Cm, bancada2Cm, bancada3Cm};
    Fila *filas[5] = {fila1Cm, fila2Cm, fila3Cm, fila4Cm, fila5Cm};

    addServenteBancada(bancada1Cm, servente1Cm);
    addServenteBancada(bancada1Cm, servente2Cm);
    addServenteBancada(bancada1Cm, servente3Cm);
    addServenteBancada(bancada1Cm, servente4Cm);
    addServenteBancada(bancada1Cm, servente5Cm);
    addServenteBancada(bancada1Cm, servente6Cm);

    addServenteBancada(bancada2Cm, servente7Cm);
    addServenteBancada(bancada2Cm, servente8Cm);
    addServenteBancada(bancada2Cm, servente9Cm);
    addServenteBancada(bancada2Cm, servente10Cm);
    addServenteBancada(bancada2Cm, servente11Cm);
    addServenteBancada(bancada2Cm, servente12Cm);

    addServenteBancada(bancada3Cm, servente13Cm);
    addServenteBancada(bancada3Cm, servente14Cm);
    addServenteBancada(bancada3Cm, servente15Cm);
    addServenteBancada(bancada3Cm, servente16Cm);
    addServenteBancada(bancada3Cm, servente17Cm);
    addServenteBancada(bancada3Cm, servente18Cm);

    if (ciclo == 0) {
      verificaEChamaUsuarioBancada(bancada1Cm, filas, &tempoTotalEspera, &numeroDeUsuariosAtendidos, &tempoTotalAtendimento);
      verificaEChamaUsuarioBancada(bancada2Cm, filas, &tempoTotalEspera, &numeroDeUsuariosAtendidos, &tempoTotalAtendimento);
      verificaEChamaUsuarioBancada(bancada3Cm, filas, &tempoTotalEspera, &numeroDeUsuariosAtendidos, &tempoTotalAtendimento);
      ciclo = 1;
    } else {
      ciclo = 0;
    }

    Sleep(1000);
  }

  return 0;
}

void verificaEChamaUsuarioBancada(Bancada *bancada, Fila *filas[], int *tempoTotalEspera, int *numeroDeUsuariosAtendidos, int *tempoTotalAtendimento) {

  if (bancada->estaVazia) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        Fila *filaAtual = filas[j];

        if (!filaVazia(filaAtual)) {
          Usuario *primeiroUsuario = filaAtual->frente->dado;

          if (primeiroUsuario->eVegetariano == bancada->vegetariana) {
            chamarParaBancada(bancada, filaAtual);
            servirUsuario(bancada, tempoTotalEspera, numeroDeUsuariosAtendidos, tempoTotalAtendimento);
            break;
          }
        }
      }
    }
  }
}

void embaralharFilas(Fila *filas[], int n) {
  for (int i = 0; i < n; i++) {
    int j = rand() % n;
    Fila *temp = filas[i];
    filas[i] = filas[j];
    filas[j] = temp;
  }
}