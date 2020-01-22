#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n,m,sum;
int a[maxn][maxn];
int s[maxn][maxn];
int check(int x,int y){
	if(sum%(x*y)) return 0;
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if(s[i][j]>a[i][j]) return 0;
			int t=a[i][j]-s[i][j]; 
			if(t!=0){
				if(i+x>n+1&&j+y>m+1) return 0;
				s[i][j]+=t;
				s[i+x][j]-=t;
				s[i][j+y]-=t;
				s[i+x][j+y]+=t;
			}
		}
	}
	return 1; 
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
	}
	int ans=sum;
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(sum/(i*j)<ans&&check(i,j)){
				ans=sum/(i*j);
			} 
		}
	}
	printf("%d\n",ans);
} 
