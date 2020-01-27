#include<iostream>
#include<cstdio>
using namespace std;
int n,ans = 0,g,sum = 0;
int a[105];

int main(){
	freopen("fjzp.in","r",stdin);
	freopen("fjzp.out","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		sum += a[i];
	}
	g = sum / n;
	for(int i = 0;i < n - 1;i++){
		if(a[i] == g) continue;
		else{
			ans++;
			a[i + 1] -= (10 - a[i]);
		}
	}
	cout<<ans<<endl;
}
