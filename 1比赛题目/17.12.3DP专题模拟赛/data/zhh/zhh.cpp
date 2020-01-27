#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n,m;
int f[maxn][maxn];
int num[maxn];
void ini(){
	f[0][0]=1;
	for(int i=1;i<maxn;i++){
		for(int j=0;j<=9;j++){
			if (j!=4){
                for(int k=0;k<=9;k++){
                    if (!(j==3&&k==7)) f[i][j]+=f[i-1][k];  
                }
            }
		}
	}
}
int work(int x){
	int ans=0,t=x,cnt=0,l;
	memset(num,0,sizeof(num));
	while(t){//将x转换到num数组 
		num[++cnt]=t%10;
		t/=10; 
	}
	for(int ptr=cnt;ptr>=1;ptr--){
        for(int j=0;j<num[ptr];j++){
        	if(!(num[ptr+1]==3&&j==7)) ans+=f[ptr][j];
		}
		if(num[ptr]==4||(num[ptr+1]==3&&num[ptr]==7)) break;
	}
	return ans;
}
int main(){
	//3,6,9WA 
	//freopen("10.in","r",stdin);
	cin>>n>>m;
	ini();
	//cout<<work(m)-work(n);
	cout<<work(m+1)-work(n);
	return 0;
}
/*dp[i][j] 长度为i的准考证号第i位为数字j的全部可能性
若为全排列：f[i][j]=f[i-1][0]+f[i-1][1]+……f[i-1][9] 
若为题目条件
 f[i][j]=f[i-1][0]+f[i-1][1]+……f[i-1][9]-f[i-1][4]
 f[i][7]=f[i-1][0]+f[i-1][1]+……f[i-1][9]-f[i-1][3]  
 */
