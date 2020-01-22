#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 120000 
using namespace std;
struct input{
	int x;
	int y;
	char ch;
}cmd[2005]; 
int n;
int lsh[maxn]; 
struct tree_node{
	int l;
	int r;
	int lsum;
	int rsum;
	int sum;
	int mark;
	int lsh_len(){
		return r-l+1;
	} 
	int real_len(){
	//	return lsh[r]-lsh[l]+1;
		return lsh[r]-lsh[l-1];
	}
}tree[maxn];

void push_up(int pos){
	tree[pos].lsum=tree[pos<<1].lsum;
	tree[pos].rsum=tree[pos<<1|1].rsum;
	tree[pos].sum=max(tree[pos<<1].rsum+tree[pos<<1|1].lsum,max(tree[pos<<1].sum,tree[pos<<1|1].sum));
    if(tree[pos<<1].lsum==tree[pos<<1].real_len()) tree[pos].lsum+=tree[pos<<1|1].lsum;
    if(tree[pos<<1|1].rsum==tree[pos<<1|1].real_len()) tree[pos].rsum+=tree[pos<<1].rsum;
  
  
}

void push_down(int pos){
	if(tree[pos].mark!=-1){
		tree[pos<<1].mark=tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos<<1].sum=tree[pos<<1].lsum=tree[pos<<1].rsum=tree[pos<<1].real_len()*tree[pos].mark;
		tree[pos<<1|1].sum=tree[pos<<1|1].lsum=tree[pos<<1|1].rsum=tree[pos<<1|1].real_len()*tree[pos].mark;
		

        
		tree[pos].mark=-1;
	}
}
void build(int l,int r,int pos){
	tree[pos].lsum=tree[pos].rsum=tree[pos].sum=0;
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=-1;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1); 
}
void update(int L,int R,int l,int r,int pos,int value){
	if(L<=l&&R>=r){
		tree[pos].mark=value;
		tree[pos].lsum=tree[pos].rsum=tree[pos].sum=tree[pos].real_len()*value;

		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,l,mid,pos<<1,value);
	if(R>mid) update(L,R,mid+1,r,pos<<1|1,value);
	push_up(pos); 

}
int query(int l,int r,int pos)  {  
    if(l==r)return lsh[l];  
    int mid=(l+r)>>1; 
	 push_down(pos);  
    if(tree[pos<<1].sum==tree[1].sum) return query(l,mid,pos<<1);  
    else if(tree[pos<<1].rsum+tree[pos<<1|1].lsum==tree[1].sum)return lsh[mid]-tree[pos<<1].rsum+1;  
    else return query(mid+1,r,pos<<1|1);  
}  
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




int main(){
	while(cin>>n){
		int j=1;
		for(int i=1;i<=n;i++){
			 scanf("%d %d %c",&cmd[i].x,&cmd[i].y,&cmd[i].ch);
		//	 lsh[i]=cmd[i].x;
		//	 lsh[i+n]=cmd[i].y;
			 
			 
			 
			  lsh[j++]=cmd[i].x-1;
			 lsh[j++]=cmd[i].x;
			 lsh[j++]=cmd[i].x+1;
			 lsh[j++]=cmd[i].y-1;
			 lsh[j++]=cmd[i].y;
			 lsh[j++]=cmd[i].y+1;
		} 
		sort(lsh+1,lsh+1+n*6);
	
		int m=unique(lsh+1,lsh+1+n*6)-lsh-1;
	
			
		build(1,m,1);
		for(int i=1;i<=n;i++){
			int tmp1=bin_search(lsh,1,m,cmd[i].x);
			int tmp2=bin_search(lsh,1,m,cmd[i].y);
			
	
			
			
			if(cmd[i].ch=='w') update(tmp1,tmp2,1,m,1,1);
			else update(tmp1,tmp2,1,m,1,0);
		}
		if(tree[1].sum<=0) printf("Oh, my god\n");
		else{
			int ans1=query(1,m,1);
			int ans2=ans1+tree[1].sum-1;
			printf("%d %d\n",ans1,ans2);
		}
	}
} 
