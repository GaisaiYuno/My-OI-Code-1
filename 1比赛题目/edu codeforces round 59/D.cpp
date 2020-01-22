#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5205
using namespace std;
int n;
int a[maxn][maxn];
int sum[maxn][maxn];
void ini(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
}

int query(int x1,int y1,int x2,int y2){
	return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}

bool check(int x){
	for(int i=1;i<=n/x;i++){
		for(int j=1;j<=n/x;j++){
			int tot=query(i*x-x+1,j*x-x+1,i*x,j*x);
			if(tot!=x*x&&tot!=0) return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		getchar();
		for(int j=1;j<=n;j+=4){
			char c=getchar();
			int x;
			if(c>='0'&&c<='9') x=c-'0';
			else x=c-'A'+10;
			for(int k=0;k<4;k++){
				a[i][j+k]=1&(x>>(3-k));
			}
		}
	}
	ini();
	for(int i=n;i>=1;i--){
		if(n%i==0){
			if(check(i)){
				printf("%d\n",i);
				return 0;
			}
		}
	}
}

