//luogu 4372 
//定义第i个分割线表示数i与i+1之间的分割线
//在每个点两边形成分割线之前点将不断产生1的贡献
//设t[i]表示第i个分割线出现的时间，则ans=sum(max(t[i],t[i-1])
// 考虑如何计算出t[i]
//对于每个数x，当一开始x右边所有比x小的数都移动到x左边才会出现分割线
//根据冒泡排序的特点，每个数每次至少移动一位，故最长的移动时间t[i]为x右边小于x的数到x最大的距离 
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int t[maxn];
struct node{
	int x;
	int id;
	friend bool operator <(node a,node b){
		if(a.x==b.x) return a.id<b.id;
		return a.x<b.x;
	}
}b[maxn];
int main(){
//	freopen("sort5.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i].x=a[i];
		b[i].id=i;
	}
	sort(b+1,b+1+n);
	int r=0;
	for(int i=1;i<=n;i++){
		r=max(r,b[i].id);
		t[i]=max(r-i,1);//若有些小于x的数在x左边，r-i为负数，不考虑 
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=max(t[i],t[i-1]);
	}
	cout<<ans;
}

