//O 
#include<iostream>
#include<algorithm>
#define maxn 3005
using namespace std;
int n,m,cnt;
int a[maxn],sum[5000001];
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
int comp(int x,int y){
	return x>y;
}
int main(){
	while(cin>>n>>m){
		cnt=0;
		for(int i=1;i<=n;i++) a[i]=fread();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum[++cnt]=0;
				sum[cnt]=a[i]+a[j];
			}
		}
        sort(sum+1,sum+1+cnt,comp);
        for(int i=1;i<=m;i++){
        	if(i!=1) cout<<' ';
        	cout<<sum[i];
		} 
        cout<<endl;
	}
}
