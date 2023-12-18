

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

void main()
{
	try 
	{
		int rows, colums, maxID, max;
		printf_s("Enter how many students: ");
		scanf_s("%d", &colums);
		printf_s("\nEnter how many object: ");
		scanf_s("%d", &rows);

		string s[2] = { "ds", "sa" };

		int** tablAR{ new int* [rows] {} };//Основная таблица с успеваемостью
		string* tablSTU = new string[colums]; //Массив с именами студентов
		string* tablOBJ = new string[rows]; //Массив с предметами
		int** tablSAR{ new int* [2] {} };//общее число прогулов

		for (int i = 0; i < rows; i++)// выделение память под столбцы
		{
			tablAR[i] = new int[colums];
		}
		for (int i = 0; i < 2; i++)// выделение память 
		{
			tablSAR[i] = new int[colums];
		}


		for (int i = 0; i < rows; i++)
		{
			printf_s("\nEnter object #%d:", i + 1);
			cin >> tablOBJ[i];
		}
		for (int i = 0; i < colums; i++)
		{
			printf_s("\nEnter name student #%d:", i + 1);
			cin >> tablSTU[i];
		}


		for (int j = 0; j < colums; j++)//заполняем успеваемость
		{
			for (int i = 0; i < rows; i++)
			{
				cout << "\nEnter academic record " << tablSTU[j] << " to " << tablOBJ[i] << ": ";
				scanf_s("%d", &tablAR[i][j]);
			}
		}

		for (int j = 0; j < colums; j++) //считаем общее кол-во прогулов
		{
			int count = 0;
			for (int i = 0; i < rows; i++)
			{
				count += tablAR[i][j];
			}
			tablSAR[0][j] = j;
			tablSAR[1][j] = count;
		}


		for (int j = 0; j < colums; j++) // сортирвка
		{
			max = 0;
			maxID = 0;
			for (int i = 0 + j; i < colums; i++)
			{
				if (max < tablSAR[1][i])
				{
					max = tablSAR[1][i];
					maxID = i;
				}
			}
			max = tablSAR[1][j]; // меняем местами эл
			tablSAR[1][j] = tablSAR[1][maxID];
			tablSAR[1][maxID] = max;
			max = tablSAR[0][j];
			//tablSAR[0][j] = tablSAR[0][maxID];
			tablSAR[0][j] = tablSAR[0][maxID];
			//tablSAR[0][j] = maxID;
			tablSAR[0][maxID] = max;

		}


		for (int i = 0; i < colums; i++)
		{
			cout << "\nName: " << tablSTU[tablSAR[0][i]] << " academic record: " << tablSAR[1][i];
		}






		for (int i = 0; i < rows; i++)// удаляем из памяти масив
		{
			delete [] tablAR[i];
		}
		for (int i = 0; i < 2; i++)
		{
			delete [] tablSAR[i];
		}
		delete[] tablSAR;
		delete[] tablAR;
		delete [] tablSTU;
		delete [] tablOBJ;
		
	}
	catch (std::exception& ex)
	{
		cout << ex.what();
	}
	
}


