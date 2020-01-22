//（G:\c++\资料）初二热身 c
#include<iostream>
using namespace std;
int a[100005];
int n;
long long ans=0;
int main() {
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		if (a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
