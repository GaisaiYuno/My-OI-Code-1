//hanoi
#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 1000
int n;
using namespace std;
int a[maxn];
int len;
int main() {
	int x,len;
	//freopen("hanoi.in","r",stdin);
	//freopen("hanoi.out","w",stdout);
	//通项公式An=2*An-1+1 
	cin>>n;
	a[0]=2;
	len=1;
	for(int i=1; i<n; i++) {
		for(int j=0; j<i-1; j++) {
			a[j]*=2;
		}
		for(int j=0; j<i-1; j++) {
			if(a[j]>=10) {
				a[j]-=10;
				a[j+1]++;
			}
		}
		a[0]++;
	}
	for(int k=0; k<maxn; k++) {
		a[k]*=2;
	}
	for(int k=0; k<maxn; k++) {
		if(a[k]>=10) {
			a[k]-=10;
			a[k+1]++;
		}
	}
	for(len=maxn-1;len>=0;len--){
		if(a[len]>0) break; 
	} 
	for(int k=len;k>=0;k--) cout<<a[k];
	return 0;
}
