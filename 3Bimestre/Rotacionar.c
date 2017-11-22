#include <stdio.h>

void rot(int vet[], int size, int nRot){
    int i;
    int v[20];
    for(i = 0; i < size; ++i){
        v[i] = vet[i];
    }
    for(i = 0; i < size; ++i){
        vet[i] = v[ ( i + nRot ) % size ];
    }

}


int main (){
    int i;
    int vetor[20]; // = {1,2,3,4,5,6};
    for(i = 0; i < 20; ++i){
        scanf(" %d", &vetor[i]);
    }
    int rota;
    scanf(" %d", &rota);
    rot(vetor, 20, rota);
    
    for(i = 0; i < 20; ++i){
        printf("%d ", vetor[i]);
    }
    return 0;
}