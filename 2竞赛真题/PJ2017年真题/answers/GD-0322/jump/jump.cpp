#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int n,d,k,a[500010],l,r,b[500010],c[500010],sum,mid;
int ck(int g){
	queue<int> q,qi;
	if (d-g>a[1]||d+g<a[1])return 0;
	q.push(b[1]);
	qi.push(1);
	while (!q.empty()){
		int u=qi.front(),x=q.front(),dis=0,ans;
		qi.pop();q.pop();
		for (int i=u;i<=n;++i){
			if (x>k)return 1;
			dis+=a[i];
			if (dis>d+g)break;
			if (dis<d-g)continue;
			x+=b[i];
			q.push(x);
			qi.push(i);
		}
	}
	return 0;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;++i){
		scanf("%d%d",c+i,b+i);
		a[i]=c[i]-c[i-1];
		if (b[i]>0){
			sum+=b[i];
		}
	}
	if (sum<k){
		printf("%d",-1);
		return 0;
	}
	l=1,r=1000000000;
	while (l<r){
		mid=(l+r)/2;
		if (ck(mid))r=mid-1;
		else l=mid+1;
//		printf("%d %d\n",l,r);
	}
	printf("%d",l);
	return 0;
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

7 4 20
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2
*/
