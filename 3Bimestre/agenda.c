#include <stdio.h>

struct contat {
	char nome[20];
	char endereco[50];
	char telefone[12];
};

typedef struct contat contato;

int functionChoice();
int search(contato a[], int n, char nome[20]);

int Inserir(contato a[], int n, contato ins);
void Consulta(contato a[], int n, char nome[20]);
int Remover(contato a[], int n, char nome[20]);
void Atualizar(contato a[], int n, contato att);
void Ordenar(contato a[], int n);
void Listar(contato a[], int n);

contato ler();

int main(){
	contato Agenda[10];
	int sizeAgenda = 0;
	int choice;
	char nome[20];
	do {
		choice = functionChoice();

		switch(choice){
			case 1:
				if(Inserir(Agenda, sizeAgenda, ler())) sizeAgenda++;
				break;
			case 2:
				scanf(" %s", nome);
				Consulta(Agenda, sizeAgenda, nome);
				break;
			case 3:
				scanf(" %s", nome);
				if(Remover(Agenda, sizeAgenda, nome)) sizeAgenda--;
				break;
			case 4:
				Atualizar(Agenda, sizeAgenda, ler());
				break;
			case 5:
				Ordenar(Agenda, sizeAgenda);
				break;
			case 6:
				Listar(Agenda, sizeAgenda);
				break;
			case 7:
				return 0;
			default:
				break;
		}
	} while(1);

	return 0;
}

int functionChoice(){
	
	int opc;

	printf("\n================== Menu ==================\n\n");
	printf("1 - Inserir\n");
	printf("2 - Consulta\n");
	printf("3 - Remover\n");
	printf("4 - Atualizar\n");
	printf("5 - Ordenar\n");
	printf("6 - Listar\n");
	printf("7 - Fim\n");
	printf("\nOpcao Desejada: ");

	scanf(" %d", &opc);

	setbuf(stdin, 0);

	return opc;
}

int search(contato a[], int n, char nome[20]){
	int i;
	for(i = 0; i < n; ++i){
		if(strcmp(a[i].nome, nome) == 0) 
			return i;
	}
	return -1;
}

int Inserir(contato a[], int n, contato ins){
	if(n == 10) {
		printf("Agenda Cheia!\n");
		return 0;
	}
	a[n] = ins;
	return 1;
}

void Consulta(contato a[], int n, char nome[20]){
	int id = search(a, n, nome);

	if(id == -1) {
		printf("Contato nao encontrado!\n");
		return;
	}

	printf("Contato:\nNome: %s\nEndereco: %s\nTelefone: %s\n",a[id].nome, a[id].endereco, a[id].telefone);
}

int Remover(contato a[], int n, char nome[20]){
	int id = search(a, n, nome);

	if(id == -1) {
		printf("Contato nao encontrado!\n");
		return 0;
	}
	int i;
	for(i = id; i < n - 1; ++i){
		a[id] = a[id+1];
	}

	return 1;
}

void Atualizar(contato a[], int n, contato att){
	int id = search(a, n, att.nome);

	if(id == -1) {
		printf("Contato nao encontrado!\n");
		return;
	}	

	a[id] = att;
}

void Ordenar(contato a[], int n){
	int i, j;
	contato temp;
	for(i = 0; i < n; ++i){
		for(j = 0; j < n - 1; ++j){
			if(strcmp(a[j].nome, a[j+1].nome) > 0){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void Listar(contato a[], int n){
	int i;
	printf("==== Contatos ====\n");
	for(i = 0; i < n; ++i){
		printf("Nome: %s\nEndereco: %s\nTelefone: %s\n\n",a[i].nome, a[i].endereco, a[i].telefone);
	}
}

contato ler(){
	char nome[20];
	char end[50];
	char tel[12];

	contato temp;

	printf("Digite o nome: ");
	scanf(" %s", nome);
	printf("Digite o endereco: ");
	scanf(" %s", end);
	printf("Digite o telefone: ");
	scanf(" %s", tel);

	strcpy(temp.nome, nome);
	strcpy(temp.endereco, end);
	strcpy(temp.telefone, tel);

	return temp;
}