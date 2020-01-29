//��=n!-ʹ��1��������ķ�����-ʹ��2��������ķ�����+ʹ1,2������ķ�����
// ʹ��1��������ķ�����=\prod(cnt[v]),cnt[v]Ϊ���е�1����v���ֵĴ���
//�ڶ�����ͬ��
//ʹ1,2������ķ�����ͬ��ֻ�ǰ��������������ԡ�ע��������1�ؼ��������򣬵�2�ؼ�������Ļ�����Ϊ0 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<utility>
#include<algorithm>
#define maxn 300000
#define mod 998244353
using namespace std;
typedef long long ll;
int n;
ll fact[maxn+5];
map<int,int> cnta,cntb;
pair<int,int>p[maxn+5];
map<pair<int,int>,int> cntp;
int main(){
	scanf("%d",&n);
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		scanf("%d %d" ,&p[i].first,&p[i].second);
		cntp[p[i]]++;
		cnta[p[i].first]++;
		cntb[p[i].second]++;
	}
	ll cnt1=1,cnt2=1,cnt12=1;
	for(auto it : cnta){
		cnt1*=fact[it.second];
		cnt1%=mod;
	}
	for(auto it : cntb){
		cnt2*=fact[it.second];
		cnt2%=mod;
	}
	
	sort(p+1,p+1+n);
	bool flag=false;
	for(int i=1;i<n;i++){
		if(p[i].second>p[i+1].second){
			flag=true;
			break;
		}
	}
	if(flag){
		cnt12=0;
	}else{
		for(auto it : cntp){
			cnt12*=fact[it.second];
			cnt12%=mod;
		}
	}
	ll ans=fact[n];
	ans=(ans-cnt1+mod)%mod;
	ans=(ans-cnt2+mod)%mod;
	ans=(ans+cnt12+mod)%mod;
	printf("%I64d\n",ans);
}

