#include "../../../include/TADs/vasilhas/vasilhas.h"
#include <stdio.h>

Vasilha *criarVasilha(Ingrediente *ingrediente) {

  Vasilha *vasilha = malloc(sizeof(Vasilha));
  if (vasilha == NULL) {
    fprintf(stderr, "Erro ao alocar memória para a vasilha.\n");
    exit(1);
  }

  vasilha->capacidade = CAPING1;
  vasilha->quantidade_Atual = CAPING1;
  vasilha->ingrediente = ingrediente;

  return vasilha;
}

bool RemoveQtdeVasilha(Vasilha *vasilha,int qtdeARemover){

  vasilha->quantidade_Atual -= qtdeARemover;
  if (vasilha->quantidade_Atual <= 0)
  {
    vasilha->quantidade_Atual = CAPING1;
  }

  return true;
}


bool TrocaDeVasilha(Vasilha *vasilha); //Função de troca das vasilhas, ainda para ser definida