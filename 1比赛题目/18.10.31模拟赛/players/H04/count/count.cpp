#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300005
using namespace std;
int n,m,t;
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
	if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}	
}


int a[maxn];
int pow2[maxn];
int Log2[maxn];
int st[maxn][32];
void prework(){
	pow2[0]=1;
	for(int i=1;i<=20;i++){
		pow2[i]=pow2[i-1]*2;
	}
	int j=0;
	Log2[0]=-1;
	for(int i=1;i<=n;i++){
		if(i==pow2[j]){
			Log2[i]=Log2[i-1]+1;
			j++;
		}else Log2[i]=Log2[i-1];
	}
}
void st_init(){
	memset(st,0,sizeof(st));
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}

int st_query(int l,int r){
	int k=Log2[r-l+1]; 
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

long long query(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		for(int j=i+1;j<=r;j++){
			if(i==j-1||st_query(i+1,j-1)<min(a[i],a[j])) ans++;
		}
	}
	return ans;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int l,r,u,v,last; 
	n=qread();
	m=qread();
	t=qread();
	for(int i=1;i<=n;i++) a[i]=qread();
	prework();
	st_init();
	last=0;
	for(int i=1;i<=m;i++){
		l=qread();
		r=qread();
		if(t==0){
			u=l;
			v=r;
		}else{
			u=(l+last-1)%(n+1);
			v=(r+last-1)%(n+1);
			if(u>v) swap(u,v); 
		}
		qprint(query(u,v));
		putchar('\n');
	} 
} 
