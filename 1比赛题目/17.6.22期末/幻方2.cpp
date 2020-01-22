#include<iostream>
#define maxn 40
using namespace std;
int hf[maxn][maxn];
int x,y;
int n;
void dis(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<hf[i][j]<<' ';
		}
		cout<<endl;
	}	
}
int main(){
	cin>>n;
	x=1;
	y=(n+1)/2;
	hf[x][y]=1;
	for(int k=2;k<=n*n;k++){
		if(x==1&&y!=n){
			x=n-1;
			y++;
			hf[x][y]=k;
			continue;
		}
		if(x!=1&&y==n){
			x--;
			y=1;
			hf[x][y]=k;
			continue;
		}
		if(x==1&&y==n){
			x++;
			hf[x][y]=k;
			continue;
		}
		if(x!=1&&y!=n){
			if(hf[x-1][y+1]==0)
            {
                x--;
                y++;
                hf[x][y]=k;
                continue;
            }
            else{
            	x++;
            	hf[x][y]=k;
            	continue;
			}   
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<hf[i][j]<<' ';
		}
		cout<<endl;
	}	
}

