#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define inf 500009
#define INF (int)1e9
using namespace std;

int x[inf],v[inf],f[inf];
int n,d,sc;

int check(int k){
	int l=max(1,d-k),r=d+k,maxn=0;
	for (int i=0;i<=n;i++){
		f[i]=-INF;
	}
	f[0]=0;
	for (int i=0;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (x[j]-x[i]>r){
				break;
			}
			if (x[j]-x[i]<l){
				continue;
			}
			f[j]=max(f[j],f[i]+v[j]);
			maxn=max(maxn,f[j]);
			if (maxn>=sc){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&sc);
	int l=0,r=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&v[i]);
		r=max(r,x[i]);
	}
	int p=0;
	while(l<r){
		int mid=(l+r)/2;
		if (check(mid)){
			r=mid;
			p=1;
		}
		else{
			l=mid+1;
		}
	}
	if (!p){
		printf("-1\n");
	}
	else{
		printf("%d\n",l);
	}
}
/*
7 4 10 
2 6
5 -3
10 3
11 -3
13 1 
17 6
20 2
*/
