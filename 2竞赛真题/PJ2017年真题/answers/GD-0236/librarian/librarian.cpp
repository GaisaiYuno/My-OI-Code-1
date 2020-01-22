#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

int code[1005];

struct require{
	int length;
	int requirecode;
}reader[1005];

bool compareUpper(int a,int b)
{
	return a>b;
}

inline int power(int length)
{
	int tmp=1;
	for(int i=0;i<length;i++)
		tmp*=10;
	return tmp;
}

int main(void)
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&code[i]);
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&reader[i].length,&reader[i].requirecode);
		reader[i].length=power(reader[i].length);
	}
	sort(code,code+n);
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(code[j]%reader[i].length==reader[i].requirecode)
			{
				cout<<code[j]<<endl;
				break;
			}
			if(j==n-1)
				cout<<-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
