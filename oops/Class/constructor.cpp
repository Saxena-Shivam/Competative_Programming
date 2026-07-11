#include<iostream>
using namespace std;
class rectangle{
    private:
    int length;
    int breadth;
public:
    rectangle(int l=0,int b=0){
        length=l;
        breadth=b;
    }
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
cout<<r.area()<<endl;
r.setLength(3);
r.setBreadth(5);
cout<<"area is : "<<r.area()<<endl;
cout<<"perimeter is: "<<r.perimeter()<<endl;
rectangle p(6);
cout<<"area is : "<<p.area()<<endl;
cout<<"perimeter is: "<<p.perimeter()<<endl;
}