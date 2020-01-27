#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100000
#define INF 0x3f3f3f3f
#define inf 1e18
#define eps 1e-7
using namespace std;
typedef long long ll;
int n;
int a[maxn+5],d[maxn+5];//d[i]=a[i]-i
int dis_d[maxn+5];//离散化后的d，用于求LIS 
int b[maxn+5];
int lis[maxn+5];//以i结尾的LIS长度 
int discrete(int *a,int *b,int n){
	static int t[maxn+5];
	int sz;
	for(int i=1;i<=n;i++) t[i]=a[i];
	sort(t+1,t+1+n);
	sz=unique(t+1,t+1+n)-t-1;
	for(int i=1;i<=n;i++){
		b[i]=lower_bound(t+1,t+1+sz,a[i])-t;
	}
	return sz;
}

struct fenwick_tree{//树状数组维护Lis数组前缀最大值 
	int sz;
	int c[maxn+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void update(int x,int v){
		for(int i=x;i<=sz;i+=lowbit(i)) c[i]=max(c[i],v); 
	}
	inline int query(int x){
		int ans=-INF;
		for(int i=x;i>0;i-=lowbit(i)) ans=max(ans,c[i]);
		return ans; 
	}
	void ini(int n){
		sz=n;
		for(int i=1;i<=n;i++) c[i]=-INF;
	}
}T;
int get_lis(){
	int dn=discrete(d,dis_d,n+1);
	T.ini(dn);
	T.update(dis_d[n+1],0);
	for(int i=1;i<=n;i++){
		lis[i]=T.query(dis_d[i])+1;
		T.update(dis_d[i],lis[i]);
	}	
	return T.query(dn);
}


struct node{
	int id;
	ll x;
	ll y;
	int f;
	node(){
		
	}
	node(int _id,ll _x,ll _y,int _f){
		id=_id;
		x=_x;
		y=_y;
		f=_f;
	}

}p[maxn+5];
int head,tail;
node tmp[maxn+5]; 
node q[maxn+5];
node ldp[maxn+5],rdp[maxn+5];
ll dp[maxn+5];
bool cmp1(node p,node q){
	return p.id<q.id;//斜率为i
}
bool cmp2(node p,node q){
	if(p.x==q.x) return p.y<q.y;
	else return p.x<q.x;
}
inline ll get_x(int j){
	return -d[j];
}
inline ll get_y(int j){
	return dp[j]-(ll)j*(j+1)/2-(ll)(j+1)*a[j]; 
}
inline double slope(node p,node q){
	double dx=p.x-q.x;
	double dy=p.y-q.y;
	if(fabs(dx)<eps) return inf;
	else return dy/dx;
}


void cdq_divide(int l,int r){
	if(l==r){
		p[l].x=get_x(p[l].id);
		p[l].y=get_y(p[l].id);
		return;
	}
	int mid=(l+r)>>1;
	int pl=0,pr=0;
	cdq_divide(l,mid);
	for(int i=l;i<=mid;i++) if(p[i].f==0) ldp[++pl]=p[i];
	for(int i=mid+1;i<=r;i++) if(p[i].f==1) rdp[++pr]=p[i];
	int head=1,tail=0;
	for(int i=1;i<=pl;i++){
		while(head<tail&&slope(ldp[i],q[tail])<=slope(q[tail],q[tail-1])) tail--;
		q[++tail]=p[i];
	}
	for(int t=1;t<=pr;t++){
		int i=rdp[t].id;
		while(head<tail&&slope(q[head],q[head+1])<=i) head++;
		int j=q[head].id;
		dp[i]=min(dp[i],dp[j]+(ll)a[j]*(i-j-1)+(ll)(i-j-1)*(i-j)/2+a[i]+b[i]);
	}
	cdq_divide(mid+1,r);
	
	int num=l;
	pl=l,pr=mid+1;
	while(pl<=mid&&pr<=r){
		if(cmp2(p[pl],p[pr])) tmp[num++]=p[pl++];
		else tmp[num++]=p[pr++];
	}
	while(pl<=mid) tmp[num++]=p[pl++];
	while(pr<=r) tmp[num++]=p[pr++];
	for(int i=l;i<=r;i++) p[i]=tmp[i];
}

int pos[maxn+5];
bool cmp3(int x,int y){
	return lis[x]<lis[y];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) d[i]=a[i]-i;//单调递增->单调不下降 
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int len=get_lis();
	printf("%d ",len);
	
	for(int i=1;i<=n;i++) pos[i]=i;
	sort(pos+1,pos+1+n,cmp3);
	int p1=0,p2=0,p3=0;
	
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	//0如何处理??? 
	for(int i=1;i<len;i++){
		p1=p2+1;
		while(lis[pos[p2+1]]==i&&p2<n) p2++;
		p3=p2;
		while(lis[pos[p3+1]]==i+1&&p3<n) p3++;
		int sz=0;
		for(int j=p1;j<=p3;j++){
			p[++sz]=node(pos[j],0,0,lis[pos[j]]==i+1);
		}
		sort(p+1,p+1+sz,cmp1);
		cdq_divide(0,sz);
	}
	ll ans=inf;
	for(int i=1;i<=n;i++) ans=min(ans,dp[i]);
	printf("%lld\n",ans);
}
