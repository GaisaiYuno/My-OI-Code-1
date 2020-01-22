#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long minn=10000001,n,m,b[10000],a,p,cot[10000];
string sr[10000],st;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>sr[i];
		for(int j=0;j<sr[i].size();j++)
		{
			b[i]=b[i]*10+int(sr[i][j]-'0');
		}
	}
	for(int i=0;i<m;i++)
	{
		cin>>a;cin>>st;
		
		for(int j=0;j<n;j++)
		{
			string sk="";
			for(int k=sr[j].size()-a;k<=sr[j].size()-1;k++)
			{
				sk+=sr[j][k];
			}
			if (sk==st&&b[j]<minn)
			minn=b[j];
		}
		if (minn==10000001)
		cot[i]=-1;
		else cot[i]=minn;
		minn=10000001;
	}
	for(int i=0;i<m;i++)
	{
		cout<<cot[i]<<endl;
	}
	return 0;
}
