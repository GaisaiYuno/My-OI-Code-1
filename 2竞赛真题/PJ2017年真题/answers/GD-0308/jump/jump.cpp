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
	if(value >= k)//���������ֵ�������ٷ�������Ϊ���Դﵽ 
		flag = 1;//����Ѱ��
	else//û���� 
	{
		int distance;
		for(int i = place+1;i<=n;i++)//������һ������
		{
			distance = x[i]-x[place];//����
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
	scanf("%d%d%d",&n,&d,&k);//n�����ӣ��̶�����d������k�� 
	
	x[0] = 0;
	s[0] = 0;
	
	for(int i=1;i<=n;i++)//����n������
	{
		scanf("%d%d",&x[i],&s[i]);//���ӵ�ԭ��ľ��룬���ӵ�ֵ 
		if(s[i] >0)
			sum += s[i];//������ֵ
	}
	
	if(sum < k)//ȫ�������������ܴﵽ���� 
	{
		printf("-1");
		return 0;
	}
	 
	for(int g = 0;1;g++)//��gö��ҸĽ�,������޴�ʱ�ض��ܹ��ɹ�
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

		dfs(0,0,0);//����㿪ʼ
		
		if(flag)//�ܴﵽ���ٷ��� 
		{
			printf("%d",g);//������ 
			return 0;//���� 
		}
	}
	fclose(stdin);
	fclose(stdout);
}
