#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MAX 100

typedef struct {
  int id;
  double food1Rate;
  double food2Rate;
  double food3Rate;
  double food4Rate;
  double food5Rate;
  double food6Rate;
  int tempoFila;
  int tempoBancada;
  int eVegetariano;
} Usuario;

void inicializarAleatoriedade() { srand(time(NULL)); }

Usuario *criarUsuario(int id) {

  Usuario *usuario = (Usuario *)malloc(sizeof(Usuario));

  if (usuario == NULL) {
    fprintf(stderr, "Erro ao alocar memória para o usuário.\n");
    exit(EXIT_FAILURE);
  }

  usuario->id = id;
  usuario->food1Rate = (double)rand() / RAND_MAX;
  usuario->food2Rate = (double)rand() / RAND_MAX;
  usuario->food3Rate = (double)rand() / RAND_MAX;
  usuario->food4Rate = (double)rand() / RAND_MAX;
  usuario->food5Rate = (double)rand() / RAND_MAX;
  usuario->food6Rate = (double)rand() / RAND_MAX;
  usuario->tempoFila = 0;
  usuario->tempoBancada = 0;
  usuario->eVegetariano = (int)rand() % 2;

  return usuario;
}
