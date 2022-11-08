//
//  main.cpp
//  LW.5
//
//  Created by Нина Альхимович on 11.09.22.
//  2. "Учащийся".

#include <iostream>

using namespace std;

class Student
{
    public:
    Student(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state);
    ~Student();
    void show();    //функция вывода информации на экран
    
    protected:
    char name[15];
    char surname[20];
    char uni[10];
    int group;
    bool scholarship;
};

class Master : virtual public Student    //одна копия параметров Student наследуется
{
    public:
    Master(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, const char *new_field, const char *new_thesis);
    ~Master();
    void show();
    
    protected:
    char field[30];
    char thesis[30];
};

class Postgraduate : public Master
{
    public:
    Postgraduate(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, const char *new_field, const char *new_thesis, int new_counter);
    ~Postgraduate();
    void show();
    
    protected:
    int counter_articles;
};

class Alumni : virtual public Student
{
    public:
    Alumni(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, bool new_alloc, bool red);
    ~Alumni();
    void show();
    
    protected:
    bool allocation;
    bool red_diploma;
};

class Applicant : public Alumni
{
    public:
    Applicant(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, bool new_alloc, bool red, bool new_exp, const char *new_lang);
    ~Applicant();
    void show();
    
    protected:
    bool experience;
    char language[20];
};

class Employee : public Postgraduate, public Applicant
{
    public:
    Employee(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, const char *new_field, const char *new_thesis, int new_counter, bool new_alloc, bool red, bool new_exp, const char *new_lang, int salary);
    ~Employee();
    void show();
    
    private:
    int salary;
};

Student::Student(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state)
{
    strcpy(name, new_name);
    strcpy(surname, new_surname);
    strcpy(uni, new_uni);
    group = new_group;
    scholarship = state;
    
    cout << "Сработал конструктор Student" << endl;
}

Student::~Student()
{
    cout << "Сработал деструктор Student" << endl;
}

Master::Master(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, const char *new_field, const char *new_thesis) : Student(new_name, new_surname, new_uni, new_group, state)
{
    strcpy(field, new_field);
    strcpy(thesis, new_thesis);
    
    cout << "Сработал конструктор Master" << endl;
}

Master::~Master()
{
    cout << "Сработал деструктор Master" << endl;
}

Postgraduate::Postgraduate(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, const char *new_field, const char *new_thesis, int new_counter) : Student(new_name, new_surname, new_uni, new_group, state), Master(new_name, new_surname, new_uni, new_group, state, new_field, new_thesis)
{
    counter_articles = new_counter;
    
    cout << "Сработал конструктор Postgraduate" << endl;
}

Postgraduate::~Postgraduate()
{
    cout << "Сработал деструктор Postgraduate" << endl;
}

Alumni::Alumni(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, bool new_alloc, bool red) : Student(new_name, new_surname, new_uni, new_group, state)
{
    allocation = new_alloc;
    red_diploma = red;
    
    cout << "Сработал конструктор Alumni" << endl;
}

Alumni::~Alumni()
{
    cout << "Сработал деструктор Alumni" << endl;
}

Applicant::Applicant(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, bool new_alloc, bool red, bool new_exp, const char *new_lang) : Student(new_name, new_surname, new_uni, new_group, state), Alumni(new_name, new_surname, new_uni, new_group, state, new_alloc, red)
{
    experience = new_exp;
    strcpy(language, new_lang);
    
    cout << "Сработал конструктор Applicant" << endl;
}

Applicant::~Applicant()
{
    cout << "Сработал деструктор Applicant" << endl;
}

Employee::Employee(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, const char *new_field, const char *new_thesis, int new_counter, bool new_alloc, bool red, bool new_exp, const char *new_lang, int new_salary) : Student(new_name, new_surname, new_uni, new_group, state), Postgraduate(new_name, new_surname, new_uni, new_group, state, new_field, new_thesis, new_counter), Applicant(new_name, new_surname, new_uni, new_group, state, new_alloc, red, new_exp, new_lang)
{
    salary = new_salary;
    
    cout << "Сработал конструктор Employee" << endl;
}

Employee::~Employee()
{
    cout << "Сработал деструктор Employee" << endl;
}

void Student::show()
{
    cout << "Имя: " << name << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Университет: " << uni << endl;
    cout << "Группа: " << group << endl;
    if(scholarship) cout << "Стипендию получает" << endl;
    
    cout << endl;
}

void Master::show()
{
    Student::show();
    cout << "Сфера деятельности: " << field << endl;
    cout << "Научная магистерская работа: " << thesis << endl;
    
    cout << endl;
}

void Postgraduate::show()
{
    Master::show();
    cout << "Количество публикаций: " << counter_articles << endl;
    
    cout << endl;
}

void Alumni::show()
{
    Student::show();
    if(allocation) cout << "Распределен(а)" << endl;
    if(red_diploma) cout << "Получил(а) красный диплом" << endl;
    
    cout << endl;
}

void Applicant::show()
{
    Alumni::show();
    if(experience) cout << "Работал(а) по специальности" << endl;
    cout << "Язык: " << language << endl;

    cout << endl;
}

void Employee::show()
{
    cout << "Имя: " << name << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Университет: " << uni << endl;
    cout << "Группа: " << group << endl;
    if(scholarship) cout << "Стипендию получает" << endl << endl;
    
    cout << "Сфера деятельности: " << field << endl;
    cout << "Научная магистерская работа: " << thesis << endl << endl;
    
    cout << "Количество публикаций: " << counter_articles << endl << endl;
    
    if(allocation) cout << "Распределен(а)" << endl;
    if(red_diploma) cout << "Получил(а) красный диплом" << endl << endl;
    
    if(experience) cout << "Работал(а) по специальности" << endl;
    cout << "Язык: " << language << endl << endl;
    
    cout << "Зарплата: " << salary << endl;

    cout << endl;
}

int main()
{
    Student Kastamarov("Oleg", "Kastamarov", "MSLU", 234, true);
    Kastamarov.show();
    
    Master Kovalevskaya("Evgeniya", "Kovalevskaya", "BSU", 564, true, "Business", "Research1");
    Kovalevskaya.show();
    
    Postgraduate Andreev("Andrey", "Andreev", "MSU", 576, false, "Medicine", "Research2", 26);
    Andreev.show();
    
    Alumni Knyazev("Konstantin", "Knyazev", "BSEU", 980, false, false, false);
    Knyazev.show();
    
    Applicant Orlova("Eve", "Orlova", "BSUIR", 502, true, true, true, false, "Chinese");
    Orlova.show();
    
    Employee Yankovskaya("Irina", "Yankovskaya", "BNTU", 435, true, "Philosophy", "Research3", 19, true, false, true, "English", 3000);
    Yankovskaya.show();

    return 0;
}
