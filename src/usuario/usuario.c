#include "../../include/usuario/usuario.h"

Usuario *criarUsuario(int id) {
  srand(time(NULL));

  Usuario *usuario = malloc(sizeof(Usuario));

  if (usuario == NULL) {
    fprintf(stderr, "Erro ao alocar memória para o usuário.\n");
    exit(1);
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

  return usuario;
}
