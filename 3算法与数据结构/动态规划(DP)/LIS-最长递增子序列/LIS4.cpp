#include<iostream>
#define maxn 1000
using namespace std;
int a[maxn],f[maxn];
int main() {
	int n=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1; i<=n+1; i++) { //i´Ó1~n+1
		f[i]=1;
		for(int j=1; j<i; j++) {
			if(a[j]<a[i]) f[i]=max(f[j]+1,f[i]);
		}
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;

}
