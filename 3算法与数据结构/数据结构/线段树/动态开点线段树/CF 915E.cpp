#include<iostream>
#include<cstdio>
#include<cstring>
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

struct node{
	int v;
	short int mark;
	node* lson;
	node* rson;
	/*int len(){
		return r-l+1;
	}
	void display(){
		printf("[%d,%d] ",l,r);
		printf("v=%d mark=%d",v,mark);
		printf("\n");
	}
	node(){
		l=r=0;
		lson=NULL;
		rson=NULL;
		v=0;
		mark=-1;
	}*/
	node(int L,int R,int V){
		v=V;
		mark=-1;
		lson=NULL;
		rson=NULL;
	}
};
node* root=NULL;
void push_up(node* root){
	root->v=root->lson->v+root->rson->v;
}
void push_down(node* root,int ln,int rn){
	if(root->mark!=-1){
		root->lson->mark=root->mark;
		root->rson->mark=root->mark;
		root->lson->v=root->mark*ln;
		root->rson->v=root->mark*rn;
		root->mark=-1;
	}
}
void update(int L,int R,int value,node* root,int l,int r){
	//root->display();
	if(L<=l&&R>=r){
		root->v=(r-l+1)*value;
		root->mark=value;
		return;
	}
	int mid=(l+r)>>1;
	if(root->lson==NULL) root->lson=new node(l,mid,mid-l+1);
	if(root->rson==NULL) root->rson=new node(mid+1,r,r-mid);
	push_down(root,mid-l+1,r-mid);
	if(L<=mid) update(L,R,value,root->lson,l,mid);
	if(R>mid) update(L,R,value,root->rson,mid+1,r);
	push_up(root);
}
void del(node *root){
	if(root->lson!=NULL) del(root->lson);
	if(root->rson!=NULL) del(root->rson);
	delete root;
	return;
}
int n,q;
int l,r,k;
int main(){
	while(scanf("%d %d",&n,&q)!=EOF){
		root=new node(1,n,n);
		while(q--){
			l=qread();
			r=qread();
			k=qread();
			if(k==1) k=0;
			else k=1;
			update(l,r,k,root,1,n);
		    qprint(root->v);
		}
		//del(root);
	}
} 
