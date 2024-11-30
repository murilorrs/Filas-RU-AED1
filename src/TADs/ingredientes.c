#include "../../include/TADs/ingredientes.h"

Ingrediente *criarIngrediente(int nome, int quantidadeIdealPorPorcao) {
  Ingrediente *ingrediente = (Ingrediente *)malloc(sizeof(Ingrediente));
  if (ingrediente == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Falha na alocação de memória para ingradiente\033[0m\n");
    exit(EXIT_FAILURE);
  }
  ingrediente->nome = nome;
  ingrediente->quantidadeConsumida = 0;
  ingrediente->quantidadeIdealPorPorcao = quantidadeIdealPorPorcao;
  return ingrediente;
}

void consumirIngrediente(Ingrediente *ingrediente, int quantidadeConsumida) { ingrediente->quantidadeConsumida += quantidadeConsumida; }

int calcularConsumoTotal(Ingrediente *ingrediente) {
  int consumoTotal = ingrediente->quantidadeConsumida;
  free(ingrediente);
  return consumoTotal;
}
