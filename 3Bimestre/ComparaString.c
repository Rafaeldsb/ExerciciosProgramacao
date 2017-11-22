#include <stdio.h>
#include <string.h>

int main(){
	char String_a[100], String_b[100];
	scanf("%[^\n]s", String_a);
	setbuf(stdin, NULL);
	scanf("%[^\n]s", String_b);
	setbuf(stdin, NULL);

	int c;
	c = strcmp(String_a, String_b);

	if(c == 0){
		printf("\nStrings iguais.\n");
	} else if(c > 0){
		printf("\nA > B\n");
	} else {
		printf("\nB > A\n");
	}

	return 0;
}