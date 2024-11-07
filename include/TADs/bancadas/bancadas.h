#ifndef BANCADA_H
#define BANCADA_H

#include <stdbool.h>

// Definições de constantes para quantidade mínima e máxima de bancadas
#define MIN_BANCADAS 1
#define MAX_BANCADAS 10

// Estrutura para representar uma bancada
typedef struct {
    int id;
    int totalAtendimentos;
    float tempoTotalAtendimento;
    bool vegetariana;
} Bancada;

// Funções relacionadas à bancada
void inicializaBancada(Bancada* bancada, int id, bool vegetariana);
void adicionaAtendimento(Bancada* bancada, float tempoAtendimento);
float calculaMediaAtendimento(Bancada* bancada);
void chamarBancadaVegetariana(Bancada* bancadaVegetariana, bool clienteVegetariano);

#endif
