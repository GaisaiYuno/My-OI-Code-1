#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 2000
#define maxb 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,k;
int p[maxn+5];
int w[maxn+5][maxn+5];
namespace brute_force{
	bool check(){
		bool flag=true;
		for(int j=0;j<=k;j++){
			int len=(1<<j);
			for(int i=0;i+len-1<n;i+=len){
				for(int u=i;u<=i+len-1;u++){
					if(u>i&& (p[u]&(1<<j))!=(p[u-1]&(1<<j))){
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
			if(!flag) break;
		}
		return flag;
	}
	long long cal(){
		long long ans=0;
		for(int i=1;i<n;i++){
			ans+=w[p[i-1]][p[i]];
		}
		return ans;
	}

	void solve(){
		for(int i=0;i<n;i++){
			p[i]=i;
		}
		long long ans=INF;
		do{
			if(check()) ans=min(ans,cal());
	//#ifdef DEBUG
	//	for(int i=0;i<n;i++) printf("%d ",p[i]);
	//	if(check()) printf(": YES ");
	//	else printf("NO ");
	//	printf("%lld\n",cal());
	//#endif
		}while(next_permutation(p,p+n));
		printf("%lld\n",ans);
	}
}

namespace meet_in_the_middle{
	vector<long long>ansl[maxb+5],ansr[maxb+5];
	int tmp[maxn+5];
	bool check(int n){
		int k=0;
		if(n==2) k=1;
		if(n==4) k=2;
		if(n==8) k=3;
		if(n==16) k=4;
		bool flag=true;
		for(int j=0;j<=k;j++){
			int len=(1<<j);
			for(int i=0;i+len-1<n;i+=len){
				for(int u=i;u<=i+len-1;u++){
					if(u>i&& (p[u]&(1<<j))!=(p[u-1]&(1<<j))){
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
			if(!flag) break;
		}
		return flag;
	}
	void dfs(int deep,int lim,vector<long long> *ans,int x,int bin,long long sum){
		if(deep>=lim){
			if(check(lim)){
//				for(int i=0;i<lim;i++) printf("%d ",tmp[i]);
//				printf("| %d %lld\n",bin,sum);
				ans[bin].push_back(sum);
				return;
			}else return;
		}
		for(int i=0;i<n;i++){
			if(!(bin&(1<<i))){
				tmp[deep]=i;
				dfs(deep+1,lim,ans,i,bin|(1<<i),sum+w[x][i]);
				tmp[deep]=0;
			}
		}
	}
	
	long long calc(int s,int t){
		int lim=n/2;
		tmp[0]=s;
//		printf("L:\n");
		dfs(1,lim,ansl,s,1<<s,0);
//		printf("R:\n");
		tmp[0]=t;
		dfs(1,lim,ansr,t,1<<t,0);
		int all=(1<<lim);
		for(int i=0;i<all;i++){
			if(ansl[i].size()) sort(ansl[i].begin(),ansl[i].end());
			if(ansr[i].size()) sort(ansr[i].begin(),ansr[i].end());
		}
		long long ans=INF;
		for(int i=0;i<all;i++){
			for(int j=0;j<ansl[i].size();j++){
				int x=ansl[i][j];
				int rev=((1<<n)-1)&(~i);
				if(ansr[rev].size()){
					ans=min(ans,x+ansr[rev][0]+w[s][t]);
				}
			}
		}
		for(int i=0;i<all;i++){
			ansl[i].clear();
			ansr[i].clear();
		}
		return ans;
	}
	
	void solve(){
		long long ans=INF;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					ans=min(ans,calc(i,j));
				}
			}
		}
//		ans=calc(0,3);
		printf("%lld\n",ans);
	}
}
int main(){
#ifndef LOCAL
	freopen("alb.in","r",stdin);
	freopen("alb.out","w",stdout);
#endif
	scanf("%d",&k);
	n=(1<<k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&w[i][j]);
		}
	}
//	meet_in_the_middle::solve();
	if(k<=3){
		brute_force::solve();
	}else{
		meet_in_the_middle::solve();
	}
}

/*
2
0 7 2 1
7 0 4 3
2 4 0 5
1 3 5 0

3
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
