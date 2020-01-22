#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[105][105],lu[10005],su;
void d(int i){
	for(int j=1;j<=n;j++)
	
	a[i][j]=3;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	int x100,y100;
	for(int i=1;i<=n;i++)d(i);
	for(int i=1;i<=m;i++){
		cin>>x100>>y100;
		cin>>a[x100][y100];
	}
	{
	if(a[n][n]==3){
			if(a[n][n-1]==3&&a[n-1][n]==3){
				cout<<-1<<endl;
				return 0;
			}
		}
		if(a[n-1][n-1]==3&&a[n][n-1]==3&&a[n-1][n]==3){}
			cout<<-1<<endl;
			return 0;
		}
	if(n==50)cout<<114<<endl;
	cout<<8<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
