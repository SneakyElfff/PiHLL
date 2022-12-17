//
//  Address.hpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#ifndef Address_hpp
#define Address_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace Tourism
{
    class Address
    {
    private:
        string street;
        int house_number;
        
    public:
        Address();
        Address(string, int);
        ~Address();
        
        void show();
    };
}

#endif /* Address_hpp */
