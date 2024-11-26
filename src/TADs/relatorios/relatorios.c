#include "relatorio.h"

void relatorioTempoMedioEsperaUsuarios(Usuario usuarios[], int n){ //Como não foi criada uma variável global ou forma global teremos que percorrer um vetor com todos usuários atendidos

    float tempoTotalEspera = 0;
    for (int i = 0; i < n; i++)
    {
        tempoTotalEspera += usuarios[i].tempoFila;
    }

    float tempoEsperaMedioUsuarios = tempoTotalEspera/n;

    printf("\n");
    printf("=========================================\n");
    printf(" Tempo médio de espera dos usuários: %.2f minutos\n", tempoEsperaMedioUsuarios);
    printf("=========================================\n");
    printf("\n");

} 


void relatorioQuantidadeTotalIngrediente(Ingrediente *Ingrediente){
   int qtdTotal = Ingrediente->quantidadeConsumida;

    printf("\n");
    printf("=========================================\n");
    printf("Quantidade total consumido de %s : %d gramas\n", Ingrediente->nome, qtdTotal);
    printf("=========================================\n");
    printf("\n");
}

void tempoMedioServente(Servente *servente){
    int tempoMedio = servente->tempoTotalAtendimento / servente->usuariosAtendidos;

    printf("\n");
    printf("=========================================\n");
    printf("Tempo médio de atendimento do servente %d : %d minutos", servente->id, tempoMedio);
    printf("=========================================\n");
    printf("\n");
}

void tempoMedioAtendimentoUsuarios(Usuario usuarios[], int n){ //Como não foi criada uma variável global ou forma global teremos que percorrer um vetor com todos usuários atendidos

    float tempoTotalAtendimento = 0;
    for (int i = 0; i < n; i++)
    {
        tempoTotalAtendimento += usuarios[i].tempoAtendimento;
    }

    int tempoMedioAtendimento = tempoTotalAtendimento / n;

    printf("\n");
    printf("=========================================\n");
    printf("Tempo médio de atendimento dos usuários : %d minutos", tempoMedioAtendimento);
    printf("=========================================\n");
    printf("\n");
}

void tempoMedioBancada(Bancada *bancada){
    int tempoMedio = bancada->tempoTotalAtendimento / bancada->totalAtendimentos;

    printf("\n");
    printf("=========================================\n");
    printf("Tempo médio de atendimento da bancada %d : %d minutos", bancada->id, tempoMedio);
    printf("=========================================\n");
    printf("\n");
}

void quantidadeUsuariosAtendidosServente(Servente *servente){
    printf("\n");
    printf("=========================================\n");
    printf("Quantidade de usuários atendidos pelo servente %d : %d usuários", servente->id, servente->usuariosAtendidos);
    printf("=========================================\n");
    printf("\n");
}

void quantidadeUsuariosAtendidosBancada(Bancada *bancada){
    printf("\n");
    printf("=========================================\n");
    printf("Quantidade de usuários atendidos pela bancada %d : %d usuários", bancada->id, bancada->totalAtendimentos);
    printf("=========================================\n");
    printf("\n");
}