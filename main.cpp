#include <stdio.h>
#include "aluno.h"
#define MAX 100
int main(){
int op;
tAlunoEntrada vetAlunos[MAX];
int tamvetAlunos = 0;


do{
		printf("\n[1] Cadastrar um novo aluno\n");
		printf("[2] Buscar aluno\n");
		printf("[3] Ler arquivo com listagem de alunos\n");
		printf("[4] Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética\n");
		printf("[5] Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética\n");
		printf("[6] Fechar programa\n");
		printf("Opcao:\n");
		scanf("%d", &op);

		if(op == 1)
		{
		}
		else if(op == 2)
		{
		}
		else if(op == 3)
		{
		}
		else if(op == 4)
		{
		}
		else if(op == 5)
		{
		}

	}while(op != 6);

	return 0;
}
