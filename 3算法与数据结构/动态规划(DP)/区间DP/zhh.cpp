#include<iostream>
#include<cstring>
#define maxn 1005
char a[maxn],b[maxn];
int dp[maxn][maxn];
int len;
using namespace std;
void debug(){
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++) cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	while(cin>>a>>b){
		len=strlen(a);
        for(int i=len-1;i>=0;i--){
			for(int j=i;j<len;j++){
				dp[i][j]=dp[i+1][j]+!(a[i]==b[i]);
				//debug();
				for(int k=i+1;k<=j;k++){
					if(b[i]==b[k]) dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j]);
			    }
		    }
	    }
	    cout<<dp[0][len-1]<<endl;
	    debug();
	}
}
/*dp[i][kj

*/
