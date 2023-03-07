//
//  main.cpp
//  LW.9
//
//  Created by Нина Альхимович on 29.11.22.
//  2. "Сотрудник".

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"
#define mode "binfile.txt"

using namespace std;

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

void Menu()
{
    cout << endl << "Выберите действие: " << endl;
    cout << "        1 - внести данные в файл;" << endl;
    cout << "        2 - вывести содержимое файла на экран;" << endl;
    cout << "        3 - найти данные по запросу;" << endl;
    cout << "        4 - удалить данные по запросу;" << endl;
    cout << "        0 - завершить;" << endl;
}

vector<fpos_t> Search(string file, string query)    //функция поиска данных объекта по запросу
{
    try
    {
        ifstream in(file, ios_base::in);    //открыть файл для чтения, используя конструктор
        if(!in.is_open()) throw "file_error";

        in.seekg(0, ios_base::beg);

        char c;
        string temp = "";
        int temp2 = 0;
        bool flag = false;
        vector<fpos_t> found = {0, 0};    //содержит стартовую и конечную позиции удаляемой области памяти

        while(!in.eof())
        {
            found[0] = in.tellg();    //запоминает начало удаляемой части
            
            while(1)
            {
                in.read((char*)&c, sizeof(char));
                if(c == '\n') break;
                temp += c;
            }
            
            if(temp == query)
            {
                flag = true;
                break;
            }
            else temp = "";
        }
        
        if(flag)
        {
            cout << "Найденная информация: " << endl << temp << endl;
            temp = "";
            
            while(1)
            {
                in.read((char*)&c, sizeof(char));
                if(c == '\n') break;
                temp += c;
            }
            cout << temp << endl;
            
            in.read((char*)&temp2, sizeof(int));
            found[1] = in.tellg();
            cout << temp2 << endl;
            
            in.close();
            return found;
        }
        
        else cout << "Ничего не найдено" << endl;
        
        found.clear();
        
        in.close();
        
        return found;
    }
    catch(string)
    {
        cout << "Error. File is not open" << endl;
        exit(-1);
    }
}

void Delete(string file, string condition, int &n)
{
    try
    {
        fstream out(file, ios::binary | ios_base::out | ios_base::in);    //открыть файл для чтения и записи
        if(!out.is_open()) throw "file_error";
        
        ifstream in(file, ios_base::binary | ios_base::in);
        if(!in.is_open()) throw "file_error";
        
        vector<fpos_t> range (2);
        char temp;
        int i = 1;
        fpos_t end = 0;
        
        out.seekp(0, ios_base::end);
        end = out.tellp();    //запоминается конец файла
        out.seekp(0, ios_base::beg);
        
        range = Search(file, condition);
        
        in.seekg(range[1]-1, ios_base::beg);    //откуда переносить данные на место удаляемой части
        out.seekp(range[0], ios_base::beg);    //начало удаляемой части
        
        while(in.tellg() != end)    //пока не достигнут конец файла
        {
            in.read((char*)&temp, sizeof(char));
            out.write((char*)&temp, sizeof(char));
            in.seekg(range[1]+i, ios_base::beg);
            out.seekp(range[0]+i, ios_base::beg);
            
            i++;
        }
        
        temp = '\n';
        while(i != end)    //пока не достигнут конец файла
        {
            out.write((char*)&temp, sizeof(char));
            out.seekp(range[0]+i, ios_base::beg);
            
            i++;
        }
        
        n--;
        in.close();
        out.close();
    }
    
    catch(string)
    {
        cout << "Error. File is not open" << endl;
        exit(-1);
    }
}


int main()
{
    try
    {
        string last = "", job = "";
        int n = 0, sum = 0;
        vector<Employee> staff;
        Employee applicant;
        
        cout << "Введите количество сотрудников: ";
        Input(n);
        staff.resize(n);
        
        for(int i=0; i<n; i++)
        {
            cout << endl << "Введите фамилию сотрудника: ";
            Input(last);
            staff[i].setSurname(last);
            cout << "Введите должность сотрудника: ";
            Input(job);
            staff[i].setPosition(job);
            cout << "Введите зарплату сотрудника: ";
            Input(sum);
            staff[i].setSalary(sum);
        }
        
        while(1)
        {
            cout << endl << "Выберите режим работы с файлами: " << endl;
            cout << "        1 - текстовый;" << endl;
            cout << "        2 - бинарный;" << endl;
            cout << "        0 - завершить;" << endl;
            
            cin.clear();    //сброс состояния ошибки
            cin.ignore(100, '\n');    //очистка содержимого буфера ввода
            
            string query;
            
            switch(getchar())
            {
                case '1':
                {
                    cout << endl << "Работа с файлами в текстовом режиме: " << endl;
                    
                    Menu();
                    cin.clear();
                    cin.ignore(100, '\n');
                    switch(getchar())
                    {
                        case '1':
                        {
                            ofstream txt_out("text file.txt", ios_base::out);
                            if(!txt_out.is_open()) throw "file_error";

                            for(int i=0; i<n; i++)
                                txt_out << staff[i];
                            
                            txt_out.close();
                            break;
                        }
                            
                        case '2':
                        {
                            ifstream txt_in("text file.txt", ios_base::in);
                            if(!txt_in.is_open()) throw "file_error";
                            
                            Employee applicant;
                            
                            for(int i=0; i<n; i++)
                            {
                                txt_in >> applicant;
                                applicant.show();
                            }
                            
                            txt_in.close();
                            break;
                        }
                            
                        case '3':
                        {
                            cout << endl << "Введите фамилию сотрудника, которого нужно найти: ";
                            Input(query);
                            Search("text file.txt", query);
                            break;
                        }
                            
                        case '4':
                        {
                            cout << endl << "Введите фамилию сотрудника, которого необходимо уволить: ";
                            Input(query);
                            Delete("text file.txt", query, n);
                            break;
                        }
                            
                        case '0':
                        {
                            break;
                        }
                            
                        default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
                    }
                    break;
                }
                    
                case '2':
                {
                    cout << endl << "Работа с файлами в бинарном режиме: " << endl;
                    Menu();
                    cin.clear();
                    cin.ignore(100, '\n');
                    switch(getchar())
                    {
                        case '1':
                        {
                            ofstream bin_out(mode, ios::binary | ios_base::out);
                            if(!bin_out.is_open()) throw "file_error";
                            
                            for(int i=0; i<n; i++)
                                staff[i].binWrite(bin_out);
                            break;
                        }
                            
                        case '2':
                        {
                            ifstream bin_in(mode, ios_base::binary | ios_base::in);
                            if(!bin_in.is_open()) throw "file_error";
                            
                            for(int i=0; i<n; i++)
                            {
                                applicant.binRead(bin_in);
                                applicant.show();
                            }
                            break;
                        }
                            
                        case '3':
                        {
                            cout << endl << "Введите фамилию сотрудника, которого нужно найти: ";
                            Input(query);
                            Search(mode, query);
                            break;
                        }
                            
                        case '4':
                        {
                            cout << endl << "Введите фамилию сотрудника, которого необходимо уволить: ";
                            Input(query);
                            Delete(mode, query, n);
                            break;
                        }
                            
                        case '0':
                        {
                            break;
                        }
                            
                        default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
                    }
                    break;
                }
                    
                case '0': return 0;
                    
                default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
            }
        }

        return 0;
    }

    catch(int)
    {
        cout << endl << "Error. Wrong input" << endl;
        exit(-1);
    }
    catch(string)
    {
        cout << "Error. File is not open" << endl;
        exit(-1);
    }
}
