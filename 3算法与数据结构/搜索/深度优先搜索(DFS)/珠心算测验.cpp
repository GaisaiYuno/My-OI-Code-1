//Âå¹È ÖéĞÄËã²âÑé 2141
#include<iostream>
#include<cstring>
#define maxn 100
using namespace std;
int n;
int num[maxn];
int used[maxn];
int main(){
	int ans=0;
    cin>>n;
    for(int u=0;u<n;u++){
   	    cin>>num[u];
    }
    memset(used,-1,sizeof(used));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		for(int k=0;k<n;k++){
    			if(num[i]+num[j]==num[k]&&num[i]!=num[j]&&used[k]==-1){
    				ans++;
    				used[k]=1;
				} 
			}
		} 
	}  
	cout<<ans;
	return 0;      
} 
