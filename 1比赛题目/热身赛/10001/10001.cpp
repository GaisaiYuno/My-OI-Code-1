//（G:\c++\资料）初二热身 b 
#include<iostream>
#include<cstdio>
#define maxn 10005
using namespace std;
int a[maxn];
int ans=0,n;
int main(){
	freopen("10001.in","r",stdin);
	freopen("10001.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=2;j<n;j++){
	   if(a[j-1]>a[j]&&a[j]<a[j+1]) ans++;
	   if(a[j]==a[j-1]&&a[j]<a[j+1]) ans++; 
	}
	cout<<ans;
	return 0;
} 
