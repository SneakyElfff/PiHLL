//
//  Firm.cpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#include <iostream>
#include "Firm.hpp"

namespace Tourism
{
    Firm::Firm()
    {
        cout << "Сработал конструктор по умолчанию Firm" << endl;
    }

    Firm::Firm(const Address &new_address, string new_sphere, int new_rating)
    {
        address = new_address;
        sphere = new_sphere;
        rating = new_rating;
        
        cout << "Сработал конструктор инициализации Firm" << endl;
    }

    Firm::~Firm()
    {
        cout << "Сработла деструктор Firm" << endl;
    }

    void Firm::show()
    {
        address.show();
        cout << "Сфера деятельности: " << sphere << endl;
        cout << "Рейтинг: " << rating << endl;
    }
}
