#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime> 
#define maxn 1000000
#define maxt 10 //���ѡ������ 
using namespace std;
typedef long long ll; 
int n;
ll  a[maxn+5];
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int random(int l,int r){
	return (long long )rand()*rand()%(r-l+1)+l;
} 

int sz=0;
ll d[maxn+5];
int cnt[maxn+5];
void divide(ll x){
	sz=0;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			d[++sz]=i;
			if(x/i!=i) d[++sz]=x/i; 
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]); 
	ll ans=0;
	for(int cas=1;cas<=maxt;cas++){
/*
		ÿ������1/2�ĸ��ʱ�ѡ�У����t��������������ѡ�У����ѡ����ʱ�Ĵ� 
		�����������x�ֽ������������x������a[i]��gcd 
		�����ĸ�������Ϊx��a[i]��gcd�Ĵ�����࣬�Ҵ�������n/2 
		����������Ĺ�����������ȥ�Ӵ�С��һ�����Ϊ����һ���������������֡�
		���������ǣ�ѡ��һ��������ȥ�ұ������������
		�������������������˵����������Ӧ������Ҳ���Ա����С����������Ӧ���Ѽӵ����С�����ļ����� 
		ʱ�临�Ӷ�O(n+d^2)
		��d��С�����Բ���TLE 
*/
		ll x=a[random(1,n)];
		divide(x);
		sort(d+1,d+sz+1);
		for(int i=1;i<=sz;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			int pos=lower_bound(d+1,d+1+sz,gcd(a[i],x))-d;
			cnt[pos]++;
		}
		for(int i=1;i<=sz;i++){
			for(int j=i+1;j<=sz;j++){
				if(d[j]%d[i]==0) cnt[i]+=cnt[j];
			}
		}
		for(int i=sz;i>=1;i--){
			if(cnt[i]*2>=n){
				ans=max(ans,d[i]);
//				break;
			}
		}
	}
	printf("%I64d\n",ans);
}
/*
2
11111111111
11111111111
*/ 

