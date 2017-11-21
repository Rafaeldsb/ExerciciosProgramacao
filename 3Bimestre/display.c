#include <stdio.h>
#include <time.h>

#define bk  "\e[1;42m"

int main(){
	char alpha[27][5][5];
	float tDelay;

	char* cl[] = {
		"\e[31m",
		"\e[32m",
		"\e[33m",
		"\e[34m",
		"\e[35m",
		"\e[36m",
		"\e[37m",
		"\e[0m"
	};

	int i, j, k, l;
	for(k = 0; k < 27; ++k){
		for(i = 0; i < 5; ++i){
			for(j = 0; j < 5; ++j){
				scanf(" %c", &alpha[k][i][j]);
			}
		}
	}
	fflush(stdin);
	__fpurge(stdin);
	scanf(" %f", &tDelay);

	char lt[] = "na turma de prog o choro eh livre";

	int numL = sizeof(lt) / sizeof(lt[0]) - 1;
	char Texto[5][1000];
	char h;
	int z;
	for(i = 0;i < 5; ++i){
		z = 0;
		for(l = 0; l < numL; ++l){
			h = lt[l];
			for(j = 0; j < 5; ++j) {
				Texto[i][z] = alpha[h - 'a'][i][j] == '.' || h == ' ' ? ' ' : '#';alpha[h - 'a'][i][j];	
				z++;
			}
			Texto[i][z++] = ' ';
			Texto[i][z++] = ' ';
		}
	}
	


	int D = 80;
	long long int x = -1, y;
	printf("");
	while(1){ 
		x = ++x;
		y = x % (numL*7+D);
		printf("\n\n\n");
		for(i = 0; i < 5; ++i){
			for(z = 0; z < 10; ++z) printf(" ");
			for(z = 0;z < D-y;++z){ 
				printf(bk); 
				printf(" ");
			}

			for(j = z; j < D; ++j){
				if(y+j >= (numL*7+D)) printf("%s ", bk);
				else printf("%s%s%c", cl[x%8],bk, Texto[i][y-D+j]);
			}
			printf(cl[7]);
			printf("\n");
		}

		float inst1=0, inst2=0;

	   	inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

	   	while (inst2-inst1< .11) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;

		system("clear");


	}



	
}
