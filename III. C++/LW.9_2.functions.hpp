//
//  functions.hpp
//  LW.9
//
//  Created by Нина Альхимович on 2.12.22.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Employee
{
private:
    string surname;
    string position;
    int salary;
public:
    Employee();    //конструктор по умолчанию
    Employee(string new_position, string new_surname, int new_salary);    //конструктор инициализации
    ~Employee();
    
    string getSurname();
    string getPosition();
    int getSalary();
    
    void setSurname(string last);
    void setPosition(string pos);
    void setSalary(int sum);
    
    void show();
    
    void binRead(ifstream &);
    void binWrite(ofstream &);
    
    Employee operator = (const Employee &);
    friend ostream &operator<<(ostream &, Employee &);
    friend istream &operator>>(istream &, Employee &);
};

#endif /* functions_hpp */
