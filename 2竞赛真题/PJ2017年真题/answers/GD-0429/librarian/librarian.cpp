#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[10000],b[10000],c[10000];
int s=1,w=100000000,h;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	 for(int i=1;i<=m;i++)
	 	 cin>>c[i]>>b[i];
	 for(int i=1;i<=m;i++)
	  {
	  	 for(int j=1;j<=c[i];j++)
	  	  s*=10;
	  	  c[i]=s;
	  	  s=1;
	  }
	  for(int i=1;i<=m;i++)
	  {
	  	for(int j=1;j<=n;j++)
	  	{
	  	  if(a[j]%c[i]==b[i])
	  	  {
	  	  	w=min(a[j],w);
	  	  	h++;
	  	  }
	  	}
	  	if(h!=0)
	  	cout<<w<<endl;
	  	else
	  	cout<<-1<<endl;
	  	h=0;
	  	w=100000000;
	  }
	  return 0;
}

