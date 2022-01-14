#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include<time.h>



int* NUM;





void DFS(int v, int** matrix, int size) {

	int N;
	printf("Введите размерность матрицы:");
	scanf("%d", &N);


	NUM[v] = 1;
	printf("%d", v);

	for (int i = 0; i < size; i++) {

		if (matrix[v][i] == 1 && NUM[i] == 0)
		{
			DFS(i, matrix, size);
		}
	}
}



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	
	int** M;
	int v, N;
	M = (int**)malloc(N * sizeof(int*));

	for (int i = 0; i < N; i++)
	{
		M[i] = (int*)malloc(N* sizeof(int));
	}

	NUM = (int*)malloc(N * sizeof(int));

	printf("Сгенерированные матрицы:");
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M[i][j] = rand() % 2;
			printf("%3d,", M[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	printf("Введите вершину, с которой будет начинаться обход:  ");
	scanf("%d", &v);

	printf("\n");
	printf("Результат:  ");
	while (NUM[v] != 1)
	{
		DFS(v, M, N);
	}
	getchar(); getchar();
}
