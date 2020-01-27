#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000000
#define INF 0x3f3f3f3f
using namespace std;
int tab[10][10][10];
int calc(int c,int a,int b){
	int ans=INF;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(i+j==0) continue;
			//注意如果i+j=0，c也=0，
			//如果a,b不为0的话，我们无法使得c=0,所以要判掉 
			if((a*i+b*j)%10==c%10){
				ans=min(ans,i+j);
			} 
		}
	}
	if(ans==INF) ans=-1;
	return ans; 
}

int n;
char s[maxn+5];
int a[maxn+5];
int solve(int x,int y){
	int ans=0;
	for(int i=1;i<n;i++){
		int tmp=(a[i+1]-a[i]+10)%10;
		if(tab[tmp][x][y]==-1) return -1;
		else ans+=tab[tmp][x][y]-1;
	}
	return ans;
}
int main(){
//	freopen("t.out","w",stdout);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				tab[i][j][k]=calc(i,j,k);
//				printf("%d\n",tab[i][j][k]);
			}
		}
	}
//	return 0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d ",solve(i,j));
		}
		printf("\n");
	}
}

