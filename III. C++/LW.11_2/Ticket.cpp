//
//  Ticket.cpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#include <iostream>
#include "Ticket.hpp"

namespace Tourism
{
    Ticket::Ticket()
    {
        cout << "Сработал конструктор по умолчанию Ticket" << endl;
    }

    Ticket::Ticket(const Country &new_country, string new_date, string new_transport)
    {
        country = new_country;
        date = new_date;
        transport = new_transport;
        
        cout << "Сработал конструктор инициализации Ticket" << endl;
    }

    Ticket::~Ticket()
    {
        cout << "Сработал деструктор Ticket" << endl;
    }

    void Ticket::setCountry(const Country &new_country)
    {
        country = new_country;
    }

    void Ticket::setDate(string new_date)
    {
        date = new_date;
    }

    void Ticket::setTransport(string new_transport)
    {
        transport = new_transport;
    }

    void Ticket::show()
    {
        country.show();
        cout << "Дата отправления: " << date << endl;
        cout << "Транспорт: " << transport << endl;
    }
}
