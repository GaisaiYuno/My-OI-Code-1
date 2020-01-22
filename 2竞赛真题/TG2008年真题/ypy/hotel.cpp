#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 200005
#define maxk 55
using namespace std;
int n,k,p;
int color[maxn],price[maxn];
int cnt_same[maxk][maxn];
int last[maxn];
int main(){
//	freopen("hotel.in","r",stdin);
//	freopen("hotel.out","w",stdout);
	printf("%.2f",(double)(sizeof(color)+sizeof(price)+sizeof(cnt_same)+sizeof(last))/1024/1024);
	scanf("%d %d %d",&n,&k,&p);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&color[i],&price[i]);
		cnt_same[color[i]][i]++;
	}
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			cnt_same[i][j]+=cnt_same[i][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		if(price[i]<=p) last[i]=i;
		else last[i]=last[i-1];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int j=last[i];
		if(j==0) continue;
		else{
			if(j!=i) ans+=cnt_same[color[i]][j];
			else ans+=cnt_same[color[i]][j-1];
		}
	}
	cout<<ans<<endl;
}
