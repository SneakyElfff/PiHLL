//
//  main.cpp
//  LW.8
//
//  Created by Нина Альхимович on 19.11.22.
//  2. Класс "Матрица".

#include <iostream>
#include <exception>
#include "descriptions.hpp"
#define m 3
#define n 4

using namespace std;

void customTerminate()
{
    cout << "Ошибка!" << endl;
    exit(-1);
}

//void customUnexpected()
//{
//    throw badAllocation();
//}

int main()
{
    int i, j, temp;
    set_terminate(customTerminate);
//    set_unexpected(customUnexpected);
    
    try
    {
        Matrix<int> array(m, n);
        Matrix<int> array2 = array;
        
        cout << endl << "Вводите матрицу:" << endl;
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
            {
                cout << "[" << i <<"]" << "[" << j << "] = ";
                cin >> temp;
                while(cin.fail())    //если введено не число
                {
                    cin.clear();    //сброс ошибки
                    cin.ignore(100, '\n');    //очистить буфер ввода
                    cout << "Ошибка ввода. Повторите попытку: ";
                    cin >> temp;
                }
                array2.set(i, j, temp);
            }
        
        while(1)
        {
            cout << endl << "Выберите действие: " << endl;
            cout << "        1 - добавить строку;" << endl;
            cout << "        2 - добавить столбец;" << endl;
            cout << "        3 - удалить строку;" << endl;
            cout << "        4 - удалить столбец;" << endl;
            cout << "        5 - найти элемент;" << endl;
            cout << "        6 - вывести на экран;" << endl;
            cout << "        7 - сравнить матрицы;" << endl;
            cout << "        0 - завершить;" << endl;
            
            cin.clear();    //сброс состояния ошибки
            cin.ignore(100, '\n');    //очистка содержимого буфера ввода
            
            int ind = 0;    //переменная, указывающая номер строки/столбца или элемент для удаления
            
            switch(getchar())
            {
                case '1': cout << "Введите номер позиции для вставки: ";
                    cin >> ind;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Введенное значение не является числом, повторите попытку: ";
                        cin >> ind;
                    }
                    
                    cout << endl << "Вводите новую строку:" << endl;
                    
                    int *new_row;
                    if((new_row = new int[array2.getRow()]) == NULL)
                        throw bad_alloc();
                    
                    for(i=0; i<array2.getRow(); i++)
                    {
                        cin >> new_row[i];
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                            cout << "Введенное значение не является числом, повторите попытку: ";
                            cin >> new_row[i];
                        }
                    }
                    
                    array2.addRow(ind, new_row);
                    array2.show();
                    
                    delete[] new_row;
                    break;
                    
                case '2': cout << "Введите номер позиции для вставки: ";
                    cin >> ind;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Введенное значение не является числом, повторите попытку: ";
                        cin >> ind;
                    }
                    
                    cout << endl << "Вводите новый столбец:" << endl;
                    
                    int *new_col;
                    if((new_col = new int[array2.getRow()]) == NULL)
                        throw bad_alloc();
                    
                    for(j=0; j<array2.getRow(); j++)
                    {
                        cin >> new_col[j];
                        while(cin.fail())
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                            cout << "Введенное значение не является числом, повторите попытку: ";
                            cin >> new_col[j];
                        }
                    }
                    
                    array2.addCol(ind, new_col);
                    array2.show();
                    
                    delete[] new_col;
                    break;
                    
                case '3': cout << "Введите номер строки для удаления: ";
                    cin >> ind;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Введенное значение не является числом, повторите попытку: ";
                        cin >> ind;
                    }
                    
                    array2.delRow(ind);
                    array2.show();
                    break;
                    
                case '4': cout << "Введите номер столбца для удаления: ";
                    cin >> ind;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Введенное значение не является числом, повторите попытку: ";
                        cin >> ind;
                    }
                    
                    array2.delCol(ind);
                    array2.show();
                    break;
                    
                case '5': cout << "Введите число для поиска: ";
                    cin >> ind;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Введенное значение не является числом, повторите попытку: ";
                        cin >> ind;
                    }
                    
                    array2.search(ind);
                    break;
                    
                case '6': array2.show(); break;
                    
                case '7': array = array2;
                    
                    if(array == array2) cout << endl << "Матрицы равны" << endl;
                    else cout << endl << "Матрицы не равны" << endl;
                    break;
                    
                case '0': return 0;
                    
                default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
            }
        }
    }
    
    catch(wrongSize obj)
    {
        cout << obj.what() << endl;
    }
    catch(badAllocation obj)
    {
        cout << "Ошибка выделения памяти." << endl;
    }
    catch(wrongParameters obj)
    {
        cout << obj.what() << endl;
    }

    return 0;
}
