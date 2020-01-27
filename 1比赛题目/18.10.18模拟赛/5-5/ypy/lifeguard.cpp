#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,k;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();\
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
struct seg{
	int l;
	int r;
	seg(){
		
	}
	seg(int L,int R){
		l=L;
		r=R;
	}
	friend bool operator <(seg a,seg b){
		if(a.l==b.l) return a.r<b.r;
		else return a.l<b.l;
	}
}a[maxn];
int main(){
	freopen("lifeguard.in","r",stdin);
	freopen("lifeguard.out","w",stdout);
	n=qread();
	k=qread();
	for(int i=1;i<=n;i++){
		a[i].l=qread();
		a[i].r=qread();
	}
	sort(a+1,a+1+n);
	cout<<0;
}
