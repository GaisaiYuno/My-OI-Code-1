#include<iostream>
#include<cstdio>
using namespace std;
int m,n,_Map[110][110],h,l,c,f[110][110],cha[110][110];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m;i++) 
	  for (int j=1;j<=m;j++)	    
		{
			_Map[i][j]=2;
			f[i][j]=2147483647;
		}	
	for (int i=1;i<=n;i++) 
	{
		cin>>h>>l>>c;
		_Map[h][l]=c;
	}
	f[1][1]=0;
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++)
	    {
	    	if (i==1 && j==1) continue;
			if (_Map[i][j]<2)
	    	{
	    		if (_Map[i-1][j]<2)
	    		{
	    			if (_Map[i-1][j]==_Map[i][j]) f[i][j]=min(f[i][j],f[i-1][j]);
	    		    if (_Map[i-1][j]!=_Map[i][j]) f[i][j]=min(f[i][j],f[i-1][j]+1);
	    		} 
	    		if (_Map[i-1][j]==3)
	    		{
	    			if (cha[i-1][j]==_Map[i][j]) f[i][j]=min(f[i][j],f[i-1][j]);
	    		    if (cha[i-1][j]!=_Map[i][j]) f[i][j]=min(f[i][j],f[i-1][j]+1);
	    		}
	    		if (_Map[i][j-1]<2)
				{
					if (_Map[i][j-1]==_Map[i][j]) f[i][j]=min(f[i][j],f[i][j-1]);
	    		    if (_Map[i][j-1]!=_Map[i][j]) f[i][j]=min(f[i][j],f[i][j-1]+1);
				}		    		
	    		if (_Map[i][j-1]==3)
				{
					if (cha[i][j-1]==_Map[i][j]) f[i][j]=min(f[i][j],f[i][j-1]);
	    		    if (cha[i][j-1]!=_Map[i][j]) f[i][j]=min(f[i][j],f[i][j-1]+1);					
				}	
	    	}
	    	 else
	    	{
	    		if (_Map[i-1][j]<2 && f[i-1][j]+2<f[i][j]) f[i][j]=f[i-1][j]+2,_Map[i][j]=3,cha[i][j]=_Map[i-1][j];
	    		if (_Map[i][j-1]<2 && f[i][j-1]+2<f[i][j]) f[i][j]=f[i][j-1]+2,_Map[i][j]=3,cha[i][j]=_Map[i][j-1];
	    	}	
	    }
/*	for (int i=1;i<=m;i++) 
	{
		for (int j=1;j<=m;j++) cout<<f[i][j]<<" ";
		cout<<endl;
	} */
	if (f[m][m]!=2147483647) cout<<f[m][m]; else cout<<-1;
	return 0;
}
