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

struct node{
	int pos,v;
};

int f[10000001],n,d,V;
node a[500010];

bool check(int x){
	int point=0,i=0;
	while (i<=n){
		int find=i+1,flag=0;
		while (find<=n && a[find].pos-a[i].pos<=d+x){
			if (x<d && (a[find].pos-a[i].pos<d-x)){
				find++;
				continue;
			}
			if (a[find].v>=0){
				flag=1;break;
			}else find++;
		}
		if (find>n){
			if (point>=V)return 1;
			else return 0;
		}
		if (flag){
			i=find;
			point+=a[find].v;
			if (point>=V)return 1;
			continue;
		}
		i=find-1;
		point+=a[find-1].v;
	}
	return 0;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int l=0,r=0,mid,sum=0;
	scanf("%d %d %d",&n,&d,&V);
	for (int i=1;i<=n;i++){
		scanf("%d %d",&a[i].pos,&a[i].v);
		if (a[i].v>0)sum+=a[i].v;
		r=max(r,a[i].pos);
	}
	if (sum<V){
		puts("-1");
		return 0;
	}
	while (l<r){
		mid=(l+r)/2;
		int ck=check(mid);
		if (ck)r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}
