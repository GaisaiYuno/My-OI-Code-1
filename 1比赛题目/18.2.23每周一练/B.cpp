#include<iostream>
#include<cstring>
#define maxn 11
using namespace std;
const int mod=9973;
struct matrix{
	int num[maxn][maxn];
};
matrix a;
matrix matrix_multi(matrix a,matrix b,int n){
	matrix tmp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			tmp.num[i][j]=0;
			for(int k=1;k<=n;k++){
				tmp.num[i][j]+=a.num[i][k]*b.num[k][j];
				tmp.num[i][j]%=mod;
			}
		}
	}
	return tmp;
}
matrix matrix_fastpow(int k,int n){
    matrix x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) { 
		     if(i==j) x.num[i][j]=1;
		     else x.num[i][j]=0;
	    } 
	} 
	y=a; 
	while(k>=1){
		if(k%2==1){
			x=matrix_multi(x,y,n); 
		}
		k/=2;
		y=matrix_multi(y,y,n);
	}
	return x;
}
int Tr(matrix m,int n){
	int ans=0;
	for(int i=1;i<=n;i++){
			ans+=m.num[i][i];
	}
	return ans%mod;
}
int t,n,k;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
			   cin>>a.num[i][j];
			} 
		}
		a=matrix_fastpow(k,n);
		cout<<Tr(a,n)<<endl;
	}
}
