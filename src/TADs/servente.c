#include "../../include/TADs/servente.h"

Servente *criarServente(int id) {
  Servente *servente = malloc(sizeof(Servente));
  if (servente == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Falha na alocação de memória para servente\033[0m\n");
    exit(EXIT_FAILURE);
  }

  servente->ingredienteAServir = 0;
  servente->id = id;
  servente->tempoSeguidoAtendimento = 0;
  servente->tempoTotalAtendimento = 0;
  servente->usuariosAtendidos = 0;
  servente->estaTrabalhando = 1;
  servente->tempoDescanso = 0;

  return servente;
}

bool checaTempoTrabalho(Servente *servente) {
  if (servente->tempoSeguidoAtendimento >= 60) {
    servente->estaTrabalhando = 0;
    return true;
  }

  if (servente->tempoDescanso > 30) {
    servente->estaTrabalhando = 1;
    servente->tempoSeguidoAtendimento = 0;
  }
  return false;
}
