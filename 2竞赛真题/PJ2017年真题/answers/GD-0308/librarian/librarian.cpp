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
struct people
{
	int order;
	int len;
	int id;
}need[1050];
int id[1050];
bool check(int book,int want,int id)
{
	book -= want;
	for(int i=1;i<=need[id].len;i++)
	{
		if(book%10!=0)
			return 0;
		book %=10;
	}
	return 1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	bool flag;
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&id[i]);
		
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&need[i].len,&need[i].id);
		need[i].order = i;
	}	
	
	/*for(int i=1;i<=n;i++)
		printf("%d ",id[i]);
	printf("\n");
	for(int i=1;i<=q;i++)
		printf("%d ",need[i].id);*/
	sort(id+1,id+1+n);//把书按照编号排序，找到即为所求 
	//sort(need+1,need+1+q,cmp1);
	
	for(int i=1;i<=q;i++)//遍历所有人的需求 
	{
		flag = 0;//输出标志 
		for(int j=1;j<=n;j++)//遍历所有书 
		{
			if(id[j] >= need[i].id)//只有大于标志，才能包含标志 
			{
				if(check(id[j],need[i].id,i))//检查到是需要的最小编号的书 
				{
					printf("%d\n",id[j]);//输出结果 
					flag = 1;//找到 
					break;//退出遍历 
				}
			}
		}
		if(flag == 0)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
