#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
string st[1500],sc;
int n,q;
bool cmp(string x,string y)
{
	return x.size()<y.size()||x.size()==y.size()&&x<y;
}
int Find(string x)
{
	string sc;int sclen=0;
	for (int i=1;i<=n;i++)
	  if (st[i].size()>=x.size())
	  {
	  	bool p=1;
	  	 sc=st[i];
	  	 sclen=sc.size()-1;
	  	 for (int j=x.size()-1;j>=0;j--)
	  	   if (x[j]==sc[sclen]) sclen--;
	  	   else {p=0;break;}
	  	 if (p) return i;
	  }
	return 0;
}

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    scanf("%d %d",&n,&q);
    st[0]="-1";
    for (int i=1;i<=n;i++)   	cin>>st[i];
    sort(st+1,st+1+n,cmp);
    for (int i=1;i<=q;i++)
    {
    	int len=0;
    	cin>>len>>sc;
    	int Fi=Find(sc);
    	cout<<st[Fi]<<endl;
	}
	return 0;
}

