#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
inline void qprint(int x){
	char ch[32];
	int k=0;
	if(x==0){
		putchar('0');
		putchar('\n');
		return;
	}
	if(x<0){
		putchar('-');
		x=-x;
	} 
	while(x>0){
		ch[k++]='0'+x%10;
		x/=10;
	} 
	for(int i=k-1;i>=0;i--) putchar(ch[i]);
	putchar('\n');
}
struct cmd{
	int l;
	int r;
	int newl;
	int newr;
	int k;
}input[maxn];
int dis[maxn*6]; 
int bin_search(int *a,int L,int R,int x){
	int l=L,r=R;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else l=mid+1; 
	}
	return -1;
}
struct node{
	int l;
	int r;
	int mark;
	int v;
	int reallen(){
		if(l!=0) return dis[r]-dis[l-1];
		else return dis[r]-dis[l]+1;
	}
	void display(){
		printf("[%d,%d] mark=%d v=%d\n",l,r,mark,v);
	}
}tree[maxn*24];
void push_up(int pos){
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=-1;
	if(l==r){
		tree[pos].v=0; 
	    return;
	} 
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1); 
	push_up(pos);
}
void push_down(int pos){
	if(tree[pos].mark!=-1){
		tree[pos<<1].mark=tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos<<1].v=tree[pos].mark*tree[pos<<1].reallen();
		tree[pos<<1|1].v=tree[pos].mark*tree[pos<<1|1].reallen();
		tree[pos].mark=-1; 
	}
}
void update(int L,int R,int l,int r,int pos,int value){
	//tree[pos].display();
	if(L<=l&&R>=r){
		tree[pos].mark=value;
		tree[pos].v=tree[pos].reallen()*value;
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,l,mid,pos<<1,value);
	if(R>mid) update(L,R,mid+1,r,pos<<1|1,value);
	push_up(pos);
}
int n,q;
int size;
int main(){
	int l,r,k;
	while(scanf("%d %d",&n,&q)!=EOF){
		size=0;
		for(int i=1;i<=q;i++){
			l=qread();
			r=qread();
			k=qread();
			input[i].l=l;
			input[i].r=r;
			input[i].k=k%2;
			if(l-1>=0)dis[++size]=l-1;
			dis[++size]=l;
			dis[++size]=l+1;
			if(r-1>=0) dis[++size]=r-1;
			dis[++size]=r;
			dis[++size]=r+1; 
		}
		//printf("%d\n",size);
		sort(dis+1,dis+1+size);
		size=unique(dis+1,dis+1+size)-dis-1; 
		//printf("%d\n",size);
		build(1,size,1);
		//printf("%d\n",tree[1].v);
		//for(int i=1;i<=size;i++) printf("%d ",dis[i]);
		//printf("\n"); 
		for(int i=1;i<=q;i++){
			input[i].newl=bin_search(dis,1,size,input[i].l);
			input[i].newr=bin_search(dis,1,size,input[i].r);
			//printf("[%d %d]->[%d %d] %d\n",input[i].l,input[i].r,input[i].newl,input[i].newr,input[i].k);
			//printf("%d\n",size); 
			update(input[i].newl,input[i].newr,1,size,1,input[i].k);
			qprint(n-tree[1].v);
		}
		//del(root);
	}
}
