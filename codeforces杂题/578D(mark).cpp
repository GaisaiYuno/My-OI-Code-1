#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n,m;
long long ans=0;
char s[maxn];
int main() {
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	ans=n*(m-1);//n-1���ַ�����ԭλ����һλ��������ԭ���ַ��������ַ�
	for(int i=1; i<n; i++) {
		if(s[i]!=s[i+1]) ans+=n*(m-1);
		//��һ���ַ�Ų����һ��λ�ã��������aaa������ͬ�������ֻ��һ�Σ��嵽1,2,3���涼һ����
		//��������m-1���ַ�
	}
	//��abababab�����Ĵ�
	//�ѵ�3��a�ŵ�������abbaabab�����ǰѵ�4��b�ŵ�ǰ��Ҳ���Ա��abbaabab
	//�����ַ�����ÿ���ַ�����ǰ������һ���ַ�����һ��
	int k=1;
	for(int i=2; i<=n; i++) {
		if(k==1) {
			if(s[i]!=s[i-1]) k++;
			else continue;
		} else {
			if(s[i]==s[i-2]) k++;
			else {
				ans-=(k-1)*k/2;
				k=1;
				if(s[i]!=s[i-1]) k=2;
			}
		}
	}
	ans-=(k-1)*k/2;
	cout<<ans;
}
