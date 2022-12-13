#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include<iostream>

// 使用 引用计数器指针和数据指针实现 共享数据成员 


class Matrix{
    public:
    int nrows;
    int ncols;
    float *data;
    int *refcount;

    public:
    Matrix(int nrows=1, int ncols=1, float fill=0): nrows(nrows), ncols(ncols) {
        this->data = new float[nrows * ncols];
        this ->refcount = new int(1);
        for (int i =0; i<nrows*ncols; i++){
            this->data[i] = fill;
        }
    }
    
    Matrix(const Matrix & m){
        this->ncols = m.ncols;
        this->nrows = m.nrows;
        this->refcount = m.refcount;
        *(this->refcount) += 1;
        this->data = m.data;
    }

    Matrix operator =(const Matrix & m){
        if (this == &m)
            return *this;
        this->ncols = m.ncols;
        this->nrows = m.nrows;
        
        *(this->refcount) -= 1;
        if (*(this->data) == 0)
            delete this->data;

        this->refcount = m.refcount;
        *(this->refcount) += 1;
        this ->data = m.data;

        return *this;
    }

    ~Matrix(){
        *(this->refcount) -= 1;
        if (*(this->refcount) == 0){
            delete [] this->data;
            delete this->refcount;
        }
    }

    float* operator[](int i){
        return this->data + i * this->ncols;
    }

    friend
    Matrix operator+(const Matrix & m, float f){
        Matrix res(m.nrows, m.ncols, 0);

        for (int i=0; i<res.nrows; i++)
            for (int j=0; j<res.ncols;j++)
                res.data[i*m.ncols+j] = m.data[i*m.ncols+j] + f;
        return res;
    }

    friend
    Matrix operator+(const Matrix & m, const Matrix & o){
        Matrix res(m.nrows, m.ncols, 0);

        for (int i=0; i<res.nrows; i++)
            for (int j=0; j<res.ncols;j++)
                res.data[i*m.ncols+j] = m.data[i*m.ncols+j] + o.data[i*m.ncols+j];
        return res;
    }

    friend
    Matrix operator*(const Matrix & m, float f){
        Matrix res(m.nrows, m.ncols, 0);

        for (int i=0; i<res.nrows; i++)
            for (int j=0; j<res.ncols;j++)
                res.data[i*m.ncols+j] = m.data[i*m.ncols+j] * f;
        return res;
    }


    friend
    std::ostream & operator<<(std::ostream & os, const Matrix & m){
        os<<"Info:"<<m.nrows<<" rows, "<<m.ncols<<" cols, "<<*m.refcount<<" refcount, loc: "<<m.data<<std::endl;
        
        for(int i=0; i<m.nrows; i++){
            for(int j=0; j<m.ncols; j++){
                os<<m.data[i*m.ncols+j]<<" ";
            }
            os<<std::endl;
        }

        return os;
    }
    
};

#endif