#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#define maxn 25
#define mod 999917
#define maxh 1000005
#define maxb 1050000
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
int n;
long long a[maxn];
int vis[maxb];
map<long long,int>mp;
vector<int>v[maxh];
int ans=0;
int cnt=0;
void dfs1(int deep,int top,long long sum,int s) {
	if(deep==top+1) {
		if(!mp.count(sum)) mp[sum]=++cnt;
		v[mp[sum]].push_back(s);
		return;
	}
	dfs1(deep+1,top,sum+a[deep],s|(1<<(deep-1)));
	dfs1(deep+1,top,sum-a[deep],s|(1<<(deep-1)));
	dfs1(deep+1,top,sum,s);
}

void dfs2(int deep,int top,long long sum,int s) {
	if(deep==top+1) {
		if(!mp.count(sum)) return;
		int id=mp[sum];
		for(int i=0;i<v[id].size();i++){
			if(!vis[v[id][i]|s]) ans++;
			vis[v[id][i]|s]=1;
		} 
		return;
	}
	dfs2(deep+1,top,sum+a[deep],s|(1<<(deep-1)));
	dfs2(deep+1,top,sum-a[deep],s|(1<<(deep-1)));
	dfs2(deep+1,top,sum,s);
}

int main() {
	n=qread();
	for(int i=1; i<=n; i++) {
		a[i]=qread();
	}
	int m=n/2;;
	dfs1(1,m,0,0);
	dfs2(m+1,n,0,0);
	printf("%d\n",ans-1);

}
