#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[500001],b[500001],n,m,k,sum=0,minn=2147483647;

void dfs(int x,int y,int z,int p){
	if(x>n){
		if(z<k)return;
		minn=min(minn,y);
		return;
	}
	dfs(x+1,y,z,p);
	dfs(x+1,max(y,abs(a[x]-p-m)),z+b[x],a[x]);
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(b[i]>0)sum+=b[i];
	}
	if(sum<k){
		printf("-1");
		return 0;
	}
	dfs(0,0,0,0);
	printf("%d",minn);
}
