#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005 
using namespace std;
int n;
int p[maxn];
int k[maxn];
int cnt=0;
void div(int x){
	for(long long i=2;i<=n;i++){
		if(x%i==0){
			p[++cnt]=i;
			while(x%i==0){
				k[cnt]++;
				x/=i;
			}
		}
	}
	if(cnt==0){
		p[++cnt]=x;
		k[cnt]=1;
	}
}
int main(){
	scanf("%d",&n);
	div(n);
	int ans=0,sum=1;
	for(int i=1;i<=cnt;i++){
		for(int j=0;;j++){
			if((1<<j)>=k[i]&&(1<<(j-1))<k[i]){
				ans=max(ans,j);
				break;
			}
		}
	}
	for(int i=1;i<=cnt;i++) sum*=p[i];
	bool flag=true;
	for(int i=1;i<=cnt;i++){
		if(k[i]!=(1<<ans)) flag=false;
	}
	if(!flag) ans++;
	printf("%d %d\n",sum,ans); 
}
