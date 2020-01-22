#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 1000
#define maxm 15
#define maxs 32768
using namespace std;
typedef long long ll; 
int n,m;
const char noi[]="NOI"; 
char str[maxn+5];
int b[maxn+5];
int sta[maxs+5][3];

void ini() {
	static int f[maxn+5]; //�൱��dp[i-1]
	static int g[maxn+5];//�൱��dp[i]
	for(int s=0; s<(1<<m); s++) {
		//s��ʾdp[i-1]�Ĳ�֣�Ҫ���������ܵõ�dp[i-1]
		for(int j=0; j<m; j++) f[j+1]=f[j]+(s>>j&1);
		for(int k=0; k<=2; k++) { //ö��a[i]��ֵ
			for(int j=1; j<=m; j++) {
				g[j]=max(g[j-1],f[j]);//dp[i][j]=max(dp[i][j-1],dp[i-1][j])
				if(str[j]==noi[k]) g[j]=max(g[j],f[j-1]+1);//dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1) (a[i]==b[j])
			}
			int t=0;
			for(int j=1; j<=m; j++) {
				if(g[j]-g[j-1]>0) t|=(1<<(j-1));//�ٰ�dp[i]���
			}
			sta[s][k]=t;//��a[i]=kʱ,dp״̬����s���t
//			printf("trans[%d][%d]=%d\n",s,k,sta[s][k]); 
		}

	}
}

const int match[3][3]={{1,0,0},{1,2,0},{1,0,3}};
//match[i][j]��ʾԭ��ĩβ��ƥ����iλ,�����ַ�noi[j]֮��ĩβƥ���λ�� 
inline int count_1(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

ll ans[maxm+5];
ll dp[2][maxs+5][3];
inline void addm(ll &x,ll y){
	x=(x+y>=mod)?(x+y-mod):(x+y);
}
int main() {
	scanf("%d %d",&n,&m);
	scanf("%s",str+1);

	ini();
	int now=0;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		memset(dp[now^1],0,sizeof(dp[now^1]));
		for(int s=0;s<(1<<m);s++){//lcs����״̬ 
			for(int j=0;j<=2;j++){//ƥ����"NOI"��λ 
				for(int k=0;k<=2;k++){//��ǰ�ַ� 
					if(j==2&&k==2) continue;//����"NOI" 
					int newj=match[j][k]; //�����µ���"NOI"��ƥ��λ�� 
					addm(dp[now^1][sta[s][k]][newj],dp[now][s][j]);
//					dp[now^1][sta[s][k]][newj]%=mod;
				}
			}
		}
		now^=1;
	}
	for(int s=0;s<(1<<m);s++){
		for(int j=0;j<=2;j++){
			int lis=count_1(s); //lis����dp[i][j]���ǲ��������1�ĸ��� 
			addm(ans[lis],dp[now][s][j]);
		}
	}
	for(int i=0;i<=m;i++) printf("%lld\n",ans[i]);
}

