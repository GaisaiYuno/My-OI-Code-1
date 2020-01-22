#include<iostream>
#include<fstream>
using namespace std;
int a[1005],n,q,ln1,ln2,p,zs;
string st[1005],b[1005],st1,st2,minn;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	 cin>>st[i];
	for (int i=1;i<=q;i++)
	 cin>>a[i]>>b[i];
	for (int i=1;i<=q;i++)
	{
		minn="";
		for (int j=1;j<=n;j++)
		{
			ln1=st[j].size();
			ln2=a[i];
			p=1;
			st1=st[j];
			st2=b[i];
			while ((ln2>0)&&(p==1))
			{
				if (st2[ln2-1]!=st1[ln1-1]) p=0;
				ln1--;
				ln2--;
			}	
			if (p==1) 
			{
				zs++;
				if (zs==1) minn=st1;
			    if (zs>1)
				{
				  if (st1.size()<minn.size()) minn=st1;
				   else if (st1.size()==minn.size())
				   {
				       if (st1<minn) minn=st1;
				   }
				}
		    }
		}
		if (zs>0) cout<<minn<<endl;
		 else cout<<"-1"<<endl;
		zs=0;
	}
	return 0;
}
