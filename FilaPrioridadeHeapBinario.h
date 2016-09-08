/**
 * @description 	Utilização de filas de prioridade usando heap binário implementado com arranjo
 * @author 			Pedro Augusto - 55423
 * @date 			06/09/2016
 */
#ifndef FilaPrioridadeHeapBinario_H
#define FilaPrioridadeHeapBinario_H

class FilaPrioridadeHeapBinario
{
	public:
		FilaPrioridadeHeapBinario(int = 10);
		~FilaPrioridadeHeapBinario();
		void insere(int);
		int remove();
		int verifica();
		int getTotal();
	private:
		int tamanho;
		int *filaPrioridade;
		int total;
		bool cheia() { return total == tamanho; }
		bool vazia() { return total == 0; }
		int getPai(int posicao) { return posicao/2; }
		int getEsquerda(int posicao) { return 2*posicao; }
		int getDireita(int posicao) { return 2*posicao+1; }
		void corrigeSubindo(int);
		void corrigeDescendo(int);
};

#endif