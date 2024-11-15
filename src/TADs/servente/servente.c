#include "../../../include/TADs/servente/servente.h"

Servente *criarServente(int id) {

  Servente *servente = malloc(sizeof(Servente));

  if (servente == NULL) {
    fprintf(stderr, "Erro ao alocar memória para o servente.\n");
    exit(1);
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
