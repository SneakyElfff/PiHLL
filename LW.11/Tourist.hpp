//
//  Tourist.hpp
//  LW.11
//
//  Created by Нина Альхимович on 15.12.22.
//

#ifndef Tourist_hpp
#define Tourist_hpp

#include <stdio.h>
#include "Person.hpp"
#include "Ticket.hpp"

namespace Tourism
{
    class Tourist : public Person
    {
    protected:
        Ticket *ticket;
        
        int record;
        string preference;
        bool Schengen;
        
    public:
        Tourist();
        Tourist(string, int, Ticket *, int, string, bool);
        ~Tourist();
        
        void setTicket(Ticket *);
        void setRecord(int);
        void setPref(string);
        void setSchengen(bool);
        
        void show();
    };
}

#endif /* Tourist_hpp */
