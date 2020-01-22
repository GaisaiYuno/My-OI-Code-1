#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int a[150][150],f[150][150],t[150][150];
int bijiao(int p,int q){
	int ns,h,l;
	if(f[p-1][q]<f[p][q-1]){
		if(f[p-1][q]!=0){
			ns=f[p-1][q];
			h=p-1;
			l=q;
		}
		else{
			ns=f[p][q-1];
			h=p;
			l=q-1;
		}
		if(a[h][l]==0){
			a[p][q]=0;
			return 0;
		}
		if(a[h][l]==0&&a[p][q]==0) return 0;
		if(a[p][q]==0&&a[h][l]!=0){
			if(t[h][l]==0){
				a[p][q]=a[h][l];
				t[p][q]=1;
				return ns+2;
			}
			else return 0;
		}
		if(a[p][q]==a[h][l]) return ns;
		if(a[p][q]!=a[h][l]) return ns+1;
	}
	else{
		if(f[p][q-1]!=0){
			ns=f[p][q-1];
			h=p;
			l=q-1;
		}
		else{
			ns=f[p-1][q];
			h=p-1;
			l=q;
		}
		if(a[h][l]==0){
			a[p][q]=0;
			return 0;
		}
		if(a[h][l]==0&&a[p][q]==0) return 0;
		if(a[p][q]==0&&a[h][l]!=0){
			if(t[h][l]==0){
				t[p][q]=1;
				a[p][q]=a[h][l];
				return ns+2;
			}
			else return 0;
		}
		if(a[p][q]==a[h][l]) return ns;
		if(a[p][q]!=a[h][l]) return ns+1;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,x,y,c;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&x,&y,&c);
		a[x][y]=c+1;
	}
	f[1][1]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) f[i][j]=1;
			else f[i][j]=bijiao(i,j);
		}
	}
	if(f[m][m]==0) cout<<"-1";
	else cout<<f[m][m]-1;
	return 0;
}
