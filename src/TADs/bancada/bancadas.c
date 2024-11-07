#include "../../../include/TADs/bancadas/bancadas.h"
#include <stdio.h>

// Função para inicializar uma bancada
void inicializaBancada(Bancada *bancada, int id, bool vegetariana) {
  bancada->id = id;
  bancada->totalAtendimentos = 0;
  bancada->tempoTotalAtendimento = 0.0;
  bancada->vegetariana = vegetariana;
}

// Função para adicionar um atendimento à bancada
void adicionaAtendimento(Bancada *bancada, float tempoAtendimento) {
  bancada->totalAtendimentos++;
  bancada->tempoTotalAtendimento += tempoAtendimento;
}

// Função para calcular a média de atendimento ao fechar o restaurante
float calculaMediaAtendimento(Bancada *bancada) {
  if (bancada->totalAtendimentos == 0) {
    return 0.0; // Nenhum atendimento foi feito
  }
  return bancada->tempoTotalAtendimento / bancada->totalAtendimentos;
}

// Função para verificar se o cliente é vegetariano e chamar a bancada vegetariana
void chamarBancadaVegetariana(Bancada *bancadaVegetariana, bool clienteVegetariano) {
  if (clienteVegetariano && bancadaVegetariana->vegetariana) {
    printf("Cliente vegetariano chamado para a bancada %d\n", bancadaVegetariana->id);
  } else {
    printf("Cliente não é vegetariano ou bancada vegetariana indisponível.\n");
  }
}
