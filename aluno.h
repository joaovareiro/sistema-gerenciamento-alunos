//Definicao de uma constante que se refere ao tamanho maximo do vetor que ira comportar os dados dos alunos
#define MAX 100
//Definicao da struct tipo aluno
struct tAlunoEntrada {
	char nome[50];
	int RA;
	double p1;
	double p2;
	double pt;
	double po;
	double media;
    int situacao;
};

//funcao para adicionar um aluno em um vetor 
void addAluno(tAlunoEntrada *vetAlunos, int &n, char *mod, int RA,double p1, double p2, double pt, double po);

//funcao que cria um arquivo txt que lista os alunos aprovados em ordem alfabetica
void criaAprovados(int &n, tAlunoEntrada *vetAlunos);

//funcao que cria um arquivo txt que lista os alunos reprovados em ordem alfabetica
void criaReprovados(int &n, tAlunoEntrada *vetAlunos);

//funcao que abre um arquivo e le o nome,o RA e as notas dos alunos e os adiciona em um vetor
void abreArquivo(tAlunoEntrada *vetAlunos, int &n);

//funcao que busca um aluno no vetor pelo nome
void buscaAluno(int &n, tAlunoEntrada *vetAlunos, char *nomedesejado);

//funcao responsavel por definir a situacao do aluno
bool aprovador(double p1, double p2, double pt);

//funcao que retorna as notas do aluno considerando a prova optativa caso seja necessario
void optativa(double p1, double p2, double pt, double po, double* r1, double* r2, double* r3);

//funcao responsavel pela ordenacao alfabetica do vetor de alunos usando o RA como criterio de desempate
void ordenaAlunos(int &n, tAlunoEntrada *vetAlunos);

//funcao que cria um arquivo txt listando todos os alunos
void criaAtual(int &n, tAlunoEntrada *vetAlunos);

//funcao que converte uma string para lower case
char* toLower(char* s);

//funcao que copia um vetor para outro (usado para pesquisar em um vetor copia no lugar do original a fim de nao alterar a formatacao original de seus nomes)
void copiar(int &n, tAlunoEntrada *vetAlunosOriginal,  tAlunoEntrada *vetAlunosCopiado);