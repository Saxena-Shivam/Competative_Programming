#include<iostream>
using namespace std;
class Base{
    public:
    Base(){
        cout<<"Default of Base"<<endl;
    }
    Base(int x){
        cout<<"pram of Base"<<x<<endl;
    }
};
class Derived: public Base{
    public:
        Derived (){
            cout<<"Default of Derived"<<endl;
        }
        Derived(int x){
            cout<<"Param of Drived"<<x<<endl;
        }
    };
int main(){
    // int x;
    // char x;
    Derived r;
    Derived s(7);
}