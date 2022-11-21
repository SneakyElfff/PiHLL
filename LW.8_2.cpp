//
//  main.cpp
//  LW.8
//
//  Created by Нина Альхимович on 19.11.22.
//  2. Класс "Матрица".

#include <iostream>
#include "descriptions.hpp"
#define m 3
#define n 4

using namespace std;

int main()
{
    int i, j;
    
    try
    {
        Matrix<int> array(m, n);
    
    
        array.show();
        int temp;
        
        Matrix<int> array2;
        array2 = array;
        
        cout << endl << "Вводите матрицу:" << endl;
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
            {
                cout << "[" << i <<"]" << "[" << j << "] = ";
                cin >> temp;
                array2.set(i, j, temp);
            }
        
        array2.show();
        
        //    cout << endl << "Вводите новую строку:" << endl;
        //    int *new_row;
        //    new_row = new int[n];
        //    for(i=0; i<n; i++)
        //        cin >> new_row[i];
        //    array2.add_row(1, new_row);
        //    array2.show();
        
//        cout << endl << "Вводите новый столбец:" << endl;
//        int *new_col;
//        new_col = new int[m];
//        for(j=0; j<m; j++)
//            cin >> new_col[j];
//        array2.add_col(2, new_col);
//        array2.show();
//
//        array2.del_col(2);
//        array2.show();
        
        array2.search(1);
        
        if(array == array2) cout << endl << "Матрицы равны" << endl;
        else cout << endl << "Матрицы не равны" << endl;
}
    
    catch(wrongSize obj)
    {
        cout << obj.what() << endl;
        cout << endl << "Ошибка. Матрицы с такими размерами не существует" << endl;
    }
    catch(bad_alloc obj)
    {
        cout << obj.what() << endl;
        cout << endl << "Ошибка выделения памяти" << endl;
    }
    catch(wrongParameters obj)
    {
        cout << endl << "Ошибка. Невозможно установить значение" << endl;
    }

    return 0;
}
