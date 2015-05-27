#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void lerVetor(int n, int* vetor){
  int i;

  for(i=0; i<n; i++){
      scanf("%d", &vetor[i]);
    }
}

int* alocarVetor(int n){
  int i;
  int* vet;

  vet = (int*)malloc(n*sizeof(int));

  for(i=0; i<n; i++){
    vet[i] = 0;
  }

  return vet;
}

void imprimirVetor(int n, int* vetor){
  int i;

  for(i=0; i<n; i++){
    
      printf("%d", vetor[i]);
      printf("\n");
    }
    
  }


void bubblesort( int* vet, int n )
{
  int i;
  int j;
  int aux;
  int k = n - 1 ;

  for(i = 0; i < n; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(vet[j] > vet[j+1])
        {
            aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1]=aux;
        }
     }
     k--;
  }
}

void insertion_sort (int *vet, int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = vet[i];
        for (j = i; j > 0 && t < vet[j - 1]; j--) {
            vet[j] = vet[j - 1];
        }
        vet[j] = t;
    }

  }

void merge(int* vet, int n) {
  int mid;
  int i, j, k;
  int* tmp;
 
  tmp = (int*) malloc(n * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = n / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < n) {
    if (vet[i] <= vet[j]) {
      tmp[k] = vet[i++];
    }
    else {
      tmp[k] = vet[j++];
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < n) {
      tmp[k++] = vet[j++];
    }
  }
  else {
    while (i < mid) {
      tmp[k++] = vet[i++];
 
    }
  }
 
  for (i = 0; i < n; ++i) {
    vet[i] = tmp[i];
  }
 
  free(tmp);
}
 
void mergeSort(int* vet, int n) {
  int mid;
 
  if (n > 1) {
    mid = n / 2;
    mergeSort(vet, mid);
    mergeSort(vet + mid, n - mid);
    merge(vet, n);
  }
}

void selection_sort(int* vet, int n) 
{ 
  int i, j, min, aux;
  for (i = 0; i < (n-1); i++) 
   {
    min = i;
    for (j = (i+1); j < n; j++) {
      if(vet[j] < vet[min]) {
        min = j;
      }
    }
    if (i != min) {
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
    }
  }
}

void shellSort(int *vet, int n) {
    int i , j , value;
    int gap = 1;
    while(gap < n) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < n; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}

void shake_sort(int* vet, int n) {
    int length,bottom,top, swapped,i,aux;
    length=n;
    bottom = 0;
    top = length - 1;
    swapped = 0; 
    while(swapped == 0 && bottom < top)//Se não houver troca de posições ou o ponteiro que
    {                                   //sobe ultrapassar o que desce, o vetor esta ordenado
        swapped = 1; 
        //Este for é a “ida” para a direita
        for(i = bottom; i < top; i = i + 1)
        {
            if(vet[i] > vet[i + 1])   //indo pra direita:testa se o próximo é maior
            {   //indo pra direita:se o proximo é maior que o atual,
                //troca as posições
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                swapped = 0;
            }
        }//fecha for
        // diminui o  `top` porque o elemento com o maior valor 
        // já está na direita (atual posição top)
        top = top - 1; 
        //Este for é a “ida” para a esquerda
        for(i = top; i > bottom; i = i - 1)
        {  if(vet[i] < vet[i - 1]) 
            {
                aux=vet[i];
                vet[i]=vet[i-1];
                vet[i-1]=aux;
                swapped = 0;
            }
        }
        //aumenta o `bottom` porque o menor valor já está
        //na posição inicial (bottom) 
        bottom = bottom + 1;  
    }//fecha while 
 }// fim da funçao

  void rank_sort (int* vet, int n){
  int maior = 0;
  int i;

  for (i=0;i<n;i++){
    if (vet[i] > maior){
      maior = vet[i];
    }
  }

  int* vetor2 = (int*)malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    vetor2[i]=0;  
  }

  for (i=0;i<n;i++){
    vetor2[vet[i]-1]= vetor2[vet[i]-1] + 1; 
  }
  
  for (i=0;i<n;i++){
    vetor2[i+1] = vetor2[i+1] + vetor2[i];
  }


  printf("\nMaior elemento é: %d\n",maior);
  for (i=0;i<n;i++){
    printf("%d \n",vetor2[i]);  
  }

  }



int main(int argc, char** argv){

  int n = atoi(argv[2]);
  char tipo[20];
  strcpy (tipo,argv[1]);

  int* vet = alocarVetor(n);
  lerVetor(n,vet);

  if (strcmp(tipo,"bubble") == 0){
  bubblesort(vet, n);
  imprimirVetor(n,vet);
  free(vet);
  }

  else if (strcmp(tipo,"insertion") == 0){
  insertion_sort(vet, n);
  imprimirVetor(n,vet);
  free(vet);
  }

  else if (strcmp(tipo,"merge") == 0){
  mergeSort(vet, n);
  imprimirVetor(n,vet);
  free(vet);
  }

  else if (strcmp(tipo,"selection") == 0){
  selection_sort(vet, n);
  imprimirVetor(n,vet);
  free(vet);
  }

  else if (strcmp(tipo,"shell") == 0){
  shellSort(vet, n);
  imprimirVetor(n,vet);
  free(vet);
  }

  else if (strcmp(tipo,"shake") == 0){
  shake_sort(vet, n);
  imprimirVetor(n,vet);
  free(vet);
  }
 
  else if (strcmp(tipo,"rank") == 0){
  rank_sort(vet, n);
  // imprimirVetor(n,vet);
  // free(vet);
  
  }

  
  return 0;
}
