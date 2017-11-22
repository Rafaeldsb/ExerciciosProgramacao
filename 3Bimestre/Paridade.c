#include <stdio.h>

void verificaParidade(int bytes[5][9]){
    int i, j;
    int s1, s2;
    int el = -1, ec = -1;
    for(i = 0; i < 4; ++i){
        s1 = 0;
        for(j = 0; j < 9; ++j){
            s1 += bytes[i][j];
            
        }
        if(s1 % 2 == 1) {
            el = i;
            break;
        }

    }
    
    for(i = 0; i < 8; ++i){
        s2 = 0;
        for(j = 0; j < 5; ++j){
            s2 += bytes[j][i];
        }
        if(s2 % 2 == 1) ec = i;
    }

    if(el == -1 && ec == -1){
        printf("\nParidade Ok\n");
    }else{
        if(el == -1){
            printf("\nErro na coluna %d\n", ec);
        }else if(ec == -1){
            printf("\nErro na linha %d\n", el);
        } else {
            printf("\nErro na cordenada (%d, %d)\n", el, ec);
        }
    }
}

int main(){
    int mat[5][9];
    int i, j;
    for(i = 0; i < 5; ++i){
        for(j = 0; j < 9; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
    //printf("!");
    verificaParidade(mat);

    return 0;
}
