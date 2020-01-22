#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define maxn 1000
using namespace std;
typedef long long ll; 
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
ll fact[maxn+5],invfact[maxn+5],invx[maxn+5];
void ini_inv(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		invx[i]=invfact[i]*fact[i-1]%mod;
	}
}

int n;
struct seg{
	int l;
	int r;
}a[maxn+5];
int dn=0;
int tmp[maxn+5];//��ɢ���� 
void discrete(){
	dn=0;
	for(int i=1;i<=n;i++){
		tmp[++dn]=a[i].l;
		tmp[++dn]=a[i].r+1;//��ѧ�߽磬Ҫת�ɿ����� 
	}
	sort(tmp+1,tmp+1+dn);
	dn=unique(tmp+1,tmp+1+dn)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(tmp+1,tmp+1+dn,a[i].l)-tmp;
		a[i].r=lower_bound(tmp+1,tmp+1+dn,a[i].r+1)-tmp;
	}
}

ll dp[maxn+5][maxn+5];//dp[i][j][k]��ʾǰi��ѧУ,��i��ѧУѡ�����ڵ�j�����䣬��k��ѧУ�ڵ�j�������� 
//��[l,r]��ѡ������k����������C(r-l+1,k) 
//dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j][k-1]*C(r-l+1,k)/C(r-l+1,k-1) (��������ֻ����(r-l+1-k)/k) 
//dp[i][j][1]=dp[i-1][j][1]+dp[i-1][x][y] (0<=x<=j-1,0<=y<=i-1) dp[i-1][x][y]��ǰ׺���Ż�
//��һά���Թ������� 
ll sum[maxn+5];
//sum[i][j]=sigma(dp[x][y][z]) (x<=i,y<=j,z<=x)
//ͬ����һά�������� 
int cnt[maxn+5];//��¼��ǰ��j�����������,����ö��k��ʱ���ֻ��ö�ٵ�j 
int main(){
	ini_inv(maxn);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i].l,&a[i].r);
	discrete();
	dp[0][0]=sum[0]=1;
	for(int j=1;j<dn;j++) sum[j]=sum[j-1]+dp[j][0]; 
	for(int i=1;i<=n;i++){
		for(int j=a[i].l;j<a[i].r;j++){
			cnt[j]++;
			for(int k=cnt[j];k>=2;k--){//����ѭ������ֹ�ظ����� 
				dp[j][k]+=(dp[j][k-1]*(tmp[j+1]-tmp[j]+1-k)%mod*invx[k]%mod);
				dp[j][k]%=mod; 
			} 
			dp[j][1]+=sum[j-1]*(tmp[j+1]-tmp[j])%mod;
			dp[j][1]%=mod;
		}
		for(int j=1;j<dn;j++){
			ll tot=0;
			for(int k=1;k<=cnt[j];k++) tot=(tot+dp[j][k])%mod;
			sum[j]=(sum[j-1]+tot)%mod;
		}
	}
	printf("%lld\n",(sum[dn-1]-1+mod)%mod);//ȥ��û���˵���� 
}

