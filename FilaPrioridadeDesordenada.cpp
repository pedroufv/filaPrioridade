/**
 * @description 	Utiliza��o de filas de prioridade com arranjo desordenado
 * @author 			Pedro Augusto - 55423
 * @date     		06/12/2016
 */
#include "FilaPrioridadeDesordenada.h"

/**
 * construtor
 */
FilaPrioridadeDesordenada::FilaPrioridadeDesordenada(int tam)
{
	tamanho = tam;
	posicaoMaior = -1;
	filaPrioridade = new int [tamanho];
	for(int i = 0; i < tamanho; i++)
		filaPrioridade[i] = -1;
	total = 0;
}

/**
 * destrutor
 */
FilaPrioridadeDesordenada::~FilaPrioridadeDesordenada()
{
	delete [] filaPrioridade;
}

/**
 * insere um inteiro
 */
void FilaPrioridadeDesordenada::insere(int elemento)
{
	if(cheia())
		return;

	filaPrioridade[total] = elemento;

	if(maior(elemento))
		posicaoMaior = total;

	++total;
}

/**
 * retorna e remove um inteiro com maior prioridade
 */
int FilaPrioridadeDesordenada::remove()
{
	if(vazia())
		return -1;

	int topo = verifica();

	for(int i = posicaoMaior; i < total; ++i)
	{
		if(filaPrioridade[i] != -1) {
			filaPrioridade[i] = filaPrioridade[i+1];
		}
	}

	--total;

	encontreMaior();

	return topo;
}

/**
 * verifica se o elemento � o maior da fila
 */
bool FilaPrioridadeDesordenada::maior(int elemento)
{
	for(int i = 0; i < total; ++i)
	{
		if(elemento < filaPrioridade[i])
			return false;
	}

	return true;
}

/**
 * encontra o elemento maior da fila
 */
void FilaPrioridadeDesordenada::encontreMaior()
{
	for(int i = 0; i < total; ++i)
	{
		if(maior(filaPrioridade[i]))
			posicaoMaior = i;
	}
}

/**
 * retorna um inteiro com maior prioridade
 */
int FilaPrioridadeDesordenada::verifica()
{
	return filaPrioridade[posicaoMaior];
}

/**
 * retorna o n�mero de elementos
 */
int FilaPrioridadeDesordenada::getTotal()
{
	return total;
}