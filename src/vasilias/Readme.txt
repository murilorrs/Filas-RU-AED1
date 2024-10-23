	IMPORTANTE

VASILHAS: Cada vasilha vai conter 1 ingrediente
CAPACIDADE: Cada vasilha tem uma capacidade definida em gramas
QUANTIDADE: Cada usuario vai ser ser servido com uma quantidade especifica de um ingrediente
SUBSTITUIÇÃO: Quando a vasilha de um ingrediente acabar, deve ser considerado um tempo para substituir por uma nova vasilha cheia.

	IMPLEMENTAÇÃO: 

Definir macros para a capacidade das vasilhas e o tempo necessario para substituir quando esvaziarem.
Controlar a quantidade de ingrediente disponivel em cada vasilha.
Funcao de substituicao: Quando a vasilha esvaziar, iniciar o tempo de substituição e repor o ingrediente.
Relatorios: Ao final, o programa deve mostrar a quantidade total consumida de cada ingrediente. (Mais pra frente) 

1.
MACROS: 

#define CAPING1 5000  ==> Capacidade da vasilha do ingrediente 1 (em gramas)
#define TEMPING1 30   ==> Tempo para substituir a vasilha do ingrediente 1 (em segundos)
#define	.......
#define .......

Isso seria repetido para todos os ingredientes...

2. 
ESTRUTURA PARA VASILHAS

	typedef struct {
    		int capacidade;      // Capacidade máxima da vasilha
    		int quantidadeAtual; // Quantidade atual de ingrediente
    		int tempoReposicao;  // Tempo para reposição da vasilha
		} Vasilha;
Essa estrutura deve armazenar a quantidade atual de ingrediente, a capacidade total, e o tempo de reposição.

3. 
Serão criados varias vasilhas (uma para cada ingrediente). Ex:

Vasilha vasilha1 = {CAPING1, CAPING1, TEMPING1};  // Inicializa a vasilha com capacidade cheia


4.
quando um usuario for servido, sera diminuido a quantidade de ingredientes na vasilha; 

If (vasilha => quantidade atual >= quantidade servida) então { vasilha => quantidade atual -= quantidade servida}
else {
        // A vasilha esvaziou, precisa repor
        printf("Vasilha esvaziou! Iniciando reposição...\n");
        vasilha->quantidadeAtual = vasilha->capacidade;  // Repor a vasilha
    }	

Nesse exemplo, se a quantidade disponível na vasilha for suficiente, ela é reduzida. Se não for, a vasilha é reposta com a capacidade total.

5.
O tempo de reposição será implementado posteriormente. 



========================================================================================================================================================================================================





