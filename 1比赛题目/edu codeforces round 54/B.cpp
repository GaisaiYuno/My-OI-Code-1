//����ÿ��������һ����С������֮��һ����ż��
//��ż��-2����ż������������С������Ϊ����������-����=ż����
//�����ż����һ·��2����0 
//����ֻҪ��һ����С�����ӾͿ����� 
#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
long long n;
int vis[maxn];
void sieve(int n){
	vis[0]=1;
	vis[1]=1;
	for(long long i=2;i<=n;i++){
		if(!vis[i]){
			for(long long j=2;i*j<=n;j++){
				vis[i*j]=1;
			}
		}
	}
}
long long chkprime(long long x){
	for(long long i=2;i*i<=x;i++){
		if(x%i==0&&vis[i]==0) return i; 
	}
	return -1;
}
int main(){
	cin>>n;
	sieve(100000);
	long long d=chkprime(n);
	if(d==-1){
		printf("1\n");
	}else{
		printf("%lld\n",(n-d)/2+1); 
	}
}
