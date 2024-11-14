#include "../../../include/TADs/servente/servente.h"
#include "../../../include/TADs/bancadas/bancadas.h"
#include "../../../include/TADs/usuarios/usuarios.h"

Servente *criarServente(int id, int ingredienteServido, int qtdeServentes) {

  Servente *servente = malloc(sizeof(Servente));

  if (servente == NULL) {
    fprintf(stderr, "Erro ao alocar memória para o usuário.\n");
    exit(1);
  }

  if (qtdeServentes >= QTSERMAX) {
    fprintf(stderr, "Quantidade de serventes passou do limite estabelecido.\n");
    exit(1);
  }

  if (ingredienteServido > 6 || ingredienteServido < 1) {
    fprintf(stderr, "Parãmetro de ingrediente passado ao criar o servente fora do range.\n");
    exit(1);
  }

  servente->ingredienteAServir = ingredienteServido;
  servente->id = id;
  servente->tempoSeguidoAtendimento = 0;
  servente->tempoTotalAtendimento = 0;
  servente->usuariosAtendidos = 0;

  return servente;
}

bool servirUsuario(Servente *servente, Bancada *bancada) { // ESSA FUNÇÃO VAI CONTER O TIPO VASILHA QUANDO IMPLEMENTAR!!!
  if (checaFoodRate(bancada->usuario, servente) < 50) {
    servente->usuariosAtendidos++;
    return true;
  }

  int qtdeAserServida = calculaQtdeServida(bancada->vasilha->ingradiente); // Tem que passar como parametro a quantidade ideal de comida a ser servida

  // Vasilha.qtde -= qtdeAserConsumida;

  servente->usuariosAtendidos++;
  return true;
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