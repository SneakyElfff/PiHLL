//
//  descriptions.hpp
//  LW.6
//
//  Created by Нина Альхимович on 23.10.22.
//

#ifndef descriptions_hpp    //директива, проверяющая, определено ли имя заголовочного файла
#define descriptions_hpp    //если не определено

#include <stdio.h>

using namespace std;

class Student
{
    public:
    Student(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks);
    virtual ~Student();    //виртуальный деструктор
    virtual void show() = 0;    //чисто виртуальная функция вывода информации на экран
    virtual void calculateGPA(int *) = 0;    //функция расчета среднего балла
    
    protected:
    char *name;
    char *surname;
    char *uni;
    int group;
    bool scholarship;
    int *exams;
    double GPA;
};

class Master : virtual public Student    //одна копия параметров Student наследуется
{
    public:
    Master(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks, const char *new_field, const char *new_thesis);
    ~Master();
    void show();
    void calculateGPA(int *);
    
    protected:
    char *field;
    char *thesis;
};

class Postgraduate : public Master
{
    public:
    Postgraduate(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks, const char *new_field, const char *new_thesis, int new_counter);
    ~Postgraduate();
    void show();
    void calculateGPA(int *);
    
    protected:
    int counter_articles;
};

class Alumni : virtual public Student
{
    public:
    Alumni(const char *new_name, const char *new_surname, const char *new_uni, int new_group, bool state, int *marks, bool new_alloc, bool red);
    ~Alumni();
    void show();
    void calculateGPA(int *);
    
    protected:
    bool allocation;
    bool red_diploma;
};

#endif    //если определено
