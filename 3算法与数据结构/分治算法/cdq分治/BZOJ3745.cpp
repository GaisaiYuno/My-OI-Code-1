//http://119.29.55.79/contest/84/problem/1
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
#define INF 0x3f3f3f3f
#define mod 1000000000
using namespace std;
typedef long long ll;

int n;
ll ans=0;
ll a[maxn+5];
ll sum_mx[maxn+5];
ll sum_mn[maxn+5];
ll sum_mxi[maxn+5];
ll sum_mni[maxn+5];
ll sum_mxmn[maxn+5]; 
ll sum_mxmni[maxn+5];
inline ll calc(ll l,ll r){
	return ((l+r)*(r-l+1)/2ll)%mod	;
	//记得取模，防止爆掉 
} 
void cdq_divide(int l,int r){//orz cdq  
//	cerr<<l<<' '<<r<<endl; 
	if(l==r){
		ans=(ans+a[l]*a[l])%mod;
		return;
	}
	int mid=(l+r)>>1;
	cdq_divide(l,mid);
	cdq_divide(mid+1,r); 
	ll mx=-INF,mn=INF;
	sum_mx[mid]=sum_mn[mid]=sum_mxi[mid]=sum_mni[mid]=sum_mxmn[mid]=sum_mxmni[mid]=0;
	for(int i=mid+1;i<=r;i++){
		mx=max(a[i],mx);
		mn=min(a[i],mn);
		sum_mx[i]=(sum_mx[i-1]+mx)%mod;
		sum_mn[i]=(sum_mn[i-1]+mn)%mod;
		sum_mxi[i]=(sum_mxi[i-1]+mx*i%mod)%mod;
		sum_mni[i]=(sum_mni[i-1]+mn*i%mod)%mod;
		sum_mxmn[i]=(sum_mxmn[i-1]+mn*mx%mod)%mod;
		sum_mxmni[i]=(sum_mxmni[i-1]+mn*mx%mod*i%mod)%mod;
	} 
	
	mx=-INF,mn=INF;
	int j=mid,k=mid;
	for(int i=mid;i>=l;i--){
		mx=max(a[i],mx);
		mn=min(a[i],mn);
		while(j<r&&a[j]>=mn&&a[j+1]>=mn) j++;
		while(k<r&&a[k]<=mx&&a[k+1]<=mx) k++;
		int a=min(j,k); 
		int b=max(j,k);
		//四倍的快乐 
		ans+=mx*mn%mod*calc(mid+1-i+1,a-i+1)%mod; //p<=a,mx*mn*(p-i+1) mid+1<=p<=a
		ans=(ans+mod)%mod;
		if(j<k){
			//a<=p<=b;
			//mx*sum(min[a+1,p]*(p-i+1))=mx*(sum(min[a+1,p]*p)-(i-1)sum(min[a+1,p]) a+1<=p<=b 
			ans+=mx*((sum_mni[b]-sum_mni[a]+mod)%mod-(sum_mn[b]-sum_mn[a]+mod)*(i-1)%mod+mod)%mod;
			ans=(ans+mod)%mod;

		}else{
			//b<=p<=a;和上面相反 
			ans+=mn*((sum_mxi[b]-sum_mxi[a]+mod)%mod-(sum_mx[b]-sum_mx[a]+mod)*(i-1)%mod+mod)%mod;
			ans=(ans+mod)%mod;
		} 
		//p>b
		//sum(mx[b+1,p]*mn[b+1,p]*(j-i+1))=sum(mx[b+1,p]*mn[b+1,p]*p)-(i-1)sum(mx[b+1,p]*mn[b+1,p])
		//b+1<=p<=r
		ans+=((sum_mxmni[r]-sum_mxmni[b]+mod)%mod-(sum_mxmn[r]-sum_mxmn[b]+mod)*(i-1)%mod+mod)%mod;
		ans=(ans+mod)%mod;
	}

}
int main(){

//	freopen("input.txt","r",stdin);
	scanf("%d",&n);
//	cerr<<n<<endl;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ans=0;
	cdq_divide(1,n);
	ans=(ans+mod)%mod;
	printf("%lld\n",ans); 
}
