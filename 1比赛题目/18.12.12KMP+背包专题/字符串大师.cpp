//���ڳ���Ϊn��ѭ������ѭ���ڵĳ���Ϊn-next[n]
//�����������ת����next����
//��next[i]>0��s[i]=s[next[i]] ����iλѭ���ڵ�һ����)
//��next[i]=0����Ҫ���죬Ҫ���ֵ�����С�����iλҪ����С
//���iλһ��������ǰ���ƥ��Ӷ�����ѭ���ڣ�ɾȥ��Щ��ĸ�Ҹ���С�ľͿ�����
//���Ե�iλһ������next[i]�ĺ�ѡ���е��ַ�
//����aiΪ����δ���ֹ�����С�ַ�������Ϊnext�Ĳ�������ϵ�����Եȼ������г��ֹ�������ַ�+1 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005 
using namespace std;
int a[maxn];
int pre[maxn];
int nex[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&pre[i]);
	}
	nex[0]=-1;
	for(int i=2;i<=n;i++){
		nex[i]=i-pre[i];
		if(nex[i]) a[i]=a[nex[i]];
		else{
			for(int j=nex[i-1];j>=0;j=nex[j]){
				a[i]=max(a[i],a[j+1]+1);
			} 
		} 
	}
	for(int i=1;i<=n;i++) printf("%c",a[i]+'a');
} 
