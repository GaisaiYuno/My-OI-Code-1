#include<fstream>
#include<cmath>
#include<string>
using namespace std;
string s[1010];
int a[1010];
int main()
{
	ifstream fin("librarian.in");
	ofstream fout("librarian.out");
	int n,m;
	int b,c,ans;
	fin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
	  fin>>s[i];
	  for(int j=0;j<s[i].size();j++)
	   a[i]=a[i]*10+s[i][j]-48;
	}
	for(int i=1;i<=m;i++)
	{
	  ans=1e9;
	  int bh;
	  fin>>b>>c;
	  for(int j=1;j<=n;j++)
	  {
	  	string x;
	  	int as=0;
	  	for(int k=s[j].size()-b;k<s[j].size();k++)
	  	 x+=s[j][k];
	  	for(int k=0;k<x.size();k++)
	  	 as=as*10+x[k]-48;
	  	if(as==c&&a[j]<ans)
	  	{
	  	  ans=a[j];
	  	  bh=j;
	  	}
	  }
	  if(ans!=1e9)
	   fout<<s[bh]<<endl;
	  else 
	   fout<<-1<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
