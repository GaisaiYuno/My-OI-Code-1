//http://119.29.55.79/contest/80/problem/1
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
#define maxk 200000
using namespace std;
int n,k;
int sz;
struct node{
	int a;
	int b;
	int c;
	int num; 
	int cnt;
}p[maxn+5],q[maxn+5];
int top=0;
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
	int c[maxk+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void update(int pos,int val){
		for(int i=pos;i<=k;i+=lowbit(i)) c[i]+=val;
	}
	inline int query(int pos){
		int ans=0;
		for(int i=pos;i>0;i-=lowbit(i)) ans+=c[i];
		return ans; 
	}
}T;
//int num[maxn+5];
int ans[maxn+5]; 
void cdq_divide(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq_divide(l,mid);
	cdq_divide(mid+1,r);
	sort(q+l,q+1+mid,cmpb);
	sort(q+mid+1,q+1+r,cmpb);
	int ptr=l-1;
	for(int i=mid+1;i<=r;i++){
		while(ptr<mid&&q[ptr+1].b<=q[i].b){
			ptr++;
			T.update(q[ptr].c,q[ptr].cnt);
		}
		//num[i]+=T.query(q[i].c);
		q[i].num+=T.query(q[i].c);
		//num必须存在结构体里，因为排序的时候被交换 
	}
	for(int i=l;i<=ptr;i++) T.update(q[i].c,-q[i].cnt);
}
int main(){
//	freopen("3.in","r",stdin);
//	freopen("3.ans","w",stdout); 
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
	}
	sort(p+1,p+1+n,cmpa);
	for(int i=1;i<=n;i++){
		if(i<n&&p[i].a==p[i+1].a&&p[i].b==p[i+1].b&&p[i].c==p[i+1].c) top++;
		else{
			q[++sz]=p[i];
			q[sz].cnt=top+1;
			top=0;
		} 
	} 
	cdq_divide(1,sz);
	for(int i=1;i<=sz;i++){
		ans[q[i].num+q[i].cnt-1]+=q[i].cnt;
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]);
} 
