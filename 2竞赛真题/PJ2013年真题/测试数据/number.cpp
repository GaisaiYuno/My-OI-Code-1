//number
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005 
using namespace std;
int n,p;
int ans;
int a[maxn];
int v[maxn];
int f[maxn];
int main(){
	int t,l;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	ans=-99999999;
	t=0;
	l=-999999999;
    //for(int i=1;i<=n;i++) v[i]=f[i]=-9999999;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=1;j<=i;j++) {
			t=max(t,t+a[j]);
			l=max(l,a[j]);
		}
		if(t!=0 )v[i]=t;
		else v[i]=l;//全为负数时需特判 
	}
	f[1]=v[1];
	for(int i=2;i<=n;i++){
		t=0;
		for(int j=1;j<i;j++){
			l=max(l,v[j]+f[j]);
			t=max(t,v[j]+f[j]);
		} 
		if(t!=0 )f[i]=t;
		else f[i]=l;
	} 
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	//debug();
	cout<<ans%p;
	return 0;
}
