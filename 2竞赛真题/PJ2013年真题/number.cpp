//number
#include<iostream>
#include<cstdio>
#define maxn 1000005
using namespace std;
long long n,p,t;
long long ans;
long long a[maxn];//���ݺܴ� 
long long v[maxn];
long long f[maxn];
int main() {
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int flag=0;
	cin>>n>>p;
	for(int i=1; i<=n; i++) scanf("%ld",&a[i]);//���ݺܴ󣬲�����cin�������TLE 
	v[1]=a[1];
	for(int i=1; i<=n; i++) {
		t=t+a[i];
		v[i]=t;
		if(t<0) t=0;//��ֹ���� 
	}
	for (int i=2; i<=n; i++) {
		if(v[i]<v[i-1]) v[i]=v[i-1];
	}
	f[1]=v[1];//������ֵ�����ֵ������ 
	f[2]=f[1]+v[1];
	for(int i=3; i<=n; i++) {//�Ż���O(n)
		f[i]=f[i-1];
		if(v[i-1]>0) f[i]+=v[i-1];
		if(f[i]>f[1]) flag=1;
		if(flag==1) f[i]%=p;
	}
	if (flag==1) cout<<f[n]; 
	else cout<<f[1];
}
