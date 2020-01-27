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
#define FOR(i,s,t) for(int i=(s);i<=(t);i++)
#define REV(i,s,t) for(int i=(s);i>=(t);i--)
#define high(x) x/(int)floor(sqrt(v.u))
#define low(x) x%(int)floor(sqrt(v.u))
#define index(x,y) x*(int)floor(sqrt(v.u))+y
using namespace std;
inline char gc(){
	static char bb[10000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,10000000,stdin),s==t)?EOF:*s++;
}
inline int read(){
	register int x=0;register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=gc();
	return x;
}
void fout(double x){
	cerr<<x<<endl;
	if(x==0)return;
	x*=10;
	putchar(int(x)+'0');
	fout(x-(int)(x));
}
double a;
int n,m,k;
int main(){
//	freopen(".in","r",stdin);
	freopen("test.txt","w",stdout);
	cin>>a;
	fout(a);
}

