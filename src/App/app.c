#include "../../include/App/app.h"

void verificaEChamaUsuarioBancada(Bancada *bancada, Fila *filas[], int *tempoTotalEspera, int *numeroDeUsuariosAtendidos, int *tempoTotalAtendimento) {
  if (bancada->estaVazia) {
    Fila *filasEmbaralhadas[4];
    for (int i = 0; i < 4; i++) {
      filasEmbaralhadas[i] = filas[i];
    }

    for (int i = 0; i < 4; i++) {
      int j = rand() % 4;
      Fila *temp = filasEmbaralhadas[i];
      filasEmbaralhadas[i] = filasEmbaralhadas[j];
      filasEmbaralhadas[j] = temp;
    }

    for (int i = 0; i < 4; i++) {
      Fila *filaAtual = filasEmbaralhadas[i];

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

void realizarSimulacao(int totalCiclos, int periodo) {

  int todosUsuariosAtendidos = 0;

  if (periodo == 1) {
    printf("CAFÉ DA MANHÃ\n\n");
  }

  int tempoTotalEspera = 0, numeroDeUsuariosAtendidos = 0, tempoTotalAtendimento = 0;
  int ciclo = 0;

  Fila *fila1Cm = criarFila(1, 0);
  Fila *fila2Cm = criarFila(2, 0);
  Fila *fila3Cm = criarFila(3, 0);
  Fila *fila4Cm = criarFila(4, 1);

  Ingrediente *ingrediente1Cm = criaIngrediente(1, 300);
  Ingrediente *ingrediente2Cm = criaIngrediente(2, 100);
  Ingrediente *ingrediente3Cm = criaIngrediente(3, 150);
  Ingrediente *ingrediente4Cm = criaIngrediente(4, 220);
  Ingrediente *ingrediente5Cm = criaIngrediente(5, 180);
  Ingrediente *ingrediente6Cm = criaIngrediente(6, 200);

  Bancada *bancada1Cm = criaBancada(1, 1, ingrediente1Cm, ingrediente2Cm, ingrediente3Cm, ingrediente4Cm, ingrediente5Cm, ingrediente6Cm);
  Bancada *bancada2Cm = criaBancada(2, 0, ingrediente1Cm, ingrediente2Cm, ingrediente3Cm, ingrediente4Cm, ingrediente5Cm, ingrediente6Cm);
  Bancada *bancada3Cm = criaBancada(3, 0, ingrediente1Cm, ingrediente2Cm, ingrediente3Cm, ingrediente4Cm, ingrediente5Cm, ingrediente6Cm);

  Servente *serventes[18];
  for (int i = 0; i < 18; i++) {
    serventes[i] = criarServente(i + 1);
  }

  for (int i = 0; i < 6; i++)
    addServenteBancada(bancada1Cm, serventes[i]);
  for (int i = 6; i < 12; i++)
    addServenteBancada(bancada2Cm, serventes[i]);
  for (int i = 12; i < 18; i++)
    addServenteBancada(bancada3Cm, serventes[i]);

  Bancada *bancadas[3] = {bancada1Cm, bancada2Cm, bancada3Cm};
  int totalBancadas = (periodo == 3) ? 2 : 3;

  Fila *filas[4] = {fila1Cm, fila2Cm, fila3Cm, fila4Cm};

  int quantidadeUsuarios = 0;

  if (periodo == 3) {
    quantidadeUsuarios = 1;
  } else {
    quantidadeUsuarios = 2;
  }

  for (int i = 0; i < totalCiclos; i++) {
    for (int j = 0; j < quantidadeUsuarios; j++) {
      Usuario *usuario = criarUsuario(i);
      if (usuario != NULL && usuario->eVegetariano == 1) {
        addFila(fila4Cm, usuario);
      } else if (usuario != NULL) {
        int filaAleatoria = (rand() % 3) + 1;
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
        }
      }
    }

    system("clear");
    if (periodo == 1) {
      printf("\033[0;35m ----------------------- CAFE DA MANHA -----------------------\033[0m\n\n");
    } else if (periodo == 2) {
      printf("\033[0;35m---------------------------- ALMOCO -----------------------\033[0m\n\n");
    } else {
      printf("\033[0;35m---------------------------- JANTAR -----------------------\033[0m\n\n");
    }
    exibeFila(fila1Cm);
    exibeFila(fila2Cm);
    exibeFila(fila3Cm);
    exibeFila(fila4Cm);

    if (ciclo == 0) {
      for (int b = 0; b < totalBancadas; b++) {
        verificaEChamaUsuarioBancada(bancadas[b], filas, &tempoTotalEspera, &numeroDeUsuariosAtendidos, &tempoTotalAtendimento);
      }
      ciclo = 1;
    } else {
      ciclo = 0;
    }

    if (filaVazia(fila1Cm) && filaVazia(fila2Cm) && filaVazia(fila3Cm) && filaVazia(fila4Cm)) {
      todosUsuariosAtendidos = 1;
      return;
    }

    Sleep(1000);
  }
}
