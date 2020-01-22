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
	static int f[maxn+5]; //相当于dp[i-1]
	static int g[maxn+5];//相当于dp[i]
	for(int s=0; s<(1<<m); s++) {
		//s表示dp[i-1]的差分，要加起来才能得到dp[i-1]
		for(int j=0; j<m; j++) f[j+1]=f[j]+(s>>j&1);
		for(int k=0; k<=2; k++) { //枚举a[i]的值
			for(int j=1; j<=m; j++) {
				g[j]=max(g[j-1],f[j]);//dp[i][j]=max(dp[i][j-1],dp[i-1][j])
				if(str[j]==noi[k]) g[j]=max(g[j],f[j-1]+1);//dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1) (a[i]==b[j])
			}
			int t=0;
			for(int j=1; j<=m; j++) {
				if(g[j]-g[j-1]>0) t|=(1<<(j-1));//再把dp[i]差分
			}
			sta[s][k]=t;//当a[i]=k时,dp状态会由s变成t
//			printf("trans[%d][%d]=%d\n",s,k,sta[s][k]); 
		}

	}
}

const int match[3][3]={{1,0,0},{1,2,0},{1,0,3}};
//match[i][j]表示原本末尾与匹配了i位,加上字符noi[j]之后末尾匹配的位数 
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
		for(int s=0;s<(1<<m);s++){//lcs数组状态 
			for(int j=0;j<=2;j++){//匹配了"NOI"几位 
				for(int k=0;k<=2;k++){//当前字符 
					if(j==2&&k==2) continue;//出现"NOI" 
					int newj=match[j][k]; //计算新的与"NOI"的匹配位数 
					addm(dp[now^1][sta[s][k]][newj],dp[now][s][j]);
//					dp[now^1][sta[s][k]][newj]%=mod;
				}
			}
		}
		now^=1;
	}
	for(int s=0;s<(1<<m);s++){
		for(int j=0;j<=2;j++){
			int lis=count_1(s); //lis长度dp[i][j]就是差分数组里1的个数 
			addm(ans[lis],dp[now][s][j]);
		}
	}
	for(int i=0;i<=m;i++) printf("%lld\n",ans[i]);
}

