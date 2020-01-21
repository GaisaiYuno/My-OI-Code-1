//http://119.29.55.79/contest/80/problem/2
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000000
#define maxm 2000000
using namespace std;
int n,m,cnt,qcnt;
typedef int ll;
struct node{
	int a;//x
	int b;//y
	int c;//时间戳 
	int type;//询问(2)还是修改(1) 
	int val; //如果是修改，就是修改值。如果是询问，就是当前符号 
	int id;//对应几号询问 
	ll ans; 
	node(){
		
	}
	node(int _a,int _b,int _c,int _type,int _val){
		a=_a;
		b=_b;
		c=_c;
		type=_type;
		val=_val;
		id=ans=0;
	}
	node(int _a,int _b,int _c,int _type,int _val,int _id){
		a=_a;
		b=_b;
		c=_c;
		type=_type;
		val=_val;
		id=_id;
		ans=0;
	}
}q[maxn+5];
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

struct fenwick_tree{
	ll c[maxn+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void update(int pos,int val){
		for(int i=pos;i<=maxn;i+=lowbit(i)) c[i]+=val;
	}
	inline ll query(int pos){
		int ans=0;
		for(int i=pos;i>0;i-=lowbit(i)) ans+=c[i];
		return ans; 
	}
}T;
node tmp[maxn+5];
void cdq_divide(int l,int r){
	int mid=(l+r)>>1;
	if(l==r) return;
	cdq_divide(l,mid);
	cdq_divide(mid+1,r);
//	sort(q+l,q+mid+1,cmpb);
//	sort(q+mid+1,q+1+r,cmpb);
	//这里不要大力sort,会TLE，回溯的时候合并就可以了
	int ptr=l-1;
	for(int i=mid+1;i<=r;i++){
		while(ptr<mid&&q[ptr+1].b<=q[i].b){
			ptr++;
			if(q[ptr].type==1) T.update(q[ptr].c,q[ptr].val);
		}
		if(q[i].type==2) q[i].ans+=T.query(q[i].c);
	} 
	for(int i=l;i<=ptr;i++) if(q[i].type==1) T.update(q[i].c,-q[i].val);
	int pl=l,pr=mid+1;
	int num=l-1;
	while(pl<=mid&&pr<=r){
		if(cmpb(q[pl],q[pr])) tmp[++num]=q[pl++];
		else tmp[++num]=q[pr++]; 
	}
	while(pl<=mid) tmp[++num]=q[pl++];
	while(pr<=r) tmp[++num]=q[pr++];
	for(int i=l;i<=r;i++) q[i]=tmp[i];
}

ll ans[maxn+5];
int main(){
	int cmd,x1,y1,x2,y2,v;
	scanf("%d",&n);
	while(1){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d %d %d",&x1,&y1,&v);
			m++;
			q[++cnt]=node(x1,y1,m,1,v);
		}else if(cmd==2){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			m++;
			qcnt++;
			q[++cnt]=node(x2,y2,m,2,1,qcnt);
			q[++cnt]=node(x1-1,y2,m,2,-1,qcnt);
			q[++cnt]=node(x2,y1-1,m,2,-1,qcnt);
			q[++cnt]=node(x1-1,y1-1,m,2,1,qcnt);
		}else{
			break;
		} 
	} 
	sort(q+1,q+1+cnt,cmpa);
	cdq_divide(1,cnt);
	for(int i=1;i<=cnt;i++){
		if(q[i].type==2){
			ans[q[i].id]+=q[i].val*q[i].ans;
		}
	}
	for(int i=1;i<=qcnt;i++) printf("%d\n",ans[i]);
} 
/*
4
1 2 3 3
2 1 1 3 3
1 2 2 2
2 2 2 3 4
3
*/ 
