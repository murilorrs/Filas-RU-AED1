#ifndef BANCADAS_H
#define BANCADAS_H

#include "../filas/filas.h"
#include "../servente/servente.h"
#include "../usuarios/usuarios.h"
#include "../vasilhas/vasilhas.h"

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

Bancada *criaBancada(int id, int vegetariana);
void addServenteBancada(Bancada *bancada, Servente *servente);
Usuario *chamarParaBancada(Bancada *bancada, Fila *fila);
void exibeBancada(Bancada *bancada);
Usuario *removeUsuarioBancada(Bancada *bancada);

#endif
