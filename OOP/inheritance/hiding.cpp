#include <iostream>
using namespace std;

class Base
{
public:
    int pub = 10;

protected:
    int pro = 20;

private:
    int pri = 30;
};

/* ========= PUBLIC INHERITANCE ========= */

class PublicDerived : public Base
{
public:
    void show()
    {
        cout << "Public Inheritance -> Derived access: ";
        cout << pub << " "; // public -> public
        cout << pro << " "; // protected -> protected
        // cout << pri;       // ❌ not accessible
        cout << endl;
    }
};

/* ========= PROTECTED INHERITANCE ========= */

class ProtectedDerived : protected Base
{
public:
    void show()
    {
        cout << "Protected Inheritance -> Derived access: ";
        cout << pub << " "; // public -> protected
        cout << pro << " "; // protected -> protected
        // cout << pri;       // ❌ not accessible
        cout << endl;
    }
};

/* ========= PRIVATE INHERITANCE ========= */

class PrivateDerived : private Base
{
public:
    void show()
    {
        cout << "Private Inheritance -> Derived access: ";
        cout << pub << " "; // public -> private
        cout << pro << " "; // protected -> private
        // cout << pri;       // ❌ not accessible
        cout << endl;
    }
};

int main()
{

    PublicDerived d1;
    d1.show();
    cout << "Object access (public inh): ";
    cout << d1.pub << endl; // ✅ accessible
    // cout << d1.pro;           // ❌ not accessible

    cout << endl;

    ProtectedDerived d2;
    d2.show();
    cout << "Object access (protected inh): ";
    // cout << d2.pub;           // ❌ not accessible
    cout << "Not allowed" << endl;

    cout << endl;

    PrivateDerived d3;
    d3.show();
    cout << "Object access (private inh): ";
    // cout << d3.pub;           // ❌ not accessible
    cout << "Not allowed" << endl;

    return 0;
}
