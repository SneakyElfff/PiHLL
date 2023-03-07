//
//  main.cpp
//  LW.3
//
//  Created by Нина Альхимович on 12.09.22.
//  2. «Целое положительное число».

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#define def 10

using namespace std;

class PositiveInteger
{
    public:
    PositiveInteger(int new_num=def);    //конструктор инициализации с параметром по умолчанию
    PositiveInteger(double);    //конструктор для преобразования в пользовательский тип
    ~PositiveInteger();
    
    PositiveInteger operator = (const PositiveInteger);
    int operator () (int k);    //возведение параметра объекта в степень аргумента
    void operator ++ ();    //префиксный оператор
    void operator ++ (int);    //постфиксный оператор
    PositiveInteger operator + (const PositiveInteger);
    PositiveInteger operator - (const PositiveInteger);
    bool operator > (const PositiveInteger);
    bool operator < (const PositiveInteger);
    bool operator == (const PositiveInteger);
    
    friend PositiveInteger operator -- (PositiveInteger &);    //префиксный оператор
    friend PositiveInteger operator -- (PositiveInteger &, int);    //постфиксный оператор
    friend PositiveInteger operator + (int, PositiveInteger);
    friend PositiveInteger operator + (PositiveInteger, int);
    friend PositiveInteger operator - (int, PositiveInteger);
    friend PositiveInteger operator - (PositiveInteger, int);
    friend bool operator > (int, const PositiveInteger &);
    friend bool operator < (int, const PositiveInteger &);
    friend bool operator == (int, const PositiveInteger);
    
    friend ostream &operator << (ostream &, const PositiveInteger &);
    friend istream &operator >> (istream &, PositiveInteger &);
    
    operator int() const;    //преобразование во встроенный тип int

    private:
    int num;
};

PositiveInteger::PositiveInteger(int new_num)
{
    num = new_num;
    
    if(new_num == def) cout << "Данные проинициализированы по умолчанию" << endl;
    else cout << "Данные проинициализированы" << endl;
}

PositiveInteger::PositiveInteger(double real_num)
{
    num = (int)real_num;
}

PositiveInteger::~PositiveInteger()
{
//    cout << "Данные разрушены" << endl;
}

PositiveInteger PositiveInteger::operator = (const PositiveInteger object)
{
    num = object.num;
    
    return *this;
}

int PositiveInteger::operator () (int k)
{
    return pow(num, k);
}

void PositiveInteger::operator ++ ()
{
    num++;
}

void PositiveInteger::operator ++ (int x)
{
    num++;
}

PositiveInteger PositiveInteger::operator + (const PositiveInteger object)
{
    PositiveInteger temp;
    
    temp.num = num + object.num;
    
    return temp;
}

PositiveInteger PositiveInteger::operator - (const PositiveInteger object)
{
    PositiveInteger temp;
    
    temp.num = num - object.num;
    
    return temp;
}

bool PositiveInteger::operator > (const PositiveInteger object)
{
    if(num > object.num) return true;
    else return false;
}

bool PositiveInteger::operator < (const PositiveInteger object)
{
    if(num < object.num) return true;
    else return false;
}

bool PositiveInteger::operator == (const PositiveInteger object)
{
    if(num == object.num) return true;
    else return false;
}

PositiveInteger operator -- (PositiveInteger & reference)
{
    reference.num--;
    
    return reference;
}

PositiveInteger operator -- (PositiveInteger & reference, int x)
{
    reference.num--;
    
    return reference;
}

PositiveInteger operator + (int x, PositiveInteger object)
{
    object.num += x;
    
    return object;
}

PositiveInteger operator + (PositiveInteger object, int x)
{
    object.num += x;
    
    return object;
}

PositiveInteger operator - (int x, PositiveInteger object)
{
    object.num = x - object.num;
    
    return object;
}

PositiveInteger operator - (PositiveInteger object, int x)
{
    object.num -= x;
    
    return object;
}

bool operator > (int x, const PositiveInteger &reference)
{
    if(reference.num < x) return true;
    
    else return false;
}

bool operator < (int x, const PositiveInteger &reference)
{
    if(reference.num > x) return true;
    
    else return false;
}

bool operator == (int x, const PositiveInteger object)
{
    if(object.num == x) return true;
    else return false;
}

ostream &operator<<(ostream &output, const PositiveInteger &object)
{
    output << object.num << endl;

    return output;
}

istream &operator>>(istream &input, PositiveInteger &object)
{
    input >> object.num;
//    input.ignore();    //пропуск пробела или /n
    
    return input;
}

PositiveInteger::operator int() const
{
    return num;
}

int main()
{
    int a, b, n, x;
    
    cout << "Введите 2 положительных числа: " << endl;
    cin >> a;
    cin >> b;
    while(a <= 0 || b <= 0)    //если введено не число
    {
        cin.clear();    //сброс состояния ошибки
        cin.ignore(100, '\n');    //очистка содержимого буфера ввода
        cout << "Введенное значение не является целым положительным числом, повторите попытку: ";
        cin >> a;
        cin >> b;
    }
    
    PositiveInteger counter1(a), counter2(b), result;
    
    cout << endl << "counter1 = " << counter1 << "counter2 = " << counter2 << "result = " << result;
    while(1)
    {
        if(result <= 0) result = 10;    //установка значения по умолчанию
            
        cout << endl << "Выберите оператор: " << endl;
        cout << setw(25) << "1 - ();" << endl;
        cout << setw(25) << "2 - ++;" << endl;
        cout << setw(54) << "3 - + (для однотипных);" << endl;
        cout << setw(54) << "4 - - (для однотипных);" << endl;
        cout << setw(59) << "5 - >/</== (для однотипных);" << endl;
        cout << setw(25) << "6 - --;" << endl;
        cout << setw(57) << "7 - + (для разных типов);" << endl;
        cout << setw(57) << "8 - - (для разных типов);" << endl;
        cout << setw(62) << "9 - >/</== (для разных типов);" << endl;
        cout << setw(41) << "0 - завершить;" << endl;
        
        cin.clear();    //сброс состояния ошибки
        cin.ignore(100, '\n');    //очистка содержимого буфера ввода
        
        switch(getchar())
        {
            case '1': cout << "Введите показатель степени: ";
                      cin >> n;
                      while(cin.fail())    //если введено не число
                      {
                          cin.clear();    //сброс состояния ошибки
                          cin.ignore(100, '\n');    //очистка содержимого буфера ввода
                          cout << "Введенное значение не является числом, повторите попытку: ";
                          cin >> n;
                      }
                      result = result(n);
                      cout << "Возведение параметра объекта result в степень аргумента: " << result << endl; break;
                
            case '2': result++;
                      cout << "Инкрементация параметра объекта result: " << result << endl; break;
                
            case '3': result = counter1 + counter2;
                      cout << endl << "Параметру объекта result присвоено значение суммы введенных объектов: " << result << endl; break;
                
            case '4': result = abs(counter1 - counter2);
                      cout << endl << "Параметру объекта result присвоено значение модуля разности объектов: " << result << endl; break;
                
            case '5': if(counter1 < counter2) {cout << "counter1 < counter2" << endl; break;}
                      else if(counter1 > counter2) {cout << "counter1 > counter2" << endl; break;}
                      else if(counter1 == counter2) {cout << "counter1 = counter2" << endl; break;}
                
            case '6': --result;
                      cout << "Декрементация параметра объекта result: " << result << endl; break;
                
            case '7': cout << "Введите второе слагаемое: ";
                      cin >> x;
                      while(cin.fail())    //если введено не число
                      {
                          cin.clear();    //сброс состояния ошибки
                          cin.ignore(100, '\n');    //очистка содержимого буфера ввода
                          cout << "Введенное значение не является числом, повторите попытку: ";
                          cin >> x;
                      }
                      result = counter2 + x;
                      cout << "Сумма counter2 и x: " << result << endl; break;
                
            case '8': cout << "Введите уменьшаемое: ";
                      cin >> x;
                      while(cin.fail())    //если введено не число
                      {
                          cin.clear();    //сброс состояния ошибки
                          cin.ignore(100, '\n');    //очистка содержимого буфера ввода
                          cout << "Введенное значение не является числом, повторите попытку: ";
                          cin >> x;
                      }
                      result = abs(x - counter1);
                      cout << "Модуль разности x и counter1: " << result << endl; break;
                
            case '9': cout << "Введите значение для сравнения: ";
                      cin >> x;
                      while(cin.fail())    //если введено не число
                      {
                          cin.clear();    //сброс состояния ошибки
                          cin.ignore(100, '\n');    //очистка содержимого буфера ввода
                          cout << "Введенное значение не является числом, повторите попытку: ";
                          cin >> x;
                      }
                      if(x > counter1) cout << "x > counter1" << endl;
                      else if(x < counter1) cout << "x < counter1" << endl;
                      if(x > counter2) cout << "x > counter2" << endl;
                      else if(x < counter2) cout << "x < counter2" << endl;
                      if(counter1 == x) cout << "counter1 = x" << endl;
                      break;
                
            case '0':
            {
                      int test = counter1;
                      cout << "Пользовательский тип преобразован во встроенный: " << test << endl;
                      result = 2.5;
                      cout << "Встроенный тип преобразован в пользовательский: " << result << endl;
                      return 0;
            }
                
            default: cout << endl << "Ошибка ввода. Повторите попытку" << endl;
        }
    }
    
    return 0;
}
