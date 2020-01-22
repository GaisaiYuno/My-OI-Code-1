#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct data
{
	int len;
	string st;
};
int n,m;
string st1;
char sw;
data b[1005],a[1005];
bool cmp(data a,data b)
{
	if (a.len==b.len) return a.st<b.st; else return a.len<b.len; 
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i].st;
		a[i].len=a[i].st.size();
	}
	for (int i=1;i<=m;i++) 
		cin>>b[i].len>>b[i].st;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=m;i++)
	{
		int f=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j].len>=b[i].len)
			{
				st1=a[j].st.substr(a[j].len-b[i].len,b[i].len);
				if (st1==b[i].st)
				{
					cout<<a[j].st<<endl;
					f=1;
					break;
				}
			}
		}
		if (f==0) cout<<-1<<endl;
	}
	return 0;
}
