//��p281 ��7.4 
#include<iostream>
#include<cstdio>
using namespace std;
int list[1025][1025];
int m;
int main(){
	cin>>m;
	int n=1<<m;
	list[0][0]=1;
	int k=1,f=1;//f�ǵ�ǰ�����С 
	while(k<=m){
		for(int i=0;i<f;i++){
			for(int j=0;j<f;j++) list[i][j+f]=list[i][j]+f; //���Ϸ����� �����Ϸ�+f 
		}
		for(int i=0;i<f;i++){
			for(int j=0;j<f;j++){
			list[i+f][j]=list[i][j+f];//���·����� �����Ϸ�һ��
			list[i+f][j+f]=list[i][j];//���Ϸ� �����·�һ�� 
			}  
		}
		f=f*2;
		k++; 
	}
	freopen("list.txt","w",stdout);//�ɲ�Ҫ 
	for(int p=0;p<n;p++){
		for(int q=0;q<n;q++) cout<<list[p][q]<<' ';
		cout<<endl;
	}
	return 0;
}
