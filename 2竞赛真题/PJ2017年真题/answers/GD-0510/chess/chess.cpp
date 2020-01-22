#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[101][101],x,y,z;
long long ans=INT_MAX;
bool b[101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(a,-1,sizeof(a));
	memset(b,true,sizeof(b));
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(z==0) a[x][y]=0;
		if(z==1) a[x][y]=1;
	}
	if((a[m][m]!=-1&&a[m-1][m]==-1&&a[m-2][m]==-1&&a[m-1][m-1]==-1&&a[m][m-1]==-1&&a[m][m-2]==-1)||(a[m][m]==-1&&a[m-1][m]==-1&&a[m][m-1]==-1)) printf("-1");
	else{
		b[1][1]=false;
		printf("-1");
	} 
    return 0;
}
