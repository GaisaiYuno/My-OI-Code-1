#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define maxv 105
#define maxn 100005
using namespace std;
vector<long long>d[maxv];
int n;
long long a[maxn];
void pre(int n){
	d[1].push_back(1);
	for(int i=2;i<=n;i++){
		for(int j=1;i*j<=n;j++){
			d[i*j].push_back(j);
		}
	}
}

int main(){
	scanf("%d",&n);
	pre(100);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	long long ans=sum;
	for(int i=1;i<=n;i++){
		long long tmp;
		for(long long j : d[a[i]]){
			tmp=sum;
			tmp+=(a[1]*j-a[1]);
			tmp-=(a[i]-a[i]/j);
			ans=min(ans,tmp);
		}
	}
	cout<<ans;
}

