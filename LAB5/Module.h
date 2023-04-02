#pragma once
#ifndef Module
#define Module
#include <iostream>;
#include <stdio.h>;
#include <conio.h>;

void GetArrays(FILE* file, int arrSize, int* arrC, int* arrP);
void WriteArrays(FILE* file, int arrSize, int* arrC, int* arrP);
bool CheckConditions(int arrSize, int* arrC, int* arrP);
void SearchIJ(int arrSize, int* arrC, int* arrP, int& iAns, int& jAns);
void SearchIJ(int arrSize, int* arrC, int* arrP, int& iAns, int& jAns, FILE* file); //перегрука для просмотра сумм

#endif