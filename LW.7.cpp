//
//  main.cpp
//  LW.7
//
//  Created by Нина Альхимович on 17.11.22.
//  2. Функция поиска максимального элемента в массиве.

#include <iostream>
#include <string.h>
#include <string>
#define num 3

using namespace std;

template<class T>    //шаблонная функция ввода информации в массив и проверки ее на корректность
void Input(T *array, int size)
{
    cout << "Вводите массив: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> array[i];
        while(cin.fail())    //если произошла ошибка при вводе
        {
            cin.clear();    //сброс ошибки
            cin.ignore(100, '\n');    //очистить буфер
            cout << "Ошибка ввода. Повторите попытку: ";
            cin >> array[i];
        }
    }
}

void Input(int &size)    //специализация для единственной переменной
{
    cin >> size;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Ошибка ввода. Повторите попытку: ";
        cin >> size;
    }
}

void Input(char **text)    //специализация для массива строк
{
    cout << "Вводите строки: " << endl;
    cin.ignore(100, '\n');
    for(int i=0; i<num; i++)
    {
        cin.getline(text[i], 100, '\n');
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка ввода. Повторите попытку: ";
            cin.getline(text[i], 100, '\n');
        }
    }
}

template<class T>
void maxInArray(T *array, int size)    //шаблонная функция поиска максимального элемента в массиве
{
    T max = 0;
    
    for(int i=0; i<size; i++)
        if(array[i] > max) max = array[i];
    
    cout << endl << "Максимальный элемент в массиве: " << max << endl << endl;
}

void maxInArray(char **array)    //специализация для поиска самой длинной строки
{
    unsigned long int max = 0;
    char *max_str = NULL;
    
    for(int i=0; i<num; i++)
        if(strlen(array[i]) > max)
        {
            max = strlen(array[i]);
            max_str = array[i];
        }
    
    cout << endl << "Строка максимальной длины: " << max_str << endl << endl;
}


int main()
{
    int i, size;
    
    cout << "Введите количество элементов массива: ";
    Input(size);
    
    //int
    int *array_int;
    if(!(array_int = (int *) calloc(size, sizeof(int))))
    {
        cout << "Память не выделена" << endl;
        return -1;
    }
    
    Input(array_int, size);
    
    maxInArray(array_int, size);
    
    //float
    float *array_float;
    if(!(array_float = (float *) calloc(size, sizeof(float))))
    {
        cout << "Память не выделена" << endl;
        return -1;
    }
    
    Input(array_float, size);
    
    maxInArray(array_float, size);
    
    //char
    char **text;
    if(!(text = (char **) calloc(num, sizeof(char *))))
    {
        cout << "Память не выделена" << endl;
        return -1;
    }
    for(i=0; i<num; i++)
        if(!(text[i] = (char *) calloc(100, sizeof(char))))
        {
            cout << "Память не выделена" << endl;
            return -1;
        }
    
    Input(text);
    
    maxInArray(text);
    
    free(array_int);
    free(array_float);
    for(i=0; i<num; i++)
        free(text[i]);
    free(text);
    
    return 0;
}
