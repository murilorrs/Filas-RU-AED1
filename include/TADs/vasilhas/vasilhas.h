#include "../ingredientes/ingredientes.h"

#define CAPING1 5000 // Capacidade da vasilha 1 (em gramas)

typedef struct {
  int capacidade;
  int quantidade_Atual;
  Ingrediente *ingrediente;
} Vasilha;

Vasilha *criarVasilha(Ingrediente *ingrediente);
