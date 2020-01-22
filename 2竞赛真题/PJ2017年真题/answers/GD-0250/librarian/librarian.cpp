#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
string bo[1010];
string re[1010];
int b[1010];
int r[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>bo[i];
		b[i]=bo[i].size();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>r[i];
		cin>>re[i];
		int w=10;
		string ans="2147483647";
		for(int z=1;z<=n;z++)
		{
			int t=b[z]-1;int h=1;
			for(int y=r[i]-1;y>=0;y--)
			{
			 if(re[i][y]!=bo[z][t])
			  {
			 	h=0; 
			 	break;
			  }	
			  t--;
			}
			 if(h==1)
			 {
			 	if(w==b[z]&&ans>bo[z])
			 	  ans=bo[z];	
			 	if(w>b[z])
			 	  {
			 	  	ans=bo[z];
			 	  	w=b[z];
			 	  }
			 }
		}
	    if(w==10) cout<<-1<<endl;
	    else cout<<ans<<endl;
    } 
	return 0;
}

