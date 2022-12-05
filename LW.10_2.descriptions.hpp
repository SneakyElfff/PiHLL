//
//  descriptions.hpp
//  LW.10
//
//  Created by Нина Альхимович on 3.12.22.
//

#ifndef descriptions_hpp
#define descriptions_hpp

#include <stdio.h>

using namespace std;

template<class T>
class Node
{
public:
    T element;
    Node<T> *next;
    
    Node();    //конструктор без параметров
    Node(T new_element);    //конструктор с параметрами
//    Node(const Node &new_Node);    //конструктор копирования
    ~Node();
};

template<class T>
Node<T>::Node()
{
    cout << endl << "Сработал конструктор по умолчанию" << endl;
}

template<class T>
Node<T>::Node(T new_element)
{
    element = new_element;
    next = NULL;
}

template<class T>
Node<T>::~Node()
{
    cout << endl << "Сработал деструктор" << endl;
}

template<class T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
    
public:
    Queue();    //конструктор по умолчанию
    ~Queue();    //деструктор
    
    T getValue();
    Node<T> *getNext();
    void set(T value, T *ptr);
    
    void Add(T value);    //добавить элемент в очередь (с повторениями)
    void AddUnique(T value);    //добавить элемент в очередь (без повторений)
    void Delete();    //удалить элемент с головы очереди
    int Search(T query, bool flag = true);    //найти элемент в очереди
    void Show();    //вывести очередь на экран
};

template<class T>
Queue<T>::Queue()    //конструктор по умолчанию
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
Queue<T>::~Queue()    //деструктор
{
}

template<class T>
void Queue<T>::Add(T value)
{
    try
    {
        Node<T> *temp = new Node<T>(value);
        if(temp == NULL)
            throw bad_alloc();
        
        if(tail == NULL)    //если очередь пуста
        {
            head = temp;
            tail = temp;
        }
        
        else
        {
            tail->next = temp;    //добавляется элемент в конец очереди
            tail = tail->next;
        }
        
        size++;
    }
    
    catch(bad_alloc)
    {
        cout << "Ошибка выделения памяти." << endl;
    }
}

template<class T>
void Queue<T>::AddUnique(T value)
{
    try
    {
        Node<T> *temp = new Node<T>(value);
        if(temp == NULL)
            throw bad_alloc();
        
        if(tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        
        else if(Search(value, false) == 0)    //если очередь не пуста, перед добавлением элемент проверяется,                                     уникальный ли он
        {
            tail->next = temp;
            tail = tail->next;
        }
        
        else cout << endl << "Элемент " << value << " уже находится в очереди." << endl << endl;
        
        size++;
    }
    catch(bad_alloc)
    {
        cout << "Ошибка выделения памяти." << endl;
    }
}

template<class T>
void Queue<T>::Delete()
{
    try
    {
        if(head == NULL)    //если удалять нечего
            throw "empty";
        
        Node<T> *temp = head;    //запоминается "голова очереди"
        
        head = head->next;    //первым в очереди становится следующий элемент
        delete temp;
        
        size--;    //уменьшается счетчик элементов очереди
        
        if(size == 0)
        {
            head = NULL;
            tail = NULL;
        }
    }
    catch(char const *)
    {
        cout << "Ошибка. Очередь пуста." << endl;
    }
}

template<class T>
int Queue<T>::Search(T query, bool flag)
{
    try
    {
        int ind = 0;
        bool found = false;
        
        if(head == NULL)
            throw "empty";
        
        Node<T> *temp = head;
        while(temp)    //пока очередь не кончилась
        {
            ind++;    //номер элемента в очереди
            if(temp->element == query)    //если искомый элемент найден
            {
                found = true;    //поднимается флаг
                break;
            }
            temp = temp->next;    //если нет, переход к следующему элементу
        }
        
        if(!found)
            ind = 0;    //обнуление номера, если элемент не найден
        
        if(flag)    //если true (функция вызвана пользователем), выводится уточняющая информация
        {
            if(found) cout << endl << "Элемент найден на " << ind << "-ом месте в очереди." << endl;
            else cout << "Элемент не найден" << endl;
        }
        
        return ind;
    }
    
    catch(const char *)
    {
        cout << "Ошибка. Очередь пуста." << endl;
        exit(-1);
    }
}

template<class T>
void Queue<T>::Show()
{
    try
    {
        if(head == NULL)
            throw "empty";
        
        cout << endl << "Очередь: " << endl;
        
        Node<T> *temp = head;
        while(temp)
        {
            cout << temp->element << endl;
            temp = temp->next;
        }
    }
    
    catch(string)
    {
        cout << "Ошибка. Очередь пуста." << endl;
    }
}

#endif /* descriptions_hpp */
