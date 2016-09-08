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
	clock_t tOrde = clock();
	FilaPrioridadeOrdenada fpo(1000);

	for(int i = 1000; i >= 1; --i)
		fpo.insere(i);

	for(int i = 0; i < 999; ++i) {
		//cout << "Remove: " << fpo.verifica() << endl;
		fpo.remove();
	}
	printf("Ordenada: %.4fs\n", (double)(clock() - tOrde)/CLOCKS_PER_SEC);

	clock_t tDese = clock();
	FilaPrioridadeDesordenada fpd(1000);

	for(int i = 1000; i >= 1; --i)
		fpd.insere(i);
	for(int i = 0; i < 999; ++i) {
		//cout << "Remove: " << fpd.verifica() << endl;
		fpd.remove();
	}
	printf("Desordenada: %.4fs\n", (double)(clock() - tDese)/CLOCKS_PER_SEC);

	clock_t tHeap = clock();
	FilaPrioridadeHeapBinario fphb(1000);

	for(int i = 1000; i >= 1; --i)
		fphb.insere(i);

	for(int i = 0; i < 1000; ++i) {
		//cout << "Verifica: " << fphb.verifica() << endl;
		fphb.remove();
	}
    printf("HeapBinario: %.4fs\n", (double)(clock() - tHeap)/CLOCKS_PER_SEC);

	return 0;
}