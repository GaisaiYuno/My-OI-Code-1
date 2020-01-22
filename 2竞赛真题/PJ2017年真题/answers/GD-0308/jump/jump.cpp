#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<map>
#include<set>
using namespace std;

int sum = 0;
bool flag = 0;
long long n,k,d,x[500050],s[500050],least,most,ans[500050];
void dfs(int place,int value,int order)
{
	if(value >= k)//跳到这里的值超过最少分数，即为可以达到 
		flag = 1;//结束寻找
	else//没超过 
	{
		int distance;
		for(int i = place+1;i<=n;i++)//遍历下一个格子
		{
			distance = x[i]-x[place];//距离
			if(least<=distance && most>=distance)
				dfs(i,value+s[i],order+1);
			if (distance > most)
				break;
			if(flag)
				return; 
		}
	}
}


int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);//n个格子，固定距离d，最少k分 
	
	x[0] = 0;
	s[0] = 0;
	
	for(int i=1;i<=n;i++)//输入n个格子
	{
		scanf("%d%d",&x[i],&s[i]);//格子到原点的距离，格子的值 
		if(s[i] >0)
			sum += s[i];//格子总值
	}
	
	if(sum < k)//全是正整数都不能达到最少 
	{
		printf("-1");
		return 0;
	}
	 
	for(int g = 0;1;g++)//用g枚金币改进,金币无限大时必定能够成功
	{
		if(g<d)
		{
			least = d-g;
			most = d+g;
		}
		else
		{
			least = 1;
			most = d+g;
		}

		dfs(0,0,0);//从起点开始
		
		if(flag)//能达到最少分数 
		{
			printf("%d",g);//输出结果 
			return 0;//结束 
		}
	}
	fclose(stdin);
	fclose(stdout);
}
