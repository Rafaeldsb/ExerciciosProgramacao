#include <stdio.h>
#include <math.h>

int main(){

	int Sudoku[9][9];

	int i, j;
	int s1, s2, s3, st;

	st = 0;
	for(i = 0; i < 9; ++i){
		st += pow(i+1, 2);
	}
	
	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
			scanf(" %d", &Sudoku[i][j]);
		}
	}

	for(i = 0; i < 9; ++i){
		s1 = 0;
		s2 = 0;
		s3 = 0;
		for(j = 0; j < 9; ++j){
			s1 += pow(Sudoku[i][j], 2);
			s2 += pow(Sudoku[j][i], 2);
			s3 += pow(Sudoku[ (j / 3) * 3 + j % 3 ] [ (i / 3) * 3 + i % 3 ] , 2);
		}
		if(s1 != st || s2 != st || s3 != st) {
			printf("\nInvalido!\n");
			return 0;
		}
	}

	printf("\nOk!\n");

	return 0;


}