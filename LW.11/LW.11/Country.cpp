//
//  Country.cpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#include <iostream>
#include "Country.hpp"

namespace Tourism
{
    Country::Country()
    {
        cout << "Сработал констукртор по умолчанию Country" << endl;
    }

    Country::Country(string new_city, string new_currency)
    {
        city = new_city;
        currency = new_currency;
        
        cout << "Сработал конструктор инициализации Country" << endl;
    }

    Country::~Country()
    {
        cout << "Сработал деструктор Country" << endl;
    }

    void Country::show()
    {
        cout << "Город: " << city << endl;
        cout << "Национальная валюта: " << currency << endl;
    }
}
