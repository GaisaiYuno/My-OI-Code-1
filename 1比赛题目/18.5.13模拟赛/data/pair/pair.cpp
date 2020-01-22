#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 500005
#define ForMyLove return 0;
struct st{
	int v;
	int g;
}st[maxn][35];
int a[maxn];
int n;
inline int max(int a,int b){
	return a>b?a:b;
}
inline int min(int a,int b){
	return a>b?b:a;
}
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void init(){
	for(int i=1;i<=n;i++) st[i][0].v=st[i][0].g=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j].v=min(st[i][j-1].v,st[i+(1<<(j-1))][j-1].v);
			st[i][j].g=gcd(st[i][j-1].g,st[i+(1<<(j-1))][j-1].g);
		}
	}
}
int query(int l,int r,int cmd){
	if(l==r) return st[l][0].v;
	int k=log2(r-l+1);
	if(cmd==1) return min(st[l][k].v,st[r-(1<<k)+1][k].v);
	else return gcd(st[l][k].g,st[r-(1<<k)+1][k].g);
}
int ans[maxn];
int is_ok(int v){
	int ans=0;
	for(int i=1;i+v<=n;i++){
		if(query(i,i+v,1)==query(i,i+v,2)){
			ans++;
		}
	}
	return ans;
}
int main(){
//	freopen("pair.in","r",stdin);
//	freopen("pair.out","w",stdout);
//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	init();
	int num=0;
	int val=0;
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)>>1;
		int tmp=is_ok(mid);
//		printf("%d %d\n",tmp,mid);
		if(tmp==0) r=mid-1;
		else{
			val=max(mid,val);
			l=mid+1;
		}
	}
	for(int i=1;i+val<=n;i++){
		if(query(i,i+val,1)==query(i,i+val,2)){
			num++;
			ans[num]=i;
		}
	}
	printf("%d %d\n",num,val);
	for(int i=1;i<=num;i++) printf("%d ",ans[i]);
	ForMyLove
//	printf("%d %d\n",query(1,n,1),query(1,n,2));
}
