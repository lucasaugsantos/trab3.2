#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void aleatorio (int n){
	int i;
	srand(time(NULL));
	for (i = 0; i < n; ++i){
			printf("%d ", 1 + rand()%n);
		printf("\n");
	}


}

void crescente (int n){
	int i;
	srand(time(NULL));
	for (i = 1; i < n; ++i){
			printf("%d ", i);
		printf("\n");
	}


}

void decrescente (int n){
	int i;
	for (i = n; i != 0; i--){
			printf("%d ", i);
		printf("\n");
	}
}

int main(int argc, char** argv){
	int n = atoi(argv[2]);
	char tipo[3];
	strcpy (tipo,argv[1]);

	if (strcmp(tipo,"-a") == 0){
	aleatorio(n);
	}

	else if (strcmp(tipo,"-c") == 0){
	crescente(n);
	}

	else if (strcmp(tipo,"-d") == 0){
	decrescente (n);
	}
	return 0;
}
