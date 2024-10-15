#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../usuario/usuario.h"

#define TEMPSERMAX 60 //o atributo tempoSeguidoAtendimento tem que ser inferior a isso
#define TEMPSERINT 30 //o servente tem que descansar pelo menos isso quando entrar em descanso

typedef struct 
{
  int tempoTotalAtendimento; //Cada vez que o programa executar e o servente estiver ativo deve ser atualizada -- Serve pro cálculo do tempo médio de atendimento
  int usuariosAtendidos; //Cada vez que atender um usuário deve ser atualizada -- Serve pro cálculo do tempo médio de atendimento
  int tempoSeguidoAtendimento; //Não pode ficar mais de uma hora (60) trabalhando
  int id;
  int ingredienteAServir; ///Ingrediente (1 a 6 do cardápio) que o servente está servindo
} Servente;

Servente *criarServente(int id);

bool servirUsuario(Servente *servente,Usuario *user); //Modificar o tipo ingrediente quando implementarem ESSA FUNÇÃO VAI TER O TIPO VASILHA QUANDO IMPLEMENTAR!!!

int checaFoodRate(Usuario *user, Servente *servente); //Retorna o foodrate do usuario pra tal tipo de ingrediente

bool checaTempoTrabalho(Servente *servente); //Checa há quanto tempo o usuario ta trabalhando

bool intervaloServente(Servente *servente); // Execu
