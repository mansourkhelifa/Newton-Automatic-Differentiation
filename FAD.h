#ifndef FAD_H
#define FAD_H
#include <iostream>

using namespace std;

template <typename T>
class FAD
{
public:


//Constructor definition

    FAD()
    {
        val_=0;
        der_=0;
    }


    double getVal()
    {
        return val_;
    }

    double getDer()
    {
        return der_;
    }


    FAD(double val, double der):val_(val), der_(der)
    {

    }

    void operator*=(const FAD & A)
    {


        double a=A.der_*val_+der_*A.val_;
        der_=a;

        val_*=A.val_;

   }

    void operator+=(const FAD & A)
    {
        double a;
        a=A.der_+der_;
        der_=a;
        val_+=A.val_;
    }


    void operator=(const FAD & A)
    {
       val_=A.val_;
       der_=A.der_;
    }


    template <class Ostream>
    Ostream& print(Ostream& s) const
    {
       s<<"value: "<<val_<<"; derivative: "<<der_<<endl;

        return s;
    }



private:
//Value derivative
double val_;
//Value derivative
double der_;

};

 template <typename T>
 FAD<T> operator*( FAD<T> & A, FAD<T> &  B)
 {
     FAD<T> C;

     C=A;


     C*=B;


     return C;

 }

 template <typename T>
 FAD<T> operator+( FAD<T> & A, FAD<T> &  B)
 {
     FAD<T> C;

     C=A;


     C+=B;


     return C;
 }


 template <class Ostream, typename T>
 ostream & operator <<(Ostream& s, const FAD<T> & A)
 {
   return A.print(s);
 }



#endif // FAD_H
