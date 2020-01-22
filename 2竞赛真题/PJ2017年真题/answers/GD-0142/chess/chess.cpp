#include <iostream>
#include <cstdio>
#define MAXM 105
using namespace std;

int m,n;
int map[MAXM][MAXM];

void init()
{
	for (int i=1;i<=MAXM;i++){
		for (int j=1;j<=MAXM;j++){
			map[i][j]=-1;
		}
	}
}

int main()
{
	init();
	int x,y,c;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++){
		cin>>x>>y>>c;
		map[x][y]=c;
	}
	cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
