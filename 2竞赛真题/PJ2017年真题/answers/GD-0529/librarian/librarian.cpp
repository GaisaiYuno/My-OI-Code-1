#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;
string st,stt,xu[1100];
int n,q,m;
bool t;
bool tmp(string a,string b)
{if (a.size()!=b.size())return a.size()<b.size();return a<b;}
int main()
{
	freopen("librarian.in","r",stdin);freopen("librarian.out","w",stdout);
	cin>>n>>q;getchar();
	for (int i=1;i<=n;i++)getline(cin,xu[i]);
	sort(xu+1,xu+n+1,tmp);
	while (q--)
	{
		scanf("%d",&m);getchar();getline(cin,st);t=true;
		for (int i=1;i<=n;i++)
		if (xu[i].size()>=m)
		{
			stt=xu[i].substr(xu[i].size()-m,m);
			if (stt==st){cout<<xu[i]<<endl;t=false;break;}
		}
		if (t){printf("-1\n");}
	}
	return 0;
}
