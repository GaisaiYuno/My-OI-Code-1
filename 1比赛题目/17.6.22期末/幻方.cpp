#include<iostream>
#define maxn 40
using namespace std;
int hf[maxn][maxn];
int x,y;
int n;
int main(){
	cin>>n;
	x=0;
	y=(n-1)/2;
	hf[x][y]=1;
	for(int k=2;k<=n*n;k++){
		if(x==0&&y!=n-1){
			x=n-1;
			y++;
		}
		if(x!=0&&y==n-1){
			x--;
			y=1;
		}
		if(x==0&&y==n-1){
			x++;
		}
		if(x!=0&&y!=n-1){
			if(a[x-1][y+1]==0)
            {
                x--;
                y++;
            }
            else 
                x++;
		}
		hf[x][y]=k;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<hf[i][j]<<' ';
		}
		cout<<endl;
	}	
}
}
