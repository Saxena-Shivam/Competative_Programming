#include<iostream>
using namespace std;
class rectangle{
private:
    int length;
    int breadth;
public:
    void setLength(int l){
        if(l>=0)
        length=l;
        else length=0;
    }
    void setBreadth(int b){
        if(b>0)
        breadth=b;
        else breadth=0;
    }
    int area(){
        return length*breadth;
    }
    int perimeter(){
        return 2*(length +breadth);
    }
};
int main(){
rectangle *p;
p= new rectangle();
cout<<p->area()<<endl;
p->setLength(3);
p->setBreadth(5);
cout<<"area is : "<<p->area()<<endl;
cout<<"perimeter is: "<<p->perimeter()<<endl;
}