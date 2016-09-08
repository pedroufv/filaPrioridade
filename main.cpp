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
	FilaPrioridadeOrdenada fpo(10000);

	clock_t tempInsOrde = clock();
	for(int i = 10000; i >= 1; --i)
		fpo.insere(i);
	printf("Ordenada - Insere: %.4fs\n", (double)(clock() - tempInsOrde)/CLOCKS_PER_SEC);

	clock_t tempRemOrde = clock();
	for(int i = 0; i < 9999; ++i) {
		//cout << "Remove: " << fpo.verifica() << endl;
		fpo.remove();
	}
	printf("Ordenada - Remove: %.4fs\n", (double)(clock() - tempRemOrde)/CLOCKS_PER_SEC);

	FilaPrioridadeDesordenada fpd(10000);

	clock_t tempInsDese = clock();
	for(int i = 10000; i >= 1; --i)
		fpd.insere(i);
	printf("Desordenada - Insere: %.4fs\n", (double)(clock() - tempInsDese)/CLOCKS_PER_SEC);

	clock_t tempRemDese = clock();
	for(int i = 0; i < 9999; ++i) {
		//cout << "Remove: " << fpd.verifica() << endl;
		fpd.remove();
	}
	printf("Desordenada - Remove: %.4fs\n", (double)(clock() - tempRemDese)/CLOCKS_PER_SEC);

	FilaPrioridadeHeapBinario fphb(10000);

	clock_t tempInsHeap = clock();
	for(int i = 10000; i >= 1; --i)
		fphb.insere(i);
	printf("HeapBinario - Insere: %.4fs\n", (double)(clock() - tempInsHeap)/CLOCKS_PER_SEC);

	clock_t tempRemHeap = clock();
	for(int i = 0; i < 10000; ++i) {
		//cout << "Verifica: " << fphb.verifica() << endl;
		fphb.remove();
	}
    printf("HeapBinario - Remove: %.4fs\n", (double)(clock() - tempRemHeap)/CLOCKS_PER_SEC);

	return 0;
}

/*
Ordenada - Insere: 384.2424s
Ordenada - Remove: 0.0001s
Desordenada - Insere: 0.0001s
Desordenada - Remove: 0.5054s
HeapBinario - Insere: 0.0001s
HeapBinario - Remove: 0.0024s
*/