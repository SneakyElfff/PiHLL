//
//  Guide.cpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#include <iostream>
#include "Guide.hpp"

namespace Tourism
{
    Guide::Guide()
    {
        cout << "Сработал конструктор по умолчанию Guide" << endl;
    }

    Guide::Guide(string new_last, int new_age, Ticket *new_ticket, int new_record, string new_pref, bool new_Schengen, string new_lan, int new_salary) : Tourist(new_last, new_age, new_ticket, new_record, new_pref, new_Schengen)
    {
        language = new_lan;
        salary = new_salary;
        
        cout << "Сработал конструктор инициализации Tourist" << endl;
    }

    Guide::~Guide()
    {
        cout << "Сработал деструктор Guide" << endl;
    }

    void Guide::show()
    {
        Tourist::show();
        cout << "Основной язык: " << language << endl;
        cout << "Зарплата: " << salary << endl;
    }
}
