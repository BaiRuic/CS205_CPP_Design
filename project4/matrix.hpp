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
        T operator()(size_t i, size_t j) const;
        bool operator == (const Matrix & other) const;
        Matrix<T> operator^(int expo);

        static Matrix<T> createDiagonal(size_t nrows, T fillVal);
        static Matrix<T> readMat(const char*filename);
        
        void info()const;
        /*
        static void printMat(const char * filename);
        static void Mat2Str();

        Matrix<T> submatrix_ROI(size_t row_start, size_t row_end, size_t col_start, size_t col_end);
        Matrix<T> submatrix_cpy(size_t row_start, size_t row_end, size_t col_start, size_t col_end);

        void adjust_ROI(size_t row_start, size_t row_end, size_t col_start, size_t col_end);
        */
};


size_t getFileRowsCols(const char *fileName, size_t & rows, size_t & cols);




template<typename T>
size_t Matrix<T>::getRows() const{
    return this->nRows;
}


template<typename T>
size_t Matrix<T>::getCols() const{
    return this->nCols;
}


template<typename T>
size_t * Matrix<T>::shape() const{
    return new size_t[2]{nRows, nCols};
}


template<typename T>
void Matrix<T>::print_shape()const{
    size_t * s = shape();
    std::cout<<"("<<s[0]<<", "<<s[1]<<")";
}


template<typename T>
bool Matrix<T>::shape_equals(const Matrix & other)const{
    size_t *tsp = this->shape();
    size_t *osp = other.shape();
    if (tsp[0]!=osp[0] || tsp[1] != osp[1])
        return false;
    return true;
}


template<typename T>
Matrix<T>::Matrix(size_t r, size_t c, T flilVal):nRows(r), nCols(c){
    data = new T [nRows * nCols];
    refCount = new size_t{1}; 
    parent_matrix = nullptr;
    fill(data, data+nRows*nCols, flilVal);
}


template<typename T>
Matrix<T>::Matrix(const Matrix<T> & other){
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
    if (*(this->refCount) == 0 && this->data != nullptr){
        if (this->parent_matrix == nullptr) 
            delete[] this->data;
        else
            delete this->parent_matrix->data;

        delete this->refCount;
    }
}


template<typename T>
Matrix<T> operator+(const Matrix<T> &left, const Matrix<T> &right){
    if (! left.shape_equals(right)){
        std::cerr<<"Addition error: matrix dimension cannot match." << endl;
        exit(EXIT_FAILURE);
    }

    Matrix<T> res(left.nRows, left.nCols);
    for(size_t i=0; i<left.nRows * left.nCols; i++)
        res.data[i] = left.data[i] + right.data[i];

    return res;    
}


template<typename T>
Matrix<T> operator-(const Matrix<T> & left, const Matrix<T> &right){
    if (! left.shape_equals(right)){
        std::cerr<<"Addition error: matrix dimension cannot match." << endl;
        exit(EXIT_FAILURE);
    }

    Matrix<T> res(left.nRows, left.nCols);
    for(size_t i=0; i<left.nRows * left.nCols; i++)
        res.data[i] = left.data[i] - right.data[i];
        
    return res;    
}


template<typename T>
Matrix<T> multiply_elements(const Matrix<T> & left, const Matrix<T> & right){
    if (! left.shape_equals(right)){
            std::cerr<<"Addition error: matrix dimension cannot match." << endl;
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


template<typename T>
T* Matrix<T>::operator[](size_t i){
    if (i >= this->nRows * this->nCols || i < 0){
        std::cerr<<"Index Error: the index "<<i<<" out of the range";
        exit(EXIT_FAILURE);
    }
    if(this->parent_matrix != nullptr)
        return this->data + i * this->parent_matrix->nCols;

    return this->data + i * this->nCols;
}


template<typename T>
T Matrix<T>::operator()(size_t i, size_t j) const{
    if (i < 0 || i >= this->nRows || j < 0 || j>=this->nCols){
        cerr<<"Index error";
        exit(EXIT_FAILURE);
    }

    if(this->parent_matrix != nullptr)
        return this->parent_matrix->data[i * this->parent_matrix->nCols + j];

    return this->data[i * this->nCols + j];
}


template<typename T>
bool Matrix<T>::operator == (const Matrix & other) const{
    if (this == &other)
        return true;

    if (this->nRows != other.nRows || this->nCols != other.nCols)
        return false;

    if (this->data == other.data)
        return true;
    
    size_t length = this->nRows * this->nCols;
    for(size_t i=0; i<length; i++){
        if (this->data[i] != other.data[i])
            return false;
    }
    return true;
}

template<typename U>
Matrix<U> matrixMaultiply(const Matrix<U> & left, const Matrix<U> & right){
    if (left.nCols != right.nRows){
        cerr<<"Multiplication error: the shape is not match";
        exit(EXIT_FAILURE);
    }

    
    Matrix<U> res(left.nRows, right.nCols);
    for(size_t i=0; i<res.nRows; i++)
        for (size_t j=0; j<res.nCols; j++)
            for(size_t k=0; k<left.nCols; k++){
                res[i][j] += left(i, k) + right(k, j);
            }

    return res;
}


template<typename T>
Matrix<T> operator *(const Matrix<T> & left, const Matrix<T> &right){
    return matrixMaultiply(left, right);
}


template<typename T>
Matrix<T> & Matrix<T>::operator *= (const Matrix<T> & other){
    *this = (*this * other);
    return *this;
}


template<typename T>
Matrix<T> Matrix<T>::operator^(int expo){
    if (this->nRows != this->nCols) {
        std::cout << "Power error: matrix is not square." << endl;
        exit(EXIT_FAILURE);
    }

    Matrix res = this->copy();
    Matrix temp = this->copy();
    expo -= 1;
    while (expo){
        if (expo & 1)
            res *= temp;
        temp *= temp;
        expo >>= 1;
    }

    return res;
}

template<typename T>
Matrix<T> Matrix<T>::createDiagonal(size_t nrows, T fillVal){
    if (nrows < 1) {
        std::cout << "Diagonal matrix error: rows is less than 1" << endl;
    }

    Matrix<T> res(nrows, nrows, 0);

    for (size_t i=0; i<nrows; i++)
        res[i][i] = 1;
    
    return res;
}


template<typename T>
void Matrix<T>::info()const{
    std::cout<<"Shape: ";
    this->print_shape();
    std::cout<<endl;
    std::cout<<"refCount: "<<*this->refCount<<endl;
    std::cout<<"ParentMatrix: "<<this->parent_matrix<<endl;
}

template<typename T>
Matrix<T> Matrix<T>::readMat(const char*fileName){
    
    //以文本模式打开in.txt备读
    ifstream srcF(fileName, ios::in); 
    if (!srcF){
        cerr<<"File Error:can not open "<<fileName<<endl;
        exit(EXIT_FAILURE);
    }

    // 计算文件的行和列
    size_t temp_rows = 0;
    size_t temp_cols = 0;

    if (!getFileRowsCols(fileName, temp_rows, temp_cols)){
        std::cerr << "File Error:can not open " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    Matrix<T> res(temp_rows, temp_cols);

    ifstream fileStream;
    fileStream.open(fileName, ios::in); // ios::in 表示以只读的方式读取文件
    for (int i = 0; i < res.nCols * res.nRows; i++) {
        fileStream >> res.data[i];
    }
    
    return res;
}


size_t getFileRowsCols(const char *fileName, size_t & rows, size_t & cols){
    std::ifstream fileStream;
                
    fileStream.open(fileName, ios::in); // ios::in 表示以只读的方式读取文件
    if (fileStream.fail()){
        return false;
    }
    // 计算行
    std::string tmp;  
    while (getline(fileStream, tmp, '\n')){
        if (tmp.size() > 0)
            rows++;
    }
    
    fileStream.clear();
    fileStream.seekg(0, ios::beg);
    // 计算列
	char c = fileStream.peek();
	while ((c != '\n') && (! fileStream.eof())){  
        fileStream >> tmp;  
        cols++;  
		c = fileStream.peek();
    }  

    fileStream.close();
    return true;
}

#endif