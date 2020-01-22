/*
Problem:�ѻ�ľ
Source:http://119.29.55.79/contest/23/problem/3
Description:
��dp[i]�ǵ�i����ľ���Լ���λ����ʱ��ǰi����ľ������ܹ�λ����Ŀ��
dp[i]=max{dp[j]|i>j,a[i]>a[j],a[i]-a[j]<=i-j}+1
����a[i]>a[j]�Ǳ�֤i,j�����Լ���λ���ϣ�a[i]-a[j]<=i-j��Ϊ�˱�֤�м����㹻�Ļ�ľ��i����a[i]���λ���ϡ�
ת��һ�·�������������:
i>j (1) 
i-a[i]>=j-a[j] (2)
a[i]>a[j] (3)
���� (2)+(3)�Ϳ��Եõ�(1)
����ֻʣ��������
��ô��ֻҪ����i-a[i]������LIS���ɡ� 
����i-a[i]���ʱ��a[i]����Ϳ���ʹ����󻯣����������ʱ��ڶ��ؼ���ҪŪ��a[i]��
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
struct node{
	int key;
	int val;
	friend bool operator < (node p,node q){
		if(p.key==q.key) return p.val<q.val;
		else return p.key<q.key;
	}
}b[maxn];
int s[maxn];
int top=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i].key=i-a[i];
		b[i].val=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(b[i].key<0) continue;//���i-a[i]<0,��a[i]>i,��i�϶������ں��ʵ�λ���ϣ�ֱ������ 
		if(b[i].val>s[top]){
			s[++top]=b[i].val;
		}else{
			int pos=lower_bound(s+1,s+1+top,b[i].val)-s;
			s[pos]=b[i].val;
		}
	}
	printf("%d\n",top);
}


