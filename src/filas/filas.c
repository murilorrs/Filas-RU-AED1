#include "../../include/filas/filas.h"

Fila *criarFila() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->frente = NULL;
  fila->tras = NULL;
  return fila;
}

void addFila(Fila *fila, Usuario dado) {
  No *novoNo = (No *)malloc(sizeof(No));
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

Usuario rmFila(Fila *fila) {
  if (fila->frente == NULL) {
    printf("Fila vazia! Não é possível remover um elemento.\n");
    exit(1);
  }

  No *noRemovido = fila->frente;
  Usuario dado = noRemovido->dado;

  fila->frente = fila->frente->proximo; // Move o frente para o próximo nó
  if (fila->frente == NULL) {
    fila->tras = NULL; // Se a fila ficou vazia, o de tras também deve ser NULL
  }

  free(noRemovido); // Libera a memória do nodo removido
  return dado;
}

bool filaVazia(Fila *fila) { return fila->frente == NULL; }
