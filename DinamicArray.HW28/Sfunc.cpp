#include <iostream>
#include "Hh.h"
#include <ctime>
#include <cstdlib>
//Функция, которая заполняет динамический массив случайными числами от min до max.
void fillArr(int arr[], int len, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (max - min) + min;
}