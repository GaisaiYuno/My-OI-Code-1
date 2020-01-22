#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;
struct node{
	string s;
	int v;
}a[1010];
bool amp(node aa,node bb)
{
	return aa.v<bb.v||(aa.v==bb.v&&aa.s<bb.s);
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	int n,q;  scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		cin>>a[i].s,a[i].v=a[i].s.size();
		//a[i].v = a[i].s-'0';
		//cout<<a[i].v<<endl;
	sort(a+1,a+n+1,amp);
	/*for (int i=1;i<=n;i++)
		cout<<a[i].s<<" "<<a[i].v<<endl;*/
	for (int i=1;i<=q;i++)
	{
		int b;  cin>>b;  string c;  cin>>c;
		if (b==1)
		{
			bool f=false;
			for (int j=1;j<=n;j++)
				if (a[j].s[a[i].v-1]==c[0])
					{cout<<a[j].s<<endl;  f=1;  break;}
			if (!f) cout<<-1<<endl;
		}
		else 
		{
			int len=c.size(),ff=0;
			for (int j=1;j<=n;j++)
			{
				bool f=true;
				if (a[j].v>=len)
				{
					for (int z=1;z<=len;z++)
						if (c[len-z]!=a[j].s[a[j].v-z])
							{f=false;  break;}
					if (f)
						{cout<<a[j].s<<endl;  ff=1;  break;}
				}
			}
			if (!ff) cout<<-1<<endl;
		}
	}
	return 0;
}

