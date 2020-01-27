#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 55
using namespace std;
int n,q;
int a[maxn];
int b[maxn];
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign; 
}
inline void qprint(int x){
	int b[32];
	int size=0;
	if(x<0) putchar('-');
	while(x>0){
		b[size++]=x%10;
		x/=10;
	}
	for(int i=size-1;i>=0;i--) putchar(b[i]+'0');
	putchar('\n');
}
int f(int l,int r,int *a){
	memset(b,0,sizeof(b));
	for(int i=l;i<=r;i++) b[i-l+1]=a[i];
	for(int i=r-l+1;i>=1;i--){
		for(int j=1;j<=i;j++){
			b[j]=b[j]^b[j+1];
		}
		if(i!=1)b[i]=0;
	}
	return b[1];
}
int query(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		for(int j=0;i+j<=r;j++){
			ans=max(ans,f(i,i+j,a));
//			printf("f([%d,%d])=%d\n",i,i+j,f(i,i+j,a));
		}
	}
	return ans;
}
int main(){
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i]=qread();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		l=qread();
		r=qread();
		qprint(query(l,r));
	}
}
/*
3
8 4 1
2
2 3
1 2
*/
