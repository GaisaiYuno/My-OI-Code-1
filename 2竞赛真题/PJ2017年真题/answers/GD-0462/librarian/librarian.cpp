#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(string a,string b)
{
	if (a.size()>b.size()) return b<a;
	else if (a.size()==b.size())
	{
		if (a>b) return b<a;
	}
}
int cp(int a,int b)
{
	if (a>b&&a!=-1||b!=-1) return b<a;
}
int n,q,bianh[1000],x,y[1000];
string s1[1000],s2;
bool pd;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<=n;i++)
		getline(cin,s1[i]);
	
	for (int i=1;i<=n;i++)
	bianh[i]=-1;	
    sort(s1+1,s1+n+1,cmp);
    
    for (int i=1;i<=n;i++)
        y[i]=s1[i].size();
        
	for (int j=1;j<=q;j++)
	{
		cin>>x;
		getline(cin,s2);
		
		for (int i=1;i<=n;i++)
		{
			pd=true;
			if (x<y[i])
			{
				for (int k=x-1;k>=0;k--)
			  {
				for (int f=y[i]-1;f>=0;f--)
				if (s1[i*f]!=s2[k]) {
				   pd=false;
				   break;
			    }
			    if (pd==true)
			    {
			    	bianh[i]=i;
			    	break;
			    }
			  }
			}	
		}
			
	}
	sort(bianh+1,bianh+n+1,cp);	
	for (int i=1;i<=n;i++)
	if (bianh[i]!=-1) for (int j=0;j<=y[bianh[i]]-1;j++) cout<<s1[bianh[i]][j];
	                  else cout<<-1;
}
