#ifndef RELATORIOS_H

#include "../TADs/bancadas.h"
#include <stdio.h>

void relatorioTempoMedioEsperaUsuarios(float tempoTotalEspera, int numeroUsuariosAtendidos);
void relatorioQuantidadeTotalIngrediente(Ingrediente Ingrediente[], int numeroElementos);
void tempoMedioServente(Servente servente[], int numeroElementos);
void tempoMedioAtendimentoUsuarios(float tempoTotalAtendimento, int numeroUsuariosAtendidos);
void tempoMedioBancada(Bancada bancada[], int numeroElementos);
void quantidadeUsuariosAtendidosServente(Servente servente[], int numeroElementos);
void quantidadeUsuariosAtendidosBancada(Bancada bancada[], int numeroElementos);
void relatorioFinal(float tempoTotalEspera, int numeroUsuariosAtendidos, float tempoTotalAtendimento, Ingrediente ingredientes[], int numIngredientes, Servente serventes[], int numServentes,
                    Bancada bancadas[], int numBancadas);

#endif // RELATORIOS_H