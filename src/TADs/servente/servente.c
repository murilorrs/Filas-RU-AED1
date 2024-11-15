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

void servirUsuario(Bancada *bancada) {
  for (int i = 0; i < bancada->numServentes; i++) {
    Servente *servente = bancada->serventes[i];

    if (checaFoodRate(bancada, servente) < 50) {
      servente->usuariosAtendidos++;
      continue;
    }

    // Identifica o ingrediente que o servente deve servir
    Ingrediente *ingrediente = bancada->vasilhas[servente->ingredienteAServir]->ingrediente;
    int qtdeAserServida = calculaQuantidadeServida(bancada->vasilhas[servente->ingredienteAServir]->ingrediente->quantidadeIdealPorPorcao);

    // Atualiza a quantidade consumida e os atendimentos do servente
    ingrediente->quantidadeConsumida += qtdeAserServida;
    servente->usuariosAtendidos++;
    servente->tempoSeguidoAtendimento++;
    servente->tempoTotalAtendimento++;

    // Verifica se o servente precisa de intervalo
    if (checaTempoTrabalho(servente)) {
      printf("Servente %d entrou em intervalo.\n", servente->id);
    }
  }
  bancada->totalAtendimentos++;
  bancada->tempoTotalAtendimento++;
  bancada->estaVazia = 1;
}

int checaFoodRate(Bancada *bancada, Servente *servente) {
  switch (servente->ingredienteAServir) {
  case 1:
    return bancada->usuario->food1Rate;

  case 2:
    return bancada->usuario->food2Rate;

  case 3:
    return bancada->usuario->food3Rate;

  case 4:
    return bancada->usuario->food4Rate;

  case 5:
    return bancada->usuario->food5Rate;

  case 6:
    return bancada->usuario->food6Rate;
  }
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

int calculaQuantidadeServida(int quantidadeIdeal) {
  int percentual = (rand() % (MAX_PERCENT - MIN_PERCENT + 1)) + MIN_PERCENT;
  return (quantidadeIdeal * percentual) / 100;
}