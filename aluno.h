#define CARAC 50
struct tAlunoEntrada {
	char nome[CARAC];
	int RA;
	float p1;
	float p2;
	float pt;
	float po;
	float media;
};

void addAluno(tAlunoEntrada *vetAlunos, int &n, char *mod, int RA, float p1, float p2, float pt, float po);
void criaAprovados();
void criaReprovados();
void abreArquivo();
void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado);
void listaAlunos();
bool aprovador(int p1, int p2, int pt);
void optativa(int p1, int p2, int po);
