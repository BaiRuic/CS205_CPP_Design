#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__
#include<iostream>

template<typename T=float>
class Matrix{
    private:
        size_t nCols;
        size_t nRows;
        T* data;
    public:
        Matrix(size_t r=1, size_t c=1, T fill=0) :nCols(c), nRows(r){
            data = new T[nCols * nRows];
            for(int i=0; i<nCols*nRows;i++)
                data[i] = fill;
        }

        Matrix(const Matrix<T> &other){
            this->nCols = other.nCols;
            this->nRows = other.nRows;
            this->data = new T[nCols * nRows];
            for(int i=0; i<nCols*nRows;i++)
                data[i] = other.data[i];
        }

        Matrix<T> & operator=(const Matrix<T> & other){
            if (this == &other)
                return *this;
            
            if (this->nCols * this->nRows != other.nCols * other.nRows){
                delete [] this->data;
                this->data = new T[other.nCols * other.nRows];
            }
            
            this->nCols = other.nCols;
            this->nRows = other.nRows;

            for(int i=0; i<nCols*nRows; i++)
                data[i] = other.data[i];

            return *this;
        }

        T& operator()(size_t i, size_t j) {
            if (i >= this->nRows || j >= this->nCols) {
                std::cerr << "Index error: array index out of bound." << std::endl;
                exit(EXIT_FAILURE);
            }
            return this->data[i*this->nCols + j];
        }

        friend 
        std::ostream & operator <<(std::ostream & os, const Matrix<T> & m){
            for(size_t i= 0; i<m.nCols * m.nRows; i++){
                os<<m.data[i]<<" ";
                if ((i+1) % m.nCols == 0 && (i+1)/m.nCols < (m.nRows))
                    os<<std::endl;
            }
            return os;
        }

        friend
        Matrix<T> operator+(const Matrix<T> & a, const Matrix<T> & b){
            if (a.nCols != b.nCols || a.nRows != b.nRows){
                std::cerr << "The shape of matrix error: (" 
                          << a.nRows<<','<<a.nCols<<") and ("
                          <<b.nRows<<','<<b.nCols<<')'
                          <<std::endl;
                exit(EXIT_FAILURE);
            }
            
            Matrix<T> res(a.nRows, a.nCols, 0);
            for (size_t i=0; i<res.nRows * res.nCols; i++)
                res.data[i] = a.data[i] + b.data[i];

            return res;
        }

        

};


#endif