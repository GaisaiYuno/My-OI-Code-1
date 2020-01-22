#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;




struct data
{
	int x,y;

};

int mi(int n)
{
	
	int s;
	if (n==1) return 10;
	else if (n==2) return 100;
	if (n%2==0) s=mi(n/2)*mi(n/2);
	else s=10*mi(n/2)*mi(n/2);
	return s;
}


int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);

	data m[1100];
	int b[1100],c[1100][8]={0};
	int n,q,max1=2147483647;
	
	
	
	
	cin>>n>>q;
	


	
	for (int i=1;i<=n;i++)
		cin>>b[i];
		
	
	
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=7;j++)
		{
			 c[i][j]=b[i]%mi(j);
			
			
		}
		
			
	}


	
	
	
	for (int i=1;i<=q;i++)
	{
		cin>>m[i].x>>m[i].y;
		max1=100000008;
		for (int j=1;j<=n;j++)
			if ((c[j][m[i].x]==m[i].y)&&(max1>=b[j])) max1=b[j]	;	
		
		for (int j=1;j<=n;j++)	
			if ((m[i].y==b[j])&&(b[j]<=max1)) max1=b[j];
		
		if (max1!=100000008) cout<<max1<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
	
}
