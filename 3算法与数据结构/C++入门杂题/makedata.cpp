#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<ctime>
char a[100][100];
using namespace std;
int main() {
	srand((unsigned)time(NULL));
	freopen("testdata.txt","w",stdout);
	int t=rand()%10+1;
	while(t--) {
		int n=rand()%10+1;
		int m=rand()%10+1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				int t=rand()%4;
				if(t==0) a[i][j]='.';
				if(t==1) a[i][j]='*';
				if(t==2) a[i][j]='|';
				if(t==3) a[i][j]='-';
			}
		}
		int x1,x2,y1,y2;
		x1=rand()%n+1;
		y1=rand()%m+1;
		x2=rand()%n+1;
		y2=rand()%m+1;
		a[x1][y1]='S';
		a[x2][y2]='T';
		cout<<n<<' '<<m<<endl;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}

}
