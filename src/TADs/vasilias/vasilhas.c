#include "../../../include/TADs/vasilias/vasilhas.h"
#include <stdio.h>

// Inicializa as vasilhas com a capacidade maxima
void inicializarVasilhas(Vasilha vasilhas[], int n) {
  for (int i = 0; i < n; i++) {
    vasilhas[i].capacidade = CAPING1;       // Capacidade padrao (pode mudar para cada vasilha)
    vasilhas[i].quantidade_Atual = CAPING1; // Comeca cheia
    vasilhas[i].tempo_reposicao = TEMPING1; // Tempo de reposicao
  }
}

// Serve uma quantidade de ingrediente de uma vasilha
void servirIngrediente(Vasilha *vasilha, int quantidadeServida) {
  if (vasilha->quantidade_Atual >= quantidadeServida) {
    vasilha->quantidade_Atual -= quantidadeServida;
    printf("Servido: %d gramas. Quantidade restante: %d\n", quantidadeServida, vasilha->quantidade_Atual);
  } else {
    // Vasilha esvaziou
    printf("Vasilha esvaziou! Tempo de reposicao: %d segundos\n", vasilha->tempo_reposicao);
    vasilha->quantidade_Atual = vasilha->capacidade; // Repor vasilha com a capacidade total
  }
}