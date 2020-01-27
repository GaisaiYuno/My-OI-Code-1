#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100000
using namespace std;
struct home {
	int s;
	int v;
} a[maxn];
int n,ans,maxs;
int comp(home x,home y) {
	int t1=x.v,t2=y.v;
	if(x.s>maxs)t1+=(x.s-maxs)*2;
	if(y.s>maxs)t2+=(y.s-maxs)*2;
	return t1>t2;
}
int main() {
	int flag=0;//标记是否重新排序
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i].s;
	for(int i=1; i<=n; i++) cin>>a[i].v;
	sort(a+1,a+1+n,comp);
	for(int i=1; i<=n; i++) {
		if(a[i].s>maxs) {
			flag=1;
			maxs=a[i].s;//记录来回最大路径
		} else flag=0;
		ans+=a[i].v;
		cout<<(ans+2*maxs)<<endl;
		if(flag==1) sort(a+i+1,a+n+1,comp);
	}
	return 0;

}
