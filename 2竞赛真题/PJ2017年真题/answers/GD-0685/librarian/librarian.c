#include<stdio.h>
long sort(long *list,int n)
{
    long min,*i;
    for(i=list,min=*list;i-list<n;i++)
    {
    	if(*i<min)
    	{
    		min=*i;
    	}
    }
    return min;
}
long find(long *book,int n,long code,int len)
{
    long *i,*j,flag,need[n];
	for(i=book,flag=0,j=need;i-book<n;i++)
	{
		if(((*i^code)<<(32-len))||(code>*i));
		else
		{
			*j=*i;
			j++;
			flag=1;
		}
	}
	if(flag==1)
	{
	return sort(need,j-need-1);
	}
	else
	{
		return -1;
	}
}
int main()
{
	int n,q,i;
	long book[1000],reader[2],finds[1000];
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&book[i]);
	}
	for(i=0;i<q;i++)
	{
		scanf("%d%lx",&reader[0],&reader[1]);
		finds[i]=find(book,n,reader[1],reader[0]);
	}
	for(i=0;i<q;i++)
	{
		printf("%ld\n",finds[i]);
	}
	return 0;
}
