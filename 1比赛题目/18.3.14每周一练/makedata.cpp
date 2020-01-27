#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 25
using namespace std;
int a[maxn][maxn];
int main() {
	freopen("data_a.txt","w",stdout); 
	srand(time(NULL));
	int t=rand()%5;
	while(t--) {
		int n=rand()%5+1;
		int m=rand()%5+1;
		int sx=rand()%n+1;
		int sy=rand()%m+1;
		int ex=rand()%n+1;
		int ey=rand()%m+1;
		cout<<n<<' '<<m<<endl; 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(i==sx&&j==sy) {
					a[i][j]=2;
				} else if(i==ex&&j==ey) {
					a[i][j]=3;
				} else {
					if(rand()%4==0) a[i][j]=1;
					else a[i][j]=0;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
                cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	cout<<0<<' '<<0<<endl;
}
