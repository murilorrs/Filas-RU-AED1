#include "../include/usuario/usuario.h"
#include <stdio.h>

int main() {

  printf("Hello, World!\n");

  Usuario *usuario = criarUsuario(1);

  printf("%d\n", usuario->food1Rate);
  printf("%d\n", usuario->food2Rate);
  printf("%d\n", usuario->food3Rate);
  printf("%d\n", usuario->food4Rate);
  printf("%d\n", usuario->food5Rate);
  printf("%d\n", usuario->food6Rate);
  printf("%d\n", usuario->eVegetariano);

  return 0;
}