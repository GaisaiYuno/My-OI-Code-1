#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 300000 
using namespace std;
int n,s;
int t[maxn+5],c[maxn+5];
int sumt[maxn+5],sumc[maxn+5];
//dp[i]=min(dp[j]+sumt[i]*(sumc[i]-sumc[j])+s*(sumc[n]-sumc[j])
//����dp[j]=(s+sumt[i])*sumc[j]+dp[i]-sumt[i]*sumc[i]-s*sumc[n]
//б��s+sumt[i],��(sumc[j],dp[j]) 
int dp[maxn+5];
int q[maxn*2+5];
int main(){
	scanf("%d %d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&t[i],&c[i]);
		sumt[i]=sumt[i-1]+t[i];
		sumc[i]=sumc[i-1]+c[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	int head=1,tail=1;//����д�߽粻���״� 
	q[head]=0;
	for(int i=1;i<=n;i++){
		while(head<tail&&
		dp[q[head+1]]-dp[q[head]]<=(s+sumt[i])*(sumc[q[head+1]]-sumc[q[head]]))head++;//б�ʴ�С�Ƚϲ����ó���������ᱻ������ 
		//head->head+1б�ʱ���Ҫ>=s+sumt[i],������˵�������ž��� 
		
		dp[i]=dp[q[head]]-(s+sumt[i])*sumc[q[head]]+sumt[i]*sumc[i]+s*sumc[n];
		
		while(head<tail&&(dp[q[tail]]-dp[q[tail-1]])*(sumc[i]-sumc[q[tail]])
							>=(dp[i]-dp[q[tail]])*(sumc[q[tail]]-sumc[q[tail-1]])) tail--;
		//tail->tail-1б��>=i->tailб��ʱ���� 
		q[++tail]=i;
		printf("dp[%d]=%d head=%d\n",i,dp[i],head);
	}
	printf("%d\n",dp[n]);
}

