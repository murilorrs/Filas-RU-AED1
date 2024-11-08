#ifndef FILAS_H
#define FILAS_H

#include "../usuarios/usuarios.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  Usuario *dado;      // Dado armazenado no no
  struct No *proximo; // Ponteiro para o próximo no
} No;

typedef struct {
  No *frente;
  No *tras;
  int id;
} Fila;

Fila *criarFila(int id);

void addFila(Fila *fila, Usuario *dado);

Usuario *rmFila(Fila *fila); // Remove e retorna o dado do início da fila

void exibeFila(Fila *fila);

bool filaVazia(Fila *fila);

#endif // FILAS_H