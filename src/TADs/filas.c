#include "../../include/TADs/filas.h"

Fila *criarFila(int id, int eVegetariana) {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  if (fila == NULL) {
    printf("\033[0;31mERROR: Falha na alocação de memória para fila\033[0m\n");
    exit(1); // Atenção: isso encerra o programa, mudar em nova versao
  }
  fila->frente = NULL;
  fila->tras = NULL;
  fila->id = id;
  fila->eVegetariana = eVegetariana;

  return fila;
}

void addFila(Fila *fila, Usuario *dado) {
  No *novoNo = (No *)malloc(sizeof(No));
  if (novoNo == NULL) {
    printf("\033[0;31mERROR: Falha na alocação de memória para novo nó\033[0m\n");
    exit(1); // Atenção: isso encerra o programa, mudar em nova versao
  }
  novoNo->dado = dado;
  novoNo->proximo = NULL;

  if (fila->tras == NULL) {
    fila->frente = novoNo;
    fila->tras = novoNo;
  } else {
    fila->tras->proximo = novoNo;
    fila->tras = novoNo;
  }
}

Usuario *rmFila(Fila *fila) {
  if (fila->frente == NULL) {
    printf("\033[0;33mFila vazia!\033[0m\n");
    return NULL;
  }

  No *noRemovido = fila->frente;
  Usuario *dado = noRemovido->dado;

  fila->frente = fila->frente->proximo;
  if (fila->frente == NULL) {
    fila->tras = NULL;
  }
  free(noRemovido);

  return dado;
}

void exibeFila(Fila *fila) {
  No *noAtual = fila->frente;

  if (fila->eVegetariana == 1) {
    printf("\033[0;36mUSUARIOS NA FILA %d \033[0;32m(Veg):\n\n\033[0m", fila->id);
  } else {
    printf("\033[0;36mUSUARIOS NA FILA %d:\n\n\033[0m", fila->id);
  }

  while (noAtual != NULL) {
    printf("ID: %02d | Food1: %02d | Food2: %02d | Food3: %02d | Food4: %02d | Food5: %02d | Food6: %02d | E Vegetariano: %d\n\n", noAtual->dado->id, noAtual->dado->food1Rate,
           noAtual->dado->food2Rate, noAtual->dado->food3Rate, noAtual->dado->food4Rate, noAtual->dado->food5Rate, noAtual->dado->food6Rate, noAtual->dado->eVegetariano);
    noAtual = noAtual->proximo;
  }

  printf("\n\n");
}

bool filaVazia(Fila *fila) {
  if (fila->frente == NULL) {
    return true;
  } else {
    return false;
  }
}
