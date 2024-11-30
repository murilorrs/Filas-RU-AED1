#include "../../include/TADs/filas.h"

Fila *criarFila(int id) {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  if (fila == NULL) {
    printf("\033[0;31mERROR: Falha na alocação de memória para fila\033[0m\n");
    exit(1); // Atenção: isso encerra o programa, mudar em nova versao
  }
  fila->frente = NULL;
  fila->tras = NULL;
  fila->id = id;
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
    fila->tras = NULL; // Se a fila ficou vazia, o de trás também vai ser NULL
  }

  printf("\033[0;32mUsuario de id %d foi removido da fila\033[0m\n\n", dado->id);
  free(noRemovido);

  return dado;
}

void exibeFila(Fila *fila) {
  No *noAtual = fila->frente;

  // system("clear");
  printf("USUARIOS NA FILA %d:\n\n", fila->id);
  while (noAtual != NULL) {
    printf("ID: %02d | Food1: %02d | Food2: %02d | Food3: %02d | Food4: %02d | Food5: %02d | Food6: %02d | E Vegetariano: %d\n\n", noAtual->dado->id, noAtual->dado->food1Rate,
           noAtual->dado->food2Rate, noAtual->dado->food3Rate, noAtual->dado->food4Rate, noAtual->dado->food5Rate, noAtual->dado->food6Rate, noAtual->dado->eVegetariano);
    noAtual = noAtual->proximo; // Move para o próximo nó
  }
  printf("\n\n");
}

bool filaVazia(Fila *fila) { return fila->frente == NULL; }
