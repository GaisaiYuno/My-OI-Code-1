#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int n,d,k;
int x[500001],s[500001];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,s+i);
		if(s[i]>0)cnt+=s[i];
	}
	if(cnt<k){
		printf("-1");
		return 0;
	}
	cnt=0;
}
