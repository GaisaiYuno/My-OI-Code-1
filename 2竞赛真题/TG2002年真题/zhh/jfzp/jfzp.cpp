#include<iostream>
#include<cstdio>
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define zhh 105
using namespace std;
int n,ans,cnt,b;
int a[zhh];
int main() {
	freopen("jfzp.in","r",stdin);
	freopen("jfzp.out","w",stdout);
	cin>>n;
	fu(i,1,n){
		cin>>a[i];
		cnt+=a[i];
	}
	b=cnt/n;
	fu(i,1,n){
		a[i]-=b;
	}	
	fu(i,1,n){
		if(a[i]==0) continue;
		a[i+1]+=a[i];
		ans++;
	}
	cout<<ans;
	return 0;
}
