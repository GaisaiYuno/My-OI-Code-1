#include<iostream>
#include<cstdio>
#include<cstring>
#define MYINF -2147483647
#define maxn 20
#define maxk 1<<16
using namespace std;
int t,n,ans;
struct node{
	int a;
	int p;
}num[maxn];
int dp[maxk][maxn];
int count[maxk];
void pre(){
	for(int i=0;i<maxk;i++){//Ԥ�����ÿ�������������м���1 
		if((i&1)==0) count[i]=count[i>>1];
		else count[i]=count[i>>1]+1;
	}
}
void ini(){//��ʼ�� 
	for(int i=0;i<(1<<n);i++){
	   for(int j=0;j<n;j++) dp[i][j]=MYINF; 
	} 
	for(int i=0;i<n;i++){
		if(num[i].p==0||num[i].p==-1) dp[1<<i][i]=0;
	}
}
int main(){
	pre();
	cin>>t;
	for(int u=1;u<=t;u++){
		cin>>n;
		for(int i=0;i<n;i++) cin>>num[i].a>>num[i].p;
		ini(); 
		for(int k=0;k<(1<<n);k++){
			for(int j=0;j<n;j++){
				if(dp[k][j]==MYINF) continue;
				//����k״̬�鿴t�Ƿ���Բ��뵽��λ�� 
				for(int t=0;t<n;t++){
					if(((k&(1<<t))==0/*����*/)&&(num[t].p==-1||num[t].p==count[k]/*�Ƿ����,��k������2��1,���p=2(����λ)����������*/)) 
					    dp[k|(1<<t)][t]=max(dp[k][j]+num[t].a*num[j].a,dp[k|(1<<t)][t]);
				}
			}
		}
		ans=MYINF; 
		for(int i=0;i<n;i++) { 
            ans=max(ans,dp[(1<<n)-1][i]); 
		} 
		printf("Case #%d:\n%d\n",u,ans);
		//debug();
	}
}
/*״̬ת�Ʒ��� 
i ��ʼλ�ã���������k�Ƴ�������k�е�һ��1 ��λ�ã�����ȥ������ 
k �����ƴ���ʹ�����
j Ϊ��״̬���һ��λ�� 
for k=0;k<(1<<16) k++
    for j=0;j<16;j++ 
       dp[k|(1<<t)][t]=max(dp[k][j]+num[t].a*num[j].a,dp[k|(1<<t)][t]);    t=0~n ע�������ǹ̶��ģ�����t������k
        k|(1<<t)��ʾ��k�ĵ�tλ���1 
*/ 
