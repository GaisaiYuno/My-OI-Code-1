//��� �޼���ƺ O(n*k)
#include<iostream>
#include<cstdio>
#define maxn 100005
long long e[maxn],f[maxn];
long long n,k,total;
using namespace std;
inline long long read(){//��������Ż� 
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
	n=read();k=read();
	for(register int i=1;i<=n;i++){//register���Լ��٣� 
		e[i]=read();
		total+=e[i];
	}
	long long tmp;
	for(register int i=k+1;i<=n;i++){
		tmp=0xfffffffffffffff;
		for(register int j=i-k;j<=i;j++){
			if(tmp>f[j-1]+e[j]) tmp=f[j-1]+e[j];
			//tmp=min(tmp,f[j-1]+e[j]);
		}
		f[i]=tmp;
	}
	printf("%lld",total-f[n]);
}
/*
״̬ת�Ʒ���(1) 
    f[i]=min{f[j-1]+i~jЧ��֮��,f[i]}   j��[i-k,i]
״̬ת�Ʒ���(2) 
  �������Ч�� 
  ����iֻţ��СЧ��,������kֻ���� 
  f[i]=min{f[j-1]+e[j],f[i]}   j��[i-k,i] 
  ����Ч�ʼ�ȥ��СЧ�ʾ��ܵõ����Ч�ʣ���ֱ�������Ч�ʿ� 
*/ 
