#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int c[11],n,q,k[1019],ans;
string a[1010];
struct www
{
	int a;
	string b;
}b[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	  for(int j=i+1;j<=n;j++)
		{
			if(a[j][a[j].size()-1]<a[i][a[i].size()-1]){
				string st=a[i];
				a[i]=a[j];
				a[j]=st;
			}
		}
		for(int i=1;i<=n;i++)		
		for(int j=0;j<a[i].size();j++)
		{
			k[i]=k[i]*10+a[i][j]-'0';
		}
	int o=-1;
	for(int i=1;i<=n;i++)if(o!=(a[i][a[i].size()-1]-'0')){o=a[i][a[i].size()-1]-'0';c[o]=i;}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].a>>b[i].b;
		ans=20000000;
		int l=b[i].b[b[i].a-1]-'0';
		if(c[l]==0){cout<<-1<<endl;continue;}
		for(int j=c[l];j<=n;j++)
		{
			if(a[j][a[j].size()-1]-'0'!=l)break;
			int r=0;
			for(int ii=b[i].a-2;ii>=0;ii--)
			{
				r++;
				if(a[j].size()-(b[i].a-ii)<0)break;
				if(b[i].b[ii]!=a[j][a[j].size()-r-1])break;{
				}
				if(ii==0)
				{
					if(k[j]<ans)ans=k[j];
				}
			}
		}
		if(ans==20000000)cout<<-1<<endl;else cout<<ans<<endl;
	}
	
}
