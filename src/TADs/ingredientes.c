#include "../../include/TADs/ingredientes.h"

Ingrediente *criarIngrediente(int nome, int quantidadeIdealPorPorcao) {
  Ingrediente *ingrediente = (Ingrediente *)malloc(sizeof(Ingrediente));
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
