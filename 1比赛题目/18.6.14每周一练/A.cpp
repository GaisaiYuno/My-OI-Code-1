#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int a,b,c,d;
char ma[maxn][maxn];
void setv(char c,int x1,int x2,int y1,int y2){
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			ma[i][j]=c;
		}
	}
}
int main(){
	scanf("%d %d %d %d",&a,&b,&c,&d);
	setv('D',1,25,1,25);
	setv('C',26,50,1,25);
	setv('B',1,25,26,50);
	setv('A',26,50,26,50);
	a--;
	b--;
	c--;
	d--;
	for(int i=1;i<=25;i++){
		for(int j=1;j<=25;j++){
			if(a==0) break;
			if(i%2&&j%2){
				ma[i][j]='A';
				a--;
			}
		}
	}
	for(int i=26;i<=50;i++){
		for(int j=1;j<=25;j++){
			if(b==0) break;
			if(i%2==0&&j%2==0){
				ma[i][j]='B';
				b--;
			}
		}
	}
	for(int i=1;i<=25;i++){
		for(int j=26;j<=50;j++){
			if(c==0) break;
			if(i%2&&j%2){
				ma[i][j]='C';
				c--;
			}
		}
	}
	for(int i=26;i<=50;i++){
		for(int j=26;j<=50;j++){
			if(d==0) break;
			if(i%2==0&&j%2==0){
				ma[i][j]='D';
				d--;
			}
		}
	}
	printf("50 50\n");
	for(int i=1;i<=50;i++){
		for(int j=1;j<=50;j++){
			printf("%c",ma[i][j]);
		}
		printf("\n");
	}
} 
