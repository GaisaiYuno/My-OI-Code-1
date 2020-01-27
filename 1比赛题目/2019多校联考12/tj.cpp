#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=99824353;
int rec[100001], fac[100001], rec_fac[100001];
int binomial(int n, int k){
	if(n<k)
		return 0;
	return (ll)fac[n]*rec_fac[k]%mod*rec_fac[n-k]%mod;
}
bool parity[1<<8];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n>>m;
	static int prefix[100001][1<<8];
	for(int i=1; i<=n; ++i){
		int num, s=0;
		cin>>num;
		while(num--){
			int a;
			cin>>a;
			s|=(1<<a);
		}
		for(int j=0; j<(1<<8); ++j)
			prefix[i][j]=prefix[i-1][j]+((s&j)==s);
	}
	rec[1]=1;
	for(int i=2; i<=n; ++i)
		rec[i]=(ll)(mod-mod/i)*rec[mod%i]%mod;
	fac[0]=1;
	rec_fac[0]=1;
	for(int i=1; i<=n; ++i){
		fac[i]=(ll)fac[i-1]*i%mod;
		rec_fac[i]=(ll)rec_fac[i-1]*rec[i]%mod;
	}
	for(int i=1; i<(1<<8); ++i)
		parity[i]=!parity[i-(i&-i)];
	while(m--){
		int l, r, k, num, s=0;
		cin>>l>>r>>k>>num;
		while(num--){
			int a;
			cin>>a;
			s|=(1<<a);
		}
		ll res=0;
		for(int i=0; i<(1<<8); ++i)
			if((i&s)==i)
				res+=binomial(prefix[r][i]-prefix[l-1][i], k)*(parity[i^s] ? -1 : 1);
		cout<<(res%mod+mod)%mod<<'\n';
	}
}
