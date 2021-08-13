#include <iostream>
#include <cmath>
#include <cassert>
#include <stdlib.h>
#include "fraction.hpp"



//Ex 10.1

    Fraction::Fraction(){
        num=0;
        den=1;
    }

    Fraction::Fraction(int p, int q){
        
        assert(q!=0);
        if (q>0){
            num=p;
            den=q;
        } else {
            num=-p;
            den=-q;
        }
    
    }

    Fraction::~Fraction(){

        //cout<<endl<<"Fraction Destructor"<<endl;

    }

    int Fraction::getNum() const{
        return num;
    }

    int Fraction::getDen() const{
        return den;
    } 

    Fraction::Fraction(const Fraction &f){
        num=f.getNum();
        den=f.getDen();

    }  

    Fraction& Fraction::operator=(const Fraction &f){
        num=f.getNum();
        den=f.getDen();
    }

//Ex 10.2

    void Fraction::reduce(){
        
        int a;
    
        a=commonDiv();
            
        den=den/a;
        num=num/a;
    }

    int Fraction::commonDiv(){
        int i,result;
        for(i=1; i <= fabs(num) && i <= den; i++){
            if(int(abs(num))%i==0 && den%i==0) {
                result = i;
            }
        }

        return result;
    }


//Ex 10.3

    Fraction::Fraction(double t){
            int k;

            if (t<0){
                k=1000000000;
            }else if(t>=0&&t<10){
                k=100000000;
            }else if(t>=10&&t<100){
                k=10000000;
            }else if(t>=100&&t<1000){
                k=1000000;
            }else if(t>=1000&&t<10000){
                k=100000;
            }else if(t>=10000&&t<100000){
                k=10000;
            }else if(t>=100000&&t<1000000){
                k=1000;
            }else if(t>=1000000&&t<10000000){
                k=100;
            }else if(t>=10000000&&t<100000000){
                k=100;
            }else if(t>=100000000&&t<1000000000){
                k=10;
            } else {k=1;}
            
            double a=t*k;
            int b=(int)a;
            num=b;
            den=k;
            reduce();
        
        }

    

//Ex 10.4

    const Fraction operator-(const Fraction& x,const Fraction& y) {
        
        int a=x.getNum()*y.getDen()-y.getNum()*x.getDen();
        int b=x.getDen()*y.getDen();
        
        Fraction z(a,b);
        z.reduce();
        return z;        
    }

    const Fraction operator*(const Fraction& x,const Fraction& y) {
        
        int a=x.getNum()*y.getNum();
        int b=x.getDen()*y.getDen();
        
        Fraction z(a,b);
        z.reduce();
        return z;        
    }

    const Fraction operator/(const Fraction& x,const Fraction& y) {

        assert(x.getDen()!=0 && y.getDen()!=0);
        
        int a=x.getNum()*y.getDen();
        int b=x.getDen()*y.getNum();
        
        Fraction z(a,b);
        z.reduce();
        return z;        
    }

    const Fraction operator+(const Fraction& x,const Fraction& y) {
        
        
        int a=x.getNum()*y.getDen()+y.getNum()*x.getDen();
        int b=x.getDen()*y.getDen();
        Fraction z(a,b);
        z.reduce();
        return z;        
    }

//Ex 10.5
    //<< Output operator

        ostream& operator<<(ostream& out,const Fraction& f) {

            out<<f.getNum()<<" / "<<f.getDen()<<endl;
            
            return out;

        }

    //Overload - operator
        const Fraction Fraction::operator-() const{
            return Fraction(-num,den);
        }

//Ex 10.6



    bool operator==(const Fraction &x, const Fraction &y){
        
        int a=x.getNum()*y.getDen();
        int b=y.getNum()*x.getDen();

        if (a==b){return 1;}
        else {return 0;}

    }

    bool operator!=(const Fraction &x, const Fraction &y){
        
        if(x==y){return 0;}
        else {return 1;}

    }

    bool operator>(const Fraction &x, const Fraction &y){
        
        int a=x.getNum()*y.getDen();
        int b=y.getNum()*x.getDen();

        if (a>b){return 1;}
        else {return 0;}

    }

    bool operator<(const Fraction &x, const Fraction &y){
        
        if(x>y){return 0;}
        else {return 1;}

    }

    bool operator<=(const Fraction &x, const Fraction &y){
        
        if(x<y||x==y){return 1;}
        else {return 0;}

    }

    bool operator>=(const Fraction &x, const Fraction &y){
        
        if(x>y||x==y){return 1;}
        else {return 0;}

    }

//Ex 10.7

    VectorFraction::VectorFraction(int Degree){

                assert(Degree>=0);
                n=Degree;

                vector=new Fraction [n];
                

                for (int j=0; j<(Degree+1); ++j) {vector[j] = Fraction();}
            
    }

    VectorFraction::~VectorFraction(){

        delete[] vector;
        //cout<<"FracvtionVector Destructor"<<endl;
    }


    const Fraction& VectorFraction::operator[](int j) const{
            assert(j>-1 && j<=n);
            return vector[j];
        };

    Fraction& VectorFraction::operator [](int j){
            assert(j>-1 && j<=n);
            return vector[j];

    };

    void VectorFraction::setElement(int i,int nu,int de){
        Fraction z(nu,de);
        vector[i]=z;
    }



    Fraction VectorFraction::getElement(int i){
        
        return vector[i];
    }

    

    int VectorFraction::getSize(){
        
        return n;
    }
    
    

       VectorFraction::VectorFraction(VectorFraction &f){
        n=f.getSize();
        
        vector= new Fraction[n];
        for (int i=0;i<n;i++){
            setElement(i,f[i].getNum(),f[i].getDen());
        }
        

    }  

    VectorFraction& VectorFraction::operator=(VectorFraction &f){
        n=f.getSize();
        
        vector= new Fraction[n];
        for (int i=0;i<n;i++){
            setElement(i,f[i].getNum(),f[i].getDen());
        }
        return *this;
    }


    void VectorFraction::sort(){

        

        for (int a=0;a<getSize();a=a+1){
        for (int b=a+1;b<getSize();b=b+1){
            Fraction aux_1=getElement(a);
            Fraction aux_2=getElement(b);
            
            if (aux_2<aux_1){// 
                setElement(a,aux_2.getNum(),aux_2.getDen());
                setElement(b,aux_1.getNum(),aux_1.getDen());
            }
        }

    }}