//HDU 1176 
#include<iostream>
#include<cstring>
#define maxn 100005 
using namespace std;
int n,x,t,maxt;
int dp[maxn][13];
inline int fread(){
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
	while(cin>>n&&n!=0){
		memset(dp,0,sizeof(dp));
		maxt=-99999999;
		while(n--){
			x=fread();
			t=fread();
			dp[t][x+1]++;//+1·ÀÖ¹dpÊ±Ô½½ç 
			if(t>maxt) maxt=t;
		}
		for(int i=maxt-1;i>=0;i--){                        
            for(int j=1;j<=11;j++){
                dp[i][j]+=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));      
            }
        }
        cout<<dp[0][6]<<endl;
	}
} 
