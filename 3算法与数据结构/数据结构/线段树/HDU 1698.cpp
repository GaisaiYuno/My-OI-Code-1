#include<iostream>
#include<cstring>
#define maxn 100001
using namespace std;
int tree[maxn*4],mark[maxn*4] ;
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

void push_up(int pos){
	tree[pos]=tree[pos*2]+tree[pos*2+1];
}
void build(int l,int r,int pos){
	if(l==r){
		tree[pos]=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	push_up(pos); 
}
void push_down(int pos,int ln,int rn){
	if(mark[pos]){
		mark[pos*2]=mark[pos];
		mark[pos*2+1]=mark[pos];
		tree[pos*2]=mark[pos]*ln;
		tree[pos*2+1]=mark[pos]*rn;
		mark[pos]=0;
	}
}
void update_section(int to_l,int to_r,int value,int now_l,int now_r,int pos){
	  //("[%d,%d]+=%d now:[%d,%d] %d\n",to_l,to_r,value,now_l,now_r,pos); 
	  if(to_l<=now_l&&now_r<=to_r){
	  	 tree[pos]=value*(now_r-now_l+1);
	  	 mark[pos]=value;
	  	 return; 
	  }
	  int mid=(now_l+now_r)/2;
	  push_down(pos,mid-now_l+1,now_r-mid);
	  if(to_l<=mid) update_section(to_l,to_r,value,now_l,mid,pos*2);
	  if(to_r>mid) update_section(to_l,to_r,value,mid+1,now_r,pos*2+1);
	  push_up(pos); 
} 
int query(int to_l,int to_r,int now_l,int now_r,int pos){
	if(to_l<=now_l&&now_r<=to_r){
		return tree[pos];
	}
	int mid=(now_l+now_r)/2;
	push_down(pos,mid-now_l+1,now_r-mid); 
	int ans=0;
	if(to_l<=mid) ans=ans+query(to_l,to_r,now_l,mid,pos*2);
	if(to_r>mid) ans=ans+query(to_l,to_r,mid+1,now_r,pos*2+1);
	return ans;
} 
int t,n,q;
int main(){
	int x,y,z;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		memset(tree,0,sizeof(tree));
		memset(mark,0,sizeof(mark)); 
		n=fread();
		q=fread();
		build(1,n,1);
		while(q--){
			x=fread();
			y=fread();
			z=fread();
			update_section(x,y,z,1,n,1);
		} 
		printf("Case %d: The total value of the hook is %d.\n",cas,query(1,n,1,n,1));
	}
} 
