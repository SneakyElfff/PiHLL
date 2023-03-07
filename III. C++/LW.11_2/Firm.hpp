//
//  Firm.hpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#ifndef Firm_hpp
#define Firm_hpp

#include <stdio.h>
#include <string>
#include "Address.hpp"

using namespace std;

namespace Tourism
{
    class Firm
    {
    private:
        Address address;
        string sphere;
        int rating;
        
    public:
        Firm();
        Firm(const Address &, string, int);
        ~Firm();
        
        void show();
        
    };
}

#endif /* Firm_hpp */
