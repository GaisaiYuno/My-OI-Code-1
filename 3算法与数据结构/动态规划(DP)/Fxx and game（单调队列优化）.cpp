//HDU 5945
//�Ż� 
#include<iostream>
#include<cstring>
#define maxn 1000020
using namespace std;
int c,x,k,t;
int dp[maxn],q[maxn];
int head,tail;
int main() {
	cin>>c;
	while(c--) {
		cin>>x>>k>>t;
		int ans=0;
		if(t==0) { //����
			while(x!=1) {
				x/=k;
				ans++;
			}
		}else if(k==0) {
			if((x-1)%t==0) ans=(x-1)/t;
			else ans=(x-1)/t+1;
		} else {
			head=0,tail=1; 
			memset(q,0,sizeof(q));
			memset(dp,0x7f,sizeof(dp));
			dp[1]=0;
			q[head]=1;
			for(int i=2; i<=x; i++) {
				while(i-q[head]>t&&head<tail) head++;//���������Ż� 
				dp[i]=dp[q[head]]+1;
				if(i%k==0) dp[i]=min(dp[i],dp[i/k]+1);
				while(dp[q[tail]]>dp[i]&&head<tail) tail--;
                q[++tail]=i;
			}
			ans=dp[x];
		}
		cout<<ans<<endl;
	}
}
//dp[i]=min(min(dp[i-t]~dp[i-1])+1,dp[i/k]+1)
/*
���ڵ������У����������������壺 
1��ά��������ֵ 
2��ȥ������״̬ 
3�����ֶ��е��������ֵ�ǵ����ݼ����У���Сֵ��֮ 
4������ѡ���ڶ���

���¹��̣� 
1��ά�����ף������������������Ѿ��ǵ�ǰ��m��֮ǰ����Ϳ��Ա�ɾ��,head++�� 
2���ڶ�β���루ÿ����һ����Ҫ�Ӷ�β��ʼ��ǰȥ������״̬�� 
*/ 
