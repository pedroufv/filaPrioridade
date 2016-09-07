/**
 * @description 	Utilização de filas de prioridade com arranjo ordenado
 * @author 			Pedro Augusto - 55423
 * @date 			06/09/2016
 */
#include "FilaPrioridadeOrdenada.h"

/**
 * construtor
 */
FilaPrioridadeOrdenada::FilaPrioridadeOrdenada(int tamanho)
{
	max = tamanho;
	filaPrioridade = new int [max];
	for(int i = 0; i < max; i++)
		filaPrioridade[i] = -1;
	total = 0;
}

/**
 * destrutor
 */
FilaPrioridadeOrdenada::~FilaPrioridadeOrdenada()
{
	delete [] filaPrioridade;
}

/**
 * insere um inteiro
 * @params int elemento
 * @return void
 */
void FilaPrioridadeOrdenada::insere(int elemento)
{
	if(cheia())
		return;

	filaPrioridade[total] = elemento;
	++total;

	ordena(0, total);
}

/**
 * retorna e remove um inteiro com maior prioridade
 * @return int
 */
int FilaPrioridadeOrdenada::remove()
{
	if(vazia())
		return -1;

	int topo = verifica();

	filaPrioridade[total-1] = -1;
	--total;

	return topo;
}

/**
 * QuickSort
 * @params int inicio, int fim
 * @return void
 */
void FilaPrioridadeOrdenada::ordena(int inicio, int fim)
{
	int aux, pivo = inicio;

    for(int i = inicio+1; i <= fim; i++){
        int j = i;

        if(filaPrioridade[j] < filaPrioridade[pivo] && (filaPrioridade[j] != -1)){
			aux = filaPrioridade[j];
			while(j > pivo){
				filaPrioridade[j] = filaPrioridade[j-1];
	            j--;
			}
			filaPrioridade[j] = aux;
         	pivo++;
        }
    }

    if(pivo-1 >= inicio){
        ordena(inicio,pivo-1);
    }

    if(pivo+1 <= fim){
        ordena(pivo+1,fim);
    }
}

/**
 * retorna um inteiro com maior prioridade
 * @return int
 */
int FilaPrioridadeOrdenada::verifica()
{
	if(vazia())
		return -1;

	return filaPrioridade[total-1];
}

/**
 * retorna o número de elementos
 * @return int
 */
int FilaPrioridadeOrdenada::getTotal()
{
	return total;
}