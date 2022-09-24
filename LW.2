//
//  main.cpp
//  LW.2
//
//  Created by Нина Альхимович on 12.09.22.
//  2. Создать класс «Деталь» со следующими данными: id – уникальный номер, name – наименование, mass – вес. Создать дружественный класс «Контроль», в котором реализовать метод установки веса детали.

#include <iostream>

using namespace std;

class Detail {
    int id;
    string name;
    int mass;
    
    friend class Control;
    
    public:
    Detail();
    Detail(int new_id, string new_name, int new_mass);
    ~Detail();
    
    friend void show(Detail object);
};

class Control
{
    public:
    void set_mass(Detail &det);
    
};

Detail::Detail()    //конструктор по умолчанию
{
    id = 30008002;
    name = "Gear";
    mass = 3;
    
    cout << "Объект проинициализирован по умолчанию" << endl << endl;
}

Detail::~Detail()
{
    cout << "Данные разрушены" << endl << endl;
}

Detail::Detail(int new_id, string new_name, int new_mass)    //конструктор инициализации
{
    if(new_id >= -2147483648 && new_id <= 2147483647) id = new_id;
    name = new_name;
    if(new_mass >= -2147483648 && new_mass <= 2147483647) mass = new_mass;
    
    cout << "Объект проинициализирован" << endl << endl;
}

void show(Detail object)
{
    cout << "Информация о детали:" << endl;
    cout << "Уникальный номер: " << object.id << endl;
    cout << "Наименование: " << object.name << endl;
    cout << "Масса: " << object.mass << endl;
}

void Control::set_mass(Detail &det)
{
    int control_mass;
    
    cout << "Введите вес детали: ";
    cin >> control_mass;
    cout << endl;
    
    det.mass = control_mass;
}

int main()
{
    Detail gear, spindle(30008039, "Spindle", 5);
    Control ctrl;
    
    cout << "До обработки: " << endl;
    show(gear);
    
    ctrl.set_mass(gear);
    
    cout << "После обработки: " << endl;
    show(gear);
    
    cout << "До обработки: " << endl;
    show(spindle);
    
    ctrl.set_mass(spindle);
    
    cout << "После обработки: " << endl;
    show(spindle);
    
    Detail details[3] = {{37002020, "Bracket", 10}, {37106003, "Adapter", 7}, {30007009, "Piston", 100}};
    
    cout << "До обработки: " << endl;
    for(int i=0; i<3; i++)
        show(details[i]);
    
    cout << "После обработки: " << endl;
    for(int i=0; i<3; i++) {
        ctrl.set_mass(details[i]);
        show(details[i]);
    }
    
    return 0;
}

//Кронштейн - 37002020 - 10
//Переходник - 37106003 - 7
//Шестерня - 30008002 - 3
//Шпиндель - 30008039 - 5
//Поршень - 30007009 - 100
