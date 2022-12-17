#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include<iostream>
#include<fstream>


using std::cout;
using std::cerr;
using std::ios;
using std::fill;
using std::endl;
using std::ifstream;

template<typename T>
class Matrix{
    private:
        size_t nRows;
        size_t nCols;
        size_t * refCount;
        T * data;
        const Matrix<T>* parent_matrix;

    public:
        Matrix(size_t nrows=1, size_t ncols=1, T fillVal=0);
        Matrix(const Matrix<T> &other);
        Matrix<T>& operator =(const Matrix<T> &other);
        ~Matrix();
        
        size_t getRows() const;
        size_t getCols() const;
        size_t* shape() const;

        void print_shape() const;
        bool shape_equals(const Matrix<T> & other) const;
        
        Matrix<T> & operator *= (const Matrix<T> & other);
        
        template <typename U>
        friend Matrix<U> operator+(const Matrix<U> &left, const Matrix<U> &right);

        template <typename U>
        friend Matrix<U> operator-(const Matrix<U> &left, const Matrix<U> &right);
        
        template <typename U>
        friend Matrix<U> matrixMaultiply(const Matrix<U> &left, const Matrix<U> &right);

        template <typename U>
        friend Matrix<U> multiply_elements(const Matrix<U> &left, const Matrix<U> &right);

        template <typename U>
        friend Matrix<U> operator * (const Matrix<U> & left, const Matrix<U> &right);
        

        Matrix<T> copy() const;
        
        T* operator[](size_t i);
        T* operator[](size_t i) const;
        T operator()(size_t i, size_t j) const;
        bool operator == (const Matrix & other) const;
        Matrix<T> operator^(int expo);

        static Matrix<T> createDiagonal(size_t nrows, T fillVal);
        static Matrix<T> readMat(const char*filename);
        
        void info()const;
        void printMat() const;
        void printMat(const char * filename);
        
        Matrix<T> submatrix_ROI(size_t row_start, size_t row_end, size_t col_start, size_t col_end);
        Matrix<T> submatrix(size_t row_start, size_t row_end, size_t col_start, size_t col_end);
        Matrix<T> submatrix_cpy(size_t row_start, size_t row_end, size_t col_start, size_t col_end);

        void adjust_ROI(size_t row_start, size_t row_end, size_t col_start, size_t col_end);
        
};


size_t getFileRowsCols(const char *fileName, size_t & rows, size_t & cols);


#include"matrixIplt.hpp"
#endif