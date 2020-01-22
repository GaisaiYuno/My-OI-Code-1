#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
struct f{
	int c;
	long long sum;
}a[105][105];
int l1,l2,t1,t2;
int oo=999999;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,x,y,C;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y>>C;
		a[x][y].c=C+1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			t1=0;t2=0;
			if((a[i][j-1].c==1&&a[i][j].c==2)||(a[i][j-1].c==2&&a[i][j].c==1)){
				t1=1;
			}
			else if(a[i][j-1].c==0){
				t1=2;
				if(a[i][j].c==0)t1=oo;
			}

			if((a[i-1][j].c==1&&a[i][j].c==2)||(a[i-1][j].c==2&&a[i][j].c==1)){
				t2=1;
			}
			else if(a[i-1][j].c==0){
				t2=2;
				if(a[i][j].c==0)t2=oo;
			}

			a[i][j].sum=min(a[i][j-1].sum+t1,a[i-1][j].sum+t2);
		}
	}
	if(a[m][m].sum>=oo){
		cout<<-1;
		return 0;
	}
	cout<<a[m][m].sum-2;
	return 0;
}
