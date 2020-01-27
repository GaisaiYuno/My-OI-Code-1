#include<iostream>
#include<cstdio>
#define maxn 105 
using namespace std;
int n;
char a[maxn][maxn];
const int walkx[4]={1,1,1,2},walky[4]={-1,1,0,0};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1); 
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]=='.'){
				a[i][j]='#';
				for(int k=0;k<4;k++){
					int x=i+walkx[k];
					int y=j+walky[k];
					if(x>=1&&x<=n&&y>=1&&y<=n&&a[x][y]=='.'){
						a[x][y]='#';
					}else{
						flag=false;
						break;
					}
				}
			}
			if(!flag) break;
		}
		if(!flag) break;
	}
	if(flag) printf("YES\n");
	else  printf("NO\n");
}	

