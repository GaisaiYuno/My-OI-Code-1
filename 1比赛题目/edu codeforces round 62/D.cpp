#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=1*(i-1)*i;
	}
	printf("%I64d\n",ans);
}

