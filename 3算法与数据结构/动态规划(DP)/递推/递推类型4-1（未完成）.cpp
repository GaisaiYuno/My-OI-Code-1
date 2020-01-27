#include<iostream>
#include<cstring>
#include<cmath>
#define maxn 1000
using namespace std;
int f[maxn][2];
int n,k;
int main(){
	cin>>n>>k;
	memset(f,0,sizeof(f));
	f[0][0]=1;
	//f[0][1]=1;
	for(int j=1;j<=n;j++){
		if(j<k){
            f[0][j]=f[1][j-1]+f[0][j-1];
            f[1][j]=f[1][j-1]+f[0][j-1];
            //f[j][0]=f[j-1][1]+f[j-1][0];
            //f[j][0]=f[j-1][1]+f[j-1][0];
		}
		if(j==k){
			f[0][j]=f[1][j-1]+f[0][j-1]-1;       //减去全是k个正面的一种 
            f[1][j]=f[1][j-1]+f[0][j-1];
            //f[j][0]=f[j-1][1]+f[j-1][0]-1;       
            //f[j][1]=f[j-1][1]+f[j-1][0];
		}
		if(j>k){
			f[0][j]=f[1][j-1]+f[0][j-1]-f[0][j-k+1];
            f[1][j]=f[1][j-1]+f[0][j-1];
		}		
	} 
    cout<<pow(2,n)-f[k][0]<<endl;
	
}
/*
至少k个连续-->至多k-1个连续 
二维数组f[0][j]正面， f[1][j]反面
递推公式 
j<k f[0][j]=f[1][j-1]+f[0][j-1]
    f[1][j]=f[1][j-1]+f[0][j-1]

j=k f[0][j]=f[1][j-1]+f[0][j-1]-1       //减去全是k个正面的一种 
    f[1][j]=f[1][j-1]+f[0][j-1]
    
j>k f[0][j]=f[1][j-1]+f[0][j-1]-f[0][j-(k-1)]
    f[1][j]=f[1][j-1]+f[0][j-1]
//需用高精度 
*/
