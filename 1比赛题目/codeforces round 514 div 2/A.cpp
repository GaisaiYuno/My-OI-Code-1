#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,L,b;
int l[maxn],t[maxn]; 
int main(){
	scanf("%d %d %d",&n,&L,&b);
	int pre=0;
	int ans=0;
	int tim=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&l[i],&t[i]);
		tim=l[i]-pre; 
		ans+=tim/b;
		pre=l[i]+t[i];
	}
	tim=L-l[n]-t[n];
	ans+=tim/b;
	printf("%d\n",ans);
}

