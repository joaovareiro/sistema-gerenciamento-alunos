#define CARAC 50
struct tAlunoEntrada {
	char nome[CARAC];
	int RA;
	double p1;
	double p2;
	double pt;
	double po;
	double media;
	int situacao;
};

void addAluno(tAlunoEntrada *vetAlunos, int &n, char *mod, int RA,double p1, double p2, double pt, double po);
void criaAprovados(int &n, tAlunoEntrada *vetAlunos);
void criaReprovados(int &n, tAlunoEntrada *vetAlunos);
void abreArquivo(tAlunoEntrada *vetAlunos, int &n);
void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado);
bool aprovador(double p1, double p2, double pt);
void optativa(double p1, double p2, double pt, double po, double* r1, double* r2, double* r3);
void ordenaAlunos(int &n, tAlunoEntrada *vetAlunos);
void criaAtual(int &n, tAlunoEntrada *vetAlunos);
void copiar(int &n, tAlunoEntrada *vetAlunosOriginal,  tAlunoEntrada *vetAlunosCopiado);
