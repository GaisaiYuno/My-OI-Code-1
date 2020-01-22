#include<bits/stdc++.h>
using namespace std;
int n,d,k,a[100000005],i,j,x,s,g;
long long tot=0;
void dfs(int z,int l,int r,long long f){
	if(f>=tot) tot=f;
	if(z>x) return;
	for(int o=l;o<=r;o++){
		if(a[z+o]!=0) dfs(z+o,l,r,f+a[z+o]);
	}
}
int main(){
	freopen("jump.in.","r",stdin);
	freopen("jump.out.","w",stdout);
	int k;
	cin>>n>>d>>k;
	for(i=1;i<=n;i++){
		cin>>x>>s;
		a[x]=s;
		if(s>0) tot+=s;
	}
	if(tot<k){
		cout<<"-1";
		return 0;
	}
	for(i=0;i<=100000006;i++){
		tot=0;
		if(i<d){
			dfs(0,d-i,d+i,0);
		}
		else dfs(0,1,d+i,0);
		if(tot>=k){
			cout<<i;
			return 0;
		}
	}
}
