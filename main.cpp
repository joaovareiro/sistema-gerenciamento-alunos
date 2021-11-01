#include <stdio.h>
#include<iostream>
#include<string>
#include "aluno.h"
#define MAX 100


int main(){

int op;
tAlunoEntrada vetAlunos[MAX];
int tamvetAlunos = 0;
char nome[MAX];
char nomedesejado[MAX];
int RA;
float p1;
float p2;
float pt;
float po;
float media;

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
		scanf(" %[^\n]", nome);
		scanf("%d %f %f %f %f",&RA,&p1,&p2,&pt,&po);
		addAluno(vetAlunos,tamvetAlunos,nome,RA,p1,p2,pt,po);
		}
		else if(op == 2)
		{
        //printf("Digite o nome do aluno que voce quer encontrar:");
        scanf(" %[^\n]", nomedesejado);
        buscaAluno(tamvetAlunos,vetAlunos,nomedesejado);
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

}
