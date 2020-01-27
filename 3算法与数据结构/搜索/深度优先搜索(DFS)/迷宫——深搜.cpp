#include<iostream>
#include<cstring>
//#include<cstdio>
using namespace std;
#define N  1000
char mg[N][N];
int used[N][N];
int c[4]= {0,0,-1,1},d[4]= {-1,1,0,0};
int xa,ya,xb,yb;
int m,n;
/* ����x 0 y -1
   ����x 0 y +1
   ����x -1 y 0
   ����x +1 y 0

*/
int search(int x,int y) {
	if (x<0||y<0||x>=n||y>=n) return 0;//Խ��
	if (mg[x][y]=='#'||used[x][y]==1) return 0;//�����ϰ� ���߹�
	if (x==xb&&y==yb) return 1;
	used[x][y]=1;
	for(int i=0; i<4; i++)
		if(search(x+c[i],y+d[i])) return 1;
	return 0;
}

int main() {
	int k;
	cin>>k;
	int out[k-1];
	for(int i=0; i<k; i++) {
		 memset(used,0,sizeof(used));
		cin>>n;
		for(int p=0; p<n; p++) {
			cin>>mg[p];
		}
		cin>>xa>>ya>>xb>>yb;
    //search(xa,ya);
    if(search(xa,ya)) out[i]=1;
    else out[i]=0;
	}
	for(int q=0;q<k;q++){
	if(out[q]==1) cout<<"YES"<<'\n';
	else cout<<"NO"<<'\n';
}
}




