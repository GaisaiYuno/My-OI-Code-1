#include<iostream>
#include<cstring>
#include<cstdio> 
#define maxn 200010
using namespace std;
int tree[maxn*4];
int h,n,w;
int ans=0;
void push_up(int pos){
	tree[pos]=max(tree[pos*2],tree[pos*2+1]);
}
void update_point(int value,int l,int r,int pos){
     if(l==r){
     	tree[pos]-=value;
     	return;
	 }
	 int mid=(l+r)/2;
	 if(tree[pos*2]>=value) update_point(value,l,mid,pos*2);
	 else update_point(value,mid+1,r,pos*2+1); 
	 push_up(pos); 
} 
int query(int value,int l,int r,int pos){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(tree[pos*2]>=value) return query(value,l,mid,pos*2);
	else return query(value,mid+1,r,pos*2+1);
}
int main(){
	while(cin>>h>>w>>n){
		int size=min(h,n);
		//build(1,size,1);
		for(int i=0;i<4*maxn;i++) tree[i]=w;
		int wide=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&wide);
			if(tree[1]<wide){
			   printf("-1\n");
			} 
			else{
				printf("%d\n",query(wide,1,size,1));
				update_point(wide,1,size,1);
			}	 
			
		}
	}
	return 0;
	
} 
