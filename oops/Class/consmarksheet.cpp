#include<iostream>
using namespace std;
class student{
public:
 int roll ;
 string name;
 void setName(){
 cout<<"enter your Name"<<endl;
 cin>>name;
 setroll();
 }
 void setroll(){
 cout<<"enter your Roll No"<<endl;
 cin>>roll;
 tMarks();
 }
 int tMarks();
 char grade(int tMarks);
};
int main(){
 student r;
 r.setName(); 

}
int student::tMarks(){
    cout<<"enter your marks of Three subject"<<endl;
    int marks[3];
for (int i=0;i<3;i++){
    cin>>marks[i];
}
int sum =0;
for(int i=0;i<3;i++){
sum+=marks[i];
}
cout<<"Tottal Marks "<< sum<<endl;
grade(sum);
return 0;
};
char student::grade(int tMarks){
    cout<<"GRADE :";
    if(tMarks>250) cout<<"A+"<<endl;
    else if(tMarks>200) cout<<"A"<<endl;
    else if (tMarks>100)cout<<"B"<<endl;
    else cout<<"F"<<endl;
    return 0;
};