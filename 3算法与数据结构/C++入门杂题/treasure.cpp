//treasure
#include<iostream>
#include<cstring>
#define maxn 10001
#define maxm 101
using namespace std;
//long long ans=0;
int n,m,r;
struct room {
	int s;
	int x;
} a[maxn][maxm];
int stair[maxn]; //记录每层有楼梯的房间数
int main() {
	//int i,j;
	memset(stair,0,sizeof(stair));
	cin>>n>>m;
	for(int u=1; u<=n; u++) {
		for(int v=1; v<=m; v++) {
			cin>>a[u][v-1].s>>a[u][v-1].x;
			if(a[u][v-1].s==1) stair[u]++;
		}
	}
	cin>>r;
	int jj=r,ii=1,ans=0,t;
	while(ii<=n) {
		ans=(ans+a[ii][jj].x)%20123;//边做边取模，防止中间结果溢出
		int tt=jj;
		t=0;
		int c=a[ii][jj].x%stair[ii];
		/*非常重要的一步！！,没有会TLE
		  减少在每一层转的次数 ，如本应找第10个，该层有3个有楼梯的房间 ，那直接找第1个
		 降低了时间复杂度，降到了O（n*m），可以承受。
		 */
		if(c==0) c=stair[ii];
		while(t<c) {
			if(a[ii][tt].s==1) t++;
			if(tt==m-1&&t!=c) tt=0;//做到循环
			else if(t!=c) tt++;
		}
		jj=tt;
		ii++;
	}
	cout<<ans%20123<<endl;
	return 0;
}
