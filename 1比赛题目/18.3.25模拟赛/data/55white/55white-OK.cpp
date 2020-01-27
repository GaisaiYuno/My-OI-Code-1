/*
用两个线段树统计[L,R]之间左端点和右端点的个数
设总区间个数为total,则ans=total-(ansl+ansr)
ansl为[L,R]之间左端点露出来的个数， 即query(1,L-1)
ansr为[L,R]之间右端点露出来的个数， 即query(r-1,m)
并且由于后插入的线段一定比之前的线段长，不会出现后插入的被前插入的包含的情况 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 200005
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

int n,m;
int k,size;
struct input_data{
	int a;
	int d;
};
input_data in[maxn];

struct Line{
	int l;
	int r;
	int newl;
	int newr;
};
Line line[maxn]; 
int dis[maxn<<1];
int bin_search(int a[],int L,int R,int x){
	int l=L,r=R;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else l=mid+1; 
	}
	return -1;
}
void discrete(){//离散化 
	sort(dis+1,dis+1+size);
	m=unique(dis+1,dis+1+size)-dis-1;
	for(int i=1;i<=k;i++){
		line[i].newl=bin_search(dis,1,m,line[i].l);
		line[i].newr=bin_search(dis,1,m,line[i].r);
		//printf("%d %d\n",line[i].newl,line[i].newr);
	}
	return;
}


struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
	}tree[maxn<<3];
	void push_up(int pos){
		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].v=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int tpos,int value,int l,int r,int pos){
		if(l==r){
			tree[pos].v+=value;
			return;
		}
		int mid=(l+r)>>1;
		if(tpos<=mid) update(tpos,value,l,mid,pos<<1);
		else update(tpos,value,mid+1,r,pos<<1|1);
		push_up(pos);
	}
	int query(int L,int R,int l,int r,int pos){
		if(L<=0||R<=0) return 0;
		if(L<=l&&R>=r){
			return tree[pos].v;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(L,R,l,mid,pos<<1);
		if(R>mid) ans+=query(L,R,mid+1,r,pos<<1|1);
		return ans;
	}  
};
segment_tree T1,T2;

void work(){
	k=0;
	int total=0;
	T1.build(1,m,1);
	T2.build(1,m,1); 
	for(int i=1;i<=n;i++){
		if(in[i].a==0){
			k++;
			total++;
			int t1=T1.query(1,line[k].newl-1,1,m,1),t2=T2.query(line[k].newr+1,m,1,m,1);
			//printf("%d %d %d\n",total,t1,t2);
			int ans=total-t1-t2-1;
			qprint(ans);
			T1.update(line[k].newl,1,1,m,1);
			T2.update(line[k].newr,1,1,m,1);
		}
		else{
			total--;
			T1.update(line[in[i].d].newl,-1,1,m,1);
			T2.update(line[in[i].d].newr,-1,1,m,1);
		}
	}
}

int main(){
	freopen("white6.in","r",stdin);
	k=size=0;
    n=qread();
  
    for(int i=1;i<=n;i++){
    	in[i].a=qread();
    	in[i].d=qread();
    	
    	if(in[i].a==0){
    		k++;
    		line[k].l=in[i].d;
    		line[k].r=k+in[i].d;
            dis[++size]=line[k].l;
            dis[++size]=line[k].r;
		}
	}
	discrete();
	work();
	return 0;
} 
/*
6
0 7
0 0
0 8
1 1
0 8
0 7
*/
