#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;
int n,m,d;
struct coffee{
	int tim;
	int id;
	int nex;
	coffee(){
		
	}
	coffee(int t){
		tim=t;
		id=nex=0;
	}
	friend bool operator < (coffee x,coffee y){
		return x.tim<y.tim;
	}
}a[maxn];
int used[maxn];
int ans[maxn];
int cnt=0;
int work(int x){
	while(x<=m&&x!=0){
//		printf("%d\n",x);
		if(!used[x]){
			used[x]=1;
			ans[a[x].id]=cnt;
		}
		x=a[x].nex;
	}
}
int check(int x){
	for(int i=x+1;i<=n;i++){
		if(a[i-x].tim+d>=a[i].tim) return 0;
	}
	return 1;
}
int bin_search(){
	int l=0,r=n,mid,ans=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
int main(){
	scanf("%d %d %d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].tim);
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	int days=bin_search();
	int k=1;
	for(int i=1;i<=n;i++){
		ans[a[i].id]=k;
		k=k%days+1;
	}
	printf("%d\n",days);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}
