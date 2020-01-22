#include <iostream>
#include <stdio.h>
#include <string.h> 
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
using namespace std;

namespace Solution
{
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

int place[200001];
int sidewalk[10001];
pair<int,int> building[1001];
pair<int,int> segment[1001];
int cntb[1000000];
int cnts[1000000];
//int sumb[1000000];
int sums[1500000];
int size,nseg;
int n,m;

int main()
{
	read(n);read(m);
	for(int i=0;i<n;i++)
	{
		read(sidewalk[i]);
		size=max(sidewalk[i],size);
//		place[size++]=sidewalk[i];
//		place[size++]=sidewalk[i]-1;
	//	place[size++]=sidewalk[i]+1;
	}
	for(int i=0;i<m;i++)
	{
		int l,r;
		read(l);read(r);
		building[i]=make_pair(l,r);
		size=max(max(size,l),r);
/*		place[size++]=l;
		place[size++]=r;
		place[size++]=l+1;
		place[size++]=l-1;
		place[size++]=r+1;
		place[size++]=r-1;*/
	}
	cout<<size<<endl;
//	sort(place,place+size);
//	size=unique(place,place+size)-place;
/*	for(int i=0;i<n;i++)
	{
		sidewalk[i]=lower_bound(place,place+size,sidewalk[i])-place;
	}
	for(int i=0;i<m;i++)
	{
		building[i].first=lower_bound(place,place+size,building[i].first)-place;
		building[i].second=lower_bound(place,place+size,building[i].second)-place;
	}*/
	for(int i=0;i<m;i++)
	{
		cntb[building[i].first]++;
		cntb[building[i].second+1]--;
	}
	for(int i=0,nowsum=0,lastsum=0;i<=size+2;i++)
	{
		nowsum+=cntb[i];
		if(nowsum==0&&lastsum!=0)
		{
			segment[nseg-1].second=i-1;
		}
		else if(nowsum!=0&&lastsum==0)
		{
			segment[nseg++].first=i;
		}
		lastsum=nowsum;
	}
/*	for(int i=0;i<nseg;i++)
	{
		cout<<segment[i].first<<" "<<segment[i].second<<endl;
	}*/
	sort(sidewalk,sidewalk+n);
	for(int i=0;i<n;i++)
	{
		cnts[sidewalk[i]]++;
	}
	sums[0]=cnts[0];
	for(int i=1;i<=size+1;i++)
	{
		sums[i]=sums[i-1]+cnts[i];
	}
/*	for(int i=0;i<=size+1;i++)
	{
		cout<<sums[i]<<" ";
	}
	cout<<endl;*/
	int movedis,ans=-1;
	for(int x=-size-1;x<=size+1;x++)
	{
		int sumnow=0;
		for(int i=0;i<nseg;i++)
		{
			sumnow+=sums[min(segment[i].second+x,size+2)]-(segment[i].first+x-1>=0?sums[segment[i].first+x-1]:0);
		}
	//	cout<<"x="<<x<<" sumnow="<<sumnow<<endl; 
		if(sumnow>ans)
		{
			ans=sumnow;
			movedis=std::abs(x);
		}
		if(sumnow==ans&&movedis>std::abs(x))
		{
			movedis=std::abs(x);
		}
	}
	cout<<movedis<<" "<<ans<<endl;
	return 0;
} 


}

int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	return Solution::main();
}

/*
4 2 
1 6 6 1 
4 5 
3 5 
*/
