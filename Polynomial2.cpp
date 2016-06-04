#include<iostream>
#include"Polynomial.h"
using namespace std;


void Polynomial::read(){
	int m;
	int maxdegree=0;
	cin>>m;
        int a[m];
	double b[m];
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<m;i++){
	maxdegree = max(maxdegree,a[i]);
	}
	n = maxdegree;
	c = new double[n+1];
	for(int i=0;i<=n;i++) c[i]=0;
	for(int i=0;i<=m-1;i++) c[(a[i])] = b[i];
}
Polynomial Polynomial::operator-(const Polynomial &p){
	Polynomial q;
	int r= max(n,p.n)+1;
	double temp[r];
	if(n>=p.n){
		for(int i=0;i<p.n+1;i++)temp[i] = c[i]-p.c[i];
		for(int i=p.n+1;i<n+1;i++)temp[i] = c[i];
	}
	else {
		for(int i=0;i<n+1;i++)temp[i]=c[i]-p.c[i];
		for(int i=n+1;i<p.n+1;i++)temp[i]=-1*p.c[i];
	}
	int k;
	for( k=r-1;temp[k]==0;k--){}
	q.n =k;
	q.c = new double[k+1];
	for(int j=0;j<=q.n;j++)q.c[j]=temp[j];
	return q;
}
Polynomial Polynomial::operator*(const Polynomial &p){
	int size = p.n+n+1;
	double q[size];
	for(int i =0 ;i<size;i++)q[i]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=p.n;j++)q[i+j]+=c[i]*p.c[j];
	}
	Polynomial r;
	r.n = n+p.n;
	r.c = new double[n+p.n+1];
	for(int i=0;i<=r.n;i++)r.c[i] = q[i];
	return r;
}
Polynomial Polynomial::integral(){
	Polynomial q;
	q.n=n+1;
	q.c = new double[q.n+1];
	for(int i=1;i<=n+1;i++){
		q.c[i]=c[i-1]/i;
	}
	q.c[0]=0;
	return q;
}
double Polynomial::valueAt(double x){

    double y=0,z=1;
    for(int i=0;i<n+1;i++){
    for(int j = 0 ;j<i;j++){
    z*=x;
    }
    y+=c[i]*z;
    z=1;
    }
    return y;
}

void Polynomial::root(){
 
	double x,g=valueAt(-1000);
	for(x=-1000;x<1000;x=x+0.1){
		if(valueAt(x)==0){
			cout<<x<<'\n';
			g=valueAt(x+0.1);
		}
		else{
			if(valueAt(x)*g<0)
			cout<<x<<'\n';
			g=valueAt(x);
		}
	}
	}

