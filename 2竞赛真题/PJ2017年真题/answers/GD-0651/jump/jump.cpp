#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
/*****************************************/	
    long ge,tan,xi,i;
    long long g[500001][2],h;
    scanf("%d%d%d",&ge,&tan,&xi);
    for(i=1;i<=ge;i++)
    {
	    scanf("%d%d",&g[i][0],&g[i][1]);
	    if(g[i][1]>0)
	    {
		    h=h+g[i][1];
	    }
    }
    if(h<xi)
    {
	    cout<<"-1";
	    fclose(stdin);
	    fclose(stdout);
	    return 0;
    }
    cout<<"1";
/*****************************************/	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
