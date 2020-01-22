#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cos[1047],bookk[1047],bb[1047],len[1047],aaa[1047];
int ans[10101];
int main()
{
   	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,m;
	cin>>n>>m;
	memset(ans,-1,sizeof(ans));
	memset(aaa,1,sizeof(aaa));
	for(int i=1;i<=n;i++) cin>>bookk[i];
	for(int i=1;i<=m;i++) cin>>len[i]>>cos[i];
	for(int i=1;i<=m;i++) 
	{
		int aa=1;
		for(int j=1;j<=len[i];j++) aa=aa*10;
		aaa[i]=aa;
	}
	for(int i=1;i<=m;i++)
	{
		int xbb=0,count=1;
		for(int j=1;j<=n;j++)
		{
			if(bookk[j]%aaa[i]==cos[i])
			{
				if(ans[i]>bookk[j])
				{
					ans[i]=bookk[j];
					xbb=j;
				}
				if(count==1) 
				{
					ans[i]=bookk[j];
					xbb=j;
				}
				count++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}
