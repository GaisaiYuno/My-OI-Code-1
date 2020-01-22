#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
long long n,m;
int k;
string st[1005],st2[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=0;i<n;i++)
	{
	cin >> st[i];
	for (int j=st[i].size();j<8;j++)
	st[i]=' '+st[i];
	}
	sort(st,st+n);
	for (int i=0;i<m;i++)
	cin >> k >> st2[i];
	for (int i=0;i<m;i++)
	{
		bool t=false;
		for (int j=0;j<n;j++)
		{
			bool tt=true;
		for (int k=st[j].size()-st2[i].size();k<st[j].size();k++)
		if (st[j][k]!=st2[i][k-st[j].size()+st2[i].size()]) {tt=false;break; }
		
		if (tt==true) {for (int jj=0;jj<st[j].size();jj++)
		if (st[j][jj]!=' ')cout << st[j][jj];cout << endl;t=true;break;}
			
		}
		if (t==false) cout << "-1"<<endl;
	}
	return 0;
}

