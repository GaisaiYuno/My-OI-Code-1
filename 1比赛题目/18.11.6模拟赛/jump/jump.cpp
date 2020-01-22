#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
#define INF 0x3f3f3f3f3f3f3f3f
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
int n,d;
int k;
int x[maxn];
int a[maxn];
long long dp[maxn];

int check(int g){
	long long tmp;
	int l0,r0;
	long long ans=0;
	if(g<d){
		l0=d-g;
		r0=d+g;
	}else{
		l0=1;
		r0=d+g;
	}
	q.clear();
	q.push_back(node(0,0));
	for(int i=1;i<=n;i++){
		while(!q.empty()&&(x[i]-q.front().x>r0||x[i]-q.front().x<l0)){
//			if(g==2)printf("%lld %d\n",q.front().v,q.front().x);
			q.pop_front();
		}
		if(q.empty()) break;
		tmp=q.front().v+a[i];
		ans=max(ans,tmp);
		while(!q.empty()&&q.back().v<tmp) q.pop_back();
		q.push_back(node(tmp,x[i]));
	}
//	printf("%d %lld\n",g,ans);
	if(ans>=k) return 1;
	else return 0;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=qread();
	d=qread();
	k=qread();
	for(int i=1;i<=n;i++){
		x[i]=qread();
		a[i]=qread();
	}
	dp[0]=0;
	x[0]=0;
	int l=0,r=x[n];
	int mid;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d\n",ans);
}
//Dedicated to Selina 
