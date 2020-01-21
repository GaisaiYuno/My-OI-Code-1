#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 2005
using namespace std;
struct line{
	double l,r,h;
	int d;
	line(void){
		l=r=h=d=0;
	} 
	line(double l1,double r1,double h1,int d1){
		l=l1;
		r=r1;
		h=h1;
		d=d1;
	}
	friend bool operator < (line x,line y){
		return x.h<y.h;
	}
};
line a[maxn];
double all[maxn*4];
struct tree_node{
	int l;
	int r;
	int cnt;
	double sum;
}tree[maxn*4];
void push_up(int pos){
	if(tree[pos].cnt!=0){
		tree[pos].sum=all[tree[pos].r+1]-all[tree[pos].l];
	}else if(tree[pos].l==tree[pos].r){
		tree[pos].sum=0; 
	}else{
		tree[pos].sum=tree[pos*2].sum+tree[pos*2+1].sum;
	}
}
void build(int l,int r,int pos){
     tree[pos].l=l;
     tree[pos].r=r;
     tree[pos].cnt=tree[pos].sum=0;
     if(l==r) return;
     int mid=(l+r)/2;
     build(l,mid,pos*2);
     build(mid+1,r,pos*2+1);
}
void update(int L,int R,int l,int r,int pos,int v){
	if(L<=l&&R>=r){
		tree[pos].cnt+=v;
		push_up(pos);
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid) update(L,R,l,mid,pos*2,v);
	if(R>mid)  update(L,R,mid+1,r,pos*2+1,v);
	push_up(pos);
}
int n;
int main(){
	int cas=0;
	while(cin>>n&&n!=0){
		for(int i=1;i<=n;i++){
			double x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			a[i]=line(x1,x2,y1,1);
			a[i+n]=line(x1,x2,y2,-1);
			all[i]=x1;
			all[i+n]=x2; 
		}
		n*=2;//每条长边看成线段
		sort(a+1,a+1+n);
		sort(all+1,all+1+n);
		int m=unique(all+1,all+1+n)-all-1;
		//unique的作用是“去掉”容器中相邻元素的重复元素（不一定要求数组有序），它会把重复的元素添加到容器末尾（所以数组大小并没有改变），而返回值是去重之后的尾地址
		double ans=0; 
		build(1,m,1);
		for(int i=1;i<n;i++){
			int l=lower_bound(all+1,all+1+m,a[i].l)-all;
			int r=lower_bound(all+1,all+1+m,a[i].r)-all;
			if(l<r) update(l,r-1,1,m,1,a[i].d);
			ans+=tree[1].sum*(a[i+1].h-a[i].h);
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n", ++cas, ans);
	}
}
