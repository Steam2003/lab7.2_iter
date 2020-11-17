#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

void create(int** a, int rowCount, int colCount, int Low, int High);
void print(int** a, int rowCount, int colCount);
int MinE(int** a, int row, int colCount);
int MaxE(int** a, int row, int colCount);
void callMinMax(int** a, int rowCount, int colCount);
void changeMinMax(int** a, int row, int indexMin, int indexMax);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int Low, High, rowCount, colCount;
	cout << "¬вед≥ть к≥льк≥сть р€дк≥в масиву: "; cin >> rowCount;
	cout << "¬вед≥ть к≥льк≥сть стовпц≥в масиву: "; cin >> colCount;
	cout << "¬вед≥ть найменше значенн€ елемента масиву: "; cin >> Low;
	cout << "¬вед≥ть найб≥льше значенн€ елемента масиву: "; cin >> High;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; ++i)
		a[i] = new int[colCount];

	create(a, rowCount, colCount, Low, High);
	print(a, rowCount, colCount);
	callMinMax(a, rowCount, colCount);
	print(a, rowCount, colCount);
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}
void create(int** a, int rowCount, int colCount, int Low, int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
		{
			a[i][j] = Low + rand() % (High - Low + 1);
		}
}
void print(int** a, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void callMinMax(int** a, int rowCount, int colCount)
{
	int indexMin = a[0][0];
	int indexMax = a[0][0];
	int max = a[0][0];
	for (int row=0; row < rowCount; row++)
		if (row % 2 == 0)
		{
			indexMin = MinE(a,row,colCount);
			indexMax = MaxE(a, row, colCount);
			changeMinMax(a, row, indexMin, indexMax);
		}

}
int MinE(int** a, int row, int colCount)
{
	int indexMin = 0;
	int min = a[0][0];
	for (int i = 0; i < colCount; ++i)
	{
		if (a[row][i] < min)
		{
			min = a[row][i];
			indexMin = i;
		}
	}
	return indexMin;
}
int MaxE(int** a, int row, int colCount)
{
	int indexMax = 0;
	int max = a[0][0];
	for (int i = 0; i < colCount; ++i)
	{
		if (a[row][i] > max)
		{
			max = a[row][i];
			indexMax = i;
		}
	}
	return indexMax;
}
void changeMinMax(int** a, int row, int indexMin, int indexMax)
{
	int tmp = a[row][indexMin];
	a[row][indexMin] = a[row][indexMax];
	a[row][indexMax] = tmp;

}

