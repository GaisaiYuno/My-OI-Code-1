#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX 3000100
using namespace std;
struct node
{
    int l,r;
    int mini,maxi,sum;
    int add,set;
}a[MAX];
int anssum,ansmin,ansmax,r,c,m;
const int inf=1000000009;
void built(int l,int r,int index)
{
    a[index].l=l;a[index].r=r;a[index].add=0;a[index].set=-1;a[index].sum=a[index].mini=a[index].maxi=0;
    if(l==r)
	return;
    int mid=l+(r-l)/2;
    built(l,mid,index<<1);built(mid+1,r,index<<1|1);
}
void pushdown(int index)
{
    if(a[index].l>=a[index].r)
	return;
    if(a[index].set!=-1)
    {
	a[index<<1].set=a[index<<1|1].set=a[index].set;
	a[index<<1].mini=a[index<<1|1].mini=a[index].set;
	a[index<<1].maxi=a[index<<1|1].maxi=a[index].set;
	a[index<<1].add=a[index<<1|1].add=0;
	a[index<<1].sum=(a[index<<1].r-a[index<<1].l+1)*a[index].set;
	a[index<<1|1].sum=(a[index<<1|1].r-a[index<<1|1].l+1)*a[index].set;
    }
    if(a[index].add>0)
    {
	int ita=a[index].add;
	a[index<<1].add+=ita;a[index<<1|1].add+=ita;
	a[index<<1].mini+=ita;a[index<<1|1].mini+=ita;
	a[index<<1].maxi+=ita;a[index<<1|1].maxi+=ita;
	a[index<<1].sum+=ita*(a[index<<1].r-a[index<<1].l+1);
	a[index<<1|1].sum+=ita*(a[index<<1|1].r-a[index<<1|1].l+1);
    }
}
void maintain(int index)
{
    if(a[index].l>=a[index].r)
	return;
    a[index].maxi=max(a[index<<1].maxi,a[index<<1|1].maxi);
    a[index].mini=min(a[index<<1].mini,a[index<<1|1].mini);
    a[index].sum=a[index<<1].sum+a[index<<1|1].sum;
}
void updateSet(int L,int R,int val,int index)
{
    if(a[index].l==L&&a[index].r==R)
    {
	a[index].set=val;
	a[index].maxi=val;
	a[index].mini=val;
	a[index].add=0;
	a[index].sum=(a[index].r-a[index].l+1)*val;
	return;
    }
    pushdown(index);
    a[index].set=-1;
    a[index].add=0;
    int mid=a[index].l+(a[index].r-a[index].l)/2;
    if(R<=mid)
	updateSet(L,R,val,index<<1);
    else if(L>mid)
	updateSet(L,R,val,index<<1|1);
    else
    {
	updateSet(L,mid,val,index<<1);
	updateSet(mid+1,R,val,index<<1|1);
    }
    maintain(index);
}
void updateAdd(int L,int R,int val,int index)
{
    if(a[index].l==L&&a[index].r==R)
    {
	a[index].add+=val;
	a[index].maxi+=val;
	a[index].mini+=val;
	a[index].sum+=(a[index].r-a[index].l+1)*val;
	return ;
    }
    pushdown(index);
    a[index].set=-1;
    a[index].add=0;
    int mid=a[index].l+(a[index].r-a[index].l)/2;
    if(R<=mid)
	updateAdd(L,R,val,index<<1);
    else if(L>mid)
	updateAdd(L,R,val,index<<1|1);
    else
    {
	updateAdd(L,mid,val,index<<1);
	updateAdd(mid+1,R,val,index<<1|1);
    }
    maintain(index);
}
void Query(int L,int R,int index)
{
    if(a[index].l==L&&a[index].r==R)
    {
	anssum+=a[index].sum;
	ansmin=min(ansmin,a[index].mini);
	ansmax=max(ansmax,a[index].maxi);
	return;
    }
    pushdown(index);
    a[index].set=-1;
    a[index].add=0;
    int mid=a[index].l+(a[index].r-a[index].l)/2;
    if(R<=mid)
	Query(L,R,index<<1);
    else if(L>mid)
	Query(L,R,index<<1|1);
    else
    {
	Query(L,mid,index<<1);
	Query(mid+1,R,index<<1|1);
    }
    maintain(index);
}
int main()
{
    while(scanf("%d%d%d",&r,&c,&m)!=EOF)
    {
	built(1,r*c,1);
	int op,x1,x2,y1,y2,val;
	while(m--)
	{
	    scanf("%d",&op);
	    if(op==1)
	    {
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
		for(int i=x1;i<=x2;i++)
		    updateAdd((i-1)*c+y1,(i-1)*c+y2,val,1);
	    }
	    else if(op==2)
	    {
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
		for(int i=x1;i<=x2;i++)
		    updateSet((i-1)*c+y1,(i-1)*c+y2,val,1);
	    }
	    else
	    {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		anssum=0;ansmin=inf;ansmax=-inf;
		for(int i=x1;i<=x2;i++)
		    Query((i-1)*c+y1,(i-1)*c+y2,1);
		printf("%d %d %d\n",anssum,ansmin,ansmax);
	    }
	}
    }
    return 0;
}

