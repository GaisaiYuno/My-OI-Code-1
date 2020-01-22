#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int book[1010],r[1010],a[1010];
int k[1010];
bool b[1010]={false};

bool check(int x,int y,int n)
{
	bool oops=true;
	int w=0;
	while(y!=0)
	{
		if(x%10!=y%10)oops=false;
		x/=10;
		y/=10;
		w++;
		if(w==n)break;
	}
	return oops;
}

int main()
{
	freopen("librarian.in","r",stdin);freopen("librarian.out","w",stdout);
	int n,q,i,j;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>book[i];
	for(i=1;i<=q;i++)
		cin>>k[i]>>r[i];
	sort(book,book+n);
	for(i=1;i<=q;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(b[j]==false&&check(book[j],r[i],k[i])){a[i]=book[j],b[j]=true;break;}
			else a[i]=-1;
		}
	}	
	for(i=1;i<=q;i++)
		cout<<a[i]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
