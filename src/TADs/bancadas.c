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

  if (bancada->numServentes >= 6) {
    printf("\033[0;33mWARNING: Bancada já está cheia\033[0m\n");
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

  if (fila->frente->dado == NULL) {
    printf("Erro: dado do usuário na fila está nulo!\n");
    return NULL;
  }

  if ((bancada->vegetariana == 1 && fila->frente->dado->eVegetariano == 1) || (bancada->vegetariana == 0 && fila->frente->dado->eVegetariano == 0)) {
    Usuario *usuario = rmFila(fila);
    if (usuario != NULL) {
      bancada->estaVazia = 0;
      bancada->usuario = usuario;
    }
    return usuario;
  }

  return NULL;
}

void servirUsuario(Bancada *bancada) {

  if (bancada == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Bancada NULL \033[0m\n");
    return;
  }

  if (bancada->serventes == NULL) {
    fprintf(stderr, "ERRO: Array de serventes é NULL\n");
    return;
  }

  if (bancada->usuario == NULL) {
    fprintf(stderr, "ERRO: Nenhum usuário para servir\n");
    bancada->estaVazia = 1;
    return;
  }

  if (bancada->vasilhas == NULL) {
    fprintf(stderr, "ERRO: Array de vasilhas não inicializado\n");
    return;
  }

  printf("Antes de entrar no for\n");

  for (int i = 0; i < 6; i++) {
    if (bancada->serventes[i] == NULL) {
    fprintf(stderr, "ERRO: Servente na posição %d não inicializado\n", i);
    continue;
    }
    printf("Pré inicialização do servente\n");

    Servente *servente = bancada->serventes[i];

    if (servente == NULL) {
      fprintf(stderr, "\033[0;31mERROR: Servente %d é NULL.\033[0m\n", i + 1);
      continue;
    }

    servente->ingredienteAServir = i;

    int foodRate = checaFoodRate(bancada, servente);
    if (foodRate < 0 || foodRate > 100) {
      fprintf(stderr, "\033[0;31mERROR: Valor inválido retornado por checaFoodRate: %d\033[0m\n", foodRate);
      continue;
    }

    printf("Executou o checafoodrate\n");

    if (foodRate < 50) {
      servente->usuariosAtendidos++;
      bancada->totalAtendimentos++;
      bancada->tempoTotalAtendimento++;
      bancada->estaVazia = 1;
      continue;
    }

    printf("passou do if do foodrate\n");

    // Verifica se o índice de ingredienteAServir é válido
    if (servente->ingredienteAServir < 0 || servente->ingredienteAServir >= 6) {
      fprintf(stderr, "\033[0;31mERROR: IngredienteAServir inválido para servente %d: %d\033[0m\n", servente->id, servente->ingredienteAServir);
      continue;
    }

    // Verifica a vasilha
    if (bancada->vasilhas[servente->ingredienteAServir] == NULL) {
      fprintf(stderr, "\033[0;31mERROR: Vasilha %d é NULL para servente %d.\033[0m\n", servente->ingredienteAServir, servente->id);
      continue;
    }
    Ingrediente *ingrediente = bancada->vasilhas[i]->ingrediente;

    if (ingrediente == NULL) {
      fprintf(stderr, "\033[0;31mERROR: Ingrediente NULL para servente %d na vasilha %d.\033[0m\n", servente->id, servente->ingredienteAServir);
    printf("passou das verificacoes\n");

    if (bancada->vasilhas[servente->ingredienteAServir] == NULL) {
    fprintf(stderr, "ERRO: Vasilha %d não inicializada\n", servente->ingredienteAServir);
    continue;
    }

    Ingrediente *ingrediente = bancada->vasilhas[servente->ingredienteAServir]->ingrediente;

    if (ingrediente == NULL) {
        fprintf(stderr, "ERRO: Ingrediente na vasilha %d é NULL\n", servente->ingredienteAServir);
        continue;
    }

    printf("iniciou ingrediente\n");

    if (ingrediente == NULL) {
      fprintf(stderr, "\033[0;31mERROR: Ingrediente NULL para servente %d na vasilha %d\033[0m\n", servente->id, servente->ingredienteAServir);
      continue;
    }

    if (ingrediente->quantidadeIdealPorPorcao <= 0) {
      fprintf(stderr, "\033[0;31mERROR: Quantidade ideal por porção inválida (%d) para ingrediente de servente %d.\033[0m\n", ingrediente->quantidadeIdealPorPorcao, servente->id);
      continue;
    }

    printf("executou verificacoes null \n");

    int qtdeAserServida = calculaQtdeServida(ingrediente->quantidadeIdealPorPorcao);

    printf("executou calculaqtdeservida");

    if (qtdeAserServida <= 0) {
      fprintf(stderr, "\033[0;31mERROR: Quantidade a ser servida inválida (%d) para ingrediente de servente %d.\033[0m\n", qtdeAserServida, servente->id);
      continue;
    }

    ingrediente->quantidadeConsumida += qtdeAserServida;
    RemoveQtdeVasilha(bancada->vasilhas[servente->ingredienteAServir], qtdeAserServida);
    printf("executou removeqtdevasilha");

    servente->usuariosAtendidos++;
    servente->tempoSeguidoAtendimento++;
    servente->tempoTotalAtendimento++;

    if (checaTempoTrabalho(servente)) {
      printf("\033[0;31mServente %d entrou em intervalo.\033[0m\n", servente->id);
    }

    bancada->tempoTotalAtendimento++;
  }
  printf("\033[1;33mCheckpoint saida loop\033[0m\n\n");

  bancada->totalAtendimentos++;
  bancada->estaVazia = 1;
  bancada->usuario = NULL;
  // TODO (Caio): Retirar daqui as informações pro relatório do usuário e depois liberar a memória
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