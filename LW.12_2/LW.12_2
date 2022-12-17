//
//  main.cpp
//  LW.12
//
//  Created by Нина Альхимович on 17.12.22.
//  2. Подсчет слов в строке.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "classes.hpp"

#define fread "strings.txt"
#define fwrite "result.txt"

using namespace std;

void checkWords(vector<string> &vec, unsigned long int &count)    //проверяет, содержит ли строка словв
{
    count = vec.size();
    
    for(int i=0; i<vec.size(); i++)
        if(vec[i] == "")
            count--;
}

int main()
{
    try
    {
        vector<string> words;
        char c;
        string temp;
        unsigned long int counter = 0, num = 0;
        
        ifstream in(fread, ios_base::in);
        if(!in.is_open()) throw FileNotOpen();
        else cout << "Файл " << fread << " открыт для чтения" << endl;
        
        try
        {
            if(in.peek() == EOF)
                throw EmptyFile();
        }
        catch(EmptyFile obj)
        {
            cout << obj.what() << endl;
        }
        
        ofstream out(fwrite, ios_base::out);
        if(!out.is_open()) throw FileNotOpen();
        else cout << "Файл " << fwrite << " открыт для записи" << endl << endl;
        
        while(!in.eof())
        {
            in >> temp;
            words.push_back(temp);    //сохранение очередного слова строки в контейнер
            
            in.read((char*)&c, sizeof(char));
            if(c == '\n')    //если достигнут конец строки
            {
                checkWords(words, counter);
                num++;    //количество строк в файле
                if(counter)
                {
                    out << counter << endl;    //запись количества слов в файл
                    cout << "В " << num << "-ой строке " << counter << " сл." << endl;
                }
                
                temp = "";
                words.clear();
                continue;
            }
        }
        
        in.close();
        out.close();
    }
    catch(FileNotOpen obj)
    {
        cout << obj.what() << endl;
        exit(-1);
    }

    return 0;
}
