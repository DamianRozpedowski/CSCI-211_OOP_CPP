#include <iostream>
using namespace std;
class Rat{
private:
 int n;
 int d;
public:
 // constructors

 // default constructor
 Rat(){
 n=0;
 d=1;
 }

 // 2 parameter constructor
 Rat(int i, int j){
 n=i;
 d=j;
 }
 // conversion constructor
 Rat(int i){
 n=i;
 d=1;
 }

 //accessor functions (usually called get() and set(...) )
 int getN(){ return n;}
 int getD(){ return d;}
 void setN(int i){ n=i;}
 void setD(int i){ d=i;}

 //arithmetic operators

 Rat operator+(Rat r){
 Rat t;
 t.n=n*r.d+d*r.n;
 t.d=d*r.d;
 return t;
 }

 Rat operator-(Rat r){
 Rat t;
 t.n=n*r.d-d*r.n;
 t.d=d*r.d;
// lowestTerm(t);
 return t;
 }


 Rat operator*(Rat r){
 Rat t;
 t.n=n*r.n;
 t.d=d*r.d;
// lowestTerm(t);
 return t;
 }


 Rat operator/(Rat r){
 Rat t;
 t.n=n*r.d;
 t.d=d*r.n;
 //lowestTerm(t);
 return t;
 }

 int gcd(int x, int y){
  if (y == 0)
   return x;
   return gcd(y, x % y);
 }

 void lowestTerm(Rat &r){
   int greatestCD= r.gcd(r.getN(),r.getD());
   r.n /= greatestCD;
   r.d /= greatestCD;
 }

 void improper(Rat &r){
   if (r.getN() > r.getD()){
     r.n%=r.d;
   }
 }

 // 2 overloaded i/o operators
 friend ostream& operator<<(ostream& os, Rat r);
 friend istream& operator>>(istream& is, Rat& r);
}; //end Rat
// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
   r.lowestTerm(r);
   if (abs(r.n) >= r.d || r.n == 0)
      os << r.n/r.d << " ";
   if (r.d != 1)
      os << (r.n/r.d <= -1 ? abs(r.n%r.d) : r.n%r.d) << "/" << r.d;
   return os;
}
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
 is>>r.n>>r.d;
  r.lowestTerm(r);
 return is;
}
int main(){

 Rat x(1,2), y(2,3), z;
 z=x+y;
 cout<<z<<endl;

 x.setN(3);
 y.setD(2);
 z=x+y;
 cout<<z <<endl;
 cin>>x;
 cout<<x <<endl;;
 z= x+5;
 cout<<z << endl;

  Rat r1(5,2), r2(3,2);
   cout << "======Testing Operators======"<<endl;
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
 return 0;
}