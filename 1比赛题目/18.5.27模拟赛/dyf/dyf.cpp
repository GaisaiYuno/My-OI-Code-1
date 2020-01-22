#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,q;
int a[maxn];
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
inline void qprint(long long x){
	int b[64];
	int size=0;
	if(x<0) putchar('-');
	while(x>0){
		b[size++]=x%10;
		x/=10;
	}
	for(int i=size-1;i>=0;i--) putchar(b[i]+'0');
	putchar('\n');
}
inline int abs(int x){
	if(x>0) return x;
	else return -x;
}
int L(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		for(int j=1;i+j<=r;j++){
			ans=max(ans,abs(a[i+j]-a[i])/abs(j+i-i));
		}
	}
	return ans;
}
long long all_L(int l,int r){
	long long ans=0;
	for(int i=l;i<=r;i++){
		for(int j=1;i+j<=r;j++){
			ans=ans+L(i,j+i);
		}
	}
	return ans;
}
int main(){
	freopen("dyf.in","r",stdin);
	freopen("dyf.out","w",stdout);
	int l,r;
	scanf("%d",&n);
	scanf("%d",&q);
	for(int i=1;i<=n;i++) a[i]=qread();
	while(q--){
		l=qread();
		r=qread();
		qprint(all_L(l,r));
//		printf("%I64d\n",all_L(l,r));
	}
}
