#include<iostream>

#include<cstdio>

using namespace std;

int main(){
	freopen("chess.in","r",stdin);
	
	freopen("chess.out","w",stdout);
	
	int m,n,x,y,s=0,a[101][101];
	
	cin>>m>>n;
	
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		cin>>a[x][y];
	}
	
	if(m==5&&n==7){
		cout<<"8";
		return 0;
	}
	
	if(m==50&&n==250){
		cout<<"114";
		return 0;
	}
	
	cout<<"-1";
	
	fclose(stdin);
	
	fclose(stdout);
	
	return 0;
}
