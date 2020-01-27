#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n,ans;
int a,b;
int used[maxn];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a+b+1!=n){
			ans++;
			continue;
		}
		if(used[a]==0) used[a]=1;
		else ans++;
	}
	cout<<ans;
	return 0;
}
