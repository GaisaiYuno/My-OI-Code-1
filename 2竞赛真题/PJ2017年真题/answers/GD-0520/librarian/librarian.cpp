#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,i,a,j;
string zfc[1000001],b;
bool cmp(string a,string b)
{
	if (a.size()!=b.size()) return a.size()<b.size(); else
	return a<b;
};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (i=1; i<=n; i++)
	 cin>>zfc[i];
	sort(zfc+1,zfc+1+n,cmp);
	for (i=1; i<=m; i++)
	 {
	 	t=0;
	 	cin>>a>>b;
	 	for (j=1; j<=n; j++)
	 	 if (zfc[j].size()>=a)
	 	 if (zfc[j].find(b,zfc[j].size()-a)==zfc[j].size()-a)
	 	{
	 		t=1;
	 		cout<<zfc[j]<<endl;
	 		break;
	 	}
	 	if (t==0) cout<<-1<<endl;
     }
    return 0;
}
