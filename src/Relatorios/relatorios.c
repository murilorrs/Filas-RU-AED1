#include "../../include/Relatorios/relatorios.h"
// #include "relatorio.h"
#include <stdio.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Forma de organização pros relatórios : serventes, bancadas e ingredientes em um vetor (preciso da quantidade de cada um também). tempoTotalEspera, numeroDeUsuariosAtendidos, tempoTotalAtendimento
// --> Variáveis globais gerenciadas ao liberar a memória do usuário
//  As unicas funções que utilizam variáveis globais sao "relatorioTempoMedioEsperaUsuarios" e "tempoMedioAtendimentoUsuarios", todas as outras necessitam de uma lista para funcionarem (para que possa
//  imprimir os dados de todos elementos existentes)

void relatorioTempoMedioEsperaUsuarios(float tempoTotalEspera, int numeroUsuariosAtendidos) {
  float tempoEsperaMedioUsuarios;
  if (numeroUsuariosAtendidos == 0)
  {
    tempoEsperaMedioUsuarios = 0;
  } else{
  tempoEsperaMedioUsuarios = tempoTotalEspera / numeroUsuariosAtendidos;
  }
  printf(ANSI_COLOR_CYAN "1. Tempo médio de espera dos usuários: %.2f minutos\n" ANSI_COLOR_RESET, tempoEsperaMedioUsuarios);
}

void relatorioQuantidadeTotalIngrediente(Ingrediente *ingrediente[], int numeroElementos) {
 
  for (int i = 0; i < numeroElementos; i++) {
    int qtdTotal = ingrediente[i]->quantidadeConsumida;
    printf(ANSI_COLOR_GREEN "\t %d: %d gramas consumidas\n" ANSI_COLOR_RESET, ingrediente[i]->nome, qtdTotal);
  }
}

void tempoMedioServente(Servente *servente[], int numeroElementos) {
  for (int i = 0; i < numeroElementos; i++) {
    float tempoMedio;
    if (servente[i]->usuariosAtendidos == 0)
    {
      tempoMedio = 0;
    } else{
      tempoMedio = servente[i]->tempoTotalAtendimento / servente[i]->usuariosAtendidos;
    }
    printf(ANSI_COLOR_YELLOW "\t Servente %d - Tempo médio de atendimento: %.2f minutos\n" ANSI_COLOR_RESET, servente[i]->id, tempoMedio);
  }
}

void tempoMedioAtendimentoUsuarios(float tempoTotalAtendimento, int numeroUsuariosAtendidos) {
  float tempoMedioAtendimento;
  if (numeroUsuariosAtendidos == 0)
  {
    tempoMedioAtendimento = 0;
  } else{
  tempoMedioAtendimento = tempoTotalAtendimento / (float)numeroUsuariosAtendidos;
  }
  printf(ANSI_COLOR_CYAN "\n2. Tempo médio de atendimento dos usuários: %.2f minutos\n" ANSI_COLOR_RESET, tempoMedioAtendimento);
}

void tempoMedioBancada(Bancada *bancada[], int numeroElementos) {
  for (int i = 0; i < numeroElementos; i++) {
    int tempoMedio;
    if (bancada[i]->totalAtendimentos == 0)
    {
      tempoMedio = 0;
    } else{
      tempoMedio = bancada[i]->tempoTotalAtendimento / bancada[i]->totalAtendimentos;
    }  
    printf(ANSI_COLOR_BLUE "\t Bancada %d - Tempo médio de atendimento: %d minutos\n" ANSI_COLOR_RESET, bancada[i]->id, tempoMedio);
  }
}

void quantidadeUsuariosAtendidosServente(Servente *servente[], int numeroElementos) {
  for (int i = 0; i < numeroElementos; i++) {
    printf(ANSI_COLOR_YELLOW "\t Servente %d - Usuários atendidos: %d\n" ANSI_COLOR_RESET, servente[i]->id, servente[i]->usuariosAtendidos);
  }
}

void quantidadeUsuariosAtendidosBancada(Bancada *bancada[], int numeroElementos) {
  for (int i = 0; i < numeroElementos; i++) {
    printf(ANSI_COLOR_BLUE "\t Bancada %d - Usuários atendidos: %d\n" ANSI_COLOR_RESET, bancada[i]->id, bancada[i]->totalAtendimentos);
  }
}

void relatorioFinal(float tempoTotalEspera, int numeroUsuariosAtendidos, float tempoTotalAtendimento, Ingrediente *ingredientes[], int numIngredientes, Servente *serventes[], int numServentes, Bancada *bancadas[], int numBancadas) {

  char linha1[71], linha2[71];
  for (int i = 0; i < 70; i++) {
    linha1[i] = (i % 2 == 0) ? '=' : '*';
    linha2[i] = (i % 2 == 0) ? '*' : '=';
  }
  linha1[70] = linha2[70] = '\0';

  printf("\n" ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, linha1);
  printf(ANSI_COLOR_GREEN "                RELATÓRIO FINAL DO RU\n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN "%s\n\n" ANSI_COLOR_RESET, linha2);

  relatorioTempoMedioEsperaUsuarios(tempoTotalEspera, numeroUsuariosAtendidos);

  tempoMedioAtendimentoUsuarios(tempoTotalAtendimento, numeroUsuariosAtendidos);

  printf(ANSI_COLOR_GREEN "\n3. Quantidade total consumida de ingredientes:\n" ANSI_COLOR_RESET);
  relatorioQuantidadeTotalIngrediente(ingredientes, numIngredientes);

  printf(ANSI_COLOR_YELLOW "\n4. Tempo médio de atendimento dos serventes:\n" ANSI_COLOR_RESET);
  tempoMedioServente(serventes, numServentes);

  printf(ANSI_COLOR_YELLOW "\n5. Quantidade de usuários atendidos pelos serventes:\n" ANSI_COLOR_RESET);
  quantidadeUsuariosAtendidosServente(serventes, numServentes);

  printf(ANSI_COLOR_BLUE "\n6. Tempo médio de atendimento das bancadas:\n" ANSI_COLOR_RESET);
  tempoMedioBancada(bancadas, numBancadas);

  printf(ANSI_COLOR_BLUE "\n7. Quantidade de usuários atendidos pelas bancadas:\n" ANSI_COLOR_RESET);
  quantidadeUsuariosAtendidosBancada(bancadas, numBancadas);

  printf("\n" ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, linha1);
  printf(ANSI_COLOR_GREEN "                    RU FECHADO\n" ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN "%s\n\n" ANSI_COLOR_RESET, linha2);
}