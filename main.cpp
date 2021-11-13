#include <stdio.h>
#include<string>
#include "aluno.h"
#define MAX 100

int main(){
int op;
tAlunoEntrada vetAlunos[MAX],vetAlunosCopia[MAX];
int tamvetAlunos = 0;
char nome[MAX];
char nomedesejado[MAX];
int RA;
double p1;
double p2;
double pt;
double po;
double media;

do{
		printf("\n[1] Cadastrar um novo aluno\n");
		printf("[2] Buscar aluno\n");
		printf("[3] Ler arquivo com listagem de alunos\n");
		printf("[4] Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética\n");
		printf("[5] Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética\n");
		printf("[6] Fechar programa\n");
		printf("Opcao:\n");
		scanf("%d", &op);

		if(op == 1){
        printf("Digite o nome do aluno(sem acentos e cedilhas):\n");
            scanf(" %[^\n]", nome);
        printf("Digite o RA:\n");
        scanf("%d",&RA);
        printf("Digite as notas da P1, P2, do Trabalho e a nota da Prova optativa, caso o aluno não tenha feito a prova optativa digite 0 no lugar da nota da PO\n");
		scanf("%lf %lf %lf %lf",&p1,&p2,&pt,&po);
		addAluno(vetAlunos,tamvetAlunos,nome,RA,p1,p2,pt,po);
		}
		else if(op == 2){
        printf("Digite o nome do aluno(sem acentos e cedilhas):\n");
        scanf(" %[^\n]", nomedesejado);
        buscaAluno(tamvetAlunos,vetAlunos,nomedesejado);
		}
		else if(op == 3){
        abreArquivo(vetAlunos,tamvetAlunos);
		}
		else if(op == 4){
        copiar(tamvetAlunos,vetAlunos,vetAlunosCopia);
        criaAprovados(tamvetAlunos,vetAlunosCopia);
		}
		else if(op == 5){
        copiar(tamvetAlunos,vetAlunos,vetAlunosCopia);
        criaReprovados(tamvetAlunos,vetAlunosCopia);
		}
	}while(op != 6);
        if(op == 6){
        copiar(tamvetAlunos,vetAlunos,vetAlunosCopia);
        criaAtual(tamvetAlunos,vetAlunos);
    }
}
