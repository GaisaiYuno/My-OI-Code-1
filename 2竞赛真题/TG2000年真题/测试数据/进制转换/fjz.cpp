#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,r;
int a[1005];
int main() {
	freopen("fjz.in","r",stdin);
	freopen("fjz.out","w",stdout);
	int len=0;
	cin>>n>>r;
	if(n==0) {
		printf("0=0(case%d)",r);
		return 0;
	}
		int t=n;
		while(1) {
			int m=t%r;
			if(m>0) {
				a[len]=m;
				t/=r;
			}
			else if(m<0){
				a[len]=t-(r*(t/r+1));
				t/=r;
				t++;
			}
			else{
				a[len]=0;
				t/=r;
			}
			len++;
			if(t>=0&&t<abs(r)) break;
		}
		a[len]=t;
		printf("%d=",n);
		for(int i=len; i>=0; i--) {
			if(a[i]>=10) printf("%c",a[i]-10+'A');
			else cout<<a[i];
		}
		printf("(base%d)\n",r);
}
