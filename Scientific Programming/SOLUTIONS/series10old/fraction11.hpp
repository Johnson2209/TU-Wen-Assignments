using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::abs;

class Fraction{

    private:

        int num;
        int den;

    public:

       
        Fraction(); 
        Fraction(int,int);  
        ~Fraction();  
        Fraction(const Fraction &f);    
        Fraction& operator=(const Fraction &f);
        int getNum() const;
        int getDen() const; 
        void setNum(int);
        void setDen(int);
        void reduce();
        int commonDiv();
        operator double(){return (double)num/den;}        
        Fraction(double);            
        const Fraction operator-() const;     
        friend bool operator==(const Fraction &x, const Fraction &y);
        friend bool operator!=(const Fraction &x, const Fraction &y);
        friend bool operator>(const Fraction &x, const Fraction &y);
        friend bool operator<(const Fraction &x, const Fraction &y);
        friend bool operator>=(const Fraction &x, const Fraction &y);
        friend bool operator<=(const Fraction &x, const Fraction &y);
};

class VectorFraction{

    private:
        
        int n;
        Fraction* vector;
    
    public:

        VectorFraction(int);
        ~VectorFraction();
        const Fraction& operator [](int j) const;
        Fraction &operator [](int j);
        void setElement(int,int,int);
        Fraction getElement(int);        
        VectorFraction& operator=(VectorFraction &t);
        VectorFraction(VectorFraction &t);
        int getSize();
        void sort();
};

   
