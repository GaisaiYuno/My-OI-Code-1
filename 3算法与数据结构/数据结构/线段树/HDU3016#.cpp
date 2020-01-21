#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 100005
#define INF 99999999
using namespace std;
struct board{
	int h;
	int v;
	int l,r;
}b[maxn]; 
struct tree_node{
	int value;
	int mark;
}tree[maxn*4]; 
inline int fread(){
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
int cmp(board a,board b){
	return a.h>b.h;
} 
void push_up(int pos){
	tree[pos].value=max(tree[pos*2].value,tree[pos*2+1].value);
}
void push_down(int pos){
	if(tree[pos].mark!=0){
		tree[pos*2].mark=tree[pos*2+1].mark=tree[pos].mark;
		tree[pos*2].value=tree[pos*2+1].value=tree[pos].mark;
		tree[pos].mark=0;
	}
}
void build(int l,int r,int pos){
	tree[pos].value=-INF;
	tree[pos].mark=0;
	if(l==r){
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
}
void update_point(int to_pos,int now_l,int now_r,int pos,int value){
	if(now_l==now_r){
		tree[pos].value=value;
		return;
	}
	push_down(pos); 
	int mid=(now_l+now_r)/2;
	if(to_pos<=mid) update_point(to_pos,now_l,mid,pos*2,value);
	else update_point(to_pos,mid+1,now_r,pos*2+1,value);
	push_up(pos); 
} 
void update_section(int to_l,int to_r,int now_l,int now_r,int pos,int value){
	if(to_l<=now_l&&now_r<=to_r){
		tree[pos].value=value;
		tree[pos].mark=value;
		return;
	}
	push_down(pos); 
	int mid=(now_l+now_r)/2;
	if(to_l<=mid) update_section(to_l,to_r,now_l,mid,pos*2,value);
	if(to_r>mid) update_section(to_l,to_r,mid+1,now_r,pos*2+1,value);
	push_up(pos);
}
int query(int to_l,int to_r,int now_l,int now_r,int pos){
	if(to_l<=now_l&&now_r<=to_r){
		return tree[pos].value;
	}
	push_down(pos); 
	int mid=(now_l+now_r)/2;
	int ans=-INF;
	if(to_l<=mid) ans=max(ans,query(to_l,to_r,now_l,mid,pos*2));
	if(to_r>mid) ans=max(ans,query(to_l,to_r,mid+1,now_r,pos*2+1));
	return ans;
}
int n,ans,maxl;
int main(){
	//freopen("input.txt","r",stdin);
	while(cin>>n){ 
		maxl=0;
		for(int i=1;i<=n;i++){
			b[i].h=fread();
			b[i].l=fread();
			b[i].r=fread();
			b[i].v=fread();
			maxl=max(b[i].r,maxl);
		}
		sort(b+1,b+1+n,cmp);
		build(1,maxl,1);
		update_point(b[1].l,1,maxl,1,b[1].v+100);
		update_point(b[1].r,1,maxl,1,b[1].v+100);
		for(int i=2;i<=n;i++){
			int now=query(b[i].l,b[i].r,1,maxl,1);
			update_section(b[i].l,b[i].r,1,maxl,1,-INF);//已经走过了 
			if(now>0){
				 update_point(b[i].l,1,maxl,1,now+b[i].v); 
				 update_point(b[i].r,1,maxl,1,now+b[i].v); 
			}
		}
		ans=tree[1].value;
		if(ans<=0) ans=-1;
		cout<<ans<<endl; 
	}
}
