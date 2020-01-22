#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int i,j,k;
	int num[1001],digit[1001],need[1001],ans[1001],temp[1001];
	int n,q;
	for(i=0;i<=1000;i++) ans[i]=2147483647;
	cin>>n>>q;
	for(i=0;i<n;i++) cin>>num[i];
	for(i=0;i<q;i++) cin>>digit[i]>>need[i];
	for(i=0;i<q;i++)
	{
		for(j=0;j<n;j++)
		{
			temp[i]=num[j]-need[i];
			for(k=0;k<digit[i];k++) temp[i]=temp[i]/10;
			for(k=0;k<digit[i];k++) temp[i]=temp[i]*10;
			if(temp[i]==(num[j]-need[i]))
			{
				if(ans[i]>num[j]) ans[i]=num[j];
			}
		}
		if(ans[i]==2147483647) ans[i]=-1;
	}
	for(i=0;i<q;i++) cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;        
}
