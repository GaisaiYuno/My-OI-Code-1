#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct house
{
	int x,s,far;
	bool get=false;
}plane[500005];
int pai(house a,house b)
{
	if(a.far!=b.far)
		return a.far<b.far;
	else
		return a.s>b.s;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,count=0,score=0,gold=0;
	cin>>n>>d>>k;
	for(int i=0;i<n;i++)
	{
		cin>>plane[i].x>>plane[i].s;
		plane[i].far=plane[i].x%d;
	}
	while(count<=n)
	{
		score+=plane[count].s;
		plane[count].get=true;
		count+=d;
	}
	sort(plane,plane+n,pai);
	for(int i=0;i<n;i++)
	{
		if(score>=k)
			break;
		else
		{
			if(plane[i].s>0 && plane[i].get==false)
			{
				if(plane[i].far>d+gold)
					{
						gold+=plane[i].far-(d+gold);
						score+=plane[i].s;
					}
				else
					{
						gold+=d-gold-plane[i].far;
						score+=plane[i].s;
					}
			}
			if(plane[i].s<0 && plane[i].get==true)
			{
				if(gold==0)
					gold+=1;
				score+=plane[i].s;
			}
		}
	}
	if(score<k)
		cout<<"-1";
	else
		cout<<gold;
	return 0;
}
