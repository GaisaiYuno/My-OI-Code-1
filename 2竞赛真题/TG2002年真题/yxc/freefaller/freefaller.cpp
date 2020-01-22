#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	freopen("freefaller.in","r",stdin);
	freopen("freefaller.out","w",stdout);
	long double H,S1,V,L,K;
	int n;
	cin>>H>>S1>>V>>L>>K>>n;
	long double stime=sqrt((H-K)/5);
	long double etime=sqrt(H/5);
	long double swa=S1-stime*V+L+0.00001;
	long double ewa=S1-etime*V+0.00001;
	int s=int(swa);
	int e=int(ewa)+1;
//	cout<<stime<<' '<<etime<<endl;
	cout<<min(s,n)-e+1;
	return 0;
}
