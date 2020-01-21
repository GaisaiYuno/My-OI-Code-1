#include<stdio.h>
#include<iostream>
using namespace std;

int stack[100];
int weizhi;

int total,n;
int sum;


void dfs(int index)

{

	int i;

	if(total==n)

	{

		printf("%d=",n);

		for(i=0; i<weizhi-1; i++)

			printf("%d+",stack[i]);

		printf("%d\n",stack[weizhi-1]);

		sum++;

	}

	if(total>n )

		return ;

	for(i=index; i>=1; i--)

	{

		total+=i;
		stack[weizhi]=i;
		weizhi++;
		dfs(i);
		total-=i;
		--weizhi;
	}

}

int  main() {
	for(;;) {
//	while (1) {
		//	freopen("out227.txt","w",stdout);
		weizhi=0;
		total=0;
		sum=0;
		cout<<"请输入小于100的正整数："<<'\n' ;
		//  while(scanf("%d",&n)!=EOF)
		cin>>n;
		cout<<'\n' ;
		cout<<"所有符合要求的等式如下："<<'\n';

		dfs(n-1);
		cout<<"等式种数为："<<sum<<'\n'<<'\n' ;
	}


}
