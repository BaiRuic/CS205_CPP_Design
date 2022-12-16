#pragma once
#include<iostream>

template<typename T>
class Matrix{
    private:
        size_t nRows;
        size_t nCols;
        size_t * refCount;
        T * data;
        const Matrix<T>* parent_matrix;

    public:
        size_t getRows() const;
        size_t getCols() const;
        int* shape() const;

        void print_shape() const;
        bool shape_equals(const Matrix<T> & other) const;
        Matrix(size_t nrows=1, size_t ncols=1, T fillVal=0);
        Matrix(const Matrix<T> &other);
        Matrix<T>& operator =(const Matrix<T> &other);
        ~Matrix();

        friend Matrix<T> operator+(Matrix<T> left, Matrix<T> right);
        friend Matrix<T> operator-(Matrix<T> left, Matrix<T> right);

        friend Matrix<T> multiply_elements(Matrix<T> left, Matrix<T> right);

        Matrix<T> copy() const;
        
        T* operator[](size_t i);
        T& operator()(size_t i, size_t j);
        bool operator == (const Matrix & other) const;
        Matrix<T> operator^(int expo);

        static Matrix<T> createDiagonal(size_t nrows, T fillVal);
        static Matrix<T> readMat(const std::string*filename);
        
        static void printMat(const std::string * filename);
        static void Mat2Str();

        Matrix<T> submatrix_ROI(size_t row_start, size_t row_end, size_t col_start, size_t col_end);
        Matrix<T> submatrix_cpy(size_t row_start, size_t row_end, size_t col_start, size_t col_end);

        void adjust_ROI(size_t row_start, size_t row_end, size_t col_start, size_t col_end);
    
};