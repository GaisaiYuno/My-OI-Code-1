#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn (1<<16)+5
using namespace std;
string str;
int T,len;
int hui[maxn];
int dp[maxn];
int is_hui(int x){
    int i=0,j=len-1;
    if(x==0) return 0;
    while(i<j){
    	while(!((1<<i)&x)){
    		i++;
		}
    	while(!((1<<j)&x)){
    		j--;
		}
    	if(str[i]!=str[j]) return 0;
    	i++;
		j--;
	}
	return 1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>str;
		len=str.length();
		for(int i=0;i<=(1<<len)-1;i++) hui[i]=is_hui(i);
		memset(dp,0x7f,sizeof(dp));
		dp[(1<<len)-1]=0;
		for(int k=(1<<len)-1;k>=0;k--){
		    for(int t=k;t<=(1<<len)-1;t=(t+1)|k){
		    	if(hui[t-k]==1){
		    		dp[k]=min(dp[k],dp[t]+1);
				} 
			} 
		} 
		cout<<dp[0]<<endl;
	}
}
