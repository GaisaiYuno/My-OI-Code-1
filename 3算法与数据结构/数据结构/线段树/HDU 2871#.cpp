#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#define maxn 50005
using namespace std;
inline int fread(){
	int x=0;
	int sign=1;
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
//struct segment_tree {
	struct node {
		int l,r;
		int used;///清除内存为1，覆盖为0，初始-1
		int lsum,rsum,maxsum;//从左，右数最大连续空余区间，和区间内最大连续空余区间
		int len() {
			return r-l+1;
		}
	} tree[maxn*4];
	void push_up(int pos) {
		tree[pos].lsum=tree[pos*2].lsum;
		tree[pos].rsum=tree[pos*2+1].rsum;
		tree[pos].maxsum=max(max(tree[pos*2].maxsum,tree[pos*2+1].maxsum),tree[pos*2].rsum+tree[pos*2+1].lsum);
		if(tree[pos].lsum==tree[pos*2].len()) tree[pos].lsum+=tree[pos*2+1].lsum;
		if(tree[pos].rsum==tree[pos*2+1].len()) tree[pos].rsum+=tree[pos*2].rsum;
	}
	void build(int l,int r,int pos) {
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].used=-1;
		tree[pos].lsum=tree[pos].rsum=tree[pos].maxsum=tree[pos].len();
		if(l==r) return;
		int mid=(l+r)/2;
		build(l,mid,pos*2);
		build(mid+1,r,pos*2+1);
	}
	void push_down(int pos) {
		if(tree[pos].used!=-1) {
			tree[pos*2].maxsum=tree[pos*2].rsum=tree[pos*2].lsum=tree[pos].used*tree[pos*2].len();
			tree[pos*2+1].maxsum=tree[pos*2+1].rsum=tree[pos*2+1].lsum=tree[pos].used*tree[pos*2+1].len();
			tree[pos*2].used=tree[pos*2+1].used=tree[pos].used;
			tree[pos].used=-1;
		}
	}
	void update_section(int to_l,int to_r,int value,int pos) {
		if(tree[pos].l==to_l&&tree[pos].r==to_r) {
			tree[pos].used=value;
			tree[pos].lsum=tree[pos].rsum=tree[pos].maxsum=tree[pos].len()*value;
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)/2;
		if(to_l>mid) update_section(to_l,to_r,value,pos*2+1);
		else if(to_r<=mid) update_section(to_l,to_r,value,pos*2);
		else {
			update_section(to_l,mid,value,pos*2);
			update_section(mid+1,to_r,value,pos*2+1);
		}
		push_up(pos);
	}
	int query(int l,int r,int pos,int len) { //找最左边的适合的连续区间的左端点
		if(l==r) return l;
		push_down(pos);
		int mid=(l+r)/2;
		if(tree[pos*2].maxsum>=len) return query(l,mid,pos*2,len);
		else if(tree[pos*2].rsum+tree[pos*2+1].lsum>=len) return mid-tree[pos*2].rsum+1;
		else return query(mid+1,r,pos*2+1,len);
	}
//};
//segment_tree T;
struct edge {
	int l;
	int r;
};
int cmp(edge x,edge y) { //用于二分查找的函数
	return x.l<y.l;
}
vector<edge>V;
int n,m;
int main() {
	string cmd;
	int x;
	edge now;
	vector<edge>::iterator it;
	while(cin>>n>>m) {
		build(1,n,1);
		V.clear();
		while(m--) {
            cin>>cmd;
            if(cmd=="Reset"){
            	update_section(1,n,1,1);
            	V.clear();
            	cout<<"Reset Now"<<endl;
			}
            else if(cmd=="New"){
            	x=fread();
            	if(tree[1].maxsum<x){
            		cout<<"Reject New"<<endl;
            		continue;
				}
				else{
					int pos=query(1,n,1,x);
					printf("New at %d\n",pos);
					update_section(pos,pos+x-1,0,1);
					now.l=pos;
					now.r=pos+x-1;
					it=upper_bound(V.begin(),V.end(),now,cmp);//二分查找出大于now的区间 
					V.insert(it,now);
				}
			}
			else if(cmd=="Free"){
				x=fread();
				now.l=now.r=x;
				it=upper_bound(V.begin(),V.end(),now,cmp);
				if(it==V.begin()){
					cout<<"Reject Free"<<endl;
					continue;
				}
				else{
					it--;
					if(it->r<now.l) cout<<"Reject Free"<<endl;
					else{
					     printf("Free from %d to %d\n",it->l,it->r);
					     update_section(it->l,it->r,1,1);
						 V.erase(it); 
				    }
			    }
			}
			else if(cmd=="Get"){
				x=fread();
				if(x>V.size()){
					cout<<"Reject Get"<<endl;
					continue;
				}else{
					printf("Get at %d\n",V[x-1].l);//VECTOR下标从0开始 
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
