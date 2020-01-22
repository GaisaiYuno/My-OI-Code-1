#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD[100]={0,10,100,1000,10000,100000,1000000,10000000};
int code[10010];
int rd()
{
	int x=1,res=0;
	char ch;
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		res=res*10;
		res+=ch-'0';
		ch=getchar();
	}
	return x*res;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	bool f=false;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>code[i];
	sort(code+1,code+n+1);
	for(int i=1;i<=q;i++)
	{
		f=false;
		int st,req;
		cin>>st>>req;
		for(int j=1;j<=n;j++)
		{
			if(code[j]%MOD[st]==req)
			{
				cout<<code[j]<<endl;
				f=true;
				break;
			}
		}
		if(!f)puts("-1");
	}
	return 0;
}
