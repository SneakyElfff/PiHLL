//
//  Guide.hpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#ifndef Guide_hpp
#define Guide_hpp

#include <stdio.h>
#include "Tourist.hpp"

namespace Tourism
{
    class Guide : public Tourist
    {
    private:
        class Firm;
        string language;
        int salary;
        
    public:
        Guide();
        Guide(string, int, Ticket *, int, string, bool, string, int);
        ~Guide();
        
        void show();
    };
}

#endif /* Guide_hpp */
