#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#define SAMPLESIZE 100.0

void wbrutesort(int *v, int n){
	unsigned int i, j;
	int buff;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(v[i] > v[j] && i < j){
				buff = v[i];
				v[i] = v[j];
				v[j] = buff;
			}
		}
	}
}

void bbrutesort(int *v, int n){
	unsigned int i, j;
	int buff;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(v[i] > v[j]){
				buff = v[i];
				v[i] = v[j];
				v[j] = buff;
			}
		}
	}
}

int power2b(int n){
	int r = 0;
	if(n<2){
		return 1;
	}
	if(n % 2 == 0){
		r = power2b(n/2);
		return r * r;
	}
	r = power2b((n-1)/2);
	return 2 * r * r;
}


int power2(int n){
	if(n==0){
		return 1;
	}
return 2 * power2(n-1);
}

int main(void){
	char url[]="tempo.txt";
	FILE *arq;
	arq = fopen(url, "w");
	struct timeval antes, depois;
	double t_antes, t_depois;
	double tempo = 0, tempo2 = 0;//, tempo4=0;
	unsigned int j, a = 0, n;
	int *v;
	
	
	if(arq == NULL){
	printf("Erro, nao foi possivel abrir o arquivo\n");
	}else{
		printf("|LOG|\n");

	for(n = 2; n <= 100000; n = n * 2){
		a = 0;
		tempo = 0.0;
		while(a < SAMPLESIZE){
			v = (int *) malloc(sizeof(int) * n);
			for (j = 0; j < n; j++)
				v[j] = j;
				
			gettimeofday(&antes, NULL);
			power2b(n);
			gettimeofday(&depois, NULL);
			t_antes = antes.tv_sec + antes.tv_usec / 1000000.0;
			t_depois = depois.tv_sec + depois.tv_usec / 1000000.0;
			tempo = tempo + (t_depois - t_antes);
			printf("\n%d %.20lf", n, tempo);
			
				
			// gettimeofday(&antes, NULL);
			// pow2(10000);
			// gettimeofday(&depois, NULL);
			// t_antes = antes.tv_sec + antes.tv_usec / 1000000.0;
			// t_depois = depois.tv_sec + depois.tv_usec / 1000000.0;
			// tempo3 = tempo3 + (t_depois - t_antes);
			// printf("%.20lf\n", tempo3);
			
			// fprintf(arq, "%.20lf \n", tempo3);
				
				
			a++;
			}
		tempo2 = tempo/SAMPLESIZE;
		fprintf(arq, "\n%d %.20lf", n, tempo2);
		}
	}
	//tempo4= tempo3/30.0;
	
	//fprintf(arq, "\n%d %.20lf", a, tempo2);
	//fprintf(arq, "\nMédia LINEAR: %.20lf\n", tempo4);
	
	printf("\nMedia LOG: %.20lf", tempo2);
	//printf("   |       Media LINEAR: %.20lf\n", tempo4);
	fclose(arq);

	return 0;
}
