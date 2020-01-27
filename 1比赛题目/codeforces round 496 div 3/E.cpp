#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 200005
using namespace std;
map<int,int>ma;
int a[maxn];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	int pos=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==m) pos=i;
	}
	long long sum=0;
	for(int i=pos;i<=n;i++){
		if(a[i]>m) sum++;
		else if(a[i]<m) sum--;
		ma[sum]++;
	}
	long long ans=0;
	sum=0;
	for(int i=pos;i>=1;i--){
		if(a[i]>m) sum++;
		else if(a[i]<m) sum--;
//		printf("%d %d\n",ma[-sum],ma[-sum+1]);
		ans+=(long long)ma[-sum];
		ans+=(long long)ma[-sum+1];
	}
	printf("%I64d\n",ans);
}
