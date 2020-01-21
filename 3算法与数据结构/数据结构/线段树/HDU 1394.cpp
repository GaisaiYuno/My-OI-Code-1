#include<iostream>
#include<cstring>
#define maxn 5005 
using namespace std;
int tree[maxn*4];
int a[maxn];
inline int fread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

void push_up(int pos) {
	tree[pos]=tree[pos*2]+tree[pos*2+1];
}
void build(int l,int r,int pos) {
	if(l==r) {
		tree[pos]=0;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	push_up(pos);
}
void update_point(int a_pos,int value,int l,int r,int pos) {
	if(l==r) {
		tree[pos]+=value;
		return;
	}
	int mid=(l+r)/2;
	if(a_pos<=mid)update_point(a_pos,value,l,mid,pos*2);
	else update_point(a_pos,value,mid+1,r,pos*2+1);
	push_up(pos);
}
int query(int to_l,int to_r,int now_l,int now_r,int pos) {
	if(to_l<=now_l&&now_r<=to_r) {
		return tree[pos];
	}
	int mid=(now_l+now_r)/2;
	int ans=0;
	if(to_l<=mid) ans=ans+query(to_l,to_r,now_l,mid,pos*2);
	if(to_r>mid) ans=ans+query(to_l,to_r,mid+1,now_r,pos*2+1);
	return ans;
}
int n;
int main() {
    while(cin>>n&&n!=0){
    	int sum=0;
    	build(1,n,1);
    	for(int i=0;i<n;i++){
    		a[i]=fread();
			sum+=query(a[i]+1,n,1,n,1); 
			update_point(a[i]+1,1,1,n,1);
		}
		int ans=sum;
		for(int i=0;i<n;i++){
			sum=sum-a[i]+n-1-a[i];
			ans=min(ans,sum);
		}
		cout<<ans<<endl; 
	} 
	return 0;
}
/*
把树的叶子节点作为每个数的对应位置
枚举到第i个数时，我们需要求出前i次插入的数中有多少个比a[i]大， 
即去寻找已经插入的数中比a[i]大的数的个数  即查询叶子节点a[i]到n的数的个数
*/
