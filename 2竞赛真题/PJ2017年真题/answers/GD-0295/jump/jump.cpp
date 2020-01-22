#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s,k,tot=0;
int f[500010],a[500010],pos[500010];
int main(void)
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&k,&s);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&pos[i],&a[i]);
		if(a[i]>0)
			tot+=a[i];
	}
	if(tot<s){
		printf("-1\n");
		return 0;
	}
	pos[0]=0;
	for(int u=0;u<=1000000;u++){//使用的金币数量 
		int maxn=a[1];
		f[0]=0;
		//printf("%d ",f[1]);
		for(int i=1;i<=n;i++){//前i个格子 
			f[i]=0;
			int j=i-1;
			if(pos[i]-pos[j]>k+u)
				break;
		/*	if(j==0&&pos[i]<k-u)
				break;*/
			while(j>=0&&pos[i]-pos[j]<k-u)
				j--;
			if(j<0)
				break;
			while(j>=0&&pos[i]-pos[j]<=k+u){
			//	printf("&&&&%d %d\n",i,j);
				f[i]=max(f[i],f[j]+a[i]);
				j--;
			}
			maxn=max(f[i],maxn);
		}
		if(maxn>=s){
			printf("%d",u);
			return 0;
		}
	}
	printf("-1\n");
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
*/
