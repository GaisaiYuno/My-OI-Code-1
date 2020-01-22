#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int x=10000000;
int len[1010],want[1010],num[1010],num1[1010],ans[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,j,k,sum,sum1,c,px;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>num[i];
		num1[i]=num[i];
	}
	for(i=1;i<=q;i++)
		cin>>len[i]>>want[i];
	for(i=1;i<=q;i++)
	{
		for(k=1;k<=n;k++)
			ans[k]=0;
		c=0;
		for(k=1;k<=n;k++)
			num1[k]=num[k];
		for(j=1;j<=n;j++)
			{
				sum=sum1=0;
				for(k=1;k<=len[i];k++)
					{
						sum1=sum=sum*10+num1[j]%10;
						num1[j]/=10;
					}
				sum=0;
				for(k=1;k<=len[i];k++)
					{
						sum=sum*10+sum1%10;
						sum1/=10;
					}
				if(sum==want[i])ans[j]=num[j];
				else {ans[j]=x;c++;}
			}
		if(c==n){cout<<-1<<endl;continue;}
		px=ans[1];
		for(k=2;k<=n;k++)
			px=min(ans[k],px);
		cout<<px<<endl;
	}
	return 0;
}
