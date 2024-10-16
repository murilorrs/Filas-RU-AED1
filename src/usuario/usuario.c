#include "../../include/usuario/usuario.h"

void iniciaAleatoriedade() { srand(time(NULL)); }

Usuario *criarUsuario(int id) {

  Usuario *usuario = malloc(sizeof(Usuario));
  if (usuario == NULL) {
    fprintf(stderr, "Erro ao alocar memória para o usuário.\n");
    exit(1);
  }

  int chanceDeSerGerado = rand() % 2;

  if (chanceDeSerGerado == 0) {
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

  int vegetariano = rand() % 11;

  if (vegetariano > 7)
    usuario->eVegetariano = 1;
  else
    usuario->eVegetariano = 0;

  usuario->tempoFila = 0;

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