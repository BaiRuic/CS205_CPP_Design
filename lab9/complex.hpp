#ifndef __Complex_HPP__
#define __Complex_HPP__

class Complex{
    private:
    float a;
    float b;
    
    public:
    Complex(float a=0.0f, float b=0.0f): a(a), b(b){}
    float getReal() const{
        return a;
    }
    float getImag() const{
        return b;
    }
    void setReal(float a){
        this->a = a;
    }
    void setImag(float b){
        this->b = b;
    }


    Complex add(const Complex & b);
    Complex subtract(const Complex & b);
    void display() const;
};


#endif 