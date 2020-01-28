#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 16
using namespace std;
int n=5;
int walkx[10]= {1,1,-1,-1,2,2,-2,-2};
int walky[10]= {2,-2,2,-2,1,-1,1,-1};
char now[maxn][maxn];
char final[maxn][maxn]= {{},{' ','1','1','1','1','1'},{' ','0','1','1','1','1'},{' ','0','0','*','1','1'},{' ','0','0','0','0','1'},{' ','0','0','0','0','0'}};
int is_same() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(now[i][j]!=final[i][j]) return 0;
		}
	}
	return 1;
}
int h() { //¹À¼Ûº¯Êý
	int cnt=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(now[i][j]!=final[i][j]) cnt++;
		}
	}
	return cnt;
}
int ida(int deep,int limit,int x,int y) {
//	printf("%d %d %d %d\n",deep,dasadfslimit,x,y);
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			printf("%c",now[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	if(deep>limit) return 0;
	if(deep==limit) {
		if(is_same()) {
//			for(int i=1; i<=n; i++) {
//				for(int j=1; j<=n; j++) {
//					printf("%c",now[i][j]);
//				}
//				printf("\n");
//			}
			return 1;
		} else return 0;
	}
	int flag=0;
	for(int i=0; i<8; i++) {
		int xx=x+walkx[i],yy=y+walky[i];
		if(xx<1||yy<1||xx>n||yy>n) continue;
		swap(now[x][y],now[xx][yy]);
		if(deep+h()<=limit) flag|=ida(deep+1,limit,xx,yy);
		swap(now[x][y],now[xx][yy]);
	}
	return flag;
}
int t;
int main() {
	scanf("%d",&t);
	while(t--) {
		int sx,sy;
		for(int i=1; i<=5; i++) {
			for(int j=1; j<=5; j++) {
				cin>>now[i][j];
				if(now[i][j]=='*') {
					sx=i;
					sy=j;
				}
			}
		}
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++) {
//				printf("%c",final[i][j]);
//			}
//			printf("\n");
//		}
		for(int i=0; i<=16; i++) {
			if(i==16) {
				printf("-1\n");
				break;
			}
			if(ida(0,i,sx,sy)) {
				printf("%d\n",i);
				break;
			}
		}
	}
}
/*
1
11111
0111*
00111
00001
00000
*/


