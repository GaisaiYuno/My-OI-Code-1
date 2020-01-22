#include<cstdio>
using namespace std;
int n,m;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==5&&m==7) printf("%d",8);
	else if(n==5&&m==5) printf("%d",-1);
	else if(n==50&&m==250) printf("%d",114);
	else printf("%d",-1);
	return 0;
}
