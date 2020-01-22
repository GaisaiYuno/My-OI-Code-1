#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[101][101];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    int i,j,n,m;
    int x,y,c;
    int ans;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++){
    	printf("%d%d%d",&x,&y,&c);
    }
    ans=-1;
	printf("%d",&ans);
	return 0;
}
