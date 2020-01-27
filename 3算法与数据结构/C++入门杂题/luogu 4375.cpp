//定义Mi表示前i个数中排序后不在前i个的数的个数 
//ans=max(Mi) 
//考虑i,i+1之间的分割点，你每一趟双向冒泡，实际上是使得一个在分割点左边的本应在右边的跑到了右边，同时让一个在分割点右边的本应在左边的跑到了左边。
//也就是说每一趟最多使得Mi-1
//考虑排序后的第i个数a[i]
//将<a[i]的数按原位置插入BIT
//查询1~i的值，得到的就是原位置在i之前且排序后在前i个的数的个数 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int used[maxn];
struct node{
	int val;
	int id;
	node(){
		
	}
	node(int x,int i){
		val=x;
		id=i;
	}
	friend bool operator <(node x,node y){
		return x.val<y.val;
	}
}a[maxn];
int tree[maxn];
inline int lowbit(int x){
	return x&(-x);
}
void update(int x,int v){
	while(x<=n){
		tree[x]+=v;
		x+=lowbit(x);
	}
} 
int query(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i].id=i;
		scanf("%d",&a[i].val);
	}
	sort(a+1,a+1+n); 
	int ans=0;
	for(int i=1;i<=n;i++){
		update(a[i].id,1);
		ans=max(ans,i-query(i));//query(i)求出的是排序前和排序后都在i前面的数的个数，用i去减就得到了 
	} 
	if(ans==0) ans=1;
	printf("%d\n",ans);
}
