#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000
using namespace std;
int n,k;
char s[maxn+5][maxn+5];
int origrow[maxn+5];
int origcol[maxn+5];
int osumrow[maxn+5];
int osumcol[maxn+5];

int rowl[maxn+5][maxn+5];
int rowr[maxn+5][maxn+5];
int rowtot[maxn+5][maxn+5];
int sumrt[maxn+5][maxn+5];

int coll[maxn+5][maxn+5];
int colr[maxn+5][maxn+5];
int coltot[maxn+5][maxn+5];
int sumct[maxn+5][maxn+5];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		rowl[i][0]=1;
		for(int j=1;j<=n;j++){
			rowl[i][j]=rowl[i][j-1]&(s[i][j]=='W');
		}
		rowr[i][n+1]=1;
		for(int j=n;j>=1;j--){
			rowr[i][j]=rowr[i][j+1]&(s[i][j]=='W');
		}
		if(rowl[i][n]==1) origrow[i]=1; 
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j+k<=n;j++){
			if(rowl[i][j]&&rowr[i][j+k+1]) rowtot[i][j]=1;
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			sumrt[i][j]=sumrt[i-1][j]+rowtot[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		coll[0][i]=1;
		for(int j=1;j<=n;j++){
			coll[j][i]=coll[j-1][i]&(s[j][i]=='W');
		}
		colr[n+1][i]=1;
		for(int j=n;j>=1;j--){
			colr[j][i]=colr[j+1][i]&(s[j][i]=='W');
		}
		if(coll[n][i]==1) origcol[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j+k<=n;j++){
			if(coll[j][i]&&colr[j+k+1][i]) coltot[j][i]=1;
		} 
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			sumct[i][j]=sumct[i][j-1]+coltot[i][j];
		}
	}
	
	for(int i=1;i<=n;i++) osumrow[i]=osumrow[i-1]+origrow[i];
	for(int i=1;i<=n;i++) osumcol[i]=osumcol[i-1]+origcol[i];
	int ans=0;
	int sum=0;
	for(int i=1;i+k-1<=n;i++){
		for(int j=1;j+k-1<=n;j++){
			sum=sumct[i-1][j+k-1]-sumct[i-1][j-1]+sumrt[i+k-1][j-1]-sumrt[i-1][j-1];
			sum-=osumrow[i+k-1]-osumrow[i-1];
			sum-=osumcol[j+k-1]-osumcol[j-1];
			sum+=osumrow[n];
			sum+=osumcol[n];
			ans=max(ans,sum);
		}
	}
	printf("%d\n",ans);
}

