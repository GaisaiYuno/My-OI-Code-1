#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string s; string ans[1005],f[1005]; bool b[1005];
bool mdzz(string s1,string s2)
{
	int ll1,ll2,k; 
	ll1=s1.length();
	ll2=s2.length(); 
	if (ll1<ll2) return false; k=ll2-1;
	for (int i=ll1-1;i>=0 && k>=0;i--)
	{
		if (s1[i]==s2[k]) 
		{
			k--;
			continue;
		}
		return false;
	}
	return true;
}
int main()
{
	memset(b,false,sizeof(b));
	std::ios::sync_with_stdio(false);
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>ans[i];
	}
	for (int i=1;i<=m;i++)
	{
		int l;
		cin>>l>>f[i];
	}
	for (int i=1;i<=m;i++)
	{
		s="100000000"; int sum=0;
		sum=0;
		for (int j=1;j<=n;j++)
		{
			if (b[j]) continue;
			if (!mdzz(ans[j],f[i])) continue;
			int l1,l2;
			l1=ans[j].length();
			l2=s.length();
			if (l1<=l2)
			{
				if (l1==l2) 
				{
					if (ans[j]<s)  {s=ans[j]; sum=j;}
				}
				else if (l1<l2) {s=ans[j]; sum=j;}
			}
		}
		b[sum]=true;
		if (s!="100000000") cout<<s<<endl;
		else cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
