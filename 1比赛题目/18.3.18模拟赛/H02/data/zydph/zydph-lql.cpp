#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005//880005
#define INF 2147483647
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
struct node{
	int l,r;
	int mark1;
	int mark2;
	int minv;
	int maxv;
	long long sum;
}tree[maxn<<2];
int a[maxn];
int n, m;
void push_up(int pos){
	tree[pos].sum=(long long)tree[pos<<1].sum+tree[pos<<1|1].sum;
	tree[pos].minv=min(tree[pos<<1].minv,tree[pos<<1|1].minv);
	tree[pos].maxv=max(tree[pos<<1].maxv,tree[pos<<1|1].maxv);
}
void build(int l,int r,int pos){
//	tree[pos].l=l;
//	tree[pos].r=r;
	tree[pos].sum=tree[pos].minv=tree[pos].maxv=0;//;
	tree[pos].mark1=tree[pos].mark2=0;
	if(l==r){
	//321	tree[pos].sum=tree[pos].minv=tree[pos].maxv=a[l];
//321		tree[pos].mark1=tree[pos].mark2=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
//321	push_up(pos);
}
void push_down(int pos,int ln,int rn){
	if(tree[pos].mark2>0){
		tree[pos<<1].mark1=tree[pos<<1|1].mark1=0;
		tree[pos<<1].mark2=tree[pos].mark2;
		tree[pos<<1|1].mark2=tree[pos].mark2;
		tree[pos<<1].sum=(long long)tree[pos].mark2*ln;
		tree[pos<<1|1].sum=(long long)tree[pos].mark2*rn;
		tree[pos<<1].maxv=tree[pos].mark2;
		tree[pos<<1|1].maxv=tree[pos].mark2;
		tree[pos<<1].minv=tree[pos].mark2;
		tree[pos<<1|1].minv=tree[pos].mark2;
		tree[pos].mark2=0;
	}
	if(tree[pos].mark1){
	//		tree[pos<<1].mark2=tree[pos<<1|1].mark2=0;
	 if(tree[pos<<1].mark2)  tree[pos<<1].mark2+=tree[pos].mark1;
	else	tree[pos<<1].mark1+=tree[pos].mark1;
	
	if(tree[pos<<1|1].mark2)  tree[pos<<1|1].mark2+=tree[pos].mark1;
	else	tree[pos<<1|1].mark1+=tree[pos].mark1;
		tree[pos<<1].sum+=(long long)tree[pos].mark1*ln;
		tree[pos<<1|1].sum+=(long long)tree[pos].mark1*rn;
		tree[pos<<1].maxv+=tree[pos].mark1;
		tree[pos<<1|1].maxv+=tree[pos].mark1;
		tree[pos<<1].minv+=tree[pos].mark1;
		tree[pos<<1|1].minv+=tree[pos].mark1;
		tree[pos].mark1=0;
	
	}
}
void update_section(int to_l,int to_r,int value,int l,int r,int pos,int upd_type,int i){
	int mid=(l+r)>>1;

	if(to_l==l&&to_r==r){
		if(upd_type==1){ //jia
		   if(tree[pos].mark2)  tree[pos].mark2+=value;
		   else 
		      tree[pos].mark1+=value;
			tree[pos].sum+=(long long)value*(r-l+1); 
			tree[pos].maxv+=value;
			tree[pos].minv+=value;
		} 
		else if(upd_type==2){
		    tree[pos].mark2=value;
		    tree[pos].mark1=0;
		    tree[pos].sum=(long long)value*(r-l+1);
		    tree[pos].minv=value;
		    tree[pos].maxv=value;
		}
		return;
	}
		push_down(pos,mid-l+1,r-mid);
	if(to_l<=mid) update_section(to_l,to_r,value,l,mid,pos<<1,upd_type,i);
	else if(to_r>mid) update_section(to_l,to_r,value,mid+1,r,pos<<1|1,upd_type,i);
	else  {
		     update_section(to_l,mid,value,l,mid,pos<<1,upd_type,i);
		     update_section(mid+1,to_r,value,mid+1,r,pos<<1|1,upd_type,i);
	}
	push_up(pos);
}
long long query(int to_l,int to_r,int l,int r,int pos,int que_type){
	if(to_l==l&&to_r==r){
		if(que_type==1) return tree[pos].sum;
		if(que_type==2) return tree[pos].minv;
		if(que_type==3) return tree[pos].maxv;
	}
//	long long ans1=0;
//	long long  ans2=INF,ans3=-INF;
	int mid=(l+r)>>1;
	push_down(pos,mid-l+1,r-mid);
	if(to_l<=mid){
	    if(que_type==1) query(to_l,to_r,l,mid,pos<<1,que_type);
	    if(que_type==2) query(to_l,to_r,l,mid,pos<<1,que_type);
	    if(que_type==3) query(to_l,to_r,l,mid,pos<<1,que_type);
	}
   else	if(to_r>mid){
		if(que_type==1) query(to_l,to_r,mid+1,r,pos<<1|1,que_type);
	    if(que_type==2) query(to_l,to_r,mid+1,r,pos<<1|1,que_type);
	    if(que_type==3) query(to_l,to_r,mid+1,r,pos<<1|1,que_type);
	}
	else {
		if(que_type==1) return query(to_l,mid,l,mid,pos<<1,que_type)+query(mid+1,to_r,mid+1,r,pos<<1|1,que_type);
	    if(que_type==2) return min((int)query(to_l,mid,l,mid,pos<<1,que_type),(int)query(mid+1,to_r,mid+1,r,pos<<1|1,que_type));
	    if(que_type==3) return max((int)query(to_l,mid,l,mid,pos<<1,que_type),(int)query(mid+1,to_r,mid+1,r,pos<<1|1,que_type));
	}
	
//	if(que_type==1) return ans1;
//	if(que_type==2) return (long long)ans2;
//	if(que_type==3) return (long long)ans3;
}



int main(){
	//freopen("zydph.in","r",stdin);
	//freopen("zydph.out","w",stdout);
	//printf("%.2fMB\n",(double)(sizeof(tree)+sizeof(a))/1024/1024);
	int c,dir,ql,qr,v;
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++) a[i]=qread();
	build(1,n,1);
	for(int i=1;i<=m;i++){
		c=qread();
		if(c==1){
			dir=qread();
			ql=qread();
			qr=qread();
			printf("%lld\n",query(ql,qr,1,n,1,dir));
		}
		else if(c==2){
			dir=qread();
			ql=qread();
			qr=qread();
			v=qread();
			update_section(ql,qr,v,1,n,1,dir,i);
		}
	}
	return 0; 
}
