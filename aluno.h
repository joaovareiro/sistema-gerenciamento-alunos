struct tAlunoEntrada {
	char nome[50];
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
void buscaAluno();
void listaAlunos();
bool aprovador(int p1, int p2, int pt);
void optativa(int p1, int p2, int po);
