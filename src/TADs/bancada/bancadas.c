#include "../../../include/TADs/bancadas/bancadas.h"
#include "../../../include/TADs/filas/filas.h"
#include "../../../include/TADs/usuarios/usuarios.h"
#include <stdio.h>

Bancada *criaBancada(int id, int vegetariana) {
  Bancada *bancada = malloc(sizeof(Bancada));
  bancada->id = id;
  bancada->totalAtendimentos = 0;
  bancada->tempoTotalAtendimento = 0;
  bancada->vegetariana = vegetariana;
  bancada->estaVazia = 1;
  return bancada;
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
    return usuario; // Retorna o ponteiro para o usuário
  }
  return NULL; // Caso não tenha usuário para atender
}

Usuario *removeUsuarioBancada(Bancada *bancada) {
  bancada->estaVazia = 1;
  return NULL;
}

void exibeBancada(Bancada *bancada) { // !!! Essa funcao ta dando segmetation fault algumas vezes, corrigir para nova versao
  printf("BANCADA %d:\n", bancada->id);
  printf("Total de atendimentos: %d\n", bancada->totalAtendimentos);
  printf("Tempo total de atendimento: %d\n", bancada->tempoTotalAtendimento);
  printf("Vegetariana: %d\n", bancada->vegetariana);
  printf("Esta vazia: %d\n", bancada->estaVazia);
  printf("Usuario na bancada: %d\n\n", bancada->usuario->id);
}