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
			f[0][j]=f[1][j-1]+f[0][j-1]-1;       //��ȥȫ��k�������һ�� 
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
����k������-->����k-1������ 
��ά����f[0][j]���棬 f[1][j]����
���ƹ�ʽ 
j<k f[0][j]=f[1][j-1]+f[0][j-1]
    f[1][j]=f[1][j-1]+f[0][j-1]

j=k f[0][j]=f[1][j-1]+f[0][j-1]-1       //��ȥȫ��k�������һ�� 
    f[1][j]=f[1][j-1]+f[0][j-1]
    
j>k f[0][j]=f[1][j-1]+f[0][j-1]-f[0][j-(k-1)]
    f[1][j]=f[1][j-1]+f[0][j-1]
//���ø߾��� 
*/
