#include<iostream>
#include<cstdio>
#define maxn 105
using namespace std;
int n,sum,cnt=0;
int a[maxn];
int main(){
	//freopen("jfzp.in","r",stdin);
	//freopen("jfzp.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int average=sum/n;
	for(int i=1;i<=n;i++) a[i]-=average;
	for(int i=1;i<=n;i++){
		if(a[i]==0) continue;
		a[i+1]+=a[i];
		a[i]=0;
        cnt++;
	}
	cout<<cnt;
	return 0;
}
