#include<iostream>
using namespace std;
class complex{
 public:
    int real;
    int img;
 
    complex(int real=0,int img=0){
        this->real=real;
        this->img=img;   
    }
     friend complex operator+(complex c1,complex c2){
    complex tempt;
        tempt.real=c1.real+c2.real;
        tempt.img=c1.img +c2.img;
        return tempt;
    }
friend  ostream& operator<<(ostream&out ,complex&c3) ;
};
ostream& operator<<(ostream&out ,complex&c3) {
cout<<c3.real<<" + "<<"i"<<c3.img<<endl;
return out;
}
int main(){
    complex c1(1,2);
    complex c2(3,4);
    complex c3;
    c3= c1 + c2;
    cout<<c3;
    return 0;

}