//HDU 3001
/*状态压缩 点集s
	   把集合s中第i个点删除： s-=3^i
	   判断第i个点是否属于集合s： 预处理表p[s][i](0<i<n) 表示s第i位的数  
*/
#include<iostream>
#include<cstdio> 
#include<cstring>
#define INF 0x7fffff
#define maxn 15
#define maxk 177147 //3^11-1
using namespace std;
int n,m;
int dis[maxn][maxn];
int pre[maxk+5][maxn];
int dp[maxk+5][maxn];
const int pow3[12]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147};
int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void do_pre(){
	memset(pre,0,sizeof(pre));
	for(int s=0;s<maxk;s++){
		int t=s,cnt=0;
        for(int i=0;i<10;i++){
        	pre[s][i]=t%3;
        	t/=3;
		}
	}
} 
int judge(int x){
	for(int i=0;i<n;i++){
		if(pre[x][i]==0) return 0;
	}
	return 1;
}
int main(){
	//freopen("out.txt","r",stdin);
	do_pre(); 
    while(cin>>n>>m){
    	memset(dis,0x7f,sizeof(dis));
    	for(int i=1;i<=m;i++){
    		int a,b,c;
    		a=fread();
    		b=fread();
    		c=fread();
    		if(dis[a-1][b-1]>c) dis[a-1][b-1]=dis[b-1][a-1]=c;
		}
		for(int i=0;i<maxk;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=INF;
			}
		}  
		for(int i=0;i<n;i++) dp[pow3[i]][i]=0;
		int ans=INF;
		for(int s=0;s<=(pow3[n]-1);s++){
			for(int i=0;i<n;i++){
				if(pre[s][i]==0) continue;
				for(int j=0;j<n;j++){
					if(i!=j&&pre[s][j]!=0){
						dp[s][i]=min(dp[s-pow3[i]][j]+dis[j][i],dp[s][i]);
					}
				}
				if(judge(s)&&ans>dp[s][i])ans=dp[s][i];
			}
		}
		//debug("dp");
		//cout<<ans<<endl;
		if(ans!=INF) cout<<ans<<endl; 
		else cout<<"-1"<<endl; 
		//debug("dp");
	}
}
/*
10 28
1 7 40
9 7 38
10 3 62
6 1 94
6 2 72
3 5 16
3 5 4
4 9 37
5 8 12
8 7 88
8 1 72
9 8 24
10 10 92
10 10 68
4 10 5
10 1 7
9 2 51
9 10 67
8 6 67
6 4 18
6 3 5
9 1 75
4 5 8
1 6 22
2 3 39
9 10 58
4 6 75
2 7 64
*/

