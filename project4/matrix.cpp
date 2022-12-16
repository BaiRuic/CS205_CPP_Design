#include"matrix.hpp"
#include<iostream>
using namespace std;


template<typename T>
size_t Matrix<T>::getRows() const{
    return this->nRows;
}


template<typename T>
size_t Matrix<T>::getCols() const{
    return this->nCols;
}


template<typename T>
int * Matrix<T>::shape() const{
    return new int[2]{nRows, nCols};
}


template<typename T>
void Matrix<T>::print_shape()const{
    int * s = shape();
    cout<<"("<<s[0]<<", "<<s[1]<<")";
}


template<typename T>
bool Matrix<T>::shape_equals(const Matrix & other)const{
    int *tsp = this->shape();
    int *osp = other.shape();
    if (tsp[0]!=osp[0] || tsp[1] != osp[1])
        return false;
    return true;
}


template<typename T>
Matrix<T>::Matrix(size_t r, size_t c, T flilVal):nRows(r), nCols(c){
    data = new T [nRows * nCols];
    refCount = new int{1};
    parent_matrix = nullptr;
    fill(data, data+nRows*nCols, flilVal);
}


template<typename T>
Matrix<T>::Matrix(const Matrix & other){
    this->nRows = other.nRows;
    this->nCols = other.nCols;

    this->refCount = other.refCount;
    *(this->refCount) += 1;

    this->data = other.data;
    this->parent_matrix = other.parent_matrix;
}


template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other){
    if (this == &other)
        return *this;
    
    this->nRows = other.nRows;
    this->nCols = other.nCols;
    this->parent_matrix = other.parent_matrix;

    *(this->refCount) -= 1;
    if (*(this->refCount) == 0 && this->data != nullptr){
        delete [] this->data;
        delete this->refCount;
    }

    this->data = other.data;
    this->refCount = other.refCount;
    *(this->refCount) += 1;
    
    return *this;
}


template<typename T>
Matrix<T>::~Matrix(){
    *(this->refCount) -= 1;
    if (*(this->reafCount) == 0 || this->data != nullptr){
        if (this->parent_matrix == nullptr) 
            delete[] this->data;
        else
            delete this->parent_matrix->data;

        delete this->refCount;
    }
}

template<typename T>
Matrix<T> operator+(Matrix<T> left, Matrix<T> right){
    if (! left.shape_equals(right)){
        cerr<<"Addition error: matrix dimension cannot match." << endl;
        exit(EXIT_FAILURE);
    }

    Matrix<T> res(left.nRows, left.nCols);
    for(size_t i=0; i<left.nRows * left.nCols; i++)
        res.data[i] = left.data[i] + right.data[i];

    return res;    
}


template<typename T>
Matrix<T> operator-(Matrix<T> left, Matrix<T> right){
    if (! left.shape_equals(right)){
        cerr<<"Addition error: matrix dimension cannot match." << endl;
        exit(EXIT_FAILURE);
    }

    Matrix<T> res(left.nRows, left.nCols);
    for(size_t i=0; i<left.nRows * left.nCols; i++)
        res.data[i] = left.data[i] - right.data[i];
        
    return res;    
}


template<typename T>
Matrix<T> multiply_elements(Matrix<T> left, Matrix<T> right){
    if (! left.shape_equals(right)){
            cerr<<"Addition error: matrix dimension cannot match." << endl;
            exit(EXIT_FAILURE);
        }

        Matrix<T> res(left.nRows, left.nCols);
        for(size_t i=0; i<left.nRows * left.nCols; i++)
            res.data[i] = left.data[i] * right.data[i];
            
        return res;    
}


template<typename T>
Matrix<T> Matrix<T>::copy() const{
    Matrix<T> res(this->nRows, this->nCols);
    for(size_t i=0; i< this->nRows * this->nCols; i++)
        res.data[i] = this->data[i];
    
    return res;
}

