#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int id;
  int food1Rate;
  int food2Rate;
  int food3Rate;
  int food4Rate;
  int food5Rate;
  int food6Rate;
  int eVegetariano;
  int tempoFila;
  int tempoAtendimento;
  int servicoFinalizado;
  char status[20];
} Usuario;

void iniciaAleatoriedade();

Usuario *criarUsuario(int id);

void contaTempoFila(Usuario *usuario); // Percorrer a fila e incrementar o tempo de cada usuario a cada vez que a funcao for chamada.

void contaTempoAtendimento(Usuario *usuario); // Conta o tempo total de atendimento desde a criação

#endif