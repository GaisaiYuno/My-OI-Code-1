//HDU 1565 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define size 20005
using namespace std;
int n;
int ans=0;
int a[maxn][maxn];
int dp[maxn][size];
struct node{
	int kind;//������� 
	int sum;//������Ӧ�ĺ� 
};
int cnt=0,front_cnt=0;
node r[size],front_r[size];
inline int read(){
	int x=0;
	char c=getchar();
	int sign=1;
	while(c<'0'||c>'9') {
		c=getchar();
		if(c=='-') sign=-1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void dfs(int h,int deep,int k,int sum){//�� �� ÿһ�е����  �� 
    /*״̬ѹ��: 
    ��20λ�Ķ���������С������32λ��
	��ʾÿһ��״̬��1��ʾѡ��0��ʾ��ѡ */ 
	if(deep>n){
		cnt++;
		r[cnt].kind=k;
		r[cnt].sum=sum;
		return;
	}
	dfs(h,deep+1,k,sum);
	/*��һ�в�ѡ,deepֱ��+1 */
	dfs(h,deep+2,(1<<(deep-1))|k,sum+a[h][deep]);
	/* ��һ��ѡ��������һ�У�����deep+2 
	   ��һ��ѡ k�ĵ�deepλΪ1 
	   1<<deep-1|k �൱�ڽ�1�ӵ�kǰ��
	   �磺deep=3 k=11 1<<deep-1=100 100|k=111 
	   ע�⣺ÿһ������ǵ�������
	   ��110 75 21 10 ѡ����21��10 
	*/
} 
int main(){
    while(cin>>n){
    	memset(r,0,sizeof(r));
    	memset(front_r,0,sizeof(front_r));
    	memset(dp,0,sizeof(dp));
    	cnt=0;
    	ans=0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++) a[i][j]=read();
		}
		for(int i=1;i<=n;i++){
			cnt=0;
			dfs(i,1,0,0); 
			for(int j=1;j<=cnt;j++){
				for(int t=1;t<=front_cnt;t++){
					if((r[j].kind&front_r[t].kind)==0) dp[i][j]=max(dp[i][j],front_r[t].sum);
				}
				dp[i][j]+=r[j].sum;
				r[j].sum=dp[i][j];
			}	
			front_cnt=cnt;		
			for(int j=1;j<=cnt;j++){
				front_r[j].kind=r[j].kind;
				front_r[j].sum=r[j].sum;
			}
		}
		for(int i=1;i<=cnt;i++) ans=max(ans,dp[n][i]);
		//debug();
		cout<<ans<<endl;
	}
}
/*
ѹ������20λ�Ķ���������С������32λ����ʾÿһ��״̬��1��ʾѡ��0��ʾ��ѡ  
��״̬��dp[i][j]�����0~i�У����ҵ�i�еĵ�j��״̬�õ������� 
״̬ת�Ʒ���dp[i][j]=max(dp[i][j],dp[i-1][t]) ����dp[i][j].k&dp[i-1][t].k==0��Ϊ�˲����ڣ�,����tΪi-1�е�ÿ��״̬ 
*/
