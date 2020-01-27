#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n,m;
char a[maxn][maxn],b[maxn][maxn]; 
struct res{
	int x;
	int y;
	int s;
}out[maxn*maxn];
void debug(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%c",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j]; 
			b[i][j]='.';
		}
	}
	int cnt=0;
//	debug();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*'){
//				printf("%d %d\n",i,j); 
				int ans=99999999,k;
				for(k=i;k>=1;k--){
					if(a[k-1][j]!='*') break;
				}
				ans=min(ans,i-k);
				for(k=i;k<=n;k++){
					if(a[k+1][j]!='*') break;
				}
				ans=min(ans,k-i);
				for(k=j;k>=1;k--){
					if(a[i][j-1]!='*') break;
				}
				ans=min(ans,j-k);
				for(k=j;k<=m;k++){
					if(a[i][k+1]!='*') break;
				}
				ans=min(ans,k-j);
				if(ans==99999999) continue;
				if(ans==0) continue;
//				printf("%d\n",ans);
				for(k=i;i-k<=ans;k--){
					b[k][j]='*';
				}
				for(k=i;k-i<=ans;k++){
					b[k][j]='*';
				}
				for(k=j;j-k<=ans;k--){
					b[i][k]='*';
				}
				for(k=j;k-j<=ans;k++){
					b[i][k]='*';
				}
				cnt++;
				out[cnt].x=i;
				out[cnt].y=j;
				out[cnt].s=ans;
//				debug();
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]!=a[i][j]){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d %d %d\n",out[i].x,out[i].y,out[i].s);
	}
}
