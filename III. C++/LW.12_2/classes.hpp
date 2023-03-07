//
//  classes.hpp
//  LW.12
//
//  Created by Нина Альхимович on 17.12.22.
//

#ifndef classes_hpp
#define classes_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Exceptions
{
protected:
    string error = "Error. Exception.";
    
public:
    virtual string what() = 0;
};

class EmptyFile : public Exceptions
{
public:
    string what()
    {
        return "Ошибка. Файл ничего не содержит.";
    }
};

class FileNotOpen : public Exceptions
{
public:
    string what()
    {
        return "Ошибка. Невозможно открыть файл.";
    }
};

#endif /* classes_hpp */
