#ifndef BANCADAS_H
#define BANCADAS_H

#include "../filas/filas.h"
#include "../usuarios/usuarios.h"

#define MIN_BANCADAS 1
#define MAX_BANCADAS 10

typedef struct {
  int id;
  int totalAtendimentos;
  int tempoTotalAtendimento;
  int vegetariana;
  int estaVazia;
  Usuario *usuario; // Usuario que está sendo atendido
} Bancada;

Bancada *criaBancada(int id, int vegetariana);
Usuario *chamarParaBancada(Bancada *bancada, Fila *fila);
void exibeBancada(Bancada *bancada);
Usuario *removeUsuarioBancada(Bancada *bancada);

#endif
