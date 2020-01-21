// Vjudge Sliding Window(POJ 2823)
#include<iostream>
#define maxn 1000000
using namespace std;
int n,k;
int a[maxn];
int main(){
	int mina,maxa;
	mina=999999999;
	maxa=0;
	for(int i=0;i<n;i++) a[i]=fread(); 
	for(int i=0;i<=n-k;i++){
		for(int j=i;j<=i+k;j++){
			if(a[j]>maxa) maxa=a[j];
			if(a[j]<mina) mina=a[j];
		}
	} 
}
