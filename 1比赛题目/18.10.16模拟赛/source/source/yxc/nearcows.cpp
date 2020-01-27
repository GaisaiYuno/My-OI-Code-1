#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define maxn 100005
#define lm 21
using namespace std;
inline int fread(){
	register int f=1,x=0;
	register char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int n,k;
vector<int>M[maxn];
int C[maxn];
int F1[maxn][lm],F2[maxn][lm];
int Fa[maxn];
void dfs1(int th,int fa){
	Fa[th]=fa;
	for(register int i=0;i<=k;i++) F1[th][i]=C[th];
	for(register vector<int>::iterator i=M[th].begin();i!=M[th].end();i++){
		if(*i==fa) continue;
		dfs1(*i,th);
		for(register int j=1;j<=k;j++){
			F1[th][j]+=F1[*i][j-1];
		}
	}
}
void dfs2(int th,int fa){
	F2[th][0]=C[th];
	F2[th][1]=C[th]+C[fa];
	for(register int i=2;i<=k;i++){
		F2[th][i]=C[th]+F2[fa][i-1];
		for(register vector<int>::iterator j=M[fa].begin();j!=M[fa].end();j++){
			if(*j==th||*j==Fa[fa]) continue;
			F2[th][i]+=F1[*j][i-2];
		}
	}
	for(register vector<int>::iterator i=M[th].begin();i!=M[th].end();i++){
		if(*i==fa) continue;
		dfs2(*i,th);
	}
}
int main(){
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	n=fread(),k=fread();
	for(int i=1;i<n;i++){
		int a=fread(),b=fread();
		M[a].push_back(b);
		M[b].push_back(a);
	}
	for(register int i=1;i<=n;i++) C[i]=fread();
	dfs1(1,0);
	dfs2(1,0);
	for(register int i=1;i<=n;i++) printf("%d\n",F1[i][k]+F2[i][k]-C[i]);
}
/*
6 2
5 1
3 6
2 4
2 1
3 2
1 2 3 4 5 6
*/
