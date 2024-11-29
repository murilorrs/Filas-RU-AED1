#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int nome;
  int quantidadeConsumida;
  int quantidadeIdealPorPorcao;
} Ingrediente;

// const char *listaIngredientes[] = {"Arroz", "Feijão", "Carne", "Salada", "Macarrão", "Frango", "Batata", "Molho", "Queijo", "Ovos", "Legumes", "Frutas"};

Ingrediente *criarIngrediente(int nome, int quantidadeIdealPorPorcao);

void consumirIngrediente(Ingrediente *ingrediente, int quantidadeConsumida);

int calcularConsumoTotal(Ingrediente *ingrediente);

#endif
