#include<iostream>
#include<string>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "aluno.h"
#define MAX 100

void addAluno(tAlunoEntrada *vetAlunos, int &n, char *mod, int RA, float p1, float p2, float pt, float po)
{
	strcpy(vetAlunos[n].nome, mod);
	vetAlunos[n].RA = RA;
	vetAlunos[n].p1 = p1;
	vetAlunos[n].p2 = p2;
	vetAlunos[n].pt = pt;
	vetAlunos[n].po = po;
	n++;

}
void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado){

for(int x = 0; x < n; x++){
    if(vetAlunos[x].nome == nomedesejado){
        printf("%s\n", vetAlunos[x].nome);
    }

}
}


void listaAlunos(){
FILE *pont_all;
pont_all = fopen("ListaDeAlunos.txt", "a");
fclose(pont_all);
}

void criaAprovados(){
FILE *pont_aprov;
pont_aprov = fopen("Aprovados.txt", "a");
fclose(pont_aprov);
printf("O arquivo com os alunos aprovados foi criado com sucesso!");
}

void criaReprovados(){
FILE *pont_reprov;
pont_reprov = fopen("Reprovados.txt", "a");
fclose(pont_reprov);
printf("O arquivo com os alunos reprovados foi criado com sucesso!");
}

/*void abreArquivo(){

printf("Digite o nome do arquivo que contem os alunos");
FILE* arqEntrada;
char nomeArq[MAX];
scanf(" %s", nomeArq);

arqEntrada = fopen(nomeArq, "r");

if( arqEntrada == NULL ){
  printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
}else{
fscanf(arqEntrada, "%s %d %f %f %f %f",nome,&RA,&p1,&p2,&pt,&po);
addAluno(vetAlunos,tamvetAlunos,nome[50],RA,p1,p2,pt,po);
}
}*/

bool aprovador(int p1, int p2, int pt){

float media = (0.35*p1)+(0.35*p2)+(0.3*pt);
if(media>=6.0){
    return true;
}else{
    return false;
}
}

void optativa(int p1, int p2, int po){
    int menor = p1;
    if(p1>p2){
        menor = p2;
    }
    if(po>menor){
        menor = po;
    }
}
