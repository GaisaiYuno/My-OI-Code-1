#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
using namespace std;
int n;
int c[maxn];
int dmin[maxn],dmax[maxn];
int premin[maxn],premax[maxn];
int sufmin[maxn],sufmax[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		dmin[i]=n+1;
	}
	for(int i=1;i<=n;i++){
		dmin[c[i]]=min(i,dmin[c[i]]);
		dmax[c[i]]=max(i,dmax[c[i]]);
	}
	memset(sufmin,0x3f,sizeof(sufmin));
	memset(premin,0x3f,sizeof(premin));
	premin[1]=dmin[1];
	premax[1]=dmax[1];
	for(int i=2;i<=n;i++){
		premin[i]=min(premin[i-1],dmin[i]);
		premax[i]=max(premax[i-1],dmax[i]); 
	}
	sufmin[n]=dmin[n];
	sufmax[n]=dmax[n];
	for(int i=n-1;i>=1;i--){
		sufmin[i]=min(sufmin[i+1],dmin[i]);
		sufmax[i]=max(sufmax[i+1],dmax[i]);
	}
	int minx=n+1,maxx=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		minx=min(premin[i-1],sufmin[i+1]);
		maxx=max(premax[i-1],sufmax[i+1]);
		ans=max(ans,abs(maxx-dmin[i]));
		ans=max(ans,abs(dmax[i]-minx));
	}
	printf("%d\n",ans);
}

