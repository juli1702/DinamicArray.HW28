#include <iostream>
#include "Hh.h"
#include <ctime>
#include <cstdlib>
//�������, ������� ��������� ������������ ������ ���������� ������� �� min �� max.
void fillArr(int arr[], int len, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (max - min) + min;
}