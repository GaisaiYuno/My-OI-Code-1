#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 55 
using namespace std;
int t,n,m;
struct node{
	int mon;//钱数
	double pb;//概率 
	node(){}
	node(int money,double psb){
		mon=money;
		pb=psb;
	} 
	friend bool operator < (node p,node q){
		if(p.mon==q.mon) return p.pb<q.pb;
		else return p.mon<q.mon;
	}
};
double rate[maxn];
int val[maxn];
int cost[maxn];
int dmnd[maxn];
vector<node>lmoney[maxn],rmoney[maxn];//money[i]表示得到的钻石数目为i时的钱和概率 
vector<double>sumr[maxn]; //对rmoney的概率求前缀和 
void dfs(vector<node> *a,int deep,int lim,int dm/*钻石数*/,int mon/*钱数*/,double pb/*概率*/){
	if(deep>lim){
		a[dm].push_back(node(mon,pb));
		return;
	}
	dfs(a,deep+1,lim,dm+1,mon,pb*(1-rate[deep]));
	dfs(a,deep+1,lim,dm,mon+val[deep],pb*rate[deep]); 
} 

int dp[maxn][maxn];//dp[i][j]表示买i个食物，消耗k颗钻石需要的钱数 
void work_dp(){
	for(int i=0;i<=n;i++) dp[0][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=i;j>=1;j--){
			for(int k=n;k>=dmnd[i];k--){
				dp[j][k]=min(dp[j][k],dp[j-1][k-dmnd[i]]+cost[i]);
			} 
		}
	}
}



int lower(vector<node> &v,int val){//返回最后一个<val的位置 
	int l=0,r=v.size()-1,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(v[mid].mon<val){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int upper(vector<node> &v,int val){//返回最后一个<=val的位置 
	int l=0,r=v.size()-1,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(v[mid].mon<=val){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}



void debug(int id,vector<node> &v){
	printf("[%d]: ",id);
	for(int i=0;i<v.size();i++){
		printf("(%d,%.2f) \t",v[i].mon,v[i].pb);
	}
	printf("\n");
}
double solve(){
	for(int i=0;i<=n;i++){
		if(lmoney[i].size()){
			sort(lmoney[i].begin(),lmoney[i].end());
//			debug(i,lmoney[i]);
		}
	}
//	printf("-----------------------------\n");
	for(int i=0;i<=n;i++){
		if(rmoney[i].size()){
			sort(rmoney[i].begin(),rmoney[i].end());
//			debug(i,rmoney[i]);
		}
	}
	for(int i=0;i<=n;i++){
		if(rmoney[i].size()){
			sumr[i].resize(rmoney[i].size());
			sumr[i][0]=rmoney[i][0].pb;
			for(int j=1;j<rmoney[i].size();j++){
				sumr[i][j]=rmoney[i][j].pb+sumr[i][j-1];
			}
		}
	}
	double ans=0;
	for(int dl=0;dl<=n;dl++){
		for(int j=0;j<lmoney[dl].size();j++){
			double sum=0;
			int money=lmoney[dl][j].mon;
			double psb=lmoney[dl][j].pb;
			for(int dr=0;dr<=n-n/2&&dr<=n-dl;dr++){
				if(rmoney[dr].size()){
					int rr=rmoney[dr].size()-1;
					for(int tot=1;tot<=m;tot++){
						double s=0;
						while(rr>=0&&money+rmoney[dr][rr].mon>=dp[tot][dl+dr]&&money+rmoney[dr][rr].mon<dp[tot+1][dl+dr]){
							s+=rmoney[dr][rr].pb;
							rr--;
						}
						sum+=psb*s*tot;
					}
				}
			}
			ans+=sum;
		}
	}
	return ans;
}
//double calc(int dm,int money,double psb){
//	double ans=0,sum=0;
//	for(int i=0;i<=n-n/2&&i<=n-dm;i++){
//		if(rmoney[i].size()){
//			for(int j=1;j<=m;j++){
//				int l=lower(rmoney[i],dp[j][i+dm]-money);
//				int r=lower(rmoney[i],dp[j+1][i+dm]-money);
////				if(r==-1) continue;
//				if(l>=0)ans+=psb*(sumr[i][r]-sumr[i][l])*j;
//				else ans+=psb*(sumr[i][r])*j;
//			}
//		}
//	}
//	return ans;
//}
void ini(){
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<=n;i++){
		lmoney[i].clear();
		rmoney[i].clear();
		sumr[i].clear();
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d %lf",&val[i],&rate[i]); 
			rate[i]/=100;
		}
		for(int i=1;i<=m;i++){
			scanf("%d %d",&cost[i],&dmnd[i]);
		}
		ini();
		work_dp();
		dfs(lmoney,1,n/2,0,0,1);
		dfs(rmoney,n/2+1,n,0,0,1);
		printf("%.4f\n",solve());
	}
}
/*
1
2 1
5 100
5 50
5 1
*/ 
