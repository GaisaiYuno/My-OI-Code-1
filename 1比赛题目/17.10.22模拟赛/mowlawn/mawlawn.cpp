//��� �޼���ƺ O(k^2*n) 
#include<iostream>
#include<cstdio>
#define maxn 100005
long long e[maxn],sum[maxn],f[maxn];
long long n,k;
using namespace std;
inline long long read(){
	long long x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int main(){
	freopen("mowlawn.9.in","r",stdin);
	n=read();
	k=read();
	for(int i=1; i<=n; i++) {
		e[i]=read();
		sum[i]=sum[i-1]+e[i];
	}
	f[1]=e[1];
	long long tmp;
	for(int i=2; i<=n; i++) {
		for(int j=i-k; j<i; j++) {
			if(j<0)	continue;
			tmp=f[j-1]+sum[i]-sum[j];
			if(tmp>f[i]) f[i]=tmp;
		}
	}
	printf("%lld\n",f[n]);
	return 0; 
}
/*
״̬ת�Ʒ���(1) 
    f[i]=min{f[j-1]+i~jЧ��֮��,f[i]} j��[i-k,i] 
״̬ת�Ʒ���(2) 
  �������Ч�� 
  ����iֻţ��СЧ��,������kֻ���� 
  f[i]=min{f[j-1]+e[j],f[i]} j��[i-k,i] 
  ����Ч�ʼ�ȥ��СЧ�ʾ��ܵõ����Ч�ʣ���ֱ�������Ч�ʿ� 
*/ 
