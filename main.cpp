#include<iostream>
// #include<simplecpp>
#include"Polynomial.h"
using namespace std;
int main(){
Polynomial q;

q.read();
q.print();

Polynomial p;

p.read();p.print();

p.root();
Polynomial s;
s = p.integral();
s.print();
Polynomial r;
r = q-p;
r.print();
Polynomial t;
t = q*p;
t.print();
Polynomial u;
u = q/p;
u.print();
Polynomial w;
w = q%p;
w.print();
// q.plot(-5,5);
// getClick();
}


