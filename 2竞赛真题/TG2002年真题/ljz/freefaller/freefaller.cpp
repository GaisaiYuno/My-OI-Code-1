#include<iostream>
#include<cstdio>  
#include<cmath>  
#include<algorithm>  
using namespace std;
double prec = 1e-5;
double H,S1,V,L,K,N,x,y,z = 1e-5,p,q;

int main(){  
	freopen("freefaller.in","r",stdin);
	freopen("freefaller.out","w",stdout);     
	cin>>H>>S1>>V>>L>>K>>N;
	x = S1 - sqrt(H / 5) * V - z;
	p = (int) x;
	if(x - p > prec) p++;
	y = S1 + L - sqrt(max(0.0,H - K - sqrt(z)) / 5) * V + z;
	q = (int) y;
	p = max(0.0,p);
	q = min(N - 1,q);
	cout<<max(0.0,q - p + 1);
}  
