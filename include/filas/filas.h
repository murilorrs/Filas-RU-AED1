#include "../usuarios/usuarios.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  Usuario dado;       // Dado armazenado no no
  struct No *proximo; // Ponteiro para o próximo no
} No;

typedef struct Fila {
  No *frente; // Ponteiro para o primeiro elemento da fila
  No *tras;   // Ponteiro para o último elemento da fila
} Fila;

Fila *criarFila(); // Cria uma nova fila

void addFila(Fila *fila, Usuario dado); // Adiciona um dado à fila

Usuario rmFila(Fila *fila); // Remove e retorna o dado do início da fila

bool filaVazia(Fila *fila); // Verifica se a fila está vazia
