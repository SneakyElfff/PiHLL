//
//  Ticket.hpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#ifndef Ticket_hpp
#define Ticket_hpp

#include <stdio.h>
#include <string>
#include "Country.hpp"

using namespace std;

namespace Tourism
{
    class Ticket
    {
    private:
        Country country;
        string date;
        string transport;
        
    public:
        Ticket();
        Ticket(const Country &, string, string);
        ~Ticket();
        
        void setCountry(const Country &);
        void setDate(string);
        void setTransport(string);
        
        void show();
    };
}

#endif /* Ticket_hpp */
