#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 100005
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
}


struct node{
	int l;
	int r;
	int v;
}tree[maxn*4];



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
		if(L<=l&&R>=r) return tree[pos].v;
	int ans=0;
	int mid=(l+r)>>1;
	if(L<=mid) ans+=query(L,R,l,mid,pos<<1);
	if(R>mid) ans+=query(L,R,mid+1,r,pos<<1|1);
	return ans;
}

struct like{
	int x;
	int y;
	int id; 
}a[maxn];
int ans[maxn];
bool cmp(like p,like q){
	if(p.y!=q.y){
		return p.y>q.y;
	}
	else return p.x<q.x;
} 
int n;
int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		memset(ans,0,sizeof(ans));
	//	  for (int i = 1; i <= n * 4; i++)  
       //    tree[i].v = 0;  
           
		for(int i=1;i<=n;i++){
			a[i].x=qread()+1;
			a[i].y=qread()+1;
			a[i].id=i;
					
		}
		sort(a+1,a+1+n,cmp);
		int x,y,id;
	//	update(1,1,1,n,1);
		build(1,n,1);
   
	  
	
		for(int i=1;i<=n;i++){
			x=a[i].x;
			y=a[i].y;
			id=a[i].id;
			if(i>1&&x==a[i-1].x&&y==a[i-1].y) ans[id]=ans[a[i-1].id];
			else ans[id]=query(1,x,1,n,1);
			//printf("[1,%d]=%d",x,query(1,x,1,n,1));
			update(x,1,1,n,1);
			//printf("  %d=1\n",x);
		}
		for(int i=1;i<=n;i++){
			qprint(ans[i]);
			if(i==n) printf("\n");
			else printf(" "); 
	
		}
	}
} 
