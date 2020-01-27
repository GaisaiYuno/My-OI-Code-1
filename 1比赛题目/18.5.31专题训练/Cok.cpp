#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n;
int sum[maxn][maxn];
int main(){
	int tmp=0;
	scanf("%d",&n);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&tmp);
			sum[i][j]=sum[i-1][j]+tmp; 
		}
	}
	int rowsum=0;
	int s=0,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s=0;
			for(int k=1;k<=n;k++){
				rowsum=sum[j][k]-sum[i-1][k];
				s+=rowsum;
				if(s<0) s=0;
				if(s>ans) ans=s;
			}
		}
	}
	printf("%d\n",ans);
}
