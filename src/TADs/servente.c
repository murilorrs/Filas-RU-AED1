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

  return servente;
}

bool checaTempoTrabalho(Servente *servente) {
  if (servente->tempoSeguidoAtendimento >= 60) {
    intervaloServente(servente);
    servente->tempoSeguidoAtendimento = 0;
    return true;
  }

  servente->tempoSeguidoAtendimento++;
  servente->tempoTotalAtendimento++;
  return false;
}

bool intervaloServente(Servente *servente) { // Essa função vai fazer o servente ficar 30 segundos fora de trabalho. Preciso ter uma ideia de como vai ser a execução do programa pra definir ela

  return false;
}