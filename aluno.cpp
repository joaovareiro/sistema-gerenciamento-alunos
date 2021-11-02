#include <stdio.h>
#include <string.h>
#include "aluno.h"
#define MAX 100

void addAluno(tAlunoEntrada *vetAlunos, int &n, char *mod, int RA, float p1, float p2, float pt, float po)
{
    float r1,r2,r3;
	strcpy(vetAlunos[n].nome, mod);
	vetAlunos[n].RA = RA;
	vetAlunos[n].p1 = p1;
	vetAlunos[n].p2 = p2;
	vetAlunos[n].pt = pt;
	vetAlunos[n].po = po;
	n++;
    optativa(p1,p2,pt,po,&r1,&r2,&r3);
    vetAlunos[n].media= (0.35*r1)+(0.35*r2)+(0.3*r3);
    if(aprovador(r1,r2,r3)==true){
    vetAlunos[n].situacao=1;
    }else{
    vetAlunos[n].situacao=0;
    }
}

void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado){
int cont = 0;
for(int x = 0; x < n; x++){
if(strstr(vetAlunos[x].nome,nomedesejado)){
    printf("%s %.1f ",vetAlunos[x].nome,vetAlunos[x+1].media);
    if(vetAlunos[x+1].situacao==1){
    printf("Aprovado\n");
    }else{
    printf("Reprovado\n");
    }
    cont ++;
  }
}
  if(cont == 0){
      printf("Aluno não encontrado na base de dados.\n");
  }
}

void optativa(float p1, float p2, float pt, float po, float* r1, float* r2, float* r3){
    float temp = p1;
    float maior = p2;
    float trabalho = pt;
    if(p1>p2){
        maior = p1;
        temp = p2;
    }
    if(po>temp){
        temp = po;
    }
    *r1 = temp;
    *r2 = maior;
    *r3 = pt;
}

bool aprovador(float p1, float p2, float pt){
float media = (0.35*p1)+(0.35*p2)+(0.3*pt);
if(media>=6.0){
    return true;
}else{
    return false;
}
}

void listaAlunos(){
FILE *pont_all;
pont_all = fopen("ListaDeAlunos.txt", "a");
fclose(pont_all);
}

void criaAprovados(int &n, tAlunoEntrada *vetAlunos){
FILE *pont_aprov;
pont_aprov = fopen("Aprovados.txt", "a");
for(int x = 0; x < n; x++)
    if(vetAlunos[x+1].situacao==1){
    fprintf(pont_aprov,"%s %d %.1f\n",vetAlunos[x].nome,vetAlunos[x].RA,vetAlunos[x+1].media);
}
fclose(pont_aprov);
}


void criaReprovados(int &n, tAlunoEntrada *vetAlunos){
FILE *pont_reprov;
pont_reprov = fopen("Reprovados.txt", "a");
for(int x = 0; x < n; x++)
    if(vetAlunos[x+1].situacao==0){
    fprintf(pont_reprov,"%s %d %.1f\n",vetAlunos[x].nome,vetAlunos[x].RA,vetAlunos[x+1].media);
}
fclose(pont_reprov);
}

/*void fixString(char *entradastring){
    int tamString = strlen(entradastring);
    entradastring[tamString - 2] = '\0';
}

void abreArquivo(tAlunoEntrada *vetAlunos, int &n){

printf("Digite o nome do arquivo que contem os alunos");
FILE* arqEntrada;
tAlunoEntrada aluno;
char nomeArq[MAX];
scanf(" %s", nomeArq);
arqEntrada = fopen(nomeArq, "r");

if( arqEntrada == NULL ){
  printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
}else{
while( fread(&aluno, sizeof(tAlunoEntrada), 1, arqEntrada)== 1 ){
fgets(nome, 40, arq);
}
}
}*/

