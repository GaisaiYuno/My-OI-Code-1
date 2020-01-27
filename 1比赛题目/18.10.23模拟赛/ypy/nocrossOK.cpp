//luogu 3657 
//首先显然可以看出是变种的LCS
//dp[i][j]表示序列a前i个与序列b前j个连线数量
//dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1](abs(a[i]-b[j])<=4))
//考虑LIS转LCS，原本的方法是记录a[i]中每个值的位置pos,将b[i]转化为pos[b[i]] 
//既然 (abs(a[i]-b[j])<=4都可杯看做“相等”
//则我们对于每个b[i]±j (0<=j<=4),将pos[b[i]±j]加入数组c,求c的LIS即为答案
//但注意到每个点只能连一条边，也就是对于每个b[i]，9个b[i]±j中只能选一个加入LIS
//所以将9个一组从大到小排序，再拼起来，这样每组数中至多有一个数被选进LIS，（若选两个，则c[i]>c[i+1],矛盾）   
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005
using namespace std;
int n;
int a[maxn],b[maxn];
int pos[maxn];
vector<int>tmp;
vector<int>c;
int s[maxn*9];
int m;
int cmp(int x,int y) {
	return x>y;
}
int solve() {
	for(int i=1;i<=n;i++){
		tmp.clear();
		for(int j=0;j<=4;j++){
			if(b[i]+j<=n) tmp.push_back(pos[b[i]+j]);
			if(b[i]-j>=1) tmp.push_back(pos[b[i]-j]);
		}
		sort(tmp.begin(),tmp.end(),cmp);
		int t=tmp.size();
		for(int j=0;j<t;j++){
			c.push_back(tmp[j]);
		}
	}
	int m=c.size();
//	for(int i=0;i<m;i++) printf("%d ",c[i]);
//	printf("\n");
	int top=0;
	for(int i=0; i<m; i++) {
		if(c[i]>s[top]) {
			s[++top]=c[i];
		} else {
			int tmp=lower_bound(s+1,s+1+top,c[i])-s;
			s[tmp]=c[i];
		}
	}
	return top;
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&b[i]);
	}
	printf("%d\n",solve());
}
