//��n%(n-next[n])==0,��aһ�����Ա�ǰ(n-next[n])���ַ��ظ�n/(n-next[n])�õ�
//֤����
//next[n]<n,��n%(n-next[n])==0,����n-next[n]<=n/2
//��n-next[n]==n/2,��next[n]=n/2ʱ����Ȼ�ַ������ֳ���ȵ����룬��֤
//��n-next[n]<n/2,��next[n]>n/2ʱ,���ַ�����Ϊ3����
// [s1 s2] 
//    [s2 s3]  
//��Ȼs1=s3
//����Ϊn%(n-next[n])==0������len(s1)=len(s2)=len(s3)
//��[s1,s2][s2,s3]���룬����s1=s2,s2=s3
//��֤ 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
int n;
char a[maxn];
int next[maxn];
int main(){
	while(scanf("%s",a+1)){
		if(a[1]=='.') break;
		n=strlen(a+1);
		next[1]=0;
		for(int i=2,j=0;i<=n;i++){
			while(j>0&&a[i]!=a[j+1]) j=next[j];
			if(a[j+1]==a[i]) j++;
			next[i]=j;
		}
		if(n%(n-next[n])==0) printf("%d\n",n/(n-next[n]));
		else printf("1\n");
	}
}
