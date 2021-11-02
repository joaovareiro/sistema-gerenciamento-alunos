#include <stdio.h>
#include <string.h>
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
char * ret;
int cont = 0;
for(int x = 0; x < n; x++){
    ret=strstr(vetAlunos[x].nome,nomedesejado);
if(strstr(vetAlunos[x].nome,nomedesejado)){
    for(int i=0;i<strlen(vetAlunos[x].nome);i++){
            printf("%c",*(ret+i));
    }
    cont++;
    printf("\n");
  }
}
  if(cont == 0){
      printf("Aluno não encontrado na base de dados.\n");
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
for(int i=0;i<n;i++){

if(aprovador(vetAlunos[i].p1,vetAlunos[i].p2,vetAlunos[i].pt)==1){

}
}
fclose(pont_aprov);
printf("O arquivo com os alunos aprovados foi criado com sucesso!");
}

void criaReprovados(){
FILE *pont_reprov;
pont_reprov = fopen("Reprovados.txt", "a");
fclose(pont_reprov);
printf("O arquivo com os alunos reprovados foi criado com sucesso!");
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

int aprovador(int p1, int p2, int pt){
int media = (0.35*p1)+(0.35*p2)+(0.3*pt);
if(media>=6.0){
    return 1;
}else{
    return 0;
}
}

void optativa(int p1, int p2, int po, int &r1, int &r2){
    int temp = p1;
    int maior = p2;
    if(p1>p2){
        maior = p1;
        temp = p2;
    }
    if(po>temp){
        temp = po;
    }
    r1 = temp;
    r2 = maior;
}

/*void optativa(int vet[2],int p1, int p2, int po){
    int temp = p1;
    int maior = p2
    if(p1>p2){
        maior = p1;
        temp = p2;
    }
    if(po>temp){
        temp = po;
    }
    printf("%d %d", maior, temp);
}*/

/*void optativa(int vet[2],int p1, int p2, int po){
    int vet[2];
    if(p1>p2 && p2>po){
        vet[0]=p1;
        vet[1]=p2;
    }
    if(p2>p1 && p1>po){
        vet[0]=p2;
        vet[1]=p1;
    }
    if(po>p1 && p1>p2){
        vet[0]=po;
        vet[1]=p1;
    }
    if(p1>po && po>p2){
        vet[0]=p1;
        vet[1]=po;
    }
    if(po>p2 && p2>p1){
        vet[0]=po;
        vet[1]=p2;
    }
    if(p2>po && po>p1){
        vet[0]=p2;
        vet[1]=po;
    }

}*/

