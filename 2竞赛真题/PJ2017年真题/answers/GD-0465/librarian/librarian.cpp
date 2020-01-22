#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
long long n,m,i,shao,l,j,ij;
string st[1000+1],dst,pan,minm;
int main ()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
    cin>>st[i];
    for (i=1;i<=m;i++)
    {
        cin>>l>>dst;
        shao=0;
        minm="0"-500;
        for (j=1;j<=n;j++)
        {
        	pan="";
        	if (l>st[j].length()) break;
        	else
        	{
        		for (ij=st[j].length()-l;ij<=st[j].length()-1;ij++)
        		{
        			pan=pan+st[j][ij];
        		}
        		if (pan==dst)
        		{
        			if (shao==0) minm=st[j];
        			else
					{
					    if (st[j].length()<minm.length()) minm=st[j];
					    else
					    if (st[j]<minm) minm=st[j];
					}
        			shao=1;
        		}
        	}
        }
        if (shao==1) cout<<minm<<endl;
        else cout<<-1<<endl;
    }
	return 0;
}

