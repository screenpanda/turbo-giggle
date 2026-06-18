#include<iostream>
using namespace std;
class Complex{
 public:
     Complex();
     Complex(int r);
     Complex(int r, int i);
     ~Complex(){};
     void operator ++();
     Complex operator ++(int);
     Complex operator+(const Complex & rhs) const;
     operator string();
     int getRealValue () {  return real;}
     int getImageValue () { return imag;}
     int getRealValue () const {return real;}
     int getImageValue () const { return imag;}

 private:
     int real;
     int imag; 

};
Complex::Complex(){
    real=5;
    imag=10; 
    //cout<<"Complex Constructor Called"<<endl;
}

Complex::Complex(int r, int i): real(r), imag(i){
    //cout<<"Complex Constructor Called"<<"\tReal="<<real<<"\tImag="<<imag<<endl;
}

Complex::Complex(int r): real(r){
    cout<<"Complex Constructor Only Real Called"<<"\tReal="<<real<<"Address"<<&real<<endl;
}

void Complex::operator++(){
       ++real;
       ++imag;
}

Complex Complex::operator++(int flag){
       Complex temp = *this;
       real++;
       imag++;
       return temp;
}

Complex Complex::operator+(const Complex & rhs) const{
       
       Complex temp;
       temp.real = real + rhs.real;
       temp.imag = imag + rhs.imag;
       return temp;
}
Complex::operator string(){
       return (to_string(real) + "+"+  to_string(imag) + "i") ;
}
//foo commit
int main(){
  Complex a;
  ++a;
  cout<<"Pre-Increment"<<endl;
  cout<<"A: Real="<<a.getRealValue()<<"\tImag="<<a.getImageValue()<<endl;
  Complex b(20,30);
  ++b;
  cout<<"Pre-Increment"<<endl;
  cout<<"B: Real="<<b.getRealValue()<<"\tImag="<<b.getImageValue()<<endl;
  b = a;
  cout<<"Assignment Operator"<<endl;
  cout<<"A: Real="<<a.getRealValue()<<"\tImag="<<a.getImageValue()<<endl;
  cout<<"B: Real="<<b.getRealValue()<<"\tImag="<<b.getImageValue()<<endl;
  Complex c = b++;
  cout<<"Post-Increment"<<endl; 
  cout<<"B: Real="<<b.getRealValue()<<"\tImag="<<b.getImageValue()<<endl;
  cout<<"C: Real="<<c.getRealValue()<<"\tImag="<<c.getImageValue()<<endl;
  cout<<"Addition Operator"<<endl;
  Complex d; 
  d = a + b; //a.operator+(b);
  cout<<"A: Real="<<a.getRealValue()<<"\tImag="<<a.getImageValue()<<endl;
  cout<<"B: Real="<<b.getRealValue()<<"\tImag="<<b.getImageValue()<<endl;
  cout<<"D: Real="<<d.getRealValue()<<"\tImag="<<d.getImageValue()<<endl;
  cout<<"Class to String Return"<<endl;
  Complex e(20,30);
  string x = e;
  cout<<x<<endl;
  cout<<"Int to Class Return "<<endl;
  int y=100;
  Complex f;
  f = y;
  cout<<"F: Real="<<f.getRealValue()<<"\tImag="<<f.getImageValue()<<endl;
  return 0;
}  