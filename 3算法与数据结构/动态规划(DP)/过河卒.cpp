//洛谷 过河卒 
#include<iostream> 
#include<cstring>
#define maxn 100 
using namespace std;
long long int a[maxn][maxn];
int hx[8]={-1,1,-2,-2,2,2,-1,1},hy[8]={-2,-2,-1,1,-1,1,2,2};
long long int n,m,p,q; 
int main(){
	memset(a,-1,sizeof(a));
	cin>>n>>m;
	cin>>p>>q;
	a[0][0]=1;
	a[p][q]=0;
	for(int j=0;j<8;j++)  a[p+hx[j]][q+hy[j]]=0;
	for(int k=0;k<=n;k++){
		for(int u=0;u<=m;u++){
			if(a[k][u]==-1){
				if(u-1<0) //防止数组越界 
				     a[k][u]=a[k-1][u];
				else if(k-1<0)
				     a[k][u]=a[k][u-1]; 
				else 
				    a[k][u]=a[k-1][u]+a[k][u-1];
			} 
		}
	}
	cout<<a[n][m];
	return 0; 
}
/*状态转移方程
    f[i][j]=f[i-1][j]+f[i][j-1] 
*/ 
