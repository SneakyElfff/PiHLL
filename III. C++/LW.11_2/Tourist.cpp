//
//  Tourist.cpp
//  LW.11
//
//  Created by Нина Альхимович on 15.12.22.
//

#include <iostream>
#include "Tourist.hpp"
#include "Ticket.hpp"

namespace Tourism
{
    Tourist::Tourist()
    {
        cout << "Сработал конструктор по умолчанию Tourist" << endl;
    }

    Tourist::Tourist(string new_last, int new_age, Ticket *new_ticket, int new_record, string new_pref, bool new_Schengen) : Person(new_last, new_age)
    {
        ticket = new_ticket;
        record = new_record;
        preference = new_pref;
        Schengen = new_Schengen;
        
        cout << "Сработал конструктор инициализации Tourist" << endl;
    }

    Tourist::~Tourist()
    {
        cout << "Сработал деструктор Tourist" << endl;
    }

    void Tourist::setTicket(Ticket *new_ticket)
    {
        ticket = new_ticket;
    }
    void Tourist::setRecord(int new_record)
    {
        record = new_record;
    }
    void Tourist::setPref(string new_pref)
    {
        preference = new_pref;
    }

    void Tourist::setSchengen(bool new_Schengen)
    {
        Schengen = new_Schengen;
    }

    void Tourist::show()
    {
        cout << endl <<  "Данные о туристе: " << endl;
        Person::show();
        cout << "Количество посещенных стран: " << record << endl;
        cout << "Предпочитаемый вид туризма: " << preference << endl;
        cout << "Наличие визы: " << Schengen << endl;
        ticket->show();
        cout << endl;
    }
}
