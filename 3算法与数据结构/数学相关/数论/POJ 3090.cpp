#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int phi[maxn];
void euler(int n){
	for(int i=2;i<=n;i++) phi[i]=i;
	for(int i=2;i<=n;i++){
		if(phi[i]==i){
			for(int j=i;j<=n;j+=i){
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
int c,n,ans;
int main(){
	scanf("%d",&c);
	for(int i=1;i<=c;i++){
		scanf("%d",&n);
		ans=0;
		euler(n);
		for(int j=1;j<=n;j++){
			ans+=phi[j]; 
		}
		ans*=2;
		ans+=3;
		printf("%d %d %d\n",i,n,ans);
	}
}
