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
		cout<<"������С��100����������"<<'\n' ;
		//  while(scanf("%d",&n)!=EOF)
		cin>>n;
		cout<<'\n' ;
		cout<<"���з���Ҫ��ĵ�ʽ���£�"<<'\n';

		dfs(n-1);
		cout<<"��ʽ����Ϊ��"<<sum<<'\n'<<'\n' ;
	}


}
