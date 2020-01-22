#include<algorithm>
#include<bitset>
#include<cstdio>
#include<deque>
#include<exception>
#include<fstream>
#include<iostream>
#include<list>
#include<map>
#include<new>
#include<queue>
#include<stack>
#include<vector>
#define FOR(i,s,t) for(register int i=s;i<=t;i++)
#define REV(i,s,t) for(rint i=s;i>=t;i--)
#define high(x) x/(int)floor(sqrt(v.u))
#define low(x) x%(int)floor(sqrt(v.u))
#define index(x,y) x*(int)floor(sqrt(v.u))+y
using namespace std;
inline char gc() {
	static char bb[10000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,10000000,stdin),s==t)?EOF:*s++;
}
inline int read() {
	register int x=0;
	register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=gc();
	return x;
}
int n,m,k;
int arr[200005];
int maxn;
bool comp(int a,int b) {
	return a>b;
}
int main() {
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=read();
	FOR(i,1,n) {
		arr[i]=read();
	}
	sort(arr+1,arr+n+1,comp);
	FOR(i,1,n) {
		if(arr[i]<=maxn)break;
		FOR(u,1,i) {
			maxn=max(maxn,arr[u]%arr[i]);
		}
	}
	cout<<maxn;
}
