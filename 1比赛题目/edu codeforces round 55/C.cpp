#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
vector<int>a[maxn];
vector<long long>sum[maxn];
vector<long long>t[maxn];
int cmp(int x,int y){
	return x>y;
}
int main(){
	int s,r,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
	}
	r=0;
	for(int i=1;i<=m;i++){
		sort(a[i].begin(),a[i].end(),cmp);
		r=max(r,(int)a[i].size());
		for(int j=1;j<a[i].size();j++){
//			printf("debug%d %d\n",i,a[i][j]);
			a[i][j]+=a[i][j-1];
		}
		for(int j=0;j<a[i].size();j++){
			t[j].push_back(a[i][j]);
		}
	}
	for(int i=0;i<r;i++){
		sort(t[i].begin(),t[i].end(),cmp);
	}
	long long ans=0,tot=0;
	for(int i=0;i<r;i++){
		auto pos=lower_bound(t[i].begin(),t[i].end(),0,cmp);
		tot=0;
		for(auto it=t[i].begin();it!=pos;it++){
			tot+=(*it);
		}
		ans=max(ans,tot);
	}
	cout<<ans;
}
