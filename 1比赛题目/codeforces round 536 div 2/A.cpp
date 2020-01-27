#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
char a[505][505];
const int walkx[4]={-1,-1,1,1},walky[4]={-1,1,-1,1};
int check(int i,int j) {
	for(int k=0; k<4; k++) {
		int x=i+walkx[k];
		int y=j+walky[k];
		if(x>=1&&x<=n&&y>=1&&y<=n) {
			if(a[x][y]=='.') return 0;
		}else return 0;
	}
	return 1;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(a[i][j]=='X'&&check(i,j)) cnt++;
		}
	}
	cout<<cnt;
}

