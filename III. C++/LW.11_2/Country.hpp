//
//  Country.hpp
//  LW.11
//
//  Created by Нина Альхимович on 16.12.22.
//

#ifndef Country_hpp
#define Country_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace Tourism
{
    class Country
    {
    private:
    string city;
    string currency;

    public:
    Country();
    Country(string, string);
    ~Country();

    void show();
    };
}

#endif /* Country_hpp */
