/**
 * @description 	Utilização de filas de prioridade
 * @author 			Pedro Augusto - 55423
 * @date 			06/09/2016
 */
#include <iostream>
#include "FilaPrioridadeOrdenada.h"
#include "FilaPrioridadeDesordenada.h"
#include "FilaPrioridadeHeapBinario.h"

using namespace std;

int main(int argc, char *argv[])
{
	FilaPrioridadeOrdenada fpo(8);

	fpo.insere(5);
	fpo.insere(40);
	fpo.insere(3);
	fpo.insere(2);
	fpo.insere(12);

	cout << "Remove: " << fpo.remove() << endl;
	cout << "Remove: " << fpo.remove() << endl;
	cout << "Remove: " << fpo.remove() << endl;
	cout << "Remove: " << fpo.remove() << endl;
	cout << "Verifica: " << fpo.verifica() << endl;

	FilaPrioridadeDesordenada fpd(5);

	fpd.insere(5);
	fpd.insere(40);
	fpd.insere(3);
	fpd.insere(2);
	fpd.insere(12);

	cout << "Remove: " << fpd.remove() << endl;
	cout << "Remove: " << fpd.remove() << endl;
	cout << "Remove: " << fpd.remove() << endl;
	cout << "Remove: " << fpd.remove() << endl;
	cout << "Remove: " << fpd.remove() << endl;
	cout << "Remove: " << fpd.remove() << endl;
	cout << "Verifica: " << fpd.verifica() << endl;

	FilaPrioridadeHeapBinario fphb(5);

	fphb.insere(5);
	fphb.insere(40);
	fphb.insere(3);
	fphb.insere(2);
	fphb.insere(12);

	cout << "Remove: " << fphb.remove() << endl;
	cout << "Remove: " << fphb.remove() << endl;
	cout << "Remove: " << fphb.remove() << endl;
	cout << "Verifica: " << fphb.verifica() << endl;

	return 0;
}