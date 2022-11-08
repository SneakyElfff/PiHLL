//
//  main.cpp
//  LW.6
//
//  Created by Нина Альхимович on 22.10.22.
//  2. "Учащийся".

#include <iostream>
#include "descriptions.hpp"

int main()
{
    Student **ptr = new Student *[3];    //массив указателей на объекты типа базового класса
    int array[3][5] = {{6, 8, 7, 9, 9}, {4, 6, 4, 3, 8}, {10, 6, 9, 4, 8}};

    if(!(ptr[0] = new Master("Evgeniya", "Kovalevskaya", "BSU", 564, true, array[0], "Business", "Research1")))
    {
        cout << "Память не выделена" << endl;
        return -1;
    }
    
    if(!(ptr[1] = new Postgraduate("Oleg", "Kastamarov", "MSLU", 576, false, array[1], "Medicine", "Research2", 26)))
    {
        cout << "Память не выделена" << endl;
        return -1;
    }
    
    if(!(ptr[2] = new Alumni("Eve", "Orlova", "BSUIR", 502, true, array[2], true, true)))
    {
        cout << "Память не выделена" << endl;
        return -1;
    }
    
    for(int i=0; i<3; i++)
    {
        ptr[i]->calculateGPA(array[i]);
        ptr[i]->show();
        delete ptr[i];    //освобождение памяти, выделенной под каждый указатель
    }
    
    delete[] ptr;    //освобождение памяти, выделенной под массив указателей

    return 0;
}
