#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500100;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct cqz{int i,x,y;}q[N];
inline bool operator<(cqz i,cqz j){
	if(i.x!=j.x)return i.x<j.x;
	if(i.i!=j.i)return i.i<j.i;
	if(i.y!=j.y)return i.y>j.y;
	return 0;
}
struct data{int x,*y;}R[N];
inline bool operator<(data i,data j){return i.x<j.x;}
inline bool operator!=(data i,data j){return i.x!=j.x;}
int n,Q,m,sm,ans[N];
int tr[N*4],mx[N*4];
inline int max(int x,int y){return x>y?x:y;}
void add(int i,int l,int r,int x,int k){
	if(l==r){
		tr[i]+=k;mx[i]=tr[i]?l:0;
		return;
	}int md=(l+r)>>1,ls=i<<1,rs=ls|1;
	if(x<=md)add(ls,l,md,x,k);
	else add(rs,md+1,r,x,k);
	tr[i]=tr[ls]+tr[rs];
	mx[i]=max(mx[ls],mx[rs]);
}
int get(int i,int l,int r,int x,int y,int k){
	if(l>=x&&r<=y)return k?tr[i]:mx[i];
	int md=(l+r)>>1,ls=i<<1,rs=ls|1,res=0,s;
	if(x<=md){
		s=get(ls,l,md,x,y,k);
		k?res+=s:res=max(res,s);
	}if(y>md){
		s=get(rs,md+1,r,x,y,k);
		k?res+=s:res=max(res,s);
	}return res;
}
int main(){
	freopen("tao.in","r",stdin);
	freopen("tao.out","w",stdout);
	int i;
	n=read();Q=n+read();
	for(i=1;i<=Q;i++){
		R[i]=(data){read(),&q[i].y};
		q[i].x=read();if(i>n)q[i].i=i-n;
	}
	sort(R+1,R+Q+1);sm=2;
	for(i=1;i<=Q;i++)
	*R[i].y=sm,sm+=R[i+1]!=R[i];
	sort(q+1,q+Q+1);
	for(i=1;i<=Q;i++)
	if(q[i].i)ans[q[i].i]=get(1,1,sm,q[i].y,sm,1);
	else{
		int x=get(1,1,sm,1,q[i].y-1,0);
		if(x>0)add(1,1,sm,x,-1);
		add(1,1,sm,q[i].y,1);
	}Q=Q-n;
	for(i=1;i<=Q;i++)printf("%d\n",ans[i]);
	return 0;
}