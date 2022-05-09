#include <iostream>
#include "Hh.h"
using namespace std;
template <typename T> void showArr(T arr[], int len);
template <typename T> T* resizeArr(T arr[], int len, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	// ������ 1. 
	/*���� ��� ������������ ������� A[n] � B[m]. ���������� ������� ������������ ������ C[n + m],
	������� ������� �� ��������� �������� A � B. ����� �������� ������� C ������� A � B ������ ����
	�������.*/
	int n, m;
	cout << "������ 1. ������� ����� �������� A � B: ";
	cin >> n >> m;
	int* dA = new int[n];
	int* dB = new int[m];
	fillArr(dA, n, 10, 31);
	cout << "����������� ������ A: ";
	showArr(dA, n);
	fillArr(dB, m, 30, 51);
	cout << "����������� ������ B: ";
	showArr(dB, m);
	cout << "����� ������ C, ������ " << m + n << ": ";
	int* dC = new int[n + m];
	for (int i = 0; i < n; i++)
		dC[i] = dA[i];
	for (int i = 0; i < m; i++)
		dC[i + n] = dB[i];
	showArr(dC, n + m);
	delete[] dA;
	delete[] dB;
	cout << endl;
	//������ 2.
	/*�������� ������� resizeArr(), ������� ��������� ������������ ������, ������� ����� ������� � �����
	����� �������. ���������� ������ ������ ���� ����������� ����� �� �����.*/
	cout << "������ 2. ������� ����� �������: ";
	int k, len1;
	cin >> k;
	cout << "����������� ������: ";
	int* dArr = new int[k];
	fillArr(dArr, k, 1, 15);
	showArr(dArr, k);
	cout << "������� ����� ����� �������: ";
	cin >> len1;
	dArr = resizeArr(dArr, k, len1);
	cout << "�������� ������: ";
	showArr(dArr, len1);



	return 0;
}
//�������, ������� ������� ������
template <typename T> void showArr(T arr[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//�������, ������� ������ ����� �������
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