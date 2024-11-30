#include "../../include/TADs/vasilhas.h"
#include <stdio.h>

Vasilha *criarVasilha(Ingrediente *ingrediente) {

  Vasilha *vasilha = malloc(sizeof(Vasilha));
  if (vasilha == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Falha na alocação de memória para vasilia\033[0m\n");
    exit(1);
  }

  vasilha->capacidade = CAPING1;
  vasilha->quantidade_Atual = CAPING1;
  vasilha->ingrediente = ingrediente;

  return vasilha;
}

bool TrocaDeVasilha(Vasilha *vasilha) {
  vasilha->quantidade_Atual = CAPING1;
  return true;
}

bool RemoveQtdeVasilha(Vasilha *vasilha, int qtdeARemover) {

  if (vasilha->quantidade_Atual <= qtdeARemover) {
    TrocaDeVasilha(vasilha);
  }
  vasilha->quantidade_Atual -= qtdeARemover;

  return true;
}