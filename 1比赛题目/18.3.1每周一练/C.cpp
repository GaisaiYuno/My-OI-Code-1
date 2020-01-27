#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define INF 2147483647
using namespace std;
int n;
struct node{
	int w;
	int s;
}a[maxn];
inline int fread(){
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
int cmp(node a,node b){
	return a.w+a.s>b.w+b.s;
}
long long sumw,ans;
int main(){
	while(cin>>n){
		sumw=0;
		ans=-INF;
		for(int i=1;i<=n;i++) {
			a[i].w=fread();
		    a[i].s=fread();
		    sumw+=a[i].w;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			sumw-=a[i].w;
			ans=max(ans,sumw-a[i].s);
		}
		if(ans<0) ans=0;
		cout<<ans<<endl;
	}
}
