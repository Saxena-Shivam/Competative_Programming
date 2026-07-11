#include<bits/stdc++.h>
using namespace std;

class rectangle{
    public:
    int l, b;
    int a;
    int *p = 0;

    int area() {
        return l * b;
    }

    int perimeter() {
        return 2 * (l + b);
    }

    // Default constructor
    rectangle() {
        l = 0;
        b = 0;
    }

    // Parameterized constructor
    rectangle(int x) {
        a = x;
        p = new int[a];
    }

    // Copy constructor (taking a const reference)
    rectangle(const rectangle &t) {
        l = t.l;
        b = t.b;
    }

    ~rectangle() {
        if (p != nullptr) {
            delete[] p;
        }
    }
};

int main() {
    rectangle r1;
    r1.b = 12;
    r1.l = 4;
    cout << r1.area() << endl;
    cout << r1.area() << endl;

    // Pointer to rectangle object
    rectangle *q;
    q = &r1;
    q->b = 12;
    q->l = 4;
    cout << q->area() << endl;
    cout << q->area() << endl;

    // Dynamically allocated rectangle
    rectangle *p = new rectangle();
    p->l = 6;
    p->b = 5;
    cout << p->area() << endl;
    cout << p->area() << endl;

    // Copy constructor
    rectangle r2(r1);
    cout << r2.area() << endl;
    rectangle *s=&r2;
    cout << s->area() << endl;

    delete p;
    return 0;
}
