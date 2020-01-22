#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a[205][205],b[205][205];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,k,m,n,s=0,p=0,q,u,r,w;
	cin>>m>>n;
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			cin>>q>>u>>r;
			a[q][u]=r+1;
		}
	}
	i=1;j=1;
	while(i!=m&&j!=m){
		k=0;
		b[i][j]=1;
		if(a[i][j+1]==2){
			j+=1;
			k=2;
			p=0;
		}
		else if(a[i][j+1]==1){
			k=1;
			j+=1;
			s++;
			p=0;
		}
		if(k!=2)if(a[i+1][j]==2){
			i+=1;
			if(k==1) {
				j-=1;
				s--;
			}
			p=0;
		}
		else if(a[i+1][j]==1){
			k=1;
			i+=1;
			s++;
			p=0;
		}
		if(a[i-1][j]==2&&b[i-1][j]==0){
			i--;
			k=2;
			p=0;
		}
		else if(a[i-1][j]==1&&b[i-1][j]==0){
			k=1;
			i--;
			s++;
			p=0;
		}
		if(k==0&&p==0){
			p++;
			s+=2;
			i+=1;
			j++;
		}
		if(p==2){
			cout<<-1;
			break;
		}
	}
	 cout<<s;
	return 0;
}
