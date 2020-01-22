//苟利国家生死以
//岂因祸福避趋之 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10005
#define maxm 1005
#define maxv 1000005
#define INF 0x7fffffff
using namespace std;
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

int n,m;
int a[maxn];
struct seg{
	int l;
	int r;
}b[maxm];
int mark[maxv];
int amax,amin,bmax,bmin;
int check(int len,int tp){
	int ans=0;
	if(tp==1){
		for(int i=1;i<=n;i++){
			if(a[i]+len>bmax) break;
			if(a[i]+len>=0&&a[i]+len<=bmax&&mark[a[i]+len]>=1){
				ans++;
			}
		}
		return ans;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]-len>=0&&a[i]-len<=bmax&&mark[a[i]-len]>=1){
				ans++;
			}
		}
		return ans;
	}
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	amax=bmax=0;
	amin=bmin=INF;
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
		if(a[i]>amax) amax=a[i];
		if(a[i]<amin) amin=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		b[i].l=qread();
		b[i].r=qread();
		mark[b[i].l]++;
		mark[b[i].r+1]--; 
		if(b[i].l<bmin) bmin=b[i].l;
		if(b[i].r>bmax) bmax=b[i].r;
	}
	for(int i=bmin;i<=bmax;i++){
		mark[i]+=mark[i-1];
	}
	int d=0,s=0;
	int len=max(bmax-amin,amax-bmin);
	int t1,t2;
	for(int i=0;i<=len;i++){
//		printf("f(%d)=%d\n",i,min(t1,t2));
		t1=check(i,1);
		t2=check(i,-1);
		if(t1>s){
			d=i;
			s=t1;
		}
		if(t2>s){
			d=i;
			s=t2;
		}
	}
	printf("%d %d\n",d,s);
} 
