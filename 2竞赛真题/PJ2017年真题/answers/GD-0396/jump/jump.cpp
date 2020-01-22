#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
long cost[500010],costing[500010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long d,k,i,n,g,maxbefore=0,jlong=1,loc,start,end,o,p,q,max;
	memset(cost,0,sizeof(cost));
	memset(costing,o,sizeof(costing));
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
	{
		cin>>loc;
		cin>>cost[loc];
		if(cost[loc]>0)maxbefore+=cost[loc];
		if(loc>jlong)jlong=loc;
	}
	if(maxbefore<k)
	{
		cout<<"-1";
		return 0;
	}
	for(g=1;g<jlong;g++)
	{
		memset(costing,0,sizeof(costing));
		for(i=1;i<=jlong;i++)
		{
			costing[i]=cost[i];
		}
		for(q=2;q<=jlong;q++)
		{
			start=q-d-g;
			end=q-d+g;
			if(start<1)start=1;
			if(end>=q)end=q-1;		
			max=-9999999;
			if(end>0&&start>0&&end>=start)
			{
				for(i=start;i<=end;i++)
				{
					if(costing[i]>max)max=costing[i];
				}
		    }
		    else max=-9999999;
			costing[q]+=max;
			
			if(costing[q]>=k)
			{
				cout<<g;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
