//��b����1�ĸ���Ϊx��c����1�ĸ���Ϊy
//�����о�Ϊ1��λ�ø���Ϊz
//�����ݳ�ԭ������ͬ��λ�ø���Ϊx+y-2*z
//����zΪ��ֵ��2*z��Ϊż��
//���ֻ��x+yΪż��
//ǰ׺�ͼ��� 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;
int n,m;
char a[maxn+5];
int suma[maxn+5];
char b[maxn+5];
int sumb[maxn+5];
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for(int i=1;i<=n;i++){
		suma[i]=suma[i-1]+a[i]-'0';
	}
	for(int i=1;i<=n;i++){
		sumb[i]=sumb[i-1]+b[i]-'0';
	}
	int ans=0;
	for(int i=1;i+m-1<=n;i++){
		if(((suma[i+m-1]-suma[i-1])+sumb[n])%2==0){
			ans++;
		}
	} 
	printf("%d\n",ans);
}

