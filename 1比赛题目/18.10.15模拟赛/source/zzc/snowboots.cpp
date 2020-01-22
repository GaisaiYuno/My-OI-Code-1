#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

namespace Solution_Snowboots
{
void read(int &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

void read(long long &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

set <int> position;//当前可用的落脚点的位置 
map <int,int> sub;//相邻两项的差值 

pair <long long,int> snow[100001];//first:深度，second:位置

map <long long,int> ans;//s大于first的靴子所需的最小d 

int main()
{
	int n,q;
	read(n);read(q);
	for(int i=0;i<n;i++)
	{
		read(snow[i].first);
		snow[i].second=i+1;
	}
	sort(snow,snow+n);
//	cout<<"sorted"<<endl;
	for(int i=0;i<n;)
	{
		int j;
		for(j=i;snow[j].first==snow[i].first;j++)
		{
		//	cout<<"j="<<j<<endl;
			if(position.size()==0)
			{
				position.insert(snow[j].second);
			}
			else if(position.size()==1)
			{
				int tmp=(*(position.begin()));
				position.insert(snow[j].second);
				sub[std::abs(tmp-snow[j].second)]++;
			}
			else
			{
				int tmp1,tmp2;
				bool flag1=false,flag2=false;
				set<int>::iterator it=position.lower_bound(snow[j].second);
				//最大 
				if(it==position.end())flag2=true;
				else tmp2=(*it);
				//最小 
				if(it==position.begin())flag1=true;
				else
				{
					it--;
					tmp1=(*it);
				}
				if(flag1)
				{
					sub[tmp2-snow[j].second]++;
				}
				else if(flag2)
				{
					sub[snow[j].second-tmp1]++;
				}
				else
				{
					sub[tmp2-tmp1]--;
					if(sub[tmp2-tmp1]==0)sub.erase(tmp2-tmp1);
					sub[tmp2-snow[j].second]++;
					sub[snow[j].second-tmp1]++;
				}
				position.insert(snow[j].second);
			}
		}
/*		cout<<"f="<<snow[i].first<<endl;
		for(map<int,int>::iterator it=sub.begin();it!=sub.end();it++)
		{
			cout<<it->first<<","<<it->second<<endl;
		}*/
		map<int,int>::iterator tmp=sub.end();
		tmp--;
		ans[snow[i].first]=tmp->first;
		i=j;
	}
/*	for(map<long long,int>::iterator it=ans.begin();it!=ans.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}*/
	while(q--)
	{
		long long s;
		int d;
		read(s);read(d);
		map<long long,int>::iterator it=ans.upper_bound(s);
		if(it==ans.end())
		{
			puts("1");
			continue;
		}
		it--;
		if(d>=it->second)puts("1");
		else puts("0");
	}
	return 0;
} 

}

int main()
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	return Solution_Snowboots::main();
}
/*
8 7
0 3 8 5 6 9 0 0
0 5
0 6
6 2
8 1
10 1
5 3
150 7
*/
