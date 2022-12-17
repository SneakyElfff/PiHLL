//
//  Person.cpp
//  LW.11
//
//  Created by Нина Альхимович on 15.12.22.
//

#include <iostream>
#include "Person.hpp"

namespace Tourism
{
    Person::Person()
    {
        cout << "Сработал конструктор по умолчанию Person" << endl;
    }

    Person::Person(string new_last, int new_age)
    {
        surname = new_last;
        age = new_age;
        
        cout << "Сработал конструктор инициализации Person" << endl;
    }

    Person::~Person()
    {
        cout << "Сработал деструктор Person" << endl;
    }

    void Person::setSurname(string new_last)
    {
        surname = new_last;
    }

    void Person::setAge(int new_age)
    {
        age = new_age;
    }

    void Person::show()
    {
        cout << "Фамилия: " << surname << endl;
        cout << "Возраст: " << age << endl;
    }
}
