//
//  descriptions.hpp
//  LW.8
//
//  Created by Нина Альхимович on 20.11.22.
//

#ifndef descriptions_hpp
#define descriptions_hpp

#include <stdio.h>
#include <string>

using namespace std;

template<class T>
class Matrix
{
private:
    T **array;
    int rows;
    int cols;
    
public:
    Matrix();
    Matrix(int new_rows, int new_cols);
    Matrix(const Matrix &new_Matrix);    //конструктор копирования
    ~Matrix();
    
    T getRow();
    T getCol();
    void set(int i, int j, T value);
    
    void addRow(int ind, T *new_row);
    void addCol(int ind, T *new_col);
    void delRow(int ind);
    void delCol(int ind);
    void search(const T &elem);
    void show();
    
    Matrix<T> operator = (const Matrix<T> &);
    bool operator == (const Matrix<T>);
};


class MatrixExceptions
{
protected:
    string error = "Error. Matrix Exception.";
    
public:
    virtual string what() = 0;
};

class wrongSize : public MatrixExceptions
{
public:
    string what()
    {
        return "Ошибка. Матрицы с такими размерами не существует.";
    }
};

class badAllocation : public MatrixExceptions
{
public:
    string what()
    {
        return "Ошибка выделения памяти.";
    }
};

class wrongParameters : public MatrixExceptions
{
public:
    string what()
    {
        return "Ошибка. Невозможно установить значение.";
    }
};


//конструкторы, деструктор
template<class T>
Matrix<T>::Matrix()
{
    rows = cols = 0;
    array = NULL;
    
    cout << "Сработал конструктор" << endl;
}

template<class T>
Matrix<T>::Matrix(int new_rows, int new_cols)
{
    if(rows < 0 || cols < 0)
        throw wrongSize();
    
    rows = new_rows;
    cols = new_cols;
    
    if((array = (T**) new T*[rows]) == NULL)
        throw bad_alloc();
    for(int i=0; i<rows; i++)
        if((array[i] = (T*) new T[cols]) == NULL)
            throw bad_alloc();
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = 0;
    
    cout << "Сработал конструктор инициализации" << endl;
}

template<class T>
Matrix<T>::Matrix(const Matrix &new_Matrix)
{
    if(rows < 0 || cols < 0)
        throw wrongSize();
    
    rows = new_Matrix.rows;
    cols = new_Matrix.cols;
    
    if((array = (T**) new T*[rows]) == NULL)
        throw bad_alloc();
    for(int i=0; i<rows; i++)
        if((array[i] = (T*) new T[cols]) == NULL)
            throw bad_alloc();
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = new_Matrix.array[i][j];
    
    cout << "Сработал конструктор копирования" << endl;
}

template<class T>
Matrix<T>::~Matrix()
{
    for(int i=0; i<rows; i++)
        delete[] array[i];
    
    delete[] array;
    
    cout << "Сработал деструктор" << endl;
}

template<class T>
T Matrix<T>::getRow()
{
    if(rows > 0 && cols > 0)
        return rows;
    else
        return 0;
}

template<class T>
T Matrix<T>::getCol()
{
    if(rows > 0 && cols > 0)
        return cols;
    else
        return 0;
}

template<class T>
void Matrix<T>::set(int i, int j, T value)
{
    if(i < 0 || i >= rows)
        throw wrongParameters();
    if(j < 0 || j >= cols)
        throw wrongParameters();
  
    array[i][j] = value;
}


//операторы
template<class T>
Matrix<T> Matrix<T>::operator = (const Matrix &new_Matrix)
{
    for(int i=0; i<rows; i++)
        delete[] array[i];
    
    delete[] array;
    
    rows = new_Matrix.rows;
    cols = new_Matrix.cols;
    
    if((array = (T**) new T*[rows]) == NULL)
        throw bad_alloc();
    for(int i=0; i<rows; i++)
        if((array[i] = (T*) new T[cols]) == NULL)
            throw bad_alloc();
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = new_Matrix.array[i][j];
    
    return *this;
}

template<class T>
bool Matrix<T>::operator == (const Matrix<T> comp)
{
    if(rows != comp.rows && cols != comp.cols)
        return false;
    else
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(array[i][j] != comp.array[i][j]) return false;
    return true;
}


//методы
template<class T>
void Matrix<T>::addRow(int ind, T *new_row)
{
    if(ind < 0 || ind > rows)
        throw wrongParameters();
    
    rows++;
    
    T **temp = array;
    
    if((array = (T**) new T*[rows]) == NULL)
        throw bad_alloc();
    for(int i=0; i<rows; i++)
        if((array[i] = (T*) new T[cols]) == NULL)
            throw bad_alloc();
    
    for(int i=0; i<ind; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = temp[i][j];
    
    for(int i=ind; i<ind+1; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = new_row[j];
    
    for(int i=ind+1; i<rows; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = temp[i-1][j];
    
    if(temp) delete[] temp;
}

template<class T>
void Matrix<T>::addCol(int ind, T *new_col)
{
    if(ind < 0 || ind > cols)
        throw wrongParameters();
    
    cols++;
    
    T **temp = array;
    
    if((array = (T**) new T*[rows]) == NULL)
        throw bad_alloc();
    for(int i=0; i<rows; i++)
        if((array[i] = (T*) new T[cols]) == NULL)
            throw bad_alloc();
    
    for(int j=0; j<ind; j++)
        for(int i=0; i<rows; i++)
            array[i][j] = temp[i][j];
    
    for(int j=ind; j<ind+1; j++)
        for(int i=0; i<rows; i++)
            array[i][j] = new_col[i];
    
    for(int j=ind+1; j<cols; j++)
        for(int i=0; i<rows; i++)
            array[i][j] = temp[i][j-1];
    
    if(temp) delete[] temp;
}

template<class T>
void Matrix<T>::delRow(int ind)
{
    if(ind < 0 || ind > rows)
        throw wrongParameters();
    
    rows--;
    
    T **temp = array;
    
    if((array = (T**) new T*[rows]) == NULL)
        throw bad_alloc();
    for(int i=0; i<rows; i++)
        if((array[i] = (T*) new T[cols]) == NULL)
            throw bad_alloc();
    
    for(int i=0; i<ind; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = temp[i][j];
    
    for(int i=ind; i<rows; i++)
        for(int j=0; j<cols; j++)
            array[i][j] = temp[i+1][j];
    
    if(temp) delete[] temp;
}

template<class T>
void Matrix<T>::delCol(int ind)
{
    if(ind < 0 || ind > cols)
        throw wrongParameters();
    
    cols--;
    
    T **temp = array;
    
    if((array = (T**) new T*[rows]) == NULL)
        throw bad_alloc();
    for(int i=0; i<rows; i++)
        if((array[i] = (T*) new T[cols]) == NULL)
            throw bad_alloc();
    
    for(int j=0; j<ind; j++)
        for(int i=0; i<rows; i++)
            array[i][j] = temp[i][j];
    
    for(int j=ind; j<cols; j++)
        for(int i=0; i<rows; i++)
            array[i][j] = temp[i][j+1];
    
    if(temp) delete[] temp;
}

template<class T>
void Matrix<T>::search(const T &elem)
{
    bool flag = false;
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            if(array[i][j] == elem)
            {
                cout << endl << "Элемент " << elem << " находится на пересечении " << i << "-ой строки и " << j << "-го столбца." << endl;
                flag = true;
            }
    
    if(!flag) cout << endl << "Заданный элемент не найден" << endl;
}

template<class T>
void Matrix<T>::show()
{
    cout << endl;
    
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            cout << array[i][j] << '\t';
        cout << endl;
    }
}

#endif /* descriptions_hpp */
