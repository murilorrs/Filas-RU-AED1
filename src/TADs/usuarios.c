#include "../../include/TADs/usuarios.h"

void iniciaAleatoriedade() { srand(time(NULL)); }

Usuario *criarUsuario(int id) {

  Usuario *usuario = malloc(sizeof(Usuario));
  if (usuario == NULL) {
    fprintf(stderr, "\033[0;31mERROR: Falha na alocação de memória para usuario\033[0m\n");
    exit(1);
  }

  int chanceDeSerGerado = rand() % 10;

  if (chanceDeSerGerado > 8) {
    free(usuario);
    return NULL;
  }

  usuario->id = id;
  usuario->food1Rate = rand() % 101;
  usuario->food2Rate = rand() % 101;
  usuario->food3Rate = rand() % 101;
  usuario->food4Rate = rand() % 101;
  usuario->food5Rate = rand() % 101;
  usuario->food6Rate = rand() % 101;
  usuario->tempoFila = 0;

  int vegetariano = rand() % 11;

  if (vegetariano > 8)
    usuario->eVegetariano = 1;
  else
    usuario->eVegetariano = 0;

  return usuario;
}

void contaTempoFila(Usuario *usuario) {

  if (usuario != NULL && strcmp(usuario->status, "fila") == 0) {
    usuario->tempoFila++;
  }
}

void contaTempoAtendimento(Usuario *usuario) {

  if (usuario != NULL) {
    usuario->tempoAtendimento++;
  }
}

void liberaUsuario(Usuario *usuario, float *tempoTotalEspera, int *numeroDeUsuariosAtendidos, float tempoTotalAtendimento) { // As ultimas 3 devem ser variáveis globais!
  tempoTotalEspera += usuario->tempoFila;
  tempoTotalAtendimento += usuario->tempoAtendimento;
  numeroDeUsuariosAtendidos++;
  free(usuario);
}