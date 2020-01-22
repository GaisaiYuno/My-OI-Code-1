#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);

	int r[1001];
	int b[1001];
	int a[1001];
	int c[1001];
	int step[1001]={0};int q,n;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<q;i++)
	{
		cin>>b[i] >> c[i];
	}
	for(int i=0;i<q;i++)
		{
			r[i]=1;
			while(b[i]!=0)
			{
				r[i]=r[i]*10;
				b[i]/=2;
			}
		}
	int qq=0;	
	for(int i=0;i<q;i++)
		for(int j=0;j<n;j++)
		{
			if(a[j]%(r[i])==c[i]){
				step[qq++]=a[j];
			}
		}
	for(int i=0;i<q;i++)
	{
		if(step[i]==0)printf("-1\n");
		else cout<<step[i]<<endl;
	}
	return 0;
}

