#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define n_bucket 100
#define num_bucket 10
#define max 10

typedef struct {
         int topo;
         int balde[n_bucket];
 }bucket;

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

  //  for (i=0;i<n;i++){
  //   printf("%d \n",vetor2[i]);  
  // }

  
  for (i=0;i<n;i++){
    vetor2[i+1] = vetor2[i+1] + vetor2[i];
  }

  for (i=0;i<n;i++){
    printf("%d \n",vetor2[i]);  
  }

  printf("ordenado \n");
  for (i=0;i<n;i++){
    if (vetor2[i+1]>vetor2[i]){
      printf("%d \n", i+1 );
    }
  }

  }

void heapsort(int* vet, int n)
{
   int i = n/2, pai, filho, t;
 
   for (;;)
   {
      if (i > 0)
      {
          i--;
          t = vet[i];
      }
      else
      {
          n--;
          if (n == 0)
             return;
          t = vet[n];
          vet[n] = vet[0];
      }
 
      pai = i;
 
      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i*2;
 
      while (filho < n)
      {
         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (vet[filho + 1] > vet[filho]))
              filho++;
          if (vet[filho] > t)
          {
             vet[pai] = vet[filho];
             pai = filho;
             filho = pai*2 + 1;
          }
          else
             break;
      }
      vet[pai] = t;
   }

}

void radixsort(int* vetor, int n) {
    int i;
    int b[n];
    int maior = vetor[0];
    int exp = 1;
 
    for (i = 0; i < n; i++) {
        if (vetor[i] > maior)
          maior = vetor[i];
    }
 
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
      for (i = 0; i < n; i++)
          bucket[(vetor[i] / exp) % 10]++; 
      for (i = 1; i < 10; i++)
          bucket[i] += bucket[i - 1];
      for (i = n - 1; i >= 0; i--)
          b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
      for (i = 0; i < n; i++)
          vetor[i] = b[i];
      exp *= 10;
    }
}

void radix_sort_binary( int* vet, int n) {
  int queue_0[n];
  int queue_1[n];
  int i,j,mask;
  for ( i = 0, mask = 1; ++i, mask <<= 1;) {
    int tail_0 = 0;
    int tail_1 = 0;

    for ( i = 0; i < n; ++i ) {
      if ( (vet[i] & mask) == 0 ) {
        queue_0[tail_0] = vet[i];
        ++tail_0;
      } else {
        queue_1[tail_1] = vet[i];
        ++tail_1;
      }
    }

    int i = 0;

    for (j = 0; j < tail_0; ++i, ++j ) {
      vet[i] = queue_0[j];
    }

    for (j = 0; j < tail_1; ++i, ++j ) {
      vet[i] = queue_1[j];
    }
  }
}

void bucket_sort(int* vet,int n){                                     
         bucket b[num_bucket];                                      
         int i,j,k;                                                 
 /* 1 */ for(i=0;i<num_bucket;i++)                    //inicializa todos os "topo"
                 b[i].topo=0;
 
 /* 2 */ for(i=0;i<n;i++){                          //verifica em que balde o elemento deve ficar
                 j=(num_bucket)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(vet[i]>=j*10){
                                 b[j].balde[b[j].topo]=vet[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                 }
         }
 
 /* 3 */ for(i=0;i<num_bucket;i++)                     //ordena os baldes
                 if(b[i].topo)
                         bubblesort(b[i].balde,b[i].topo);
 
         i=0;
 /* 4 */ for(j=0;j<num_bucket;j++){                    //põe os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         vet[i]=b[j].balde[k];
                         i++;
                 }
         }
 }
 
 void quickrecursivocentral (int * vet, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = vet[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (vet[i] < p)
            i++;
        while (p < vet[j])
            j--;
        if (i >= j)
            break;
        t = vet[i];
        vet[i] = vet[j];
        vet[j] = t;
    }
    quickrecursivocentral(vet, i);
    quickrecursivocentral(vet + i, n - i);
}

 void quickrecursivoprimeiro (int * vet, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = vet[1];
    for (i = 0, j = n - 1;; i++, j--) {
        while (vet[i] < p)
            i++;
        while (p < vet[j])
            j--;
        if (i >= j)
            break;
        t = vet[i];
        vet[i] = vet[j];
        vet[j] = t;
    }
    quickrecursivoprimeiro(vet, i);
    quickrecursivoprimeiro(vet + i, n - i);
}

void quickrecursivomediana3 (int * vet, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
      int mediana[3];
      mediana[0]=vet[0];
      mediana[1]=vet[n-1];
      mediana[2]= vet[n/2];
      insertion_sort (mediana,3);

    p = mediana[1];
    for (i = 0, j = n - 1;; i++, j--) {
        while (vet[i] < p)
            i++;
        while (p < vet[j])
            j--;
        if (i >= j)
            break;
        t = vet[i];
        vet[i] = vet[j];
        vet[j] = t;
    }
    quickrecursivomediana3(vet, i);
    quickrecursivomediana3(vet + i, n - i);
}

void quickprimeiro(int *vet, int n) {

  int MAX_LEVELS = n;
  
  int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R, swap ;

  beg[0]=0; 
  end[0]=n;
  while (i>=0) {
    L=beg[i]; 
    R=end[i]-1;
    if (L<R) {
      piv=vet[L];
      while (L<R) {
        while (vet[R]>=piv && L<R) R--; if (L<R) vet[L++]=vet[R];
        while (vet[L]<=piv && L<R) L++; if (L<R) vet[R--]=vet[L]; }
      vet[L]=piv; beg[i+1]=L+1; end[i+1]=end[i]; end[i++]=L;
      if (end[i]-beg[i]>end[i-1]-beg[i-1]) {
        swap=beg[i]; beg[i]=beg[i-1]; beg[i-1]=swap;
        swap=end[i]; end[i]=end[i-1]; end[i-1]=swap; }}
    else {
      i--; }}}

long int fatorial(int n){
  if(n==1)
    return 1;
  else
    return (n*fatorial(n-1));
}
void liberarVetores(int** permutacoes, int* valor, long int p){
  int i;

  for(i=0; i<p; i++){
    free(permutacoes[i]);
  }

  free(valor);
  free(permutacoes);
}

void addItem(int* vetor, int** permutacoes, int n){
  static int indice = 0;
    int i = 0;

    int* novo = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++){
      novo[i]=vetor[i] -1;
    }

    permutacoes[indice++] = novo;
}


void visit(int k, int n, int* valor, int** permutacoes){
    int i;
    static int level = -1;

    level = level+1;
    valor[k] = level;
    if (level == n)
      addItem(valor, permutacoes, n);
    else
      for (i = 0; i < n; i++)
        if (valor[i] == 0)
          visit(i, n, valor, permutacoes);
    
    level = level-1;
    valor[k] = 0;
}

int verifica_ordenado (int* vet, int n){
  int i =0;
  for (i=0;i<n;i++){
    if (vet[i]<vet[i+1])
      return 1;
  }
  return 0;

}




// void otima(int n, long int p){
//   int* valor;
//   int** permutacoes;
//   int i;
//   valor = alocarVetor(n);
//   permutacoes = (int**) malloc(p*sizeof(int*));

//   if(permutacoes == NULL){
//     printf("ERRO: Nao há espaço suficiente em memória\n");
//     exit(1);
//   }
//   visit(0, n, valor, permutacoes);
  
//   for (i=0;i<n;i++){
//     if (verifica_ordenado(permutacoes[i],n) == 1)

//   }


//   liberarVetores(permutacoes, valor, p);
// }


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
   imprimirVetor(n,vet);
   free(vet);
  
  }

  else if (strcmp(tipo,"heap") == 0){
   heapsort(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  
  }

  else if (strcmp(tipo,"radix") == 0){
   radixsort(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  }

  else if (strcmp(tipo,"radixbin") == 0){
   radix_sort_binary(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  }

  else if (strcmp(tipo,"bucket") == 0){
   bucket_sort(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  }

  else if (strcmp(tipo,"quickrecursivocentral") == 0){
   quickrecursivocentral(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  }

  else if (strcmp(tipo,"quickrecursivoprimeiro") == 0){
   quickrecursivoprimeiro(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  }
  
  else if (strcmp(tipo,"quickrecursivomediana3") == 0){
   quickrecursivoprimeiro(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  }

  else if (strcmp(tipo,"quickprimeiro") == 0){
   quickprimeiro(vet, n);
   imprimirVetor(n,vet);
   free(vet);
  }

  return 0;
}
