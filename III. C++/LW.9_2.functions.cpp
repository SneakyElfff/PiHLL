//
//  functions.cpp
//  LW.9
//
//  Created by Нина Альхимович on 2.12.22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"

using namespace std;

Employee::Employee()
{
    salary = 0;
    
    cout << endl << "Сработал конструктор" << endl;
}

Employee::Employee(string new_surname, string new_position, int new_salary)
{
    surname = new_surname;
    position = new_position;
    salary = new_salary;
    
    cout << endl << "Сработал конструктор с параметрами" << endl;
}

Employee::~Employee()
{
    cout << endl << "Сработал деструктор" << endl;
}

string Employee::getSurname()
{
    return surname;
}

string Employee::getPosition()
{
    return position;
}

int Employee::getSalary()
{
    return salary;
}

void Employee::setSurname(string last)
{
    surname = last;
}

void Employee::setPosition(string pos)
{
    position = pos;
}

void Employee::setSalary(int sum)
{
    salary = sum;
}

void Employee::show()
{
    cout << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Должность: " << position << endl;
    cout << "Зарплата: " << salary << endl;
}

void Employee::binWrite(ofstream &out)
{
    for(int i=0; i<surname.length(); i++)
        out.write((char*)&surname[i], sizeof(surname[i]));
    out << endl;

    for(int i=0; i<position.length(); i++)
        out.write((char*)&position[i], sizeof(position[i]));
    out << endl;
    
    out.write((char*)&salary, sizeof(int));
    out << endl;
}

void Employee::binRead(ifstream &in)
{
    char c;
    
    in.read((char*)&c, sizeof(char));
    if(c != '\n') in.seekg(-1, ios_base::cur);
    
    surname = "";
    while(1)
    {
        in.read((char*)&c, sizeof(char));
        if(c == '\n') break;
        surname += c;
    }

    position = "";
    while(1)
    {
        in.read((char*)&c, sizeof(c));
        if(c == '\n') break;
        position += c;
    }
    
    in.read((char*)&salary, sizeof(int));
}

Employee Employee::operator = (const Employee &object)
{
    surname = object.surname;
    position = object.position;
    salary = object.salary;
    
    return *this;
}

ostream &operator<<(ostream &out, Employee &object)
{
    out << object.surname << endl << object.position << endl << object.salary << endl;
    
    return out;
}

istream &operator>>(istream &in, Employee &object)
{
    in >> object.surname >> object.position >> object.salary;
    return in;
}

void reversePrintFromFile(ifstream &in)
{
    
}
