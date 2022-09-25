//
//  main.cpp
//  LW.2
//
//  Created by Нина Альхимович on 12.09.22.
//  2. Создать класс «Деталь» со следующими данными: id – уникальный номер, name – наименование, mass – вес. Создать дружественный класс «Контроль», в котором реализовать метод установки веса детали.

#include <iostream>

using namespace std;

class Detail
{
    int id;
    string name;
    int mass;
    
    static int counter;    //счетчик объектов класса
    
    friend class Control;
    
    public:
    Detail();
    Detail(string new_name, int new_mass);
    ~Detail();
    
    friend void show(Detail object);    //метод вывода содержимого объекта класса на экран
};

int Detail::counter = 0;

class Control
{
    public:
    void setMass(Detail &det);    //метод установки значения атрибута mass класса Detail
    
};

Detail::Detail()    //конструктор по умолчанию
{
    name = "Gear";
    mass = 3;
    
    counter++;
    id = counter;
    
    cout << "Объект проинициализирован по умолчанию" << endl << endl;
}

Detail::~Detail()    //деструктор
{
//    cout << "Данные разрушены" << endl << endl;
}

Detail::Detail(string new_name, int new_mass)    //конструктор инициализации
{
    name = new_name;
    mass = new_mass;
    
    counter++;
    id = counter;
    
    cout << "Объект проинициализирован" << endl << endl;
}

void show(Detail object)
{
    cout << "Информация о детали:" << endl;
    cout << "Уникальный номер: " << object.id << endl;
    cout << "Наименование: " << object.name << endl;
    cout << "Масса: " << object.mass << endl << endl;
}

void Control::setMass(Detail &det)
{
    int control_mass;
    
    cout << "Введите вес детали: ";
    cin >> control_mass;
    while(cin.fail())    //если введено не число
    {
        cin.clear();    //сброс состояния ошибки
        cin.ignore(100, '\n');    //очистка содержимого буфера ввода
        cout << "Значение переменной вышло за реальный диапазон значений, повторите попытку: ";
        cin >> control_mass;
    }
    cout << endl;
    
    det.mass = control_mass;
}

int main()
{
    Detail gear("Bracket", 100), spindle("Spindle", 5);
    Control ctrl;
    
    void beforeAfter(Detail &object, Control ctrl);    //функция вывода содержимого объектов класса до и                                                       после обработки методом класса Control
    beforeAfter(gear, ctrl);
    
    beforeAfter(spindle, ctrl);

    Detail details[3];
    
    for(int i=0; i<3; i++)
        beforeAfter(details[i], ctrl);
    
    return 0;
}

void beforeAfter(Detail &object, Control ctrl)
{
    cout << "До обработки: " << endl;
    show(object);
    
    ctrl.setMass(object);
    
    cout << "После обработки: " << endl;
    show(object);
}
