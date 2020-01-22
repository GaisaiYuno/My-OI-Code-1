#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,q,tb[1001],b[1001][9],rl[1001],r[1001],i,j,minn;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	const int ft[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&tb[i]);
		for(j=1;j<=8;j++) b[i][j]=tb[i]%ft[j];
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&rl[i],&r[i]);
		minn=10000001;
		for(j=1;j<=n;j++)
			if(r[i]==b[j][rl[i]]) minn=min(minn,tb[j]);
		if(minn==10000001) printf("-1\n");
		else printf("%d\n",minn);
	}
	return 0;
}
