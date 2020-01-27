#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;
inline void qread(int& x) {
    x=0;
    char c=getchar();
    int sign=1;
    while(c<'0'||c>'9') {
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    x*=sign;
}
inline void qprint(int x) {
    if(x<0) {
        putchar('-');
        qprint(-x);
    } else if(x==0) {
        putchar('0');
        return;
    } else {
        if(x/10>0) qprint(x/10);
        putchar('0'+x%10);
    }
}

int n,m,p,q;
int fa[maxn+5];//记录i下一个没被覆盖的位置 
void ini(int n){
	for(int i=1;i<=n+1;i++) fa[i]=i;
} 
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
} 

int a[maxn+5];
void update(int l,int r,int v){
	int p=find(l);
	while(p<=r){
		a[p]=v;
		fa[p]=p+1;
		p=find(p);
	}
}
int main(){
	qread(n);
	qread(m);
	qread(p);
	qread(q);
	ini(n);
	for(int i=m; i>=1;i--){//倒序覆盖，这样之后的就不会被之前的覆盖 
		int l=(i*p+q)%n+1;
		int r=(i*q+p)%n+1;
		if(l>r) swap(l,r);
		update(l,r,i);
	}
	for(int i=1;i<=n;i++){
		qprint(a[i]);
		putchar('\n');
	}
} 

