#ifndef RELATORIOS_H

#include "../filas/filas.h"
#include "../servente/servente.h"
#include "../usuarios/usuarios.h"
#include "../vasilhas/vasilhas.h"
#include "../bancadas/bancadas.h"

#include <stdio.h>

void relatorioTempoMedioEsperaUsuarios(Usuario usuarios[], int n); //Como não foi criada uma variável global ou forma global teremos que percorrer um vetor com todos usuários atendidos

void relatorioQuantidadeTotalIngrediente(Ingrediente *Ingrediente);

void tempoMedioServente(Servente *servente);

void tempoMedioAtendimentoUsuarios(Usuario usuarios[], int n); //Como não foi criada uma variável global ou forma global teremos que percorrer um vetor com todos usuários atendidos

void tempoMedioBancada(Bancada *bancada);

void quantidadeUsuariosAtendidosServente(Servente *servente);

void quantidadeUsuariosAtendidosBancada(Bancada *bancada);

#endif //RELATORIOS_H