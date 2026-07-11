#include<bits/stdc++.h>
using namespace std;
class Base {
public:
    int x = 5;
};

class Derived : public Base {
public:
    void changeX() { x = 10; }
};


int main(){
    // Your code here
    Derived d;
d.changeX();
cout << d.x;  // Outputs 10
// Base b;
// cout<<b.x;
Base b;
Derived *q=&b;
    return 0;
}