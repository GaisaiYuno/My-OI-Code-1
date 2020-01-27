#include<iostream>
#include<cstdio>
#define maxn 5005
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign;
}

int h,w,q;
char s[maxn+5];
char a[maxn+5][maxn+5];
int sum1[maxn+5][maxn+5];
int sum2[maxn+5][maxn+5];
void ini(){
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int val=0;
			if(a[i][j]=='.'&&a[i][j-1]=='.') val++;
			sum1[i][j]=sum1[i][j-1]+sum1[i-1][j]-sum1[i-1][j-1]+val; 
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int val=0;
			if(a[i][j]=='.'&&a[i-1][j]=='.') val++;
			sum2[i][j]=sum2[i][j-1]+sum2[i-1][j]-sum2[i-1][j-1]+val; 
		}
	}
}

int query_1(int x1,int y1,int x2,int y2){
	y1++;
	return sum1[x2][y2]-sum1[x1-1][y2]-sum1[x2][y1-1]+sum1[x1-1][y1-1];
}

int query_2(int x1,int y1,int x2,int y2){
	x1++;
	return sum2[x2][y2]-sum2[x1-1][y2]-sum2[x2][y1-1]+sum2[x1-1][y1-1];
}
int main(){
	int x1,y1,x2,y2;
	scanf("%d %d",&h,&w);
	for(int i=1;i<=h;i++){
		scanf("%s",s+1);
		for(int j=1;j<=w;j++){
			a[i][j]=s[j];
		}
	}
	ini();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int maxx=max(x1,x2),minx=min(x1,x2);
		int maxy=max(y1,y2),miny=min(y1,y2);
		printf("%d\n",query_1(minx,miny,maxx,maxy)+query_2(minx,miny,maxx,maxy));
	}
}
/*
...#
#...
#.#.
#..
*/ 
