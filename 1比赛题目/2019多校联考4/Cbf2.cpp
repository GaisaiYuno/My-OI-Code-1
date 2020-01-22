#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector> 
#define maxn 200000 
#define maxlogn 23
#define INF 0x3f3f3f3f
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
		putchar('0'+x%10);
	} 
}

int n,m,mv;
int a[maxn+5];
int tmp[maxn+5];
void discrete(){
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	mv=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+mv,a[i])-tmp;
} 

vector<int>pos[maxn+5]; 
struct segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxn*maxlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].val=INF;
		if(lson(x)) tree[x].val=min(tree[lson(x)].val,tree[x].val);
		if(rson(x)) tree[x].val=min(tree[rson(x)].val,tree[x].val);
	}
	void update(int &x,int pos,int val,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].val=val;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) update(lson(x),pos,val,l,mid);
		else update(rson(x),pos,val,mid+1,r); 
	}
	int query(int x,int L,int R,int l,int r){
		if(L<=l&&R>=r) return tree[x].val;
		int mid=(l+r)>>1;
		int ans=INF;
		if(L<=mid) ans=min(ans,query(lson(x),L,R,l,mid));
		if(R>mid) ans=min(ans,query(rson(x),L,R,mid+1,r));
		return ans;
	} 
}T; 
int root[maxn+5];
int query(int id,int l,int r){
	int s=lower_bound(pos[id].begin(),pos[id].end(),l)-pos[id].begin();
	int e=upper_bound(pos[id].begin(),pos[id].end(),r)-pos[id].begin()-1;
	int ans=INF;
	if(s<e) ans=min(ans,T.query(root[id],s+1,e,1,pos[id].size()));
	return ans;
}

int top=0;
int num[maxn+5]; 

int main(){
	int l,r;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	discrete();
	for(int i=1;i<=n;i++){
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=mv;i++){
		int sz=pos[i].size();
		for(int j=0;j<sz-1;j++)  T.update(root[i],j+1,pos[i][j+1]-pos[i][j],1,sz);
	}
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		top=0;
		for(int j=l;j<=r;j++) num[++top]=a[j];
		sort(num+1,num+1+top);
		top=unique(num+1,num+1+top)-num-1;
		int ans=INF;
		for(int j=1;j<=top;j++)	ans=min(ans,query(num[j],l,r));
		
		if(ans==INF) ans=-1;
		qprint(ans);
		putchar('\n');
	}
}

