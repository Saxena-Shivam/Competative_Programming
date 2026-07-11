#include <iostream>
using namespace std;
class Complex
{
    int real;
    int img;
    int id = 0;
    static int cnt;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
        id = ++cnt;
        cout << "Created " << id << endl;
    }
    Complex add(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    // Complex operator+(Complex c)
    // {
    //     Complex temp;
    //     temp.real = real + c.real;
    //     temp.img = img + c.img;
    //     return temp;
    // }
    friend Complex operator+(Complex c1, Complex c2);

    int getreal()
    {
        return real;
    }
    void display()
    {
        cout << real << "+ i " << img << endl;
    }
    ~Complex()
    {
        cout << "Destroyed " << id << endl;
    }
};
int Complex::cnt = 0;
int main()
{
    Complex c1(3, 4);
    Complex c2(-2, 8);
    Complex c = operator+(c2, c1);
    Complex c4 = c2 + c;
    c.display();
    c4.display();
    return 0;
}
Complex operator+(Complex c1, Complex c2)
{
    Complex c;
    c.real = c1.real + c2.real;
    c.img = c1.img + c2.img;
    return c;
}