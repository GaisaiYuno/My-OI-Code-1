#include<iostream>
#include<cstdio>
using namespace std;
int n,q,a[2000],b[2000],l[2000],c[2000]={0};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++) cin>>l[i]>>b[i];
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)
	{
		if(a[i]>a[j])
		{
			int t;
			t=a[i];a[i]=a[j];a[j]=t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			int bj=0;int x=a[j],y=b[i];
		 for(int k=1;k<=l[i];k++)
		 {
		 	if(x%10!=y%10) {bj=1;break;}  
		    x/=10;y/=10;
		 }
		    if(bj==0) {c[i]=a[j];break;}
	}
	       if(c[i]==0) c[i]=-1;
	}
	for(int i=1;i<=q;i++) cout<<c[i]<<' ';
	fclose(stdin);fclose(stdout);
}
