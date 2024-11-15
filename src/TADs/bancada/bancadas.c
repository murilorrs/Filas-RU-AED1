#include "../../../include/TADs/bancadas/bancadas.h"
#include <stdio.h>

Bancada *criaBancada(int id, int vegetariana) {
  Bancada *bancada = malloc(sizeof(Bancada));
  bancada->id = id;
  bancada->totalAtendimentos = 0;
  bancada->tempoTotalAtendimento = 0;
  bancada->vegetariana = vegetariana;
  bancada->estaVazia = 1;
  return bancada;
}

void addServenteBancada(Bancada *bancada, Servente *servente) {
  for (int i = 0; i < 6; i++) {
    if (bancada->serventes[i] == NULL) {
      bancada->serventes[i] = servente;
      servente->ingredienteAServir = i + 1;
      bancada->numServentes++;
      return;
    }
  }
}

Usuario *chamarParaBancada(Bancada *bancada, Fila *fila) {
  if (fila->frente == NULL) {
    printf("Fila vazia!\n");
    return NULL; // Caso a fila esteja vazia
  }

  if (fila->frente->dado->eVegetariano == 0) {
    Usuario *usuario = rmFila(fila);
    bancada->estaVazia = 0;
    bancada->usuario = usuario;
    return usuario; // Retorna o ponteiro para o usuário se precisar usar em algum caso
  }
  return NULL; // Caso não tenha usuário para atender
}

void servirUsuario(Bancada *bancada) {
  for (int i = 0; i < bancada->numServentes; i++) {
    Servente *servente = bancada->serventes[i]; // Pega o servente i que vai atender agora na bancada

    if (checaFoodRate(bancada, servente) < 50) {
      servente->usuariosAtendidos++;
      continue;
    }

    // Identifica o ingrediente que o servente deve servir
    Ingrediente *ingrediente = bancada->vasilhas[servente->ingredienteAServir]->ingrediente; // Pega a vasilha i que o servente vai servir e verifica o ingrediente
    int qtdeAserServida = calculaQtdeServida(bancada->vasilhas[servente->ingredienteAServir]->ingrediente->quantidadeIdealPorPorcao);

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
  default:
    return -1; // Valor de retorno padrão em caso de erro
  }
}

Usuario *removeUsuarioBancada(Bancada *bancada) {
  bancada->estaVazia = 1;
  return NULL;
}

void exibeBancada(Bancada *bancada) { // !!! Essa funcao ta dando segmetation fault algumas vezes, corrigir para nova versao
  printf("BANCADA %d:\n", bancada->id);
  printf("Total de atendimentos: %d\n", bancada->totalAtendimentos);
  printf("Tempo total de atendimento: %d\n", bancada->tempoTotalAtendimento);
  printf("Vegetariana: %d\n", bancada->vegetariana);
  printf("Esta vazia: %d\n", bancada->estaVazia);
  printf("Usuario na bancada: %d\n\n", bancada->usuario->id);
}

int calculaQtdeServida(int quantidadeIdeal) {
  int percentual = (rand() % (MAX_PERCENT - MIN_PERCENT + 1)) + MIN_PERCENT;
  return (quantidadeIdeal * percentual) / 100;
}