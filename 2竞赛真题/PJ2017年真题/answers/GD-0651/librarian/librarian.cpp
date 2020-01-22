#include<iostream>
#include<cstdio>
using namespace std;

int cf(int a,int b)
{
	int c;
	c=1;
	for(int i=1;i<=b;i++)
	{
		c=c*a;
	}
	return c;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
/*****************************************/	
	int dz,s,e;
	int c1,c2;
	long long ans=10000001;
	int xq[1001],xw[1001],bm[1001];
/*****************************************/
	cin>>s>>dz;
	for(int c1=1;c1<=s;c1++)
	{
		scanf("%d",&bm[c1]);
	}
	for(c1=1;c1<=dz;c1++)
	{
		scanf("%d",&xw[c1]);
		scanf("%d",&xq[c1]);
	}
/******************************************/
	for(c1=1;c1<=dz;c1++)
	{
		e=cf(10,xw[c1]);
		for(c2=1;c2<=s;c2++)
		{
			e=bm[c2]%e;
			if(e==xq[c1]&&bm[c2]<ans)
			{
				ans=bm[c2];
			}
		}
		if(c1!=dz)
		{
		  if(ans==10000001)
		  {
			  cout<<-1<<endl;
		  }
		  else
		  {
			  cout<<ans<<endl;
		  }
	    }
	    else
	    {
	    	if(ans==10000001)
		  {
			  cout<<-1;
		  }
		  else
		  {
			  cout<<ans;
		  }
	    }
	    ans=10000001;
	}
/*****************************************/	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
