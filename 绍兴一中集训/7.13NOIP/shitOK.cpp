/*
https://www.luogu.org/problemnew/show/U76980
��a��С�������� 
ö��һ����a[i]��������������ڵ�x�α�����ķ��������ܵõ���������Դ𰸵Ĺ��ף��������Ǻܺ�ֱ����.���ǿ���������ǰx�α�����ĸ���
�ȿ������ǵı���������
ö��һ������{3,1,2,4,5}����1��ʼ�ƶ�.����k=2
x=1,��������{3,1,2} ȥ��1
x=2����4�������䣬{3,1,2,4} ȥ��2 �������䳤��Ϊ[1,x+k-1]
���Է�������������������е�ǰmin(n,x+k-1)��������ǰiС�ġ����һ�¾͵õ���i�α�����ĸ���
��m=min(n,x+k-1)��Ϊ��i�β�����ʱ�������ֹ�����������

ö��m�������ж��ٱȵ�ǰ���ģ���Ϊj ,m-x<=j<=m
���������д���a[i]������n-i���� ����ѡ��j�����뵱ǰ���䣬C(n-i,j)
����������С��a[i]������i-1��������ѡ��m-1-j�����뵱ǰ���� C(i-1,m-1-j)
�ܷ�����C(n-i,j)*C(i-1,m-1-j)

�������л�������˳���Ȱ�m�������У��ٰ�ʣ��n-m�������У� ����sum=sigma(C(m-i,j)*C(i-1,m-1-j))*(m!)*(n-m)! 

�ٿ���һ�����ʱ��Ĺ���
�����ڵ�x�α��������x+1~n֮���ʱ�䶼Ҫ����a[i] ,����a[i]*(n+1-x) 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300
#define mod 1000000007
using namespace std;
typedef long long ll;
ll fact[maxn+5],invfact[maxn+5];
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x){
	return fast_pow(x,mod-2);
}
inline ll C(int n,int m){
	if(n<m) return 0;//С��������� 
	if(n==m) return 1;
	if(m==0) return 1;
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

void pre_work(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<=n;i++) invfact[i]=inv(fact[i]);
}

int n,k; 
int a[maxn+5];
ll cnt[maxn+5];//ǰ׺�� ��ǰx�α�����ķ�����
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pre_work(n);
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		cnt[0]=0;
		for(int x=1;x<=n;x++){
			cnt[x]=0;
			int m=min(x+k-1,n);
			for(int j=m-x;j<m;j++){
				cnt[x]+=C(n-i,j)*C(i-1,m-j-1)%mod;
				cnt[x]%=mod;
			}
			cnt[x]=cnt[x]*fact[m]%mod*fact[n-m]%mod;
			ll dcnt=(cnt[x]-cnt[x-1]+mod)%mod;//��� 
			ans+=dcnt*a[i]%mod*(n-x+1)%mod;
			ans%=mod;
		}
	}
	printf("%lld\n",ans);
} 
