// Laboratory_work_s2_number_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL)); // генерация случайных чисел
    int rows = 0;
    int columns = 0;
    cout << "Введите количество рядков: "; // введите количество строк
    cin >> rows;

    cout << "Введите количество столбцов: "; // введите количество столбцов
    cin >> columns;

    // динамическое создание двумерного массива 
    int** array = new int* [rows]; // строки в массиве
    for (int count = 0; count < rows; count++)
        array[count] = new int[columns]; // столбцы

    // заполнение массива
    for (int count_row = 0; count_row < rows; count_row++){
        for (int count_column = 0; count_column < columns; count_column++) {
            array[count_row][count_column] = rand() % 200 - 100; //заполнение массива случайными числами [-100; 100].

            //rand() % 20 - 10; [-10; 10] для теста
        }
    }
        
    for (int count_row = 0; count_row < rows; count_row++)
    {
        for (int count_column = 0; count_column < columns; count_column++)
            cout << setw(2) << array[count_row][count_column] << " "; //вывод массива
        cout << endl;
    }

    int* ptrarray = new int[columns]; // создание динамического массива
    for (int count = 0; count < columns; count++)
        ptrarray[count] = 0;

    for (int count_column = 0; count_column < columns; count_column++)
    {
        for (int count_row = 0; count_row < rows; count_row++)
            if (array[count_row][count_column] >= 0)
                ptrarray[count_column] += array[count_row][count_column];
            else
            {
                ptrarray[count_column] = 0;
                break;
            }
    }

    cout << endl;
    for (int count = 0; count < columns; count++)
        if (ptrarray[count] != 0)
            cout << setw(2) << ptrarray[count] << " "; // вывод массива
        else
            cout << setw(3) << " ";
    cout << endl;
    // удаление двумерного динамического массива
    for (int i = 0; i < 2; i++)
        delete[]array[i];

    delete[] ptrarray; 

	return 0;
}
