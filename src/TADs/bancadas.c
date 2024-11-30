#include "../../include/TADs/bancadas.h"
#include <stdio.h>

Bancada *criaBancada(int id, int vegetariana) {
  Bancada *bancada = malloc(sizeof(Bancada));
  if (bancada == NULL) {
    printf("\033[0;31mERROR: Falha na alocação de memória para bancada\033[0m\n");
    return NULL;
  }

  bancada->id = id;
  bancada->totalAtendimentos = 0;
  bancada->tempoTotalAtendimento = 0;
  bancada->vegetariana = vegetariana;
  bancada->estaVazia = 1;
  bancada->numServentes = 0;
  bancada->usuario = NULL;

  return bancada;
}

void addServenteBancada(Bancada *bancada, Servente *servente) {
  if (bancada == NULL || servente == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Bancada ou servente NULL\033[0m\n");
    return;
  }

  for (int i = 0; i < 6; i++) {
    if (bancada->serventes[i] == NULL) {
      bancada->serventes[i] = servente;
      servente->ingredienteAServir = i + 1;
      bancada->numServentes++;
      return;
    }
  }
  fprintf(stderr, "\033[0;31mERROR: Não há espaço para mais serventes na bancada\033[0m\n");
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
    int qtdeAserServida = calculaQtdeServida(ingrediente->quantidadeIdealPorPorcao);

    // Atualiza a quantidade consumida e os atendimentos do servente
    ingrediente->quantidadeConsumida += qtdeAserServida;                                 // Incrementa o ingrediente pro relatório final
    RemoveQtdeVasilha(bancada->vasilhas[servente->ingredienteAServir], qtdeAserServida); // Tira a quantidade consumida da vasilha
    servente->usuariosAtendidos++;
    servente->tempoSeguidoAtendimento++;
    servente->tempoTotalAtendimento++;

    // Verifica se o servente precisa de intervalo
    if (checaTempoTrabalho(servente)) {
      printf("\033[0;31mServente %d entrou em intervalo.\033[0m\n", servente->id);
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

void exibeBancada(Bancada *bancada) {
  if (bancada == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Bancada NULL\033[0m\n");
    return;
  }

  printf("BANCADA %d:\n", bancada->id);
  printf("Total de atendimentos: %d\n", bancada->totalAtendimentos);
  printf("Tempo total de atendimento: %d\n", bancada->tempoTotalAtendimento);
  printf("Vegetariana: %d\n", bancada->vegetariana);
  printf("Esta vazia: %d\n", bancada->estaVazia);

  if (bancada->usuario != NULL) {
    printf("Usuario na bancada: %d\n\n", bancada->usuario->id);
  } else {
    printf("Usuario na bancada: Nenhum\n\n");
  }

  // printf("Serventes na bancada:\n");
  // for (int i = 0; i < 6; i++) {
  //   if (bancada->serventes[i] != NULL) {
  //     printf("Servente %d\n", bancada->serventes[i]->id);
  //     printf("Tempo total de atendimento: %d\n", bancada->serventes[i]->tempoTotalAtendimento);
  //     printf("Tempo seguido de atendimento: %d\n", bancada->serventes[i]->tempoSeguidoAtendimento);
  //     printf("Usuarios atendidos: %d\n", bancada->serventes[i]->usuariosAtendidos);
  //     printf("Ingrediente a servir: %d\n\n", bancada->serventes[i]->ingredienteAServir);
  //   } else {
  //     printf("Servente %d: Nenhum servente alocado.\n", i + 1);
  //   }
  // }
}

int calculaQtdeServida(int quantidadeIdeal) {
  int percentual = (rand() % (MAX_PERCENT - MIN_PERCENT + 1)) + MIN_PERCENT;
  return (quantidadeIdeal * percentual) / 100;
}