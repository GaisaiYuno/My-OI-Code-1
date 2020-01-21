#include<iostream>
#include<cstring>
using namespace std;
char lq[100][100];
char lq2[100][100];
int n,m;
int c[8]= {0,0,-1,1,-1,1,-1,1},d[8]= {-1,1,0,0,-1,-1,1,1};
/* 向上x 0 y -1
   向下x 0 y +1
   向左x -1 y 0
   向右x +1 y 0
   左上x -1 y-1
   右上x +1 y-1
   左下x -1 y+1
   右下x +1 y+1
*/
int sao(int x,int y) {
  if (x<0||y<0||x>=n||y>=m) return 0;
  for(int i=0;i<8;i++){
  lq2[x+c[i]][y+d[i]]=lq2[x+c[i]][y+d[i]]+1;
  }
  return 0;
}
int main() {
	cin>>n>>m;
	memset(lq2,0,sizeof(lq2));

	for(int p=0; p<n; p++) {
		cin>>lq[p];
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; i++) {
			if(lq[i][j]='#'){
			lq2[i][j]='*';
			sao(i,j);
			}
	}
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cout<<lq2[i][j];
	}
   }
   return 0;
}
