//
//  main.cpp
//  LW.9
//
//  Created by Нина Альхимович on 29.11.22.
//  2. "Сотрудник".

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee
{
private:
    string surname;
    string position;
    int salary;
public:
    Employee();
    Employee(string new_position, string new_surname, int new_salary);
    ~Employee();
    
    string getSurname();
    string getPosition();
    int getSalary();
    
    void setSurname(string last);
    void setPosition(string pos);
    void setSalary(int sum);
    
    void show();
    
    void binRead(ifstream &);
    void binWrite(ofstream &);
    
    Employee operator = (const Employee &);    //присваивает содержимое одной матрицы другой
    friend ostream &operator<<(ostream &, Employee &);
    friend istream &operator>>(istream &, Employee &);
};

Employee::Employee()
{
    salary = 0;
    
    cout << endl << "Сработал конструктор" << endl;
}

Employee::Employee(string new_surname, string new_position, int new_salary)
{
    surname = new_surname;
    position = new_position;
    salary = new_salary;
    
    cout << endl << "Сработал конструктор с параметрами" << endl;
}

Employee::~Employee()
{
    cout << endl << "Сработал деструктор" << endl;
}

string Employee::getSurname()
{
    return surname;
}

string Employee::getPosition()
{
    return position;
}

int Employee::getSalary()
{
    return salary;
}

void Employee::setSurname(string last)
{
    surname = last;
}

void Employee::setPosition(string pos)
{
    position = pos;
}

void Employee::setSalary(int sum)
{
    salary = sum;
}

void Employee::show()
{
    cout << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Должность: " << position << endl;
    cout << "Зарплата: " << salary << endl;
}

void Employee::binWrite(ofstream &out)
{
    for(int i=0; i<surname.length(); i++)
        out.write((char*)&surname[i], sizeof(surname[i]));
    out << endl;

    for(int i=0; i<position.length(); i++)
        out.write((char*)&position[i], sizeof(position[i]));
    out << endl;
    
    out.write((char*)&salary, sizeof(int));
    out << endl;
}

void Employee::binRead(ifstream &in)
{
    char c;
    
    in.read((char*)&c, sizeof(char));
    if(c != '\n') in.seekg(-1, ios_base::cur);
    
    surname = "";
    while(1)
    {
        in.read((char*)&c, sizeof(char));
        if(c == '\n') break;
        surname += c;
    }

    position = "";
    while(1)
    {
        in.read((char*)&c, sizeof(c));
        if(c == '\n') break;
        position += c;
    }
    
    in.read((char*)&salary, sizeof(int));
}

Employee Employee::operator = (const Employee &object)
{
    surname = object.surname;
    position = object.position;
    salary = object.salary;
    
    return *this;
}

ostream &operator<<(ostream &out, Employee &object)
{
    out << object.surname << endl << object.position << endl << object.salary << endl;
    
    return out;
}

istream &operator>>(istream &in, Employee &object)
{
    in >> object.surname >> object.position >> object.salary;
    return in;
}

void reversePrintFromFile(ifstream &in)
{
    
}

void search(ifstream &in, string query)
{
    in.seekg(0);
    
    char c;
    string temp = "";
    int temp2 = 0;
    bool flag = false;

    while(!in.eof())
    {
        while(1)
        {
            in.read((char*)&c, sizeof(char));
            if(c == '\n') break;
            temp += c;
        }
        
        if(temp == query)
        {
            flag = true;
            break;
        }
        else temp = "";
    }
    
    if(flag)
    {
        cout << "Найденная информация: " << endl << temp << endl;
        temp = "";
        
        while(1)
        {
            in.read((char*)&c, sizeof(char));
            if(c == '\n') break;
            temp += c;
        }
        cout << temp << endl;
        
        in.read((char*)&temp2, sizeof(int));
        cout << temp2 << endl;
    }
    else cout << "Ничего не найдено" << endl;
}


int main()
{
    string surname, position;
    int n, salary;
    
    Employee empty;
    
    cout << "Введите количество сотрудников: ";
    cin >> n;
    
    cout << "Введите фамилию сотрудника: ";
    cin >> surname;
    cout << "Введите должность сотрудника: ";
    cin >> position;
    cout << "Введите зарплату сотрудника: ";
    cin >> salary;
    Employee Stakhovich(surname, position, salary);
    
    cout << "Введите фамилию сотрудника: ";
    cin >> surname;
    cout << "Введите должность сотрудника: ";
    cin >> position;
    cout << "Введите зарплату сотрудника: ";
    cin >> salary;
    Employee Gaviar(surname, position, salary);
    
    cout << endl << "Работа с файлами в бинарном режиме: " << endl;
    
    Employee applicant;
    
    ofstream bin_out("files.bin", ios::binary | ios_base::out);
    if(!bin_out)
    {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }
    bin_out.seekp(0);

    Stakhovich.binWrite(bin_out);
    Gaviar.binWrite(bin_out);
    
    ifstream bin_in("files.bin", ios_base::binary | ios_base::in);    //открыть файл, используя конструктор
    if(!bin_in)
    {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }
    
    applicant.binRead(bin_in);
    applicant.show();
    applicant.binRead(bin_in);
    applicant.show();
    
    string query;
    cout << endl << "Введите фамилию сотрудника, которого нужно найти: ";
    cin >> query;
    search(bin_in, query);
    
    bin_out.close();
    bin_in.close();
    
    
    cout << endl << "Работа с файлами в текстовом режиме: " << endl;

    applicant = Gaviar;

    ofstream txt_out("files.txt", ios_base::out);
    if(!txt_out)
    {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }

    txt_out << applicant;

    ifstream txt_in("files.txt", ios_base::in);    //открыть файл, используя конструктор
    if(!txt_in)
    {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }

    txt_in >> applicant;
    applicant.show();

    txt_out.close();
    txt_in.close();
    
    return 0;
}
