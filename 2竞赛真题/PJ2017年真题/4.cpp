#include<iostream>
#include<cstdio>
#define maxn 500000
using namespace std;
int n,d,k;
int l=0,r=0;
struct node {
	int x;//Œª÷√
	int s;//µ√∑÷
}a[maxn];
long long f[maxn];
inline int read() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int main() {
	n=read();
	d=read();
	k=read();
	for(int i=1; i<=n; i++) {
		a[i].x=read();
		a[i].s=read();
	}
	int l=0,r=0;
	for(int i=1; i<=n; i++) {
		f[i]=-100000000;
		while(a[i].x-a[r].x>=mind)r++;
		while(a[i].x-a[l].x>maxd)l++;
		for(int j=l; j<r; j++)
			f[i]=max(f[i],f[j]);
		f[i]+=a[i].s;
	}
}
