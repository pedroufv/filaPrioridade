/**
 * @description 	Utilização de filas de prioridade com arranjo ordenado
 * @author 			Pedro Augusto - 55423
 * @date     		06/12/2016
 */
#ifndef FilaPrioridadeOrdenada_H
#define FilaPrioridadeOrdenada_H

class FilaPrioridadeOrdenada
{
	public:
		FilaPrioridadeOrdenada(int = 10);
		~FilaPrioridadeOrdenada();
		void insere(int);
		int remove();
		int verifica();
		int getTotal();
	private:
		int max;
		int *filaPrioridade;
		int total;
		bool cheia() { return total == max; }
		bool vazia() { return total == 0; }
		void ordena(int, int);
};

#endif