#include <string.h>
#define MAX 50

struct tAlunoEntrada {
	char nome[MAX];
	int RA;
	float p1;
	float p2;
	float pt;
	float po;
	float media;
};

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

void criaAprovados(){
FILE *pont_aprov;
pont_aprov = fopen("aprovados.txt", "a");
fclose(pont_aprov);
printf("O arquivo com os alunos aprovados foi criado com sucesso!");
}

void criaReprovados(){
FILE *pont_reprov;
pont_reprov = fopen("Reprovados.txt", "a");
fclose(pont_reprov);
printf("O arquivo com os alunos reprovados foi criado com sucesso!");
}

void abreArquivo(){

printf("Digite o nome do arquivo que contem os alunos");
FILE* arqEntrada;
char nomeArq[MAX];
scanf(" %s", nomeArq);

arqEntrada = fopen(nomeArq, "r");

if( arqEntrada == NULL ){
  printf("\n\n Arquivo %s nao pode ser aberto.\n\n", nomeArq);
}else{
	//adicionar alguma forma de os dados serem adicionados no vetor
}
