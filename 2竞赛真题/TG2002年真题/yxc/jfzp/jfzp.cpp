#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A[10005];
int main(){
	freopen("jfzp.in","r",stdin);
	freopen("jfzp.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		sum+=A[i];
	}
	sum/=n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int a=A[i]-sum;
		if(A[i]==sum)continue;
		A[i]-=a;
		A[i+1]+=a;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
