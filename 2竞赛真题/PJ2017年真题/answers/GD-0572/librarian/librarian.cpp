#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fin(x) freopen(x,"r",stdin)
#define fou(x) freopen(x,"w",stdout)
using namespace std;

inline int rd()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}

const int bin[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

int n,q,a[1010],l,x;
bool flag;

int main()
{
	fin("librarian.in");fou("librarian.out");
	n=rd();q=rd();
	fo(i,1,n)a[i]=rd();
	sort(a+1,a+n+1);
	while(q--){
		l=rd();x=rd();
		flag=1;
		fo(i,1,n){
			if(a[i]<x)continue;
			if((a[i]-x)%bin[l]==0){
				flag=0;
				printf("%d\n",a[i]);
				break;
			}
		}
		if(flag)puts("-1");
	}
}
