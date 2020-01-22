#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

namespace Solution
{

template <typename tp>
void read(tp &x)
{
	char ch=getchar();x=0;bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

int pointx[100001];
int pointy[100001];
pair<int,int>point[100001];
int n;

int check(int x,int y)
{
	int sum1=0,sum2=0,sum3=0,sum4=0;
	for(int i=0;i<n;i++)
	{
		if(point[i].first<x)
		{
			if(point[i].second<y)sum1++;
			else sum2++;
		}
		else
		{
			if(point[i].second<y)sum3++;
			else sum4++;
		}
	}
//	printf("check(%d,%d)=%d,%d,%d,%d\n",x,y,sum1,sum2,sum3,sum4);
	return max(max(sum1,sum2),max(sum3,sum4));
}

int main()
{
	read(n);
	for(int i=0;i<n;i++)
	{
		read(point[i].first);
		read(point[i].second);
		pointx[i]=point[i].first;
		pointy[i]=point[i].second;
	}
	sort(pointx,pointx+n);
	sort(pointy,pointy+n);
	int ans=n+100;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans=min(ans,check(pointx[i],pointy[j]));
		}
	}
	cout<<ans<<endl;
/*	
	for(int i=0;i<n;i++)
	{
		cout<<pointx[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<pointy[i]<<" ";
	}
	cout<<endl;*/
	/*int midx=pointx[n/2],midy=pointy[n/2];
	int px1=lower_bound(pointx,pointx+n,midx)-pointx;
	int px2=upper_bound(pointx,pointx+n,midx)-pointx;
	int py1=lower_bound(pointy,pointy+n,midy)-pointy;
	int py2=upper_bound(pointy,pointy+n,midy)-pointy;
	int finalx=max(n-px1,px1)<max(n-px2,px2)?pointx[px1]:pointx[px2];
	int finaly=max(n-py1,py1)<max(n-py2,py2)?pointy[py1]:pointy[py2];
	cout<<px1<<" "<<py1<<endl;
	cout<<px1<<" "<<py2<<endl;
	cout<<px2<<" "<<py1<<endl;
	cout<<px2<<" "<<py2<<endl;
	cout<<check(pointx[px1],pointx[py1])<<endl;
	cout<<check(pointx[px1],pointx[py2])<<endl;
	cout<<check(pointx[px2],pointx[py1])<<endl;
	cout<<check(pointx[px2],pointx[py2])<<endl;
//	cout<<check(332880,332259)<<endl;
	//cout<<min(check(pointx[px1],pointx[py1]),check(point[px1],point[py2]));*/
	return 0;
}

}

int main()
{
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	return Solution::main();
}
