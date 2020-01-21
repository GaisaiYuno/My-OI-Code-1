//HDU 4281
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 17
#define INF 2139062143
using namespace std;
struct node{
	int x;
	int y;
	int c;
};
node prob[MAXN];
int dp1[1<<MAXN],dp2[1<<MAXN][MAXN],stat[1<<MAXN],best[1<<MAXN];
bool ok[1<<MAXN]; 
int dis[MAXN][MAXN];
int n,m,cnt,ans1,ans2;
inline int fread(){
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
int getdis(node i,node j){
	return ceil(sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y)));
}
int pack_01(){
	int sum;
	cnt=0;
	memset(dp1,0x7f,sizeof(dp1));
	memset(stat,0,sizeof(stat));
	memset(ok,false,sizeof(ok));
	for(int i=0;i<(1<<n);i++){//枚举答题情况 
		sum=0;
		for(int j=0;j<n;j++){
			if((1<<j)&i) sum+=prob[j].c;
		}
		if(sum<=m){
		    stat[cnt++]=i;
		    ok[i]=true;
		} 
	}
	dp1[0]=0;
	for(int i=0;i<cnt;i++){
		for(int j=(1<<n)-1;j>=0;j--){
			if((j&stat[i])==0) dp1[j+stat[i]]=min(dp1[j+stat[i]],dp1[j]+1);  
			//if((j&stat[i])==0) dp[j-stat[i]]=min(dp[j-stat[i]]+1,dp[j]);
		}
	}
	if(dp1[(1<<n)-1]==INF) return -1;
	return dp1[(1<<n)-1];
}
void tsp(){
	memset(dp2,0x7f,sizeof(dp2));
	memset(best,0x7f,sizeof(best)) ;
	dp2[1][0]=0;
	for(int s=0;s<(1<<n);s++){
		if(!ok[s]) continue;
		for(int i=0;i<n;i++){
			if(s&(1<<i)==0) continue;
			for(int j=0;j<n;j++){
				if(i==j||s&(1<<j)==0) continue;
				dp2[s][i]=min(dp2[s][i],dp2[s&~(1<<i)][j]+dis[j][i]);
			}
			best[s]=min(best[s],dp2[s][i]+dis[i][0]);
		}
	}
}
int mtsp(){//多人tsp 
	tsp();
	for(int i=1;i<(1<<n);i++){
		//for(int j=i-1;j>0;j--){
		//为了保证i包含j,用i&j
		//如：i=1100,j=1010,i&j=1000
		for(int j=i&(i-1);j;j=i&(j-1)){ 
			if(i&1) best[i]=min(best[i],best[(i-j)|1]+best[j]);//规定1开始，则best[(i-j)|1],保证状态合法 
		}
	}
    return best[(1<<n)-1];
}
int main(){
	//freopen("testdata.txt","r",stdin); 
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			cin>>prob[i].x>>prob[i].y;
		}
		memset(dis,0x7f,sizeof(dis));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dis[i][j]=dis[j][i]=getdis(prob[i],prob[j]);
			}
		}
		for(int i=0;i<n;i++) cin>>prob[i].c;
		ans1=pack_01();
		if(ans1==-1) ans2=-1;
		else ans2=mtsp();
		cout<<ans1<<' '<<ans2<<endl; 
	}
}
