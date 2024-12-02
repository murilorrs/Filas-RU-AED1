#ifndef BANCADAS_H
#define BANCADAS_H

#include "./filas.h"
#include "./servente.h"
#include "./usuarios.h"
#include "./vasilhas.h"

#define MIN_BANCADAS 1
#define MAX_BANCADAS 10

typedef struct {
  int id;
  int totalAtendimentos;
  int tempoTotalAtendimento;
  int vegetariana;
  int estaVazia;
  int numServentes;
  Servente *serventes[6]; // Serventes que estão atendendo na bancada
  Usuario *usuario;       // Usuario que está sendo atendido
  Vasilha *vasilhas[6];   // Vasilha que está sendo usada
} Bancada;

Bancada *criaBancada(int id, int vegetariana, Ingrediente *ingrediente1, Ingrediente *ingrediente2, Ingrediente *ingrediente3, Ingrediente *ingrediente4, Ingrediente *ingrediente5,
                     Ingrediente *ingrediente6);

void addServenteBancada(Bancada *bancada, Servente *servente);

Usuario *chamarParaBancada(Bancada *bancada, Fila *fila);

void exibeQuantidadeAtualVasilhas(Bancada *bancada);

void exibeBancada(Bancada *bancada);

void servirUsuario(Bancada *bancada);

int checaFoodRate(Bancada *bancada, Servente *servente);

int calculaQtdeServida(int quantidadeIdeal);

#endif
