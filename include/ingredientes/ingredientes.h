#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definir macro de ingredientes
#define DEFINIR_INGREDIENTES(ing1, ing2, ing3, ing4, ing5, ing6)

// Definir aceitacao dos ingredientes
#define DEFINIR_ACEITACAO(ing1, aceit1, ing2, aceit2, ing3, aceit3, ing4, aceit4, ing5, aceit5, ing6, aceit6)

// Definir probabilidade de aceitacao
#define NPROBING1 70  // 70% de chance de aceitar ing1
#define NPROBING2 80  // 80% de chance de aceitar ing2
#define NPROBING3 90  // 90% de chance de aceitar ing3
#define NPROBING4 50  // 50% de chance de aceitar ing4
#define NPROBING5 60  // 60% de chance de aceitar ing5
#define NPROBING6 40  // 40% de chance de aceitar ing6

// Simular aceitaaoo de ingredientes
#define AVALIAR_ACEITACAO(probabilidade) ((rand() % 100) < (probabilidade))

// Definir quantidades minima e maxima dos ingredientes
#define DEFINIR_QTD_ING(ing1, min1, max1, ing2, min2, max2, ing3, min3, max3, ing4, min4, max4, ing5, min5, max5, ing6, min6, max6)

// Definir tempo de substituicao das vasilhas
#define DEFINIR_TEMPO_SUBSTITUICAO(ing1, t1, ing2, t2, ing3, t3, ing4, t4, ing5, t5, ing6, t6)

// Definir quantidade minima para substituicao
#define DEFINIR_MINIMO_SUBSTITUICAO(ing1, s1, ing2, s2, ing3, s3, ing4, s4, ing5, s5, ing6, s6)