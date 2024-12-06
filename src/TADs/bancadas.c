#include "../../include/TADs/bancadas.h"
#include <stdio.h>

Bancada *criaBancada(int id, int vegetariana, Ingrediente *ingrediente1, Ingrediente *ingrediente2, Ingrediente *ingrediente3, Ingrediente *ingrediente4, Ingrediente *ingrediente5,
                     Ingrediente *ingrediente6) {
  Bancada *bancada = malloc(sizeof(Bancada));
  if (bancada == NULL) {
    printf("\033[0;31mERROR: Falha na alocação de memória para bancada\033[0m\n");
    return NULL;
  }

  bancada->vasilhas[0] = criaVasilha(ingrediente1);
  bancada->vasilhas[1] = criaVasilha(ingrediente2);
  bancada->vasilhas[2] = criaVasilha(ingrediente3);
  bancada->vasilhas[3] = criaVasilha(ingrediente4);
  bancada->vasilhas[4] = criaVasilha(ingrediente5);
  bancada->vasilhas[5] = criaVasilha(ingrediente6);

  bancada->serventes[0] = NULL;
  bancada->serventes[1] = NULL;
  bancada->serventes[2] = NULL;
  bancada->serventes[3] = NULL;
  bancada->serventes[4] = NULL;
  bancada->serventes[5] = NULL;

  bancada->usuario = NULL;

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

  if (bancada->numServentes > 6) {
    printf("\033[0;33mWARNING: Bancada %d ja esta cheia\033[0m\n", bancada->id);
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
}

Usuario *chamarParaBancada(Bancada *bancada, Fila *fila) {
  if (fila == NULL || bancada == NULL) {
    printf("Fila ou bancada inválida!\n");
    return NULL;
  }

  if (fila->frente == NULL) {
    printf("Fila vazia!\n");
    return NULL;
  }
  if (bancada->estaVazia == 1) {

    if ((bancada->vegetariana == 1 && fila->frente->dado->eVegetariano == 1) || (bancada->vegetariana == 0 && fila->frente->dado->eVegetariano == 0)) {
      Usuario *usuario = rmFila(fila);
      if (usuario != NULL) {
        bancada->estaVazia = 0;
        bancada->usuario = usuario;
      }
      printf("\033[0;32m--->USUARIO DE ID \033[0;31m%d\033[0;32m FOI CHAMADO PARA A BANCADA \033[0;31m%d\033[0;32m<---\033[0m\n\n", bancada->usuario->id, bancada->id);

      return usuario;
    }
  }

  return NULL;
}

void servirUsuario(Bancada *bancada, int *tempoTotalEspera, int *numeroDeUsuariosAtendidos, int *tempoTotalAtendimento) {
  if (bancada == NULL || tempoTotalEspera == NULL || numeroDeUsuariosAtendidos == NULL || tempoTotalAtendimento == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Parâmetro NULL detectado.\033[0m\n");
    return;
  }

  for (int i = 0; i < 5; i++) {
    Servente *servente = bancada->serventes[i];

    checaTempoTrabalho(servente);

    if (servente == NULL || servente->estaTrabalhando == 0) {
      fprintf(stdout, "\033[0;33mServente %d não está disponível. Procurando substituto...\033[0m\n", i + 1);

      int encontrado = 0;
      for (int j = 0; j < 5; j++) {
        if (j == i)
          continue;

        Servente *substituto = bancada->serventes[j];
        if (substituto != NULL && substituto->estaTrabalhando == 1) {
          servente = substituto;
          encontrado = 1;
          substituto->usuariosAtendidos++;
          substituto->tempoTotalAtendimento++;
          (stdout, "\033[0;32mServente %d substituído pelo Servente %d.\033[0m\n", i + 1, j + 1);
          break;
        }
      }

      if (!encontrado) {
        fprintf(stderr, "\033[0;31mERROR: Nenhum substituto disponível para Servente %d.\033[0m\n", i + 1);
        continue;
      }
    }

    servente->ingredienteAServir = i + 1;

    int foodRate = checaFoodRate(bancada, servente);
    if (foodRate < 0 || foodRate > 100) {
      fprintf(stderr, "\033[0;31mERROR: Valor inválido retornado por checaFoodRate: %d\033[0m\n", foodRate);
      continue;
    }

    if (foodRate < 50) {
      servente->usuariosAtendidos++;
      bancada->tempoTotalAtendimento++;
      contaTempoAtendimento(bancada->usuario);
      continue;
    }

    Ingrediente *ingrediente = bancada->vasilhas[i]->ingrediente;
    int qtdeAserServida = calculaQtdeServida(ingrediente->quantidadeIdealPorPorcao);

    ingrediente->quantidadeConsumida += qtdeAserServida;
    RemoveQtdeVasilha(bancada->vasilhas[servente->ingredienteAServir], qtdeAserServida);

    servente->usuariosAtendidos++;
    servente->tempoSeguidoAtendimento++;
    servente->tempoTotalAtendimento++;
    bancada->tempoTotalAtendimento++;
    contaTempoAtendimento(bancada->usuario);
  }

  bancada->totalAtendimentos++;
  bancada->estaVazia = 1;

  *numeroDeUsuariosAtendidos += 1;
  *tempoTotalEspera += bancada->usuario->tempoFila;
  *tempoTotalAtendimento += bancada->usuario->tempoAtendimento;

  free(bancada->usuario);
  bancada->usuario = NULL;
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
    return -1;
  }
}

int calculaQtdeServida(int quantidadeIdeal) {
  int percentual = (rand() % (MAX_PERCENT - MIN_PERCENT + 1)) + MIN_PERCENT;
  return (quantidadeIdeal * percentual) / 100;
}

void exibeBancada(Bancada *bancada) {
  if (bancada == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Bancada NULL\033[0m\n");
    return;
  }

  printf("\033[0;32mBANCADA %d:\033[0m\n", bancada->id);
  printf("Total de atendimentos: %d\n", bancada->totalAtendimentos);
  printf("Tempo total de atendimento: %d\n", bancada->tempoTotalAtendimento);
  printf("Vegetariana: %d\n", bancada->vegetariana);
  printf("Esta vazia: %d\n", bancada->estaVazia);

  if (bancada->usuario != NULL) {
    printf("ID do usuario na bancada: %d\n\n", bancada->usuario->id);
  } else {
    printf("Usuario na bancada: Nenhum\n\n");
  }

  if (bancada == NULL || bancada->serventes == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Bancada ou serventes NULL\033[0m\n");
    return;
  }
  printf("\033[0;32mVasilhas na bancada:\033[0m\n");
  for (int i = 0; i < 6; i++) {
    if (bancada->vasilhas[i] != NULL) {
      printf("Vasilha %d:\n", i + 1);
      printf("Ingrediente: %d\n", bancada->vasilhas[i]->ingrediente->nome);
      printf("Quantidade consumida: %d\n", bancada->vasilhas[i]->ingrediente->quantidadeConsumida);
      printf("Quantidade ideal por porção: %d\n\n", bancada->vasilhas[i]->ingrediente->quantidadeIdealPorPorcao);
    } else {
      printf("Vasilha %d: Nenhuma vasilha alocada.\n", i + 1);
    }
  }
  printf("\033[0;32mServentes na bancada:\033[0m\n");
  for (int i = 0; i < 6; i++) {
    if (bancada->serventes[i] != NULL) {
      if (bancada->serventes[i]->id >= 0) {
        printf("Servente %d\n", bancada->serventes[i]->id);
      } else {
        printf("Servente inválido na posição %d.\n", i + 1);
      }
      printf("Tempo total de atendimento: %d\n", bancada->serventes[i]->tempoTotalAtendimento);
      printf("Tempo seguido de atendimento: %d\n", bancada->serventes[i]->tempoSeguidoAtendimento);
      printf("Usuarios atendidos: %d\n", bancada->serventes[i]->usuariosAtendidos);
      printf("Ingrediente a servir: %d\n\n", bancada->serventes[i]->ingredienteAServir);
    } else {
      printf("Servente %d: Nenhum servente alocado.\n", i + 1);
    }
  }
}