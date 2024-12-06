#ifndef SERVENTE_H
#define SERVENTE_H

#include "./ingredientes.h"
#include "./usuarios.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEMPSERMAX 60
#define TEMPSERINT 30
#define MAXSERINI 3
#define QTSERMAX 18
#define QTSERMIN 3
#define MIN_PERCENT 80
#define MAX_PERCENT 120

typedef struct {
  int tempoTotalAtendimento;
  int tempoDescanso;
  int usuariosAtendidos;
  int tempoSeguidoAtendimento;
  int id;
  int ingredienteAServir;
  int estaTrabalhando;
} Servente;

Servente *criarServente(int id);

bool checaTempoTrabalho(Servente *servente);

bool intervaloServente(Servente *servente);

#endif
