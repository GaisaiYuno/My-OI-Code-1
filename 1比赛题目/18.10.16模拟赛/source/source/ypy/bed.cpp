//CodeVS 1809
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 300005
#define maxlog 32
#define INF 0x7f7f7f7f
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,k;
int a[maxn];
int stmax[maxn][maxlog],stmin[maxn][maxlog];
void st_init(){
	memset(stmin,0x7f,sizeof(stmin));
	for(int i=1;i<=n;i++) stmax[i][0]=stmin[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
			stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]);
		}
	}
}

int query_max(int l,int r){
	int t=log2(r-l+1);
	return max(stmax[l][t],stmax[r-(1<<t)+1][t]);
}

int query_min(int l,int r){
	int t=log2(r-l+1);
	return min(stmin[l][t],stmin[r-(1<<t)+1][t]);
}

int check(int len){
	int minv=INF;
	for(int i=1;i+len-1<=n;i++){
		minv=min(minv,query_max(i,i+len-1)-query_min(i,i+len-1));
	}
	if(minv>k) return 0;
	else return 1;
}

int main(){
	n=qread();
	k=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
	}
	st_init();
	int l=1,r=n,mid;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%d\n",ans);
}
