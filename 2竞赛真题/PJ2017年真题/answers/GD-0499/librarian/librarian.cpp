#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int n,q;
string f[1010];
bool cmp(string a,string b)
{
	int i=1;
	if(a.size()==b.size()) return a<b;
	if(a.size()==1) return true;
	if(b.size()==1) return false;
	while(min(a.size(),b.size())!=i++)
	{
		if(a[a.size()-i]<b[b.size()-i]) return true;
	}
	if(b.size()<a.size()) return false;
	if(a.size()<b.size()) return true;
	return true;
}
string find(int a,string b)
{
	int s=0;
	while(n!=s++)
	{
		bool flag=false;
		for(int i=1;i<=a;i++)
		{
			if(f[s][f[s].size()-i]!=b[a-i])
			{
				flag=true;
				break;
			}
		}
		if(flag) continue;
		return f[s];
	}
	return "-1";
}
void input()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n,cmp);
}
void work()
{
	int a;
	string b;
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		cout<<find(a,b)<<endl;
	}
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	input();
	work();
	return 0;
}
