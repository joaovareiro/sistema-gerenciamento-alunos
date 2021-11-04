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
    optativa(p1,p2,pt,po,&r1,&r2,&r3);
    vetAlunos[n].media = (0.35*r1)+(0.35*r2)+(0.3*r3);
    if(aprovador(r1,r2,r3)==true){
    vetAlunos[n].situacao=1;
    }else{
    vetAlunos[n].situacao=0;
    }
    n++;
}

void ordenaAlunos(int &n,tAlunoEntrada *vetAlunos){
  int x,y,z;

  tAlunoEntrada aux;
  for(x=0; x<=n;x++){
    for (y=x+1; y<n ;y++){
      if((strcmp(vetAlunos[x].nome,vetAlunos[y].nome)==0) && (vetAlunos[x].RA>vetAlunos[y].RA)){
                aux = vetAlunos[x];
                vetAlunos[x] = vetAlunos[y];
                vetAlunos[y] = aux;
        }
      z = strcmp(vetAlunos[x].nome,vetAlunos[y].nome);
      if(z>0){
                aux = vetAlunos[x];
                vetAlunos[x] = vetAlunos[y];
                vetAlunos[y] = aux;
            }
        }
    }
}

void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado){
ordenaAlunos(n,vetAlunos);
int cont = 0;
for(int x = 0; x < n; x++){
if(strstr(vetAlunos[x].nome,nomedesejado)){
    printf("%s %.1f ",vetAlunos[x].nome,vetAlunos[x].media);
    if(vetAlunos[x].situacao==1){
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

void criaAprovados(int &n, tAlunoEntrada *vetAlunos){
ordenaAlunos(n, vetAlunos);
int cont = 0;
FILE *pont_aprov;
pont_aprov = fopen("Aprovados.txt", "a");

for(int x = 0; x < n; x++)
    if(vetAlunos[x].situacao==1){
    fprintf(pont_aprov,"%s %d %.1f\n",vetAlunos[x].nome,vetAlunos[x].RA,vetAlunos[x].media);
    cont++;
}
fprintf(pont_aprov,"Total: %d",cont);
fclose(pont_aprov);
}


void criaReprovados(int &n, tAlunoEntrada *vetAlunos){
ordenaAlunos(n, vetAlunos);
FILE *pont_reprov;
int cont = 0;
pont_reprov = fopen("Reprovados.txt", "a");
for(int x = 0; x < n; x++)
    if(vetAlunos[x].situacao==0){
    fprintf(pont_reprov,"%s %d %.1f\n",vetAlunos[x].nome,vetAlunos[x].RA,vetAlunos[x].media);
    cont++;
}
fprintf(pont_reprov,"Total: %d",cont);
fclose(pont_reprov);
}


void abreArquivo(tAlunoEntrada *vetAlunos, int &n){
printf("%d\n",n);
printf("Digite o nome do arquivo que contem os alunos\n");
FILE* arqEntrada;
char nomeArq[MAX];
scanf(" %s", nomeArq);
arqEntrada = fopen(nomeArq, "r");
tAlunoEntrada teste;

if( arqEntrada == NULL ){
  printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
}else{

for (int k = n; feof(arqEntrada)==0;k++){

    fscanf(arqEntrada, "%50[^0123456789] %d %f %f %f %f\n",vetAlunos[k].nome,&vetAlunos[k].RA,&vetAlunos[k].p1,&vetAlunos[k].p2,&vetAlunos[k].pt,&vetAlunos[k].po);

    addAluno(vetAlunos,n,vetAlunos[k].nome,vetAlunos[k].RA,vetAlunos[k].p1,vetAlunos[k].p2,vetAlunos[k].pt,vetAlunos[k].po);
}
ordenaAlunos(n, vetAlunos);
fclose(arqEntrada);
}
}
