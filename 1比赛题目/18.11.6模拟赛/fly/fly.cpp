#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 25
using namespace std;
int n;
long long a[maxn];
long long sum[maxn];
long long sum1,sum2,sum3,sum4;
int cnt=0;
long long query(int l,int r){
	return sum[r]-sum[l-1];
}
int main(){
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int u=k+1;u<=n;u++){
					sum1=query(i+1,j);
					sum2=query(j+1,k);
					sum3=query(k+1,u);
					sum4=sum[n]-sum1-sum2-sum3;
					if(sum1==sum3&&sum2==sum4){
						cnt++;
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
}
//Dedicated to Selina 
