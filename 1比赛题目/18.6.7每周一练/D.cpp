#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;
int n;
inline int lowbit(int x){
	return x&(-x);
}
int t[maxn];
void update(int x,int v){
	while(x>0){
		t[x]=max(t[x],v);
		x-=lowbit(x);
	}
}
int query(int x){
	int ans=-1;
	while(x<=n){
		ans=max(ans,t[x]);
		x+=lowbit(x);
	}
	return ans;
}
struct node{
	int x;
	int y;
	int z;
	int dis;
}a[maxn];
int cmpx(node p,node q){
	return  p.x<q.x;
}
int cmpy(node p,node q){
	return p.y>q.y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].y);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].z);
	sort(a+1,a+1+n,cmpx);
	a[1].dis=1;
	for(int i=2;i<=n;i++){
		if(a[i].x==a[i-1].x)a[i].dis=a[i-1].dis;
		else a[i].dis=a[i-1].dis+1;
	}
	sort(a+1,a+1+n,cmpy);
	memset(t,-1,sizeof(t));
	int i=1,j,ans=0;
	while(i<=n){
		for(j=i;j<=n&&a[j].y==a[i].y;j++){
			if(query(a[j].dis+1)>a[j].z) ans++;
		} 
		for(j=i;j<=n&&a[j].y==a[i].y;j++){
			update(a[j].dis,a[j].z);
		}
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}
