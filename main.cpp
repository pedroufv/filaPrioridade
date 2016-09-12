/**
 * @description 	Utilização de filas de prioridade
 * @author 			Pedro Augusto - 55423
 * @date 			06/09/2016
 */
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include "FilaPrioridadeOrdenada.h"
#include "FilaPrioridadeDesordenada.h"
#include "FilaPrioridadeHeapBinario.h"

using namespace std;

int main(int argc, char *argv[])
{

	int numeroIteracoes;

	cout << "Entre com o número de iterações: ";
	cin >> numeroIteracoes;

	FilaPrioridadeOrdenada fpo(numeroIteracoes);

	clock_t tempInsOrde = clock();
	for(int i = numeroIteracoes; i >= 1; --i)
		fpo.insere(i);
	printf("Ordenada - Insere: %.6fs\n", (double)(clock() - tempInsOrde)/CLOCKS_PER_SEC);

	clock_t tempRemOrde = clock();
	for(int i = 0; i < numeroIteracoes-1; ++i) {
		//cout << "Remove: " << fpo.verifica() << endl;
		fpo.remove();
	}
	printf("Ordenada - Remove: %.6fs\n", (double)(clock() - tempRemOrde)/CLOCKS_PER_SEC);

	FilaPrioridadeDesordenada fpd(numeroIteracoes);

	clock_t tempInsDese = clock();
	for(int i = numeroIteracoes; i >= 1; --i)
		fpd.insere(i);
	printf("Desordenada - Insere: %.6fs\n", (double)(clock() - tempInsDese)/CLOCKS_PER_SEC);

	clock_t tempRemDese = clock();
	for(int i = 0; i < numeroIteracoes-1; ++i) {
		//cout << "Remove: " << fpd.verifica() << endl;
		fpd.remove();
	}
	printf("Desordenada - Remove: %.6fs\n", (double)(clock() - tempRemDese)/CLOCKS_PER_SEC);

	FilaPrioridadeHeapBinario fphb(numeroIteracoes);

	clock_t tempInsHeap = clock();
	for(int i = numeroIteracoes; i >= 1; --i)
		fphb.insere(i);
	printf("HeapBinario - Insere: %.6fs\n", (double)(clock() - tempInsHeap)/CLOCKS_PER_SEC);

	clock_t tempRemHeap = clock();
	for(int i = 0; i < numeroIteracoes; ++i) {
		//cout << "Verifica: " << fphb.verifica() << endl;
		fphb.remove();
	}
    printf("HeapBinario - Remove: %.6fs\n", (double)(clock() - tempRemHeap)/CLOCKS_PER_SEC);

	return 0;
}

/*
Realizar escalas de entrada entrada entre 1000 e 9000

#numeroIteracoes = 10000
Ordenada - Insere: 1027.4855070000s
Ordenada - Remove: 0.0001850000s
Desordenada - Insere: 0.0001940000s
Desordenada - Remove: 1.1181360000s
HeapBinario - Insere: 0.0002410000s
HeapBinario - Remove: 0.0043530000s

#numeroIteracoes = 1000
Ordenada - Insere: 1.0485910000s
Ordenada - Remove: 0.0000180000s
Desordenada - Insere: 0.0000200000s
Desordenada - Remove: 0.0113520000s
HeapBinario - Insere: 0.0000240000s
HeapBinario - Remove: 0.0003130000s


#numeroIteracoes = 100
Ordenada - Insere: 0.0028530000s
Ordenada - Remove: 0.0000040000s
Desordenada - Insere: 0.0000060000s
Desordenada - Remove: 0.0002660000s
HeapBinario - Insere: 0.0000070000s
HeapBinario - Remove: 0.0000480000s

#numeroIteracoes = 10
Ordenada - Insere: 0.0000110000s
Ordenada - Remove: 0.0000010000s
Desordenada - Insere: 0.0000020000s
Desordenada - Remove: 0.0000050000s
HeapBinario - Insere: 0.0000020000s
HeapBinario - Remove: 0.0000030000s

#numeroIteracoes = 1
Ordenada - Insere: 0.0000020000s
Ordenada - Remove: 0.0000010000s
Desordenada - Insere: 0.0000010000s
Desordenada - Remove: 0.0000010000s
HeapBinario - Insere: 0.0000010000s
HeapBinario - Remove: 0.0000020000s
*/