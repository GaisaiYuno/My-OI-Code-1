#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
#define mod 1000000007
using namespace std;
int t,n;
char a[maxn];
int next[maxn];
//ע�⵽next[i],next[next[i]...����ǰ׺��i��ǰ��׺
//ֻҪ��next��ʱ����Ƽ���һ�¾Ϳ��Եõ�������num����(���ص���ǰ��׺����) 
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
			while(j>0&&a[i]!=a[j+1]) j=next[j];//j�����£�������i�Ĵ��Ժ�j��λ��һ����i/2����ߣ�Ҳ�������Ѿ�����Ҫ���� 
			if(a[i]==a[j+1]) j++;
			while(j*2>i) j=next[j];//��j*2>iʱ�����ظ����� 
			ans=ans*(num[j]+1)%mod;
		}
		printf("%lld\n",ans);
	}
}
