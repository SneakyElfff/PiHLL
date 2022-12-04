//
//  main.cpp
//  LW.10
//
//  Created by Нина Альхимович on 3.12.22.
//  2. Очередь.

#include <iostream>
#include <iterator>
#include "descriptions.hpp"

template<class T>    //шаблонная функция ввода информации и проверки ее на корректность
void Input(T &var)
{
    cin >> var;
    while(cin.fail())    //если произошла ошибка при вводе
    {
        cin.clear();    //сброс ошибки
        cin.ignore(100, '\n');    //очистить буфер
        cout << "Ошибка ввода. Повторите попытку: ";
        cin >> var;
    }
}

int main()
{
    char choice;
    int itemp;
    double dtemp;
    string stemp;
    
    cout << "Выберите тип данных: " << endl;
    cout << "        1 - int;" << endl;
    cout << "        2 - double;" << endl;
    cout << "        3 - string;" << endl;
    
    cin >> choice;
    
    Queue<int> integers;
    Queue<double> fractions;
    Queue<string> strings;
    
    while(1)
    {
        cout << endl << "Выберите действие: " << endl;
        cout << "        1 - добавить элемент в очередь;" << endl;
        cout << "        2 - добавить элемент в очередь (без повторений);" << endl;
        cout << "        3 - удалить элемент из очереди;" << endl;
        cout << "        4 - найти элемент в очереди;" << endl;
        cout << "        5 - просмотреть содержимое очереди;" << endl;
        cout << "        0 - завершить;" << endl;
        
        cin.clear();    //сброс состояния ошибки
        cin.ignore(100, '\n');    //очистка содержимого буфера ввода
        
        switch(getchar())
        {
            case '1':
            {
                cout << endl << "Введите элемент: ";
                switch(choice)
                {
                    case '1':
                        Input(itemp);
                        integers.Add(itemp);
                        break;
                    case '2':
                        Input(dtemp);
                        fractions.Add(dtemp);
                        break;
                    case '3':
                        Input(stemp);
                        strings.Add(stemp);
                        break;
                    default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
                }
                break;
            }
                
            case '2':
            {
                cout << endl << "Введите элемент: ";
                switch(choice)
                {
                    case '1':
                        Input(itemp);
                        integers.AddUnique(itemp);
                        break;
                    case '2':
                        Input(dtemp);
                        fractions.AddUnique(dtemp);
                        break;
                    case '3':
                        Input(stemp);
                        strings.AddUnique(stemp);
                        break;
                    default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
                }
                break;
            }
                
            case '3':
            {
                switch(choice)
                {
                    case '1':
                        integers.Delete();
                        break;
                    case '2':
                        fractions.Delete();
                        break;
                    case '3':
                        strings.Delete();
                        break;
                    default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
                }
                break;
            }
                
            case '4':
            {
                cout << endl << "Введите элемент, который необходимо найти: ";
                switch(choice)
                {
                    case '1':
                        Input(itemp);
                        integers.Search(itemp);
                        break;
                    case '2':
                        Input(dtemp);
                        fractions.Search(dtemp);
                        break;
                    case '3':
                        Input(stemp);
                        strings.Search(stemp);
                        break;
                    default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
                }
                break;
            }
                
            case '5':
            {
                switch(choice)
                {
                    case '1':
                        integers.Show();
                        break;
                    case '2':
                        fractions.Show();
                        break;
                    case '3':
                        strings.Show();
                        break;
                    default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
                }
                break;
            }
                
            case '0':
                return 0;
                
            default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
        }
    }

    return 0;
}
