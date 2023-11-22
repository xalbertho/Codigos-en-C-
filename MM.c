#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;


//FUNCIONES YA CREADAS

void *multiplicacion1();
void *multiplicacion2();

void *resta1();
void *resta2();

void *suma1();
void *suma2();


//MATRICES INICIALIZADAS


int A[3][3]= {1,3,1,
	          3,1,1,
	          5,3,3};

int B[3][3]= {2,2,1,
	          1,4,3,
              0,5,3};


//INTERVALOS PARA LA FORMACION DE MATRICES EN EL FOR

int num1=1;
int num2=3;



//SE DECLARAN MATRICES VACIAS AL PRINCIPIO PARA HACER MAS FACIL
//EL AGREGAR AMBOS HILOS A CADA OPERACION

int sum[3][3]={0,0,0,
	           0,0,0,
	           0,0,0};

int res[3][3]={0,0,0,
	           0,0,0,
	           0,0,0};

int mul[3][3]={0,0,0,
	           0,0,0,
	           0,0,0};


int main(){
	//imprimeMatrizA();
	//imprimeMatrizB();
	pthread_t id_hilo1;
	pthread_t id_hilo2;
	pthread_t id_hilo3;

	pthread_t id_h1;
	pthread_t id_h2;
	pthread_t id_h3;


	void* valor_retorno;
	if(pthread_create(&id_hilo1,NULL,*suma1,NULL)){
		printf("Problema en creacion de hilo");
		exit(EXIT_FAILURE);
	}

	if(pthread_create(&id_h1,NULL,*suma2,NULL)){
		printf("Problema en creacion de hilo");
		exit(EXIT_FAILURE);
	}

	if(pthread_create(&id_hilo2,NULL,*resta1,NULL)){
		printf("Problema en creacion de hilo");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&id_h2,NULL,*resta2,NULL)){
		printf("Problema en creacion de hilo");
		exit(EXIT_FAILURE);
	}

	if(pthread_create(&id_hilo3,NULL,*multiplicacion1,NULL)){
		printf("Problema en creacion de hilo");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&id_h3,NULL,*multiplicacion2,NULL)){
		printf("Problema en creacion de hilo");
		exit(EXIT_FAILURE);
	}

	if(pthread_join(id_hilo1,&valor_retorno)){
		printf("Problema al crear enlace con el hilo");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(id_h1,&valor_retorno)){
		printf("Problema al crear enlace con el hilo");
		exit(EXIT_FAILURE);
	}

	if(pthread_join(id_hilo2,&valor_retorno)){
		printf("Problema al crear enlace con el hilo");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(id_h2,&valor_retorno)){
		printf("Problema al crear enlace con el hilo");
		exit(EXIT_FAILURE);
	}

	if(pthread_join(id_hilo3,&valor_retorno)){
		printf("Problema al crear enlace con el hilo");
		exit(EXIT_FAILURE);
	}
	if(pthread_join(id_h3,&valor_retorno)){
		printf("Problema al crear enlace con el hilo");
		exit(EXIT_FAILURE);
	}

}


void *suma1(){
	printf("Estoy en la SUMA con el pid %ld",pthread_self());
	for(int i=0; i<num1; i++){
		for(int j=0;j<num2;j++){
		sum[i][j] = A[i][j] + B[i][j];
		}
		printf("\n");
	}
	pthread_mutex_unlock(&mutex1);
	return 0;
}

void *suma2(){
	printf("Estoy en la SUMA con el pid %ld",pthread_self());
	for(int i=1; i<num2; i++){
		for(int j=0;j<num2;j++){
		sum[i][j] = A[i][j] + B[i][j];
		}
		printf("\n");
	}
	printf("---RESULTADO SUMA--\n");
	for(int i=0; i<num2; i++){
		for(int j=0;j<num2;j++){
			printf("%i\t",sum[i][j]);
		}
		printf("\n");
	}
	pthread_mutex_lock(&mutex1);
	return 0;
}

void *resta1(){
	printf("Estoy en la RESTA con el pid%ld",pthread_self());
	for(int i=0; i<num1; i++){
		for(int j=0;j<num2;j++){
			res[i][j] = A[i][j] - B[i][j];
		}
		printf("\n");
	}
	pthread_mutex_unlock(&mutex2);
	return 0;
}

void *resta2(){
	printf("Estoy en la RESTA con el pid%ld",pthread_self());
	for(int i=1; i<num2; i++){
		for(int j=0;j<num2;j++){
			res[i][j] = A[i][j] - B[i][j];
		}
		printf("\n");
	}
	printf("---RESULTADO RESTA--\n");
	for(int i=0; i<num2; i++){
		for(int j=0;j<num2;j++){
			printf("%i\t",res[i][j]);
		}
		printf("\n");
	}
	pthread_mutex_lock(&mutex2);
	return 0;
}

void *multiplicacion1(){
	printf("Estoy en la MULTIPLICACION con el pid %ld",pthread_self());
	for(int i=0; i<num2; i++){
		for(int j=0;j<num1;j++){
			int r=0;
			for(int k=0;k<num2;k++){
				r+= A[j][k] * B[k][i];
			}
		mul[j][i]=r;
		}
		printf("\n");
	}
	pthread_mutex_unlock(&mutex3);
	return 0;
}

void *multiplicacion2(){
	printf("Estoy en la MULTIPLICACION con el pid %ld",pthread_self());
	for(int i=0; i<num2; i++){
		for(int j=1;j<num2;j++){
			int r=0;
			for(int k=0;k<num2;k++){
				r+= A[j][k] * B[k][i];
			}
		mul[j][i]=r;
		}
		printf("\n");
	}
	printf("---RESULTADO MULTIPLICACION--\n");
	for(int i=0; i<num2; i++){
		for(int j=0;j<num2;j++){
			printf("%i\t",mul[i][j]);
		}
		printf("\n");
	}
	pthread_mutex_lock(&mutex3);
	return 0;
	}










/*void imprimeMatrizA(){
	printf("---IMPRIMIENDO MATRIZ A---\n");
	for(int i=0; i<num2; i++){
		for(int j=0;j<num2;j++){
			printf("%i\t",A[i][j]);
		}
		printf("\n");
	}
}

void imprimeMatrizB(){
	printf("---IMPRIMIENDO MATRIZ B---\n");
	for(int i=0; i<num2; i++){
		for(int j=0;j<num2;j++){
			printf("%i\t",B[i][j]);
		}
		printf("\n");
	}
}*/

