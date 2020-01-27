//drawing
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<ctime>
#define maxn 55
#define maxk 550
using namespace std;
int map[maxn][maxn];
char pic[maxk][maxk];
int m,n,k,l;
int x0,y0;//基准点，第一行第一个方块的第一个像素在画中的坐标
const char block[6][8]={
	"..+---+",
	"./   /|",
	"+---+ |",
	"|   | +",
	"|   |/.",
	"+---+.."
};
/*
x=2y+4x
y=2y+3z

整个图的右上角坐标
x=2y+4x+1
y=2y+3z
将这个右上角坐标取最大值，就是整张图的范围
*/
void cal_k() {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			k=max(k,2*(m-i-1)+3*(map[i][j]+1)) ;
		}
	}
	return;
}
void cal_l() {
	l = 4*n + 2*m + 1 ;
	return;
}
void cal_std() {
	x0 = k - 4 - 2*m;
	y0 = 2*m - 2;
	return;
}
void paint(int a,int b,int c) { //画第a行第b列从下往上数第c个方块
	int x,y;
	x=x0+2*a-3*c;//计算本块坐标
	y=y0+4*b-2*a;
	for(int i=0; i<6; i++) {
		for(int j=0; j<7; j++) {
			if(block[i][j]!='.') pic[x+i][y+j]=block[i][j];
		}
	}
	return;
}
int main() {
	int i,j;
	srand((unsigned)time(NULL));
	//freopen("drawing10.in","r",stdin);
	freopen("pic.txt","w",stdout);
	m=rand()%56;
	n=rand()%56; 
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) map[i][j]=rand()%100;
	}
	cal_k();
	cal_l();
	cal_std();
	memset(pic,'.',sizeof(pic));
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			for(int u=0; u<map[i][j]; u++) {
				paint(i,j,u);
			}
		}
	}
	for(i=0;i<k;i++){
        for(j=0;j<l;j++){
            cout<<pic[i][j];
        }
        cout<<endl;
    }
    return 0;
}
