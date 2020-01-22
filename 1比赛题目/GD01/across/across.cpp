#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
using namespace std;
typedef long double db;
int n;
db W,U,V;
db T1,T2;
struct seg{
	db l;
	db r;
	seg(){
		
	}
	seg(db _l,db _r){
		l=_l;
		r=_r;
	}
	friend bool operator < (seg p,seg q){
		if(p.l==q.l) return p.r<q.r;
		else return p.l<q.l;
	}
}f[maxn+5],g[maxn+5];
int sz1=0,sz2=0;

int m;
int dir;
db x[maxn+5];
db L[maxn+5];
void get_seg(int id){
	for(int i=1;i<=m;i++){
		db l=(0-x[i])/(-dir*U)-id*W/V;
		db r=(0-(x[i]+dir*L[i]))/(-dir*U)-(id-1)*W/V;
		l=max(l,T1);
		r=min(r,T2);
		if(l<=r) f[++sz1]=seg(l,r);
	}
}

void merge(){//线段的并 
	sort(f+1,f+1+sz1);
	db l=T1,r=T1;
	for(int i=1;i<=sz1;i++){
		if(f[i].l<=r){//相交 
			if(f[i].r>r) r=f[i].r; //但不包含 
		}else{
			g[++sz2]=seg(l,r);
			l=f[i].l;
			r=f[i].r;
		}
	}
	g[++sz2]=seg(l,r);
	sort(g+1,g+1+sz2);
}

int main(){
//	freopen("across.in","r",stdin);
//	freopen("across.out","w",stdout);
	char ch[2];
	scanf("%d %Lf %Lf %Lf %Lf %Lf",&n,&W,&U,&V,&T1,&T2);
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		dir=(ch[0]=='W'?1:-1);
		scanf("%d",&m);
		for(int j=1;j<=m;j++) scanf("%Lf %Lf",&L[j],&x[j]);
		get_seg(i);
	}
	merge();
	db ans=0;
	ans=max(ans,g[1].l-T1);
	ans=max(ans,T2-g[sz2].r);
	for(int i=1;i<sz2;i++){
		ans=max(ans,g[i+1].l-g[i].r);
	}
	printf("%.3Lf\n",ans);
}
