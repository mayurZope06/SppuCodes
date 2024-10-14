// Implement a class Complex which represents the Complex Number data type. 
// Implement the following 
// 1. Constructor (including a default constructor which creates the complex number 0+0i). 
// 2. Overload operator+ to add two complex numbers. 
// 3. Overload operator* to multiply two complex numbers. 
// 4. Overload operators << and >> to print and read Complex Numbers.

// Complex number
#include <iostream>
using namespace std;
class Complex
{
public:
    int real, imag;
    // constructor
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    // friend functions of complex class
    friend ostream &operator<<(ostream &out, Complex  &obj);
    friend istream &operator>>(istream &in, Complex &obj);
    // overloading of + operator
    Complex operator+(Complex  &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    // overloading of * operator
    Complex operator*(Complex  &obj)
    {
        Complex res;
        res.real = ((real) * (obj.real)) - ((imag) * (obj.imag));
        res.imag = ((real) * (obj.imag)) + ((obj.real) * (imag));
        return res;
    }
};

ostream &operator<<(ostream &cout, Complex  &obj)
{
    cout << obj.real;
    cout << "+i" << obj.imag;
    return cout;
}
istream &operator>>(istream &in, Complex &obj)
{
    cout << "\n Enter Real Part: " << endl;
    in >> obj.real;
    cout << "\n Enter Imaginary Part: " << endl;
    in >> obj.imag;
    return in;
}
int main()
{
    Complex c1, c2, c3, c4;
    cout << "\n-----Enter First Number-----";
    cin >> c1;
    cout << "\n-----Enter Second Number-----";
    cin >> c2;
    // Addition
    c3 = c1 + c2;
    cout << "\n The Addition of Complex Number is : " << c3;
    // Multiplication
    c4 = c1 * c2;
    cout << "\n The Multiplication of Complex Number is :" << c4 << endl;
    return 0;
}