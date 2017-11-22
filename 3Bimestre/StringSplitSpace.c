#include <stdio.h>

#define splitMax 20

int split(char texto[], char termo, char dest[splitMax][20]);
void print(char textSplited[splitMax][20], int n);

int main(){

	char texto[100];
	char tSplit[splitMax][20];
	int n;
	//fgets(texto,100, stdin);
	scanf("%[^\n]s", texto);
	setbuf(stdin, NULL);

	n = split(texto, ' ', tSplit);
	print(tSplit, n);


	return 0;
}

int split(char texto[], char termo, char dest[splitMax][20]){
	int pos;
	int i, j;

	pos = 0; j = 0;
	for(i = 0; texto[i] != '\0'; ++i){
		if(texto[i] != termo){
			dest[pos][j++] = texto[i];
		} 
		else if(texto[i] == termo && texto[i+1] != termo) {
			dest[pos++][j] = '\0';
			j = 0;
		}
	}
	dest[pos++][j] = '\0';
	return pos;
	//dest[pos][0] = '\0';
}

void print(char textSplited[splitMax][20], int n){
	int i, j;

	for(i = 0; i < n; ++i){
		printf("%s\n", textSplited[i]);
	}
}