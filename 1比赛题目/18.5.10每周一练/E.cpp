 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 200005
#define INF 2147483647
using namespace std;
struct table{
	int maxv;
	int minv;
}st[maxn][20];
int a[maxn],b[maxn];
int cnt=0;
void st_init(int *a,int *b,int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<20;j++){
			st[i][j].maxv=-INF;
			st[i][j].minv=INF;
		}
	}
	for(int i=1;i<=n;i++){
		 st[i][0].maxv=a[i];
		 st[i][0].minv=b[i];
	} 
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j].maxv=max(st[i][j-1].maxv,st[i+(1<<(j-1))][j-1].maxv);
			st[i][j].minv=min(st[i][j-1].minv,st[i+(1<<(j-1))][j-1].minv);
		}
	}
}
int st_query(int l,int r,int cmd){
	int k=log2(r-l+1);
	if(cmd==1) return max(st[l][k].maxv,st[r-(1<<k)+1][k].maxv);
	else if(cmd==2) return min(st[l][k].minv,st[r-(1<<k)+1][k].minv);
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]); 
	st_init(a,b,n);
	long long ans=0; 
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		int ans_l,ans_r; 
		ans_l=ans_r=-1;
		if(st_query(l,r,2)>st_query(l,r,1)) continue;
		while(l<=r){
			int mid=(l+r)>>1;
			int maxv=st_query(i,mid,1);
			int minv=st_query(i,mid,2);
			if(minv==maxv){
				ans_r=max(ans_r,mid);
				l=mid+1;
			}else  if(minv<maxv){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		
		if(ans_r==-1) continue;
		l=i;
		r=ans_r;
		ans_l=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			int maxv=st_query(i,mid,1);
			int minv=st_query(i,mid,2);
			if(minv==maxv){
				if(ans_l==-1) ans_l=mid;
				else ans_l=min(ans_l,mid);
				r=mid-1;
			}
			else if(minv<maxv){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans+=(ans_r-ans_l+1);
	} 
	printf("%I64d\n",ans);
//	printf("%d %d\n",st_query(1,n,1),st_query(1,n,2));
}

