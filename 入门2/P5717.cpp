#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    //寻找最大值，使其成为d 
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    if(a+b<=c){cout<<"Not triangle";return 0;}
    if(pow(a,2)+pow(b,2)==pow(c,2))cout<<"Right triangle"<<endl;
    if(pow(a,2)+pow(b,2)>pow(c,2))cout<<"Acute triangle"<<endl;
    if(pow(a,2)+pow(b,2)<pow(c,2))cout<<"Obtuse triangle"<<endl;
    if(a==b||a==c||b==c)cout<<"Isosceles triangle"<<endl;
    if(a==b&&b==c)cout<<"Equilateral triangle"<<endl;
    return 0;
} 