#include "../TADs/bancadas.h"
#include "../TADs/filas.h"
#include "../TADs/ingredientes.h"
#include "../Relatorios/relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void realizarSimulacao(int totalCiclos, int periodo);
void verificaEChamaUsuarioBancada(Bancada *bancada, Fila *filas[], int *tempoTotalEspera, int *numeroDeUsuariosAtendidos, int *tempoTotalAtendimento);
