#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxw 300
#define maxn 1000000
using namespace std;
typedef long long ll;
vector<ll>w[maxw+5];
ll dp[2][maxn+5];
int n,m;
void divide(int l,int r,int x,int y,int now,int mod,int rest){
	//列[l,r],行[x,y]; 
	if(l>r) return;
	int mid=(l+r)>>1,pos=mid;
	dp[now^1][mid*mod+rest]=dp[now][mid*mod+rest];
	for(int j=min(y,mid-1);j>=x;j--){//枚举可能成为pos(mid)的列,注意j<mid 
		if(mid-j>(int)w[mod].size()) break;
//		printf("%d\n",w[mod][mid-j-1]);
		if(dp[now][j*mod+rest]+w[mod][mid-j-1]>dp[now^1][mid*mod+rest]){
			dp[now^1][mid*mod+rest]=dp[now][j*mod+rest]+w[mod][mid-j-1];
			pos=j;
		} 
	}
	divide(l,mid-1,x,pos,now,mod,rest);
	divide(mid+1,r,pos,y,now,mod,rest);
}

inline int cmp(int x,int y){
	return x>y;
}
int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		w[x].push_back(y);
	} 
	for(int i=1;i<=maxw;i++){
		sort(w[i].begin(),w[i].end(),cmp);
		for(int j=1;j<(int)w[i].size();j++) w[i][j]+=w[i][j-1]; 
	}
	int now=0;
	for(int i=1;i<=300;i++){
		if(w[i].size()){
			for(int j=0;j<i;j++){
				//将模i同余的所有位置拿出来
				divide(0,(m-j)/i,0,(m-j)/i,now,i,j); 
			}
			for(int j=1;j<=m;j++){
				dp[now^1][j]=max(dp[now^1][j],dp[now^1][j-1]);
				//我们dp的子状态是体积<=j,而分治过程中是=j 
			}
			now^=1;
		}
	}
	for(int i=1;i<=m;i++) printf("%I64d ",dp[now][i]);
}

