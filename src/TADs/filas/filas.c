#include "../../../include/TADs/filas/filas.h"

Fila *criarFila(int id) {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->frente = NULL;
  fila->tras = NULL;
  fila->id = id;
  return fila;
}

void addFila(Fila *fila, Usuario *dado) {
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

Usuario *rmFila(Fila *fila) {
  if (fila->frente == NULL) {
    printf("Fila vazia!\n");
    exit(1); // Atenção: isso encerra o programa, mudar em nova versao
  }

  No *noRemovido = fila->frente;
  Usuario *dado = noRemovido->dado;

  fila->frente = fila->frente->proximo;
  if (fila->frente == NULL) {
    fila->tras = NULL; // Se a fila ficou vazia, o de trás também vai ser NULL
  }

  printf("Usuario de id %d foi removido da fila\n\n", dado->id);
  free(noRemovido);

  return dado;
}

void exibeFila(Fila *fila) {
  No *noAtual = fila->frente;

  // system("clear");
  printf("USUARIOS NA FILA %d:\n", fila->id);
  while (noAtual != NULL) {
    printf("ID: %02d | Food1: %02d | Food2: %02d | Food3: %02d | Food4: %02d | Food5: %02d | Food6: %02d | E Vegetariano: %d\n", noAtual->dado->id, noAtual->dado->food1Rate, noAtual->dado->food2Rate,
           noAtual->dado->food3Rate, noAtual->dado->food4Rate, noAtual->dado->food5Rate, noAtual->dado->food6Rate, noAtual->dado->eVegetariano);
    noAtual = noAtual->proximo; // Move para o próximo nó
  }
  printf("\n\n");
}

bool filaVazia(Fila *fila) { return fila->frente == NULL; }
