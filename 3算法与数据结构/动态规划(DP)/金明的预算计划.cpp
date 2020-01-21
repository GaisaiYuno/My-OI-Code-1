//洛谷 金明的预算方案 1064
#include<iostream>
#include<cmath> 
#define maxn 10000
using namespace std;
int v[maxn],w[maxn];
int v1[maxn],w1[maxn];
int v2[maxn],w2[maxn];
int f[maxn];
int V,M,N; 
int main(){
	int inv,inp,inq;
	cin>>N>>M;
	int cnt=0;
	for(int k=1;k<=M;k++){
		cin>>inv>>inp>>inq;
		inv/=10;
		if(inq){
			if(!v1[inq]){
				v1[inq]=inv;
				w1[inq]=inv*inp;
			}
			else{
				v2[inq]=inv;
				w2[inq]=inv*inp;
			}
		}
		else{
			v[k]=inv;
			w[k]=inv*inp;
			cnt=k;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=N/10;j>=v[i];j--){
			f[j]=max(f[j-v[i]]+w[i],f[j]);
			if(j-v[i]-v1[i]>=0) f[j]=max(f[j-v[i]-v1[i]]+w[i]+w1[i],f[j]);
			if(j-v[i]-v2[i]>=0) f[j]=max(f[j-v[i]-v2[i]]+w[i]+w2[i],f[j]);
			if(j-v[i]-v1[i]-v2[i]>=0) f[j]=max(f[j-v[i]-v1[i]-v2[i]]+w[i]+w1[i]+w2[i],f[j]);
		}
	}
	cout<<f[N/10]*10;
} 
