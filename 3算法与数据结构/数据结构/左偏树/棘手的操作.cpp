//http://hzwer.com/5780.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define maxn 300005
using namespace std;
int n,q;
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
	x*=sign; 
}
inline void qread(long long &x){
	x=0;
	long long sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign; 
}
inline void qprint(long long x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

multiset<long long>S;
struct left_tree{
	int l[maxn];
	int r[maxn];
	int fa[maxn];
	int dist[maxn];
	long long v[maxn];
	long long tag[maxn];
	int cnt=0;
	void New(long long val){
		v[++cnt]=val;
	}
	int findrt(int x){
//		printf("findrt : %d\n",x);
		while(fa[x]) x=fa[x];
		return x;
	}
	void add_tag(int x,long long d){
		if(x==0) return;
		v[x]+=d;
		tag[x]+=d;
	}
	void push_down(int x){
		add_tag(l[x],tag[x]);
		add_tag(r[x],tag[x]);
		tag[x]=0;
	} 
	 
	int sta[maxn];
	void push_down_anc(int x){
		int tp=0;
		while(x!=0){
			sta[++tp]=x;
			x=fa[x];
		}
		for(int i=tp;i>=1;i--){
			push_down(sta[i]);
		}
	}
	int _merge(int x,int y){
		if(!x||!y) return x+y;
		if(v[x]<v[y]) swap(x,y);
		push_down(x);
		push_down(y);
		r[x]=_merge(r[x],y);
		fa[r[x]]=x;
		if(dist[l[x]]<dist[r[x]]) swap(l[x],r[x]);
		dist[x]=dist[r[x]]+1;
		return x;
	}
	int del(int x){
		fa[l[x]]=0;
		fa[r[x]]=0;
		push_down_anc(x);
		int f=fa[x];
		int t=_merge(l[x],r[x]);
		if(x==l[f]) l[f]=t;
		else r[f]=t;
		return t;
	}
//	void insert(int x,long long val){
//		fa[x]=0;
//		l[x]=r[x]=0;
//		tag[x]=0;
//		v[x]=val;
//	}
	long long top(int x){
//		printf("topok\n");
		int t=findrt(x);
//		printf("findok %d %d\n",t,v[2]);
		return v[t];
	}
	
	void update_point(int x,long long d){
		push_down_anc(x);
		int rt=del(x);
		v[x]+=d;
		_merge(x,rt);
	}
	
	void update_heap(int x,long long d){
		int p=findrt(x);
		add_tag(p,d);
	}
	
	long long get_v(int x){
		push_down_anc(x);
		return v[x];
	}
}T;
long long all;
inline void work_A1(int x,long long v){
	long long topv=T.top(x);
	S.erase(S.lower_bound(topv));
	T.update_point(x,v);
	topv=T.top(x);
//	printf("heapok\n");
	S.insert(topv);
}
inline void work_A2(int x,long long v){
	int p=T.findrt(x);
	long long topv=T.top(p);
	S.erase(S.lower_bound(topv));
	T.update_heap(p,v);
	topv=T.top(p);
//	printf("heapok\n");
	S.insert(topv);
}
inline void work_A3(long long v){
	all+=v;
}
inline void work_U(int x,int y){
	if(T.findrt(x)==T.findrt(y)) return;
	int vx=T.top(T.findrt(x));
	int vy=T.top(T.findrt(y));
	if(vx<vy) S.erase(S.lower_bound(vx));
	else S.erase(S.lower_bound(vy));
	T._merge(x,y);
}
inline long long work_F1(int x){
	return T.get_v(x)+all;
}
inline long long work_F2(int x){
	int p=T.findrt(x);
	return T.top(p)+all;
}
inline long long work_F3(){
	return *(--S.end())+all;
}

char op[3];
long long a[maxn];
int main(){
#ifdef FILE_IO
	freopen("input.txt","r",stdin);
	freopen("myans.txt","w",stdout); 
#endif
	int x,y;
	long long v;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i]);
	}
	for(int i=1;i<=n;i++){
		T.New(a[i]);
		S.insert(a[i]);
	}
	qread(q);
	for(int i=1;i<=q;i++){
		scanf("%s",op);
		if(op[0]=='A'){
			if(op[1]=='1'){
				qread(x);
				qread(v);
				work_A1(x,v);
			}else if(op[1]=='2'){
				qread(x);
				qread(v);
				work_A2(x,v);
			}else{
				qread(v);
				work_A3(v);
			}
		}else if(op[0]=='F'){
			if(op[1]=='1'){
				qread(x);
				qprint(work_F1(x));
				putchar('\n');
			}else if(op[1]=='2'){
				qread(x);
				qprint(work_F2(x));
				putchar('\n');
			}else{
				qprint(work_F3());
				putchar('\n');
			}
		}else{
			qread(x);
			qread(y);
			work_U(x,y);
		}
	}
}
