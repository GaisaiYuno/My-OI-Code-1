#include<iostream>
#include<cstdio>
#define maxn 2005
#define maxm 2005
using namespace std;
int n,m;
char t[maxn][maxm];
int a[maxn][maxm];
int sum[maxn];
int main(){
	char tmp;
	scanf("%d %d\n",&n,&m);
	for(int i=0;i<n;i++) gets(t[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=t[i-1][j-1]-'0';
			sum[j]+=a[i][j];
		}
	}
	bool flag=false;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt=0;
		int j;
		for(j=1;j<=m;j++){
			if(sum[j]-a[i][j]==0){
				break;
			}
			cnt++;
		}
		if(cnt==m) flag=true;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}
