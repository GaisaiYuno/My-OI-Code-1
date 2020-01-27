#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 100005
int n,m;
long long ans[maxn];
int fa[maxn];
bool vis[maxn];
int mx=0;
struct node{
	long long num;
	int id;
}f[maxn];
struct node1{
	long long w;
	long long v;
	int id;
}q[maxn];
bool cmp(node a,node b){
	if(a.num==b.num){
		return a.id<b.id;
	}
	else{
		return a.num>b.num;
	}
}
bool cmp1(node1 a,node1 b){
	if(a.w==b.w){
		return a.id<b.id;	
    }
    else{
    	return a.w>b.w;
	}
}
int rnk[maxn];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
//		rnk[i]=1;
	}
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void add(int x){
	vis[x]=true;
	int temp;
	rnk[x]=1;
	mx=max(rnk[x],mx);
	if(vis[x-1]){
		temp=find(x-1);
		fa[temp]=x;
		rnk[x]+=rnk[temp];
		mx=max(mx,rnk[x]);
	}
	if(vis[x+1]){
		temp=find(x+1);
		fa[x]=temp;
		rnk[temp]+=rnk[x];
		mx=max(mx,rnk[temp]);
	}
}
int main(){
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	scanf("%d%d",&n,&m);
//	cout<<n<<" "<<m<<endl;
	init();
	for(int i=1;i<=n;i++){
		scanf("%lld",&f[i].num);
		f[i].id=i;
	}
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&q[i].w,&q[i].v);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp1);
	int topn=1,topm=1;
	mx=0;
	while(topn<=n&&topm<=m){
		if(f[topn].num>q[topm].w){
//			vis[f[topn].id]=true;
/*			if(vis[f[topn].id+1]&&f[topn].id+1<=n){
				temp1=find(f[topn].id),temp2=find(f[topn].id+1);
				rnk[temp1]+=rnk[temp2];
				mx=max(mx,rnk[temp1]);
				fa[temp2]=temp1;
			}
			if(vis[f[topn].id-1]&&f[topn].id-1>=1){
				temp1=find(f[topn].id),temp2=find(f[topn].id-1);
				rnk[temp2]+=rnk[temp1];
				mx=max(mx,rnk[temp2]);
				fa[temp1]=temp2;
			}*/		
			add(f[topn].id);
			topn++;	
		}
		else{
//			cout<<mx<<endl;
			if(q[topm].v>=mx+1){
				ans[q[topm].id]=1;
			}
			else{
				ans[q[topm].id]=0;
			}
			topm++;
		}
	}
	if(topm<=m){
		for(int i=topm;i<=m;i++){
			if(q[i].v>=mx+1){
				ans[q[i].id]=1;
			}
			else{
				ans[q[i].id]=0;
			}			
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
}
