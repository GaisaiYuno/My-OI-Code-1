#include<iostream>
#include<cstdio>
#define maxn 100000
int n,m;
int phi[maxn+5];
void euler_init()
{
	int top=maxn;
	for(int i=2;i<=top;++i)phi[i]=i;
	for(int i=2;i<=top;++i)
	{
		if(phi[i]==i){
			for(int j=i;j<=top;j+=i){
				phi[j]-=phi[j]/i;
			}
		} 
		phi[i]+=phi[i-1];
	}
}
int main()
{
	euler_init();
	scanf("%d %d",&n,&m);
	if(phi[n]<m) printf("Impossible");
	else printf("Possible");
	return 0;
}

