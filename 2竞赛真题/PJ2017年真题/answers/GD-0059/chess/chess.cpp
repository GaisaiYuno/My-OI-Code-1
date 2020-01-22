#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
int oo=1000000;
int ch[105][105];
int w[105][105];
int n,m;
using namespace std;
int f(int k,int l)
{
	for(int i=-1;i<=1;i++)
	for(int j=-1;j<=1;j++)
    if(abs(i)+abs(j)==1)
	if(k+i>0 && k+i<m+1 && l+j>0 && l+j<m+1)
	{
	    if(ch[k+i][l+j]!=0)
	    {
	  		if(ch[k+i][l+j]==ch[k][l]) 
			{
		  	  	if(w[k+i][l+j]>w[k][l])
				{
				  	w[k+i][l+j]=w[k][l];
				  	f(k+i,l+j);
				}
			}
	  		else 
	  		if(w[k+i][l+j]>w[k][l]+1)
			{
			    w[k+i][l+j]=w[k][l]+1;
			 	f(k+i,l+j);
		    }
	  	}
	}
	for(int i=-2;i<=2;i++)
	for(int j=-2;j<=2;j++)
	if(k+i>0 && k+i<m+1 && l+j>0 && l+j<m+1)
	if(abs(i)+abs(j)==2)
	{
		if(ch[i+k][j+l]!=0)
		{
			if(ch[k+i][l+j]==ch[k][l])
			{
				if(w[k+i][l+j]>w[k][l]+2)
				{
					w[k+i][l+j]=w[k][l]+2;
					f(k+i,l+j);
				}
			}
			else
			if(w[k+i][l+j]>w[k][l]+3)
			{
			 	w[k+i][l+j]=w[k][l]+3;
			 	f(k+i,l+j);
		    }
		}
	}
	return 0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    
    cin>>m>>n;
    for(int i=1;i<=n;i++) 
    {
    	int a,b,c;
    	cin>>a>>b>>c;
    	ch[a][b]=c+1;
    }
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)
    w[i][j]=oo;
    w[1][1]=0;
    f(1,1);
    if(w[m][m]!=oo) cout<<w[m][m];
    else
    {
    	w[m][m]=min(w[m][m],w[m-1][m]+2);
    	w[m][m]=min(w[m][m],w[m][m-1]+2);
    	if(w[m][m]==oo) cout<<-1;
    	else cout<<w[m][m];
    }
    return 0;
}
