#define CARAC 50
struct tAlunoEntrada {
	char nome[CARAC];
	int RA;
	float p1;
	float p2;
	float pt;
	float po;
	float media;
  int situacao;
};

void addAluno(tAlunoEntrada *vetAlunos, int &n, char *mod, int RA, float p1, float p2, float pt, float po);
void criaAprovados(int &n, tAlunoEntrada *vetAlunos);
void criaReprovados(int &n, tAlunoEntrada *vetAlunos);
void abreArquivo(tAlunoEntrada *vetAlunos, int &n);
void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado);
void listaAlunos();
bool aprovador(float p1, float p2, float pt);
void optativa(float p1, float p2, float pt, float po, float* r1, float* r2, float* r3);
void imprime(int &n, tAlunoEntrada *vetAlunos);
