# include<iostream>
# include<cstdio>
# include<cstdlib>
# include<algorithm>
# include<cmath>
# include<string>
# include<cstring>
using namespace std;
int t[1000+5];
string ss[1000+5];
int main()
{
	int n,q,l,w,xxx,m,ll;
	string xx;
	
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>ss[i];
		for (int j=0;j<=ss[i].size()-1;j++)
		{
			t[i]=t[i]*10+(ss[i][j]-48);
		}
	}
	for (int i=1;i<=q;i++)
	{
		cin>>l>>xx;
		m=10000100;
		for (int j=1;j<=n;j++)
		{
			ll=ss[j].size(); w=ss[j].find(xx,ll-l);
			if (w>=0) {if (t[j]<m) {m=t[j];}}
		}
		if (m!=10000100) {cout<<m<<endl;} else {cout<<-1<<endl;}
	}
	return 0;
}
