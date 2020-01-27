#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n,m;
char tmp[maxn];
char a[maxn][maxn];
char b[maxn][maxn];
int walkx[8]= {1,1,1,-1,-1,-1,0,0};
int walky[8]= {0,1,-1,0,1,-1,1,-1};
int check(int x,int y) {
	for(int i=0; i<8; i++) {
		if(a[x+walkx[i]][y+walky[i]]!='#') {
			return 0;
		}
	}
	return 1;
}

void work(int x,int y) {
	for(int i=0; i<8; i++) {
		b[x+walkx[i]][y+walky[i]]='#';
	}
}
int main() {
	memset(b,'.',sizeof(b)); 
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%s",tmp);
		for(int j=1; j<=m; j++) {
			a[i][j]=tmp[j-1];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(check(i,j)) {
				work(i,j);
			}
		}
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!=b[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(flag) printf("YES");
	else printf("NO");
}
