//
//  Address.cpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#include <iostream>
#include "Address.hpp"

namespace Tourism
{
    Address::Address()
    {
        cout << "Сработал конструктор по умолчанию Address" << endl;
    }

    Address::Address(string new_street, int new_num)
    {
        street = new_street;
        house_number = new_num;
        
        cout << "Сработал конструктор по инициализации Address" << endl;
    }

    Address::~Address()
    {
        cout << "Сработал деструктор Address" << endl;
    }

    void Address::show()
    {
        cout << "Улица, номер дома: " << street << ", " << house_number << endl;
    }
}
