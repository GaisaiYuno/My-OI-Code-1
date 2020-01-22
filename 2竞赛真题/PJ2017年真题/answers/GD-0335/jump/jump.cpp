#include<bits/stdc++.h>
using namespace std;
int l,r,n,d,k,m;
int f[500001],x[500001],s[500001];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
		if(s[i]>0) m+=s[i];
	}
	if(m<k){
		cout<<"-1";
		return 0;
	}
	l=0,r=x[n];
	while(l<r){
		int mid=(l+r)/2;
		memset(f,0,sizeof(f));
//		cout<<l<<" "<<r<<" "<<mid<<"\n";
		f[n]=s[n];
		for(int i=n-1;i>=0;i--){
			f[i]=s[i];
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d+mid) break;
				if(x[j]-x[i]>=d-mid) f[i]=max(f[i],f[j]+s[i]);
			}
		}
//		cout<<f[0]<<"\n";
		if(f[0]>=k) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
