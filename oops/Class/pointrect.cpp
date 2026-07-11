#include<iostream>
using namespace std;
class rectangle{
private:
    int length;
    int breadth;
public:
    void setLength(int l){
        length=l;
    }
    void setBreadth(int b){
        breadth=b;
    }
    int area(){
        return length*breadth;
    }
    int perimeter(){
        return 2*(length +breadth);
    }
};
int main(){
rectangle r;
rectangle *p;
p=&r;
cout<<r.area()<<endl;
p->setLength(3);
p->setBreadth(5);
cout<<"area is : "<<r.area()<<endl;
cout<<"perimeter is: "<<r.perimeter()<<endl;
}