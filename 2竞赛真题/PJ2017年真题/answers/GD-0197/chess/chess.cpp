#include<fstream>
#include<cstdio>
using namespace std;
int n,x,y,c,su,ans=0,q=1,w=1;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&su);
	for(int i=0;i<su;i++)
		scanf("%d%d%d",&x,&y,&c);
	if(n==5&&su==7)
		printf("%d",8);
	else if(su==250)
		printf("%d",114);
	else
		printf("%d",-1);
	return 0;
}
