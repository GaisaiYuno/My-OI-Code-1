#include<stdio.h>
#include<iostream>
using namespace std;
int chai[100];
int weizhi,total,n,num;
void dfs(int a) {
	int i;
	if(total==n) {
		//cout<<n<<"=";
		for(i=0; i<weizhi-1; i++)	cout<<chai[i]<<"+";
		cout<<chai[weizhi-1]<<'\n';
		num++;
		return;
	}

	if(total>n )
		return ;
	for(i=1; i<=a; i++) {
		total+=i;
		chai[weizhi]=i;
		weizhi++;
		dfs(i);
		total-=i;
		--weizhi;
	}

}

int  main() {
//	while(1) {
		weizhi=0;
		total=0;
		num=0;
		cout<<"请输入小于100的正整数："<<'\n' ;
		//  while(scanf("%d",&n)!=EOF)
		cin>>n;
		cout<<'\n' ;
		 freopen("拆分自然数结果.txt","w",stdout);
		cout<<"所有符合要求的等式如下："<<'\n';

		dfs(n-1);
		cout<<"等式种数为："<<num<<'\n'<<'\n' ;
//	}


}

