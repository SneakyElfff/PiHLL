//
//  descriptions.cpp
//  LW.6
//
//  Created by Нина Альхимович on 23.10.22.
//

#include <iostream>
#include "descriptions.hpp"

Student::Student(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks)
{
    if(!(name = new char[15]))
    {
        cout << "Память не выделена" << endl;
        return;
    }
    strcpy(name, new_name);
    if(!(surname = new char[20]))
    {
        cout << "Память не выделена" << endl;
        return;
    }
    strcpy(surname, new_surname);
    if(!(uni = new char[10]))
    {
        cout << "Память не выделена" << endl;
        return;
    }
    strcpy(uni, new_uni);
    group = new_group;
    scholarship = state;
    if(!(exams = new int[5]))
    {
        cout << "Память не выделена" << endl;
        return;
    }
    for(int i=0; i<5; i++)
        exams[i] = marks[i];
    
    cout << endl << "Сработал конструктор Student" << endl;
}

Student::~Student()
{
    delete name;
    delete surname;
    delete uni;
    delete exams;
    
    cout << "Сработал деструктор Student" << endl << endl;
}

Master::Master(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks, const char *new_field, const char *new_thesis) : Student(new_name, new_surname, new_uni, new_group, state, marks)
{
    if(!(field = new char[30]))
    {
        cout << "Память не выделена" << endl;
        return;
    }
    strcpy(field, new_field);
    if(!(thesis = new char[30]))
    {
        cout << "Память не выделена" << endl;
        return;
    }
    strcpy(thesis, new_thesis);
    
    cout << "Сработал конструктор Master" << endl;
}

Master::~Master()
{
    delete field;
    delete thesis;
    
    cout << "Сработал деструктор Master" << endl;
}

Postgraduate::Postgraduate(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks, const char *new_field, const char *new_thesis, int new_counter) : Student(new_name, new_surname, new_uni, new_group, state, marks), Master(new_name, new_surname, new_uni, new_group, state, marks, new_field, new_thesis)
{
    counter_articles = new_counter;
    
    cout << "Сработал конструктор Postgraduate" << endl;
}

Postgraduate::~Postgraduate()
{
    cout << "Сработал деструктор Postgraduate" << endl;
}

Alumni::Alumni(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks, bool new_alloc, bool red) : Student(new_name, new_surname, new_uni, new_group, state, marks)
{
    allocation = new_alloc;
    red_diploma = red;
    
    cout << "Сработал конструктор Alumni" << endl;
}

Alumni::~Alumni()
{
    cout << "Сработал деструктор Alumni" << endl;
}

//методы

void Student::show()
{
}

void Master::show()
{
    cout << "Имя: " << name << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Университет: " << uni << endl;
    cout << "Группа: " << group << endl;
    if(scholarship) cout << "Стипендию получает" << endl;
    cout << "Отметки за прошедшую сессию: " << endl;
    for(int i=0; i<5; i++)
        cout << exams[i] << " ";
    cout << endl << "Средний балл: " << GPA << endl;
    
    cout << "Сфера деятельности: " << field << endl;
    cout << "Научная магистерская работа: " << thesis << endl;
    
    cout << endl;
}

void Postgraduate::show()
{
    Master::show();
    cout << "Количество публикаций: " << counter_articles << endl;
    
    cout << endl;
}

void Alumni::show()
{
    cout << "Имя: " << name << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Университет: " << uni << endl;
    cout << "Группа: " << group << endl;
    if(scholarship) cout << "Стипендию получает" << endl;
    cout << "Отметки за прошедшую сессию: " << endl;
    for(int i=0; i<5; i++)
        cout << exams[i] << " ";
    cout << endl << "Средний балл: " << GPA << endl;
    
    if(allocation) cout << "Распределен(а)" << endl;
    if(red_diploma) cout << "Получил(а) красный диплом" << endl;
    
    cout << endl;
}

void Student::calculateGPA(int *array)
{
}

void Master::calculateGPA(int *array)
{
    for(int i=0; i<5; i++)
        GPA += exams[i];
    GPA /= 5;
    
    Student::calculateGPA(array);
}

void Postgraduate::calculateGPA(int *array)
{
    Master::calculateGPA(array);
}

void Alumni::calculateGPA(int *array)
{
    for(int i=0; i<5; i++)
        GPA += exams[i];
    GPA /= 5;
}
