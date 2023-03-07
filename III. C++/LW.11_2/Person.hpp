//
//  Person.hpp
//  LW.11
//
//  Created by Нина Альхимович on 15.12.22.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace Tourism
{
    class Person
    {
    protected:
        string surname;
        int age;
        
    public:
        Person();
        Person(string, int);
        ~Person();
        
        void setSurname(string);
        void setAge(int);
        
        void show();
    };
}

#endif /* Person_hpp */
