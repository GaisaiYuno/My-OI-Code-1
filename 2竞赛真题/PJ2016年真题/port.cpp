#include<iostream>
#include<cstring>
using namespace std;
int n;
int boat[1001][1002];
bool con[1001];
int main(){
	int i,j,k,cnt,ans;
	cin>>n;
	memset(boat,0,sizeof(boat));
	memset(con,false,sizeof(con));
	for(i=0;i<n;i++){
        cin>>boat[i][0]>>boat[i][1];
        for(j=2;j<=boat[i][1]+1;j++) cin>>boat[i][j];
	}
    for(i=0;i<n;i++){
    	ans=0;
    	for(j=0;j<=i;j++){
    		if(boat[i][0]-boat[j][0]<=86400){
    			for(k=2;k<=boat[j][1]+1;k++){
    				con[boat[j][k]]=true;
				} 
			}
		} 
		int tmp=0;
		for(j=0;j<=i;j++){
		  if(boat[i][0]-boat[j][0]<=86400)
			if(boat[j][1]>=tmp) tmp=boat[j][1];
		}
		for(j=1;j<=tmp;j++) if(con[j]) ans++;
		cout<<ans<<endl;
	}
	return 0;
} 
