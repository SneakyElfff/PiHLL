//
//  main.cpp
//  LW.11
//
//  Created by Нина Альхимович on 15.12.22.
//  2. Человек, страна, турфирма, путевка, адрес, тургид, турист.

#include <iostream>
#include "Person.hpp"
#include "Tourist.hpp"
#include "Guide.hpp"
#include "Ticket.hpp"
#include "Country.hpp"
#include "Firm.hpp"

template<class T>
void check(T &var)
{
    cin >> var;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Ошибка ввода. Повторите попытку: ";
        cin >> var;
    }
}

namespace tour = Tourism;

using namespace tour;

using std::cout, std::cin;

int main()
{
    Tourist Someone;
    string stemp, stemp2;
    int itemp;
    
    cout << endl << "Введите данные о туристе: " << endl;
    cout << "Введите фамилию: ";
    cin >> stemp;
    Someone.setSurname(stemp);
    cout << "Введите возраст: ";
    check(itemp);
    Someone.setAge(itemp);
    cout << "Введите количество посещенных стран: ";
    check(itemp);
    Someone.setRecord(itemp);
    cout << "Введите предпочитаемый вид туризма: ";
    cin >> stemp;
    Someone.setPref(stemp);
    cout << "В случае наличия Шенгенской визы нажмите 1, в случае отсутствия - 0: ";
    check(itemp);
    Someone.setSchengen(itemp);
    
    cout << "Введите пункт назначения: ";
    cin >> stemp;
    cout << "Введите местную валюту: ";
    cin >> stemp2;
    
    Ticket Something(Country(stemp, stemp2), "", "");
    cout << "Введите дату отъезда: ";
    cin >> stemp;
    Something.setDate(stemp);
    cout << "Введите транспорт: ";
    cin >> stemp;
    Something.setTransport(stemp);
    
    Ticket *ptr = new Ticket;
    *ptr = Something;
    Someone.setTicket(ptr);
    
    Someone.show();
    
    return 0;
}
