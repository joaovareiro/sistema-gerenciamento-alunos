#define CARAC 50
struct tAlunoEntrada {
	char nome[CARAC];
	int RA;
	float p1;
	float p2;
	float pt;
	float po;
	float media;
    char situacao[CARAC];
};

void addAluno(tAlunoEntrada *vetAlunos, int &n, char *mod, int RA, float p1, float p2, float pt, float po);
void criaAprovados(int &n, tAlunoEntrada *vetAlunos);
void criaReprovados();
void abreArquivo(tAlunoEntrada *vetAlunos, int &n);
void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado);
void listaAlunos();
int aprovador(int p1, int p2, int pt);
void optativa(int p1, int p2, int po, int &r1, int &r2);
void fixString(char *entradastring);
