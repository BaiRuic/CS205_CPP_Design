#ifndef _CStereoShape_H_
#define _CStereoShape_H_

#include<iostream>
#define PI 3.1415926

class CStereoShape{
    private:
        static int numberOfObject;

    public:
        CStereoShape(){
            numberOfObject += 1;
        }

        ~CStereoShape(){
            numberOfObject -= 1;
        }

        virtual float GetArea(){
            std::cout<<"CStereoShape::GetArea()"<<std::endl;
            return 0.0;
        }
        virtual float GetVolume(){
            std::cout<<"CStereoShape::GetVolume()"<<std::endl;
            return 0.0;
        }

        virtual void Show(){
            std::cout<<"CStereoShape::Show()"<<std::endl;
        }

        int GetNumOfObject(){
            return numberOfObject;
        }


};

int CStereoShape::numberOfObject = 0;

class CCube: public CStereoShape{
    private:
        float length;
        float width;
        float height;
    
    public:
        CCube(float l=1, float w=1, float h=1): length(l), width(w), height(h){}
        
        float GetArea(){
            return 2 * (length * width + length * height + width * height);
        }

        float GetVolume(){
            return length * width * height;
        }

        void Show(){
            std::cout<<"The ccube with length: "<< length<<", width: "<<width<<", heigth: "<<height
                <<", and the area and volume are "<< GetArea()<<", "<<GetVolume()<<", respectively."
                <<std::endl;
        }
};

class CSphere: public CStereoShape{
    private:
        float radius;
    public:
        CSphere(float r=1):radius(r){}

        float GetArea(){
            return 4 * PI * radius * radius;
        }

        float GetVolume(){
            return 4.0 / 3.0 * PI * radius * radius * radius;
        }

        void Show(){
            std::cout<<"The CSphere with radius: "<< radius
                <<", and the area and volume are "<< GetArea()<<", "<<GetVolume()<<", respectively."
                <<std::endl;
        }

        
};

#endif