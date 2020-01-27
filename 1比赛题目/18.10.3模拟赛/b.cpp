#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define INF 100000000000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

inline void qread(long long &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

char c[30];
inline void qprint(long long x){
	if(x==0){
		putchar('0');
		putchar('\n');
		return;
	}
	int ptr=0;
	while(x>0){
		c[++ptr]=x%10+'0';
		x/=10;
	}
	for(int i=ptr;i>=1;i--) putchar(c[i]);
	putchar('\n');
}

int n;
struct seg{
	long long l;
	long long r;
	seg(){
		
	}
	seg(long long L,long long R){
		l=L;
		r=R;
	}
	friend bool operator <(seg a,seg b){
		if(a.l==b.l) return a.r<b.r;
		else return a.l<b.l;
	}
}a[maxn];
long long count(int del){
	long long l=-1,r=-1;
	long long ans=0;
	for(int i=1;i<=n+1;i++){
		if(i==del) continue;
		else{
			if(l==-1&&r==-1){
				l=a[i].l;
				r=a[i].r;
			}
			if(a[i].l>r){
				ans+=(r-l);
				l=a[i].l;
				r=a[i].r;
			}else{
				l=min(l,a[i].l);
				r=max(r,a[i].r);
			}	
		}
	}
	return ans;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
//	freopen("t699.in","r",stdin);
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i].l);
		qread(a[i].r);
	}
	sort(a+1,a+1+n);
	a[n+1]=seg(INF,INF);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,count(i));
	}
	qprint(ans);
}
