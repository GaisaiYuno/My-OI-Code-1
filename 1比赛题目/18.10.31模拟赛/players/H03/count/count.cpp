#include<iostream>
#include<cstdio>
using namespace std;
int st[300005][23];
int n,m,type;
void init(){
	for(int u=1;(1<<u)<n;u++){
		for(int i=1;i+(1<<u)<=n+1;i++){
			st[i][u]=max(st[i][u-1],st[i+(1<<(u-1))][u-1]);
		}
	}
}
int query(int l,int r){
	int k;
	for(k=0;(1<<(k+1))<(r-l+1);k++);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int lans;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m>>type;
	for(int i=1;i<=n;i++)cin>>st[i][0];
	init();
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		if(type)l=(l-1+lans)%n+1,r=(r-1+lans)%n+1;
		int ans=0;
		for(int u=l;u<=r-1;u++){
			ans++;
			for(int j=u+2;j<=r;j++){
				if(query(u+1,j-1)<min(st[u][0],st[j][0]))ans++;
			}
		}
		cout<<ans<<endl;
	}
}
