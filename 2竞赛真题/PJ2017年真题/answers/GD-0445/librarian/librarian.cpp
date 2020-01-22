#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int k=0,n,m,ans[1005];
string a[1005],b;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	for(int i=0;i<1005;i++)ans[i]=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)
	{
		int flag=0,kp=0;
		cin>>k>>b;
		for(int j=0;j<n;j++)
		{
			int f=0,sum=0;
			for(int ij=a[j].size()-1,ik=k-1;ij>=a[j].size()-k+1,ik>=0;ij--,ik--)
			{
				if(a[j][ij]!=b[ik]){f=1;break;}
			}
			if(f==1)break;
			if(f==0)
			{
				flag=1;
				for(int kjl=0;kjl<a[j].size();kjl++)sum=sum*10+a[j][kjl]-'0';
				ans[kp]=sum;kp++;
			}
		}
		sort(ans,ans+kp);
		if(flag==1)
		cout<<ans[0]<<endl;
		else
		cout<<-1<<endl;
		for(int op=0;op<1005;op++)ans[op]=0;
	}
	return 0;
}
