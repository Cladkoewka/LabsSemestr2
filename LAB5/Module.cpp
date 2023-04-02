#include "Module.h";
#include <stdio.h>;
#include <conio.h>;

void GetArrays(FILE *file, int arrSize, int *arrC, int *arrP)
{
	for (int i = 0; i < arrSize; i++) 
	{
		fscanf_s(file, "%d", &arrC[i]);
	}
	fscanf_s(file, "\n");
	for (int j = 0; j < arrSize; j++)
	{
		fscanf_s(file, "%d", &arrP[j]);
	}
	return;
}


void WriteArrays(FILE* file, int arrSize, int* arrC, int* arrP)
{
	fprintf_s(file, "Array size = %d;\n", arrSize);
	fprintf_s(file, "ArrayC:\n");
	for (int i = 0; i < arrSize; i++)
	{
		fprintf_s(file, "%d ", arrC[i]);
	}
	fprintf_s(file, "\n");
	fprintf_s(file, "ArrayP:\n");
	for (int j = 0; j < arrSize; j++)
	{
		fprintf_s(file, "%d ", arrP[j]);
	}
	fprintf_s(file, "\n");
	return;
}


bool CheckConditions(int arrSize, int* arrC, int* arrP)
{
	int sumP = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sumP += arrP[i];
	}
	for (int i = 0; i < arrSize; i++)
	{
		if (arrC[i] >= sumP)
			return false;
	}
	return true;
}

void SearchIJ(int arrSize, int* arrC, int* arrP, int &iAns, int &jAns)
{
	int I = 0;
	int J = 0;
	float oldSum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			float newSum = arrC[i] / (1 + pow(arrP[j], 2) + pow(arrC[i], 2));
			if (newSum > oldSum)
			{
				oldSum = newSum;
				I = i;
				J = j;
			}
		}
	}
	iAns = I;
	jAns = J;
	return;
}

void SearchIJ(int arrSize, int* arrC, int* arrP, int& iAns, int& jAns, FILE *file) // перегрука для просмотра сумм
{
	int I = 0;
	int J = 0;
	float oldSum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			float newSum = arrC[i] / (1 + pow(arrP[j], 2) + pow(arrC[i], 2));
			fprintf_s(file, "sum = %f; i = %u; j = %u\n", newSum, i, j);
			if (newSum > oldSum)
			{
				oldSum = newSum;
				I = i;
				J = j;
			}
		}
	}
	iAns = I;
	jAns = J;
	return;
}