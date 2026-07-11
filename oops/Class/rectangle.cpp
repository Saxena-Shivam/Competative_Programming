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
// r.length=5;
// r.breadth=6;
cout<<r.area()<<endl;
r.setLength(3);
r.setBreadth(5);
cout<<"area is : "<<r.area()<<endl;
cout<<"perimeter is: "<<r.perimeter()<<endl;

}