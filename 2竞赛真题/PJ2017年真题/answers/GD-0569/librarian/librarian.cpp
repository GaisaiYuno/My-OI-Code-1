#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int shu[1010],xq,ss,rs,i,j,hw,ws,my,weishu;
	cin>>ss>>rs;
	shu[0]=0;
	for(i=1;i<=ss;i++)
	{
		j=i;
		cin>>shu[i];
		while(shu[j]<shu[j-1])
		{
			hw=shu[j];
			shu[j]=shu[j-1];
			shu[j-1]=hw;
			j--;
		}
	}
	for(i=1;i<=rs;i++)
	{
		my=1;
		cin>>ws>>xq;
		weishu=pow(10,ws);
		for(j=1;j<=ss;j++)
		{
			if(shu[j]%weishu==xq)
			{
				cout<<shu[j]<<"\n";
				my=0;
				break;
			}
		}
		if(my)
		  cout<<-1<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
