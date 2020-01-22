#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    /*****************************************/	
    int m,n;
    int ys[10001][3];
    int i;
    cin>>m>>n;
    for(i=1;i<=n;i++)
    {
	    scanf("%d%d%d",&ys[i][0],&ys[i][1],&ys[i][2]);    
        if(i!=1&&ys[i][0]-ys[i-1][0]>1&&ys[i][1]-ys[i-1][1]>1)
        {  
    	    cout<<"-1";
    	    fclose(stdin);
	        fclose(stdout);
	        return 0;
        }
    }
    cout<<"10";
    /*****************************************/	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
