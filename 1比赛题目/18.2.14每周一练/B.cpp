#include<iostream>
#include<cstring>
#include<algorithm> 
#define maxn 505
using namespace std;
int l,n,m,s,x;
int size;
int a[maxn],b[maxn],c[maxn];
long long sum[maxn*maxn]; 
inline int fread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int is_found(long long num){
	int l=1,r=size;
	while(l<=r){
		int mid=(l+r)/2;
		if(sum[mid]>num) r=mid-1;
		else if(sum[mid]<num) l=mid+1;
		else return 1;
	}
	return 0;
}
int main() {
    int cnt=0;
	while(cin>>l>>n>>m) {
		size=0;
		for(int i=1; i<=l; i++) a[i]=fread();
		for(int i=1; i<=n; i++) b[i]=fread();
		for(int i=1; i<=m; i++) c[i]=fread();
		for(int i=1; i<=l; i++){
			for(int j=1; j<=n; j++) {
				sum[++size]=(long long)(a[i]+b[j]);
				//cout<<sum[size]<<' ';
			} 
		}
		//cout<<endl; 
		sort(sum+1,sum+size+1); 
		//for(int i=1;i<=size;i++) cout<<sum[i]<<' ';
		//cout<<endl;
		printf("Case %d:\n",++cnt);
		cin>>s;
		while(s--) {
			bool flag=false;
		    cin>>x;
		    for(int i=1;i<=m;i++){
		    	//cout<<x<<' '<<x-c[i]<<' '; 
		    	//cout<<is_found(x-c[i])<<endl;
		    	if(is_found(x-c[i])){
		    		flag=true;
		    		break;
				}
			}
			if(flag) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
