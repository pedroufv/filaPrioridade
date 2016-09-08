/**
 * @description 	Utilização de filas de prioridade usando heap binário implementado com arranjo
 * @author 			Pedro Augusto - 55423
 * @date 			06/09/2016
 */
#include <iostream>
#include "FilaPrioridadeHeapBinario.h"

using namespace std;

/**
 * construtor
 */
FilaPrioridadeHeapBinario::FilaPrioridadeHeapBinario(int tam)
{
	tamanho = tam;
	filaPrioridade = new int [tamanho+1];
	for(int i = 0; i < tamanho; i++)
		filaPrioridade[i] = -1;
	total = 0;
}

/**
 * destrutor
 */
FilaPrioridadeHeapBinario::~FilaPrioridadeHeapBinario()
{
	delete [] filaPrioridade;
}

/**
 * insere um inteiro
 * @params int elemento
 * @return void
 */
void FilaPrioridadeHeapBinario::insere(int elemento)
{
	if(cheia())
		return;

	filaPrioridade[++total] = elemento;

	corrigeSubindo(total);
}

/**
 * retorna e remove um inteiro com maior prioridade
 * @return int
 */
int FilaPrioridadeHeapBinario::remove()
{
	if(vazia())
		return -1;

	int topo = verifica();

	filaPrioridade[1] = -1;

	corrigeDescendo(1);

	total--;

	return topo;
}

/**
 * retorna um inteiro com maior prioridade
 * @return int
 */
int FilaPrioridadeHeapBinario::verifica()
{
	if(vazia())
		return -1;

	return filaPrioridade[1];
}

/**
 * retorna o número de elementos
 * @return int
 */
int FilaPrioridadeHeapBinario::getTotal()
{
	return total;
}

/**
 * corrige os elementos subindo
 * @params int posicao
 * @return void
 */
void FilaPrioridadeHeapBinario::corrigeSubindo(int posicao)
{
	if(posicao == 1)
		return;

    int pai = getPai(posicao);
    if(filaPrioridade[posicao] > filaPrioridade[pai]){
        swap(filaPrioridade[posicao], filaPrioridade[pai]);

        corrigeSubindo(pai);
    }
}

/**
 * corrige os elementos descendo
 * @params int posicao
 * @return void
 */
void FilaPrioridadeHeapBinario::corrigeDescendo(int posicao)
{
	int direita = getDireita(posicao);
    int esquerda = getEsquerda(posicao);
    int maior = posicao;

    if(direita <= total && filaPrioridade[direita] > filaPrioridade[maior])
    	maior = direita;

    if(esquerda <= total && filaPrioridade[esquerda] > filaPrioridade[maior])
    	maior = esquerda;

    if(maior != posicao){
        swap(filaPrioridade[posicao], filaPrioridade[maior]);
        corrigeDescendo(maior);
    }
}