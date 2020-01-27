/*
For Selina
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#define maxn 1000005
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

inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}
	if(x==0){
		putchar('0');
		return;
	}
	if(x>0){
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

map<int,int>id;
map<int,int>app;
vector<int>d[maxn];
int n,m;
int cnt=0;
int vis[maxn*10];
int prime[maxn*10];
int a[maxn];
void sieve(int n){
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&(long long)i*prime[j]<=(long long)n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}


void divide(int n){
	for(int i=1;i<=cnt;i++){
		for(int j=prime[i];j<=n;j+=prime[i]){
			if(id.count(j)) d[id[j]].push_back(i);
		}
	}
}

int t[maxn];
int sum[maxn];
int main(){
	qread(n);
	int mv=0;
	for(int i=1;i<=n;i++){
		qread(a[i]);
		if(a[i]>mv) mv=a[i];
		id[a[i]]=i;		
		app[a[i]]++;
	}
	sieve(mv);
	divide(mv);
	for(int i=1;i<=n;i++){
		for(int j=0;j<d[i].size();j++){
			t[d[i][j]]+=app[a[i]];
		}
	}
	for(int i=1;i<=cnt;i++){
		sum[i]=sum[i-1]+t[i];
	}
	qread(m);
	int l,r;
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		l=lower_bound(prime+1,prime+1+cnt,l)-prime;
		r=upper_bound(prime+1,prime+1+cnt,r)-1-prime;
		qprint(sum[min(cnt,r)]-sum[l-1]);
		putchar('\n');
	}
}
