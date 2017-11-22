#include <stdio.h>

int CompareString(char texto[1001], char palavra[21], int pos){
	int i;
	for(i = 0; palavra[i] != '\0'; ++i)
		if(texto[pos+i] != palavra[i]) return 0;
	return i;
}

//void Rotaciona(char texto[1001])
int RemoveString(char texto[1001], char RemoveString[21]){
	int i, j, k;
	int qtd = 0;

	for(i = 0; texto[i] != '\0'; ++i){
		int n = CompareString(texto, RemoveString, i);
		if(n > 0){
			for(j = 0; j < n; ++j){
				for(k = i; texto[k] != '\0'; ++k){
					texto[k] = texto[k+1];
				}
			}
			i--;
			qtd++;
		}
	}
	return qtd;
}


int main(){
	char texto[1001];
	char palavra[21];
	int qtdRemoved;

	scanf("%[^\n]s", texto);
	setbuf(stdin, NULL);

	scanf("%[^\n]s", palavra);

	qtdRemoved = RemoveString(texto, palavra);
	printf("\n%s\nRemovido %i ", texto, qtdRemoved);


	return 0;
}