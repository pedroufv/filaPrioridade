/**
 * @description 	Utilização de filas de prioridade
 * @author 			Pedro Augusto - 55423
 * @date     		06/12/2016
 */
#include <iostream>
#include "FilaPrioridadeOrdenada.h"
#include "FilaPrioridadeDesordenada.h"

using namespace std;

int main(int argc, char *argv[])
{
	FilaPrioridadeOrdenada fpo(5);

	fpo.insere(5);
	fpo.insere(40);
	fpo.insere(3);
	fpo.insere(2);
	fpo.insere(12);

	fpo.remove();
	fpo.remove();
	cout << fpo.verifica() << endl;

	FilaPrioridadeDesordenada fpd(5);

	fpd.insere(5);
	fpd.insere(40);
	fpd.insere(3);
	fpd.insere(2);
	fpd.insere(12);

	fpd.remove();
	fpd.remove();
	cout << fpd.verifica() << endl;

	return 0;
}