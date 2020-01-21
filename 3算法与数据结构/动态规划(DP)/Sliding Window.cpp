#include<iostream>
#include<cstring>
#define maxn 100005
using namespace std;
int a[maxn],sum[maxn];
int n,k;
int lmax,rmax,lmin,rmin,smax,smin;
int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int main(){
	while(cin>>n>>k){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			a[i]=fread();
			sum[i]=sum[i-1]+a[i];
		}
		smax=0;
		smin=99999999;
		for(int i=1;i<=n;i++){
			if(sum[i+k]-sum[i]>smax){
				smax=sum[i+k]-sum[i];
				lmax=i;
				rmax=i+k;
			}
			if(sum[i+k]-sum[i]<smin){
				smin=sum[i+k]-sum[i];
				lmin=i;
				rmin=i+k;
			}
		}
		for(int i=lmin;i<=rmin;i++){
			if(i!=lmin) cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
		for(int i=lmax;i<=rmax;i++){
			if(i!=lmax) cout<<' ';
			cout<<a[i];
		}
        for(int i=lmin;i<=rmin;i++){
			if(i!=lmin) cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
	}
}
