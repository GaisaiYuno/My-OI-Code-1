#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define maxn 100000 
using namespace std;
int n;
int a[maxn+5];
map<int,int>cnt;
bool check(){
	if(cnt.count(0)&&cnt[0]>1) return 0;
	for(auto x : cnt){//�г��ִ�������2�� 
		if(x.second>2) return 0;
	}
	int num=0;
	for(auto x : cnt){
		if(x.second>1) num++; 
	}
	if(num>=2) return 0;//��2�����ִ�������1�� 
	for(auto x : cnt){
		if(x.second>1&&cnt.count(x.first-1)) return 0;
		//x����>1��,x-1���֣�������ȡx������ȡx-1���������ͬ 
	} 
	return 1;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	if(!check()){//����ʼ���
		printf("cslnb\n"); 
	}else{
		long long sum=0;
		//����ȡ������Сȡ���󣬵�i��ȡ��i-1�����������������ͬ
		//��Ϊ������ȡ�����ж�һ����ż�ԣ�������һ��˭ȡ��ȡ�ľ��� 
		for(int i=1;i<=n;i++){
			sum+=a[i]-(i-1); 
		} 
		if(sum%2==1) printf("sjfnb\n");
		else printf("cslnb\n");
	}
	
}

