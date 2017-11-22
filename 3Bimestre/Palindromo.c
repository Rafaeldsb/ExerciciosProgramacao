#include <stdio.h>

int pal(char palavra[]){
    int size = 0;
    int i = 0;

    while(palavra[size] != '\0'){
        size++;
    }
    
    for(i = 0; i < size; ++i){
        if(palavra[i] != palavra[size-i-1]) return 0;
    }
    return 1;
}

int main(){
    char palavra[20];

   scanf("%s", palavra);

    if(pal(palavra)){
        printf("\nEh um palindromo\n");
    } else{
        printf("\nNao eh um palindromo");
    }

    return 0;
}