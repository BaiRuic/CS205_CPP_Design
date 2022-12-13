#ifndef _MATRIX_1_HPP_
#define _MATRIX_1_HPP_

#include<iostream>
#include<memory>
// 使用 share_ptr 实现共享数据成员 


class Matrix{
    public:
    int nrows;
    int ncols;
    std::shared_ptr<float[]> data;

    public:
    Matrix(int nrows=1, int ncols=1, float fill=0.0f): nrows(nrows), ncols(ncols) {
        data = std::make_shared<float[]>(nrows * ncols);
        std::cout<<"data_done"<<std::endl;
        for (int i =0; i<nrows*ncols; i++){
            data[i] = fill;
        }
        std::cout<<"matrix——done"<<std::endl;
    }
    
    Matrix(const Matrix & m){
        this->ncols = m.ncols;
        this->nrows = m.nrows;
        this->data = m.data;
    }

    Matrix operator =(const Matrix & m){
        if (this == &m)
            return *this;
        this->ncols = m.ncols;
        this->nrows = m.nrows;
        this ->data = m.data;

        return *this;
    }

    ~Matrix(){
    }

    float* operator[](int i){
        return this->data.get() + i * this->ncols;
    }

    friend
    Matrix operator+(const Matrix & m, float f){
        Matrix res(m.nrows, m.ncols, 0.0);

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
        os<<"Info:"<<m.nrows<<" rows, "<<m.ncols<<" cols, "<<m.data.use_count()<<" refcount, loc: "<<m.data.get()<<std::endl;
        
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