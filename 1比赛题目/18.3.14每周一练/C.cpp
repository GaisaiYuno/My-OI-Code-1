#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1025
using namespace std;
int tree[maxn<<1][maxn<<1];
int s;
void push_up(int posx,int posy){
	tree[posx][posy]=tree[posx][posy*2]+tree[posx][posy*2+1];
} 
void update_y(int to_posy,int v,int l,int r,int posx,int posy){
	//tree[posx][posy]+=v;
	if(l==r){
		tree[posx][posy]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(to_posy<=mid) update_y(to_posy,v,l,mid,posx,posy*2);
	else update_y(to_posy,v,mid+1,r,posx,posy*2+1);
	push_up(posx,posy);
}
void update_x(int to_posx,int to_posy,int v,int l,int r,int posx){
	update_y(to_posy,v,1,s,posx,1);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(to_posx<=mid) update_x(to_posx,to_posy,v,l,mid,posx*2);
	else update_x(to_posx,to_posy,v,mid+1,r,posx*2+1);
}
int query_y(int to_l,int to_r,int l,int r,int posx,int posy){
	if(to_l<=l&&to_r>=r) return tree[posx][posy];
	int mid=(l+r)>>1;
	int ans=0;
	if(to_r<=mid) ans+=query_y(to_l,to_r,l,mid,posx,posy*2);
	if(to_l>mid) ans+=query_y(to_l,to_r,mid+1,r,posx,posy*2+1);
	return ans;
}
int query_x(int to_lx,int to_rx,int to_ly,int to_ry,int l,int r,int posx){
	if(to_lx<=l&&to_rx>=r) return query_y(to_ly,to_ry,1,s,posx,1);
	int mid=(l+r)>>1;
	int ans=0;
	if(to_rx<=mid) ans+=query_x(to_lx,to_rx,to_ly,to_ry,l,mid,posx*2);
	if(to_lx>=mid) ans+=query_x (to_lx,to_rx,to_ly,to_ry,mid+1,r,posx*2);
	return ans;
	
}
int main(){
	int cmd;
	int x,y,a;
	int l,b,r,t;
	while(scanf("%d",&cmd)){
		if(cmd==3) break;
		else if(cmd==0){
			scanf("%d",&s);
			memset(tree,0,sizeof(tree));
		}
		else if(cmd==1){
			scanf("%d%d%d",&x,&y,&a);
			update_x(x,y,a,1,s,1);
		}
		else if(cmd==2){
			scanf("%d%d%d%d",&l,&b,&r,&t);
			printf("%d\n",query_x(l,r,b,y,1,s,1));
		}
	}
}
