#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int a[1010],s[1010][11],b[1010],can[1010];

int work(int X,int i){
	int now,k=0,lenth=0;
	while (X){
		now=X%10;
		s[i][++k]=now;
		X/=10;
	}
	return k;
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,m,len,x,p;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		b[i]=work(a[i],i);
	}
	for (int i=1;i<=m;i++){
		int flag=0;
		scanf("%d %d",&len,&x);
		for (int l=1;l<=n;l++)can[l]=1;
		for (int j=1;j<=len;j++){
			p=x%10;
			x/=10;
			for (int k=1;k<=n;k++){
				if (can[k] && b[k]>=len)if (s[k][j]!=p)can[k]=0;
				if (b[k]<len)can[k]=0;
			}
		}
		for (int j=1;j<=n;j++)if (can[j]){
			flag=1;
			printf("%d\n",a[j]);
			break;
		}
		if (!flag)puts("-1");
	}
}
/*
5 5
2123
1123
23
24
24
*/
