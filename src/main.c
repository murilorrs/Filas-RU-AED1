#include "../include/App/app.h"

int main() {
  int choice;
  int param1, param2;
  system("clear");

  while (1) {
    printf("\033[1;34m========================================\033[0m\n");
    printf("\033[1;36m        SIMULADOR DO RESTAURANTE \033[0m\n");
    printf("\033[1;34m========================================\033[0m\n\n");

    printf("\033[1;33mMenu:\033[0m\n");
    printf("\033[1;32m1.\033[0m Executar simulacao 1 - Cafe da Manha\n");
    printf("\033[1;32m2.\033[0m Executar simulacao 2 - Almoco\n");
    printf("\033[1;32m3.\033[0m Executar simulacao 3 - Jantar\n");
    printf("\033[1;35m4.\033[0m Executar todas as simulacoes\n");
    printf("\033[1;31m0.\033[0m Sair\n");

    printf("\n\033[1;37m=> \033[0m");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      realizarSimulacao(10, 1);
      break;
    case 2:
      realizarSimulacao(210, 2);
      break;
    case 3:
      realizarSimulacao(150, 3);
      break;
    case 4:
      realizarSimulacao(5, 1);
      realizarSimulacao(10, 2);
      realizarSimulacao(10, 3);
      break;
    case 5:
    case 0:
      printf("\033[1;31mSaindo da simulacao.\033[0m\n");
      return 0;
    default:
      printf("\033[1;31mOpcao invalida. Tente novamente! \033[0m\n");
    }

    printf("\n\033[1;34m========================================\033[0m\n");
    printf("\033[1;37mPressione Enter para continuar...\033[0m\n");
    getchar();
    getchar();
    system("clear");
  }

  return 0;
}
