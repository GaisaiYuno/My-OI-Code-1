#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
#define mod 1000000007
using namespace std;
int t,n;
char a[maxn];
int next[maxn];
//注意到next[i],next[next[i]...都是前缀串i的前后缀
//只要求next的时候递推计算一下就可以得到弱化版num数组(可重叠的前后缀数量) 
long long num[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",a+1);
		n=strlen(a+1);
		next[1]=0;
		num[1]=1;
		for(int i=2,j=0;i<=n;i++){
			while(j>0&&a[i]!=a[j+1]) j=next[j];
			if(a[i]==a[j+1]) j++;
			next[i]=j;
			num[i]=num[j]+1;
		}
		long long ans=1;
		for(int i=2,j=0;i<=n;i++){
			while(j>0&&a[i]!=a[j+1]) j=next[j];//j不更新，求完了i的答案以后，j的位置一定在i/2的左边，也就是它已经满足要求了 
			if(a[i]==a[j+1]) j++;
			while(j*2>i) j=next[j];//当j*2>i时会有重复部分 
			ans=ans*(num[j]+1)%mod;
		}
		printf("%lld\n",ans);
	}
}
