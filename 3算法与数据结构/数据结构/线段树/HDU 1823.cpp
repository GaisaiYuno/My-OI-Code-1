#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 1000
using namespace std;
double tree[(maxn+5)<<2][(maxn+5)<<2];
void push_up_x(int pos1,int pos2){
	tree[pos1][pos2]=max(tree[pos1<<1][pos2],tree[pos1<<1|1][pos2]);
}
void push_up_y(int pos1,int pos2){
	tree[pos1][pos2]=max(tree[pos1][pos2<<1],tree[pos1][pos2<<1|1]);
}
void build_y(int l,int r,int pos1,int pos2){
	tree[pos1][pos2]=-1.0;
	if(l==r){
	    return;
	} 
	int mid=(l+r)>>1;
	build_y(l,mid,pos1,pos2<<1);
	build_y(mid+1,r,pos1,pos2<<1|1);
}
void build_x(int l,int r,int pos){
	build_y(0,maxn,pos,1);
	if(l==r) return;
	int mid=(l+r)>>1;
	build_x(l,mid,pos<<1);
	build_x(mid+1,r,pos<<1|1);
} 
void update_y(int to_pos,double v,int l,int r,int pos1,int pos2){
	tree[pos1][pos2]=max(tree[pos1][pos2],v);
	if(l==r){
		return; 
	}
	int mid=(l+r)>>1;
	if(to_pos<=mid) update_y(to_pos,v,l,mid,pos1,pos2<<1);
	else  update_y(to_pos,v,mid+1,r,pos1,pos2<<1|1);
	push_up_y(pos1,pos2);
}
void update_x(int to_posx,int to_posy,double v,int l,int r,int pos){
	update_y(to_posy,v,1,maxn,pos,1);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(to_posx<=mid) update_x(to_posx,to_posy,v,l,mid,pos<<1);
	else update_x(to_posx,to_posy,v,mid+1,r,pos<<1|1);
}
double query_y(int to_l,int to_r,int l,int r,int pos1,int pos2){
	if(to_l<=l&&to_r>=r) return tree[pos1][pos2];
	int mid=(l+r)>>1;
	if(to_r<=mid) return query_y(to_l,to_r,l,mid,pos1,pos2<<1);
	else if(to_l>mid) return query_y(to_l,to_r,mid+1,r,pos1,pos2<<1|1);
	else return max(query_y(to_l,to_r,l,mid,pos1,pos2<<1),query_y(to_l,to_r,mid+1,r,pos1,pos2<<1|1));
}
double query_x(int h1,int h2,int to_l,int to_r,int l,int r,int pos){
	if(h1<=l&&h2>=r) return query_y(to_l,to_r,1,maxn,pos,1);
	int mid=(l+r)>>1;
	if(h2<=mid) return query_x(h1,h2,to_l,to_r,l,mid,pos<<1);
	else if(h1>mid) return query_x(h1,h2,to_l,to_r,mid+1,r,pos<<1|1);
	else return max(query_x(h1,h2,to_l,to_r,l,mid,pos<<1),query_x(h1,h2,to_l,to_r,mid+1,r,pos<<1|1));
} 
int t; 
char cmd;
int main(){
    while(cin>>t&&t!=0){
    	build_x(100,200,1); 
    	while(t--){   		
    		cin>>cmd;
    		if(cmd=='I'){
    			int h;
    			double x,y;
				cin>>h>>x>>y;
				update_x(h,(int)(x*10),y,100,200,1); 
			}else{
				int h1,h2;
				double x1,x2;
				int x1i,x2i;
				cin>>h1>>h2>>x1>>x2;
				x1i=(int)(x1*10);
				x2i=(int)(x2*10);
				if(h1>h2){int tmp=h1;h1=h2;h2=tmp;} 
				if(x1i>x2i){int tmp=x1i;x1i=x2i;x2i=tmp;}
				double ans=query_x(h1,h2,x1i,x2i,100,200,1); 
				if(ans==-1.0) cout<<"-1"<<endl;
				else printf("%.1f\n",ans);
			}
		}
	}
} 

