//http://119.29.55.79/contest/80/problem/4
//分类讨论上下左右四种情况
//通过翻转坐标全部变成左下的情况
//min(x-x'+y-y')=x+y-max(x'+y') 
//转化成三维偏序查最大值: x,y,时间都小的最大值 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000000
#define INF 0x3f3f3f3f
#define  register 
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	x=x*sign; 
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10); 
		putchar(x%10+'0');
	}
} 
int n,m,cnt,qcnt;
struct node{
	int a;
	int b;
	int c;
	int type;
	int id;
	int ans;
	node(){
		
	}
	node(int _a,int _b,int _c,int _type){
		a=_a;
		b=_b;
		c=_c;
		type=_type;
		id=0;
		ans=-INF;
	}
	node(int _a,int _b,int _c,int _type,int _id){
		a=_a;
		b=_b;
		c=_c;
		type=_type;
		id=_id;
		ans=-INF;
	}
};
node q[maxn+5],dat[maxn+5];//dat保存翻转前的变量 
int cmpa(node p,node q){
	if(p.a==q.a){
		if(p.b==q.b) return p.c<q.c;
		else return p.b<q.b;
	}else return p.a<q.a;
}
int cmpb(node p,node q){
	if(p.b==q.b) return p.c<q.c;
	else return p.b<q.b;
}

struct fenwick_tree{//树状数组可以维护前缀最大值，且常数小 
	int c[maxn+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void update(int pos,int val){
		for(int i=pos;i<=cnt;i+=lowbit(i)) c[i]=max(c[i],val);
	}
	inline void clear(int pos){
		for(int i=pos;i<=cnt;i+=lowbit(i)) c[i]=-INF;
	}
	inline int query(int pos){
		int ans=-INF;
		for( int i=pos;i>0;i-=lowbit(i)) ans=max(ans,c[i]);
		return ans;
	}
}T;
node tmp[maxn+5];
void cdq_divide(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq_divide(l,mid);
	cdq_divide(mid+1,r);
	 int ptr=l-1;
	for(int i=mid+1;i<=r;i++){
		if(q[i].type==2){//这样写有玄学优化作用，原因未知. 
			while(ptr<mid&&q[ptr+1].b<=q[i].b){ 
				ptr++;
				if(q[ptr].type==1) T.update(q[ptr].c,q[ptr].a+q[ptr].b);
			}
			q[i].ans=max(q[i].ans,T.query(q[i].c));
		}
	
	} 
	for(int i=l;i<=ptr;i++) if(q[i].type==1) T.clear(q[i].c);
	int num=l-1;
	int pl=l,pr=mid+1;
	while(pl<=mid&&pr<=r){
		if(cmpb(q[pl],q[pr])) tmp[++num]=q[pl++];
		else tmp[++num]=q[pr++];
	}
	while(pl<=mid) tmp[++num]=q[pl++];
	while(pr<=r) tmp[++num]=q[pr++];
	for(int i=l;i<=r;i++) q[i]=tmp[i];
}

int res[maxn+5];
int main(){
	int t,x,y;
	int maxx,maxy,minx,miny;
	maxx=maxy=-INF;
	minx=miny=INF;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(x);
		qread(y);
		cnt++;
		q[cnt]=node(x,y,cnt,1);
		maxx=max(maxx,x);
		minx=min(minx,x);
		maxy=max(maxy,y);
		miny=min(miny,y);
	} 
	for(int i=1;i<=m;i++){
		qread(t);
		qread(x);
		qread(y);
		if(t==1){
			cnt++;
			q[cnt]=node(x,y,cnt,1);
		}else{
			cnt++;
			qcnt++;
			q[cnt]=node(x,y,cnt,2,qcnt);
		}
		maxx=max(maxx,x);
		minx=min(minx,x);
		maxy=max(maxy,y);
		miny=min(miny,y);
	}
	for(int i=1;i<=cnt;i++) dat[i]=q[i];
	
	for(int i=1;i<=qcnt;i++) res[i]=INF;
	for(int i=1;i<=cnt;i++) T.c[i]=-INF;
	
	sort(q+1,q+1+cnt,cmpa);//左下 
	cdq_divide(1,cnt);
	for(int i=1;i<=cnt;i++){
		if(q[i].type==2) res[q[i].id]=min(res[q[i].id],q[i].a+q[i].b-q[i].ans);
	} 
	
	for(int i=1;i<=cnt;i++){//右下 
		q[i]=dat[i];
		q[i].a=2*maxx-q[i].a;
	}
	sort(q+1,q+1+cnt,cmpa);
	cdq_divide(1,cnt);
	for(int i=1;i<=cnt;i++){
		if(q[i].type==2) res[q[i].id]=min(res[q[i].id],q[i].a+q[i].b-q[i].ans);
	} 
	
	for(int i=1;i<=cnt;i++){//左上 
		q[i]=dat[i];
		q[i].b=2*maxy-q[i].b;
	}
	sort(q+1,q+1+cnt,cmpa);
	cdq_divide(1,cnt);
	for(int i=1;i<=cnt;i++){
		if(q[i].type==2) res[q[i].id]=min(res[q[i].id],q[i].a+q[i].b-q[i].ans);
	} 
	
	for(int i=1;i<=cnt;i++){//右上 
		q[i]=dat[i];
		q[i].a=2*maxx-q[i].a; 
		q[i].b=2*miny-q[i].b;
	}
	sort(q+1,q+1+cnt,cmpa);
	cdq_divide(1,cnt);
	for(int i=1;i<=cnt;i++){
		if(q[i].type==2) res[q[i].id]=min(res[q[i].id],q[i].a+q[i].b-q[i].ans);
	} 
	
	for(int i=1;i<=qcnt;i++){
		qprint(res[i]);
		putchar('\n');
	}
} 
