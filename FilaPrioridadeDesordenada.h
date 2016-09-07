/**
 * @description 	Utilização de filas de prioridade com arranjo desordenado
 * @author 			Pedro Augusto - 55423
 * @date     		06/12/2016
 */
#ifndef FilaPrioridadeDesordenada_H
#define FilaPrioridadeDesordenada_H

class FilaPrioridadeDesordenada
{
	public:
		FilaPrioridadeDesordenada(int = 10);
		~FilaPrioridadeDesordenada();
		void insere(int);
		int remove();
		int verifica();
		int getTotal();
	private:
		int tamanho;
		int *filaPrioridade;
		int total;
		int posicaoMaior;
		bool cheia() { return total == tamanho; }
		bool vazia() { return total == 0; }
		bool maior(int);
		void encontreMaior();
};

#endif