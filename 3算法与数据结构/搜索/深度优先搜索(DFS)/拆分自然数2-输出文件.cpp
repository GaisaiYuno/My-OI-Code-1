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
		cout<<"������С��100����������"<<'\n' ;
		//  while(scanf("%d",&n)!=EOF)
		cin>>n;
		cout<<'\n' ;
		 freopen("�����Ȼ�����.txt","w",stdout);
		cout<<"���з���Ҫ��ĵ�ʽ���£�"<<'\n';

		dfs(n-1);
		cout<<"��ʽ����Ϊ��"<<num<<'\n'<<'\n' ;
//	}


}

