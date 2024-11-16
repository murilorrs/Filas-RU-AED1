#include "../ingredientes/ingredientes.h"
#include <stdbool.h>

#define CAPING1 5000 // Capacidade da vasilha 1 (em gramas)

typedef struct {
  int capacidade;
  int quantidade_Atual;
  Ingrediente *ingrediente;
} Vasilha;

Vasilha *criarVasilha(Ingrediente *ingrediente);

bool RemoveQtdeVasilha(Vasilha *vasilha,int qtdeARemover);

bool TrocaDeVasilha();  //Função para trocar vasilhas, ainda para ser definida.
