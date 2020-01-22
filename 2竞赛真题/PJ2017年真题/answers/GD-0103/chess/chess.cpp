#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
char s[102][102];
int n,m,a=0,b=0,corn=0; 
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    memset(s,'.',sizeof(s))
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	int x,y;
    	scanf("%d %d",&x,&y);
    	getchar();
    	scanf("%c",&s[x][y]);
    }
	s[n+1][n+1]='s';
    while(a!=n && b!=n)
    {
    	a++;
    	b++;
		if(a==n && b==n)
    	break;
    	if(s[a+1][b]=='.' && s[a+1][b+1]=='.' && s[a][b+1]=='.')
    	{
    		printf("-1");
    		return 0;
    	}else if((s[a][b]==s[a+1][b+1] && s[a+1][b]==s[a][b])||(s[a][b]==s[a+1][b+1] && s[a][b+1]==s[a][b]))
    	{
    		
    	}else if((s[a+1][b]!='.' || s[a][b+1]!='.') && (s[a+1][b]==s[a][b] || s[a+1][b]==s[a+1][b+1] || s[a][b+1]==s[a][b] || s[a][b+1]==s[a+1][b+1]))
    	{
    		corn++;
    	}else if(s[a][b]==s[a+1][b+1])
    	{
    		corn+=2;
    	}else{
    		corn+=3;
    	}
    }
    printf("%d",corn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
