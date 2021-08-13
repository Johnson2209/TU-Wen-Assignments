#include<iostream>
#include <cmath>
#include "triangle.hpp"
using namespace std;


 int main(){
   double x0,x1,y0,y1,z0,z1;
   Triangle tri;

   cout<<"enter x0 and x1"<<endl;
   cin>>x0>>x1;
   tri.setX(x0, x1);
   cout<<"enter y0 and y1"<<endl;
   cin>>y0>>y1;
   tri.setY(y0, y1);
   cout<<"enter z0 and z1"<<endl;
   cin>>z0>>z1;
    tri.setZ(z0, z1);

   cout<<"area of Triangle is"<<tri.getArea()<<endl;

   cout<<"perimeter of Triangle is"<<tri.getperimeter()<<endl;

     if(tri.isEquilateral()){
     cout<<"triangle is equilateral";}
     else{
       cout<<"triangle is not equilateral"<<endl;
     }

    return 0;
 }
