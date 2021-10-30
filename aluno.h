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
