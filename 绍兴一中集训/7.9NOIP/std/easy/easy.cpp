#include<cstdio>
#include<cstring>
#include<iostream>

#define fi first
#define se second
#define nn 400010
#define mk make_pair
using namespace std;

inline int Read(){
	char c=getchar();int num=0,f=1;
	while ('0'>c||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0'<=c&&c<='9') num=num*10+c-'0',c=getchar();
	return(num*f);
}

int n,m,a[nn];
struct Th{int nm,l,r;};
struct Node{pair<int,int> mxl,mxr,mnl,mnr;Th mn,mx;int sum,rv;}t[nn*4];
inline Th max(Th a,Th b) {if(a.nm>b.nm)return(a);return(b);}
inline Th min(Th a,Th b) {if(a.nm<b.nm)return(a);return(b);}
inline Node Meg(Node L,Node R){
	Node res;res.rv=0;
	res.mxl=max(L.mxl,mk(L.sum+R.mxl.fi,R.mxl.se));
	res.mxr=max(R.mxr,mk(R.sum+L.mxr.fi,L.mxr.se));
	res.mx=max(L.mx,R.mx);res.mx=max(res.mx,(Th){L.mxr.fi+R.mxl.fi,L.mxr.se,R.mxl.se});
	
	res.mnl=min(L.mnl,mk(L.sum+R.mnl.fi,R.mnl.se));
	res.mnr=min(R.mnr,mk(R.sum+L.mnr.fi,L.mnr.se));
	res.mn=min(L.mn,R.mn);res.mn=min(res.mn,(Th){L.mnr.fi+R.mnl.fi,L.mnr.se,R.mnl.se});
	res.sum=L.sum+R.sum;
	return(res);
}
inline void Rev(Node &x){
	swap(x.mxl,x.mnl),swap(x.mxr,x.mnr),swap(x.mx,x.mn);
	x.mxl.fi*=-1,x.mxr.fi*=-1,x.mx.nm*=-1;
	x.mnl.fi*=-1,x.mnr.fi*=-1,x.mn.nm*=-1;
	x.sum*=-1,x.rv^=1;
}
inline void Down(int x){
	if (!t[x].rv) return;
	Rev(t[x*2]),Rev(t[x*2+1]),t[x].rv^=1;
}

inline void Build(int x,int l,int r){
	int md=(l+r)/2;
	if (l==r){
		t[x].mxl=t[x].mxr=mk(a[l],l);
		t[x].mnl=t[x].mnr=mk(a[l],l);
		t[x].mn=t[x].mx=(Th){a[l],l,l};
		t[x].sum=a[l];return;
	}
	Build(x*2,l,md);
	Build(x*2+1,md+1,r);
	t[x]=Meg(t[x*2],t[x*2+1]);
}

inline void Chg(int x,int l,int r,int a,int b){
	int md=(l+r)/2;
	if (l==r){
		t[x].mxl=t[x].mxr=mk(b,a);
		t[x].mnl=t[x].mnr=mk(b,a);
		t[x].mn=t[x].mx=(Th){b,a,a};
		t[x].sum=b;return;
	}
	Down(x);
	if (a<=md) Chg(x*2,l,md,a,b);
	if (md<a) Chg(x*2+1,md+1,r,a,b);
	t[x]=Meg(t[x*2],t[x*2+1]);
}
inline void Rol(int x,int l,int r,int a,int b){
	int md=(l+r)/2;
	if (l==a&&r==b) {Rev(t[x]);return;}
	Down(x);
	if (b<=md) Rol(x*2,l,md,a,b);
	if (md<a) Rol(x*2+1,md+1,r,a,b);
	if (a<=md&&md<b){
		Rol(x*2,l,md,a,md);
		Rol(x*2+1,md+1,r,md+1,b);
	}
	t[x]=Meg(t[x*2],t[x*2+1]);
}

inline Node Ask(int x,int l,int r,int a,int b){
	int md=(l+r)/2;
	if (l==a&&r==b) return(t[x]);
	if (b<=md) return(Ask(x*2,l,md,a,b));
	if (md<a) return(Ask(x*2+1,md+1,r,a,b));
	if (a<=md&&md<b){
		Node L=Ask(x*2,l,md,a,md);
		Node R=Ask(x*2+1,md+1,r,md+1,b);
		return(Meg(L,R));
	}
}

pair<int,int> s[nn];int tot,ans;
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	
	n=Read();
	for (int i=1;i<=n;i++) a[i]=Read();
	Build(1,1,n);
	m=Read();
	for (int i=1;i<=m;i++){
		int op=Read(),x,y,z;
		if (!op) x=Read(),y=Read(),Chg(1,1,n,x,y);
		else{
			ans=tot=0;
			x=Read(),y=Read(),z=Read();
			for (int j=1;j<=z;j++){
				Node res=Ask(1,1,n,x,y);
				if (res.mx.nm<0) break;
				s[++tot]=mk(res.mx.l,res.mx.r);
				ans+=res.mx.nm;
				Rol(1,1,n,res.mx.l,res.mx.r);
			}
			printf("%d\n",ans);
			for (int j=1;j<=tot;j++)
			Rol(1,1,n,s[j].fi,s[j].se);
		}
	}
}
/*
考虑用费用流解决子问题:
S->i(1,0)  i->i+1(1,a[i])  i->K(1,0)  K->T(1,0)跑最大费用流即可
模拟最大费用流的步骤:找出最大的一段,取反后继续找
有线段树模拟即可 
*/
