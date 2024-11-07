#ifndef VASILHAS_H
#define VASILHAS_H

// Definição das macros para a capacidade das vasilhas e tempo de reposição
#define CAPING1 5000 // Capacidade da vasilha 1 (em gramas)
#define TEMPING1 30  // Tempo de reposição da vasilha 1 (em segundos)

typedef struct {
  int capacidade;
  int quantidade_Atual;
  int tempo_reposicao;
} Vasilha;

// Funções que serão implementadas em vasilhas.c
void inicializarVasilhas(Vasilha vasilhas[], int n);
void servirIngrediente(Vasilha *vasilha, int quantidadeServida);

#endif