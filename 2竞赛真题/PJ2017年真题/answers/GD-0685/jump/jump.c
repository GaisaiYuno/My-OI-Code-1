#include<stdio.h>
int max(long *list,long size)
{
	long *max,*i;
	for(max=i=list;i-list<size;i++)
	{
		if(*i>*max)
		{
			max=i;
		}
	}
	return max-list;
}
long sum(long *list,int n)
{
	long *i,s;
	for(i=list,n=0;i-list<n;i++)
	{
		if(*i>0)
		{
			s+=*i;
		}
	}
	return s;
}
long jump(long *points,long n,int d,int g)
{
	long p,*i,r1,r2;
	r2=d+g;
	if(g<=d)
	{
		r1=d-g;	
	}
	else
	{
		r1=1;
	}
	for(i=points;i-points<n;)
	{
		i+=max(i+r1,r2-r1);
		if(*i==0)break;
		p+=*i;
	}
	return p;
}
int findg(long *points,long n,int d,long k)
{
	int g;
	for(g=0;jump(points,n,d,g)<k;g++)
	{
		if(g<0)
		return -1;
	}
	return g;
}
int main()
{
	long n,k,i,p,x;
	int d;
	long points[500000]={0};
	scanf("%ld%d%ld",&n,&d,&k);
	for(i=0;i<n;i++)
	{
		scanf("%ld%ld",&x,&p);
		points[x]=p;
	}
	p=sum(points,n);
	if(p<k)
	{
		printf("-1");
	}
	else
	{
		printf("%d",findg(points,n,d,k));
	}
	return 0;
}
