#include <iostream>
#include "Hh.h"
using namespace std;
template <typename T> void showArr(T arr[], int len);
template <typename T> T* resizeArr(T arr[], int len, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	// Задача 1. 
	/*Даны два динамических массива A[n] и B[m]. Необходимо создать динамический массив C[n + m],
	который состоит из элементов массивов A и B. После создания массива C массивы A и B должны быть
	удалены.*/
	int n, m;
	cout << "Задача 1. Введите длины массивов A и B: ";
	cin >> n >> m;
	int* dA = new int[n];
	int* dB = new int[m];
	fillArr(dA, n, 10, 31);
	cout << "Изначальный массив A: ";
	showArr(dA, n);
	fillArr(dB, m, 30, 51);
	cout << "Изначальный массив B: ";
	showArr(dB, m);
	cout << "Новый массив C, длиною " << m + n << ": ";
	int* dC = new int[n + m];
	for (int i = 0; i < n; i++)
		dC[i] = dA[i];
	for (int i = 0; i < m; i++)
		dC[i + n] = dB[i];
	showArr(dC, n + m);
	delete[] dA;
	delete[] dB;
	cout << endl;
	//Задача 2.
	/*Создайте функцию resizeArr(), которая принимает динамический массив, текущую длину массива и новую
	длину массива. Переданный массив меняет свою изначальную длину на новую.*/
	cout << "Задача 2. Введите длину массива: ";
	int k, len1;
	cin >> k;
	cout << "Изначальный массив: ";
	int* dArr = new int[k];
	fillArr(dArr, k, 1, 15);
	showArr(dArr, k);
	cout << "Введите новую длину массива: ";
	cin >> len1;
	dArr = resizeArr(dArr, k, len1);
	cout << "Итоговый массив: ";
	showArr(dArr, len1);



	return 0;
}
//Функция, которая выводит массив
template <typename T> void showArr(T arr[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Функция, которая меняет длину массива
template <typename T> T* resizeArr(T arr[], int len, int n) {
	if (n <= 0)
		return arr;

	if (n >= len) {
		T* tmp = new T[len];
		for (int i = 0; i < len; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = new T[len + n];
		for (int i = 0; i < len; i++)
			arr[i] = tmp[i];
		delete[] tmp;
	}
	return arr;

	if (n < len)
		len -= n;
	T* tmp = new T[len];
	for (int i = 0; i < len; i++)
		tmp[i] = arr[i];
	delete[] arr;
	return tmp;
}