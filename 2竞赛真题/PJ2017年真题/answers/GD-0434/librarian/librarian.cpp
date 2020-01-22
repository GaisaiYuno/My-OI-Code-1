#include<cstdio>
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
string s,k;
stringstream str;
bool ok=1;
int n,q,a[1005],p,l,ans[1005][1005];
bool y[1005][1005];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	memset(ans,-1,sizeof(ans));
	memset(y,1,sizeof(y));
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&l,&p);
		if(ans[l][p]!=-1||!(y[l][p]))
		{
			cout<<ans[l][p]<<endl;
			continue;
		} 
		else
		{
			y[l][p]=0;
			str<<p;
			str>>k;
			str.clear();
			for(int j=0;j<n;j++)
			{
				ok=1;
				str<<a[j];
				str>>s;
				str.clear();
				for(int z=1;z<=l;z++)
				{
					if(s[s.size()-z]!=k[k.size()-z])
					{
						ok=0;
						break;
					}
				}
				if(ok)
				{
					ans[l][p]=a[j];
					break;
				}
			}
		}
		cout<<ans[l][p]<<endl;
	}
	return 0;
}

