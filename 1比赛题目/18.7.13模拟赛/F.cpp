#include <iostream>
#include <cstdio>
#define maxn 505
using namespace std;
int n,m,k;
char map[maxn][maxn];
int cnt1[maxn][maxn];//heng
int cnt2[maxn][maxn];//shu
int cnt[maxn][maxn];//zong he
int sum[maxn][maxn];//qian zhui he
void ini(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]=='.'){
				if(j+1<=m&&map[i][j+1]=='.') cnt1[i][j]=1;
				if(i+1<=n&&map[i+1][j]=='.') cnt2[i][j]=1;
				cnt[i][j]=cnt1[i][j]+cnt2[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[i][j-1]+cnt[i][j];
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch=getchar();
			while(ch!='.'&&ch!='#')ch=getchar();
			map[i][j]=ch;
		}
	}
	ini();
	scanf("%d",&k);
	int a,b,c,d;
	for(int i=1;i<=k;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int ans=0;
		for(int j=a;j<=c;j++){
			ans+=sum[j][d]-sum[j][b-1];
		}
		for(int j=a;j<=c;j++){
			ans-=cnt1[j][d];
		}
		for(int j=b;j<=d;j++){
			ans-=cnt2[c][j];
		}
		printf("%d\n",ans);
	}
}
