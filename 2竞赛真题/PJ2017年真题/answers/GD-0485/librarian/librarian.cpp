#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;
int n,m,x,y,mina,flag;
int tem1,tem2,num1,num2;
int a[1000+5];
int p[10+5],q[10+5];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		mina=100000000;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==y) {mina=a[j];break;}
			else if(a[j]>y)
			{
				for(int k=1;k<=10;k++) {p[k]=0;q[k]=0;}
				num1=0;num2=0;flag=0;
				tem1=a[j];tem2=y;
				while(tem1!=0)
				{
					num1++;
					p[num1]=tem1%10;
					tem1/=10;
				}
				while(tem2!=0)
				{
					num2++;
					q[num2]=tem2%10;
					tem2/=10;
					if(p[num2]!=q[num2])
					{
						flag=1;
						break;
					}
				}
				if(flag==0) mina=min(mina,a[j]);
			}
		}
		if(mina!=100000000) printf("%d\n",mina);
		else  cout<<-1<<endl;
	}
	return 0;
}
