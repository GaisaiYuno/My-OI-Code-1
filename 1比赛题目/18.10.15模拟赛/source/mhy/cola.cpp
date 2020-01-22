#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 35
#define Size 2
using namespace std;
//struct Matrix{
//	int num[MAXN][MAXN];
//	int m,n;
//	void print(string s){
//		cout<<s<<endl;
//		for (int i=1;i<=m;++i){
//			for (int j=1;j<=n;++j){
//				printf("%d ",num[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
//};
vector<int>G[MAXN];
int t,n,m;
static int DP[MAXN][Size];
//Matrix operator * (Matrix a,Matrix b){
//	Matrix ans;
//	memset(ans.num,0,sizeof(ans.num));
//	for (register int i=1;i<=a.m;++i){
//		for (register int j=1;j<=a.n;++j){
//			for (register int k=1;k<=b.n;++k){
//				ans.num[i][j]=((a.num[i][k]*b.num[k][j])%MOD+ans.num[i][j])%MOD;
//			}
//		}
//	}
//	ans.m=a.m;
//	ans.n=a.n;
//	return ans;
//}
//inline Matrix ksm(int t,Matrix edge){
//	Matrix st;
//	for (int i=1;i<=n;++i){
//		for (int j=1;j<=n;++j){
//			st.num[i][j]=(i==j);
//		}
//	}
//	st.m=n,st.n=n;
//	while (t){
//		if (t&1){
//			st=st*edge;
//		}
//		edge=edge*edge;
//		t>>=1;
//	}
//	Matrix add;
//	for (int i=1;i<=n;++i){
//		add.num[1][i]=1;
//	}
//	add.m=n,add.n=n;
//	return add*st;
//}
static int s[MAXN];
void dp(){
	for (register int i=1;i<=n;++i){
		DP[i][(t&1)]=1;
	}
	register int k=t-1;
	for (;k>=0;k-=4){
		int x=(k&1),y=!(k&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
		x=((k-1)&1),y=!((k-1)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
		x=((k-2)&1),y=!((k-2)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
		x=((k-3)&1),y=!((k-3)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
	}
	if (k==1){
		int x=((k-1)&1),y=!((k-1)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
	}
	else if (k==2){
		int x=((k-1)&1),y=!((k-1)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
		x=((k-2)&1),y=!((k-2)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
	}
	else if (k==3){
		int x=((k-1)&1),y=!((k-1)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
		x=((k-2)&1),y=!((k-2)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
		x=((k-3)&1),y=!((k-3)&1);
		for (register int i=1;i<=n;++i){
			DP[i][x]=(DP[i][y]+1);
			for (register int j=0;j<s[i];++j){DP[i][x]=(DP[i][x]+DP[G[i][j]][y])%2017;}
		}
	}
}
void print_dp(){
	for (int i=t;i>=0;--i){
		for (int j=1;j<=n;++j){
			printf("%d ",DP[j][i]);
		}
		printf("\n");
	}
}
int main(){
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (register int i=1;i<=n;++i){
		s[i]=G[i].size();
	}
	scanf("%d",&t);
	dp();
	printf("%d\n",DP[1][0]);
}
