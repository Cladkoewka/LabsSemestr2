#include <iostream>;
#include <stdio.h>;
#include <conio.h>;
#include "Module.h";


void main()
{
	FILE *inputFile, *outputFile;
	int arraySize, *arrayC, *arrayP;
	fopen_s(&inputFile, "data1.txt", "rt");
	fopen_s(&outputFile, "res1.txt", "w");
	fscanf_s(inputFile, "%d\n", &arraySize);
	arrayC = new int[arraySize];
	arrayP = new int[arraySize];
	GetArrays(inputFile, arraySize, arrayC, arrayP); // Считывание массивов из файла
	WriteArrays(outputFile, arraySize, arrayC, arrayP); // Вывод исходных данных в файл
	if (CheckConditions(arraySize, arrayC, arrayP))
	{
		int i, j;
		//SearchIJ(arraySize, arrayC, arrayP, i, j, outputFile); //перегрука для просмотра сумм
		SearchIJ(arraySize, arrayC, arrayP, i, j); //поиск i, j подходящих под условие
		fprintf_s(outputFile, "I = %u\t", i);
		fprintf_s(outputFile, "J = %u", j);
	}
	return;
}