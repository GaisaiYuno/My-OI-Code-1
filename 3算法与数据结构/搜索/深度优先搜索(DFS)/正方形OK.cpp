//openjudge square
#include<iostream>
#include<cstring>         
#include<algorithm> 
using namespace std;
int numb[21];
int used[21];
int ans[101];
int x=0;
int m,sum;              

int  dfs(int step,int now,int left,int stick) {//stick每边火柴棍数 //step边数 
	if(step==3&&left==sum/4) return 1;
	else if(step==3) return  0;
	if(stick==m-1) return  0;
                              
	for(int i=stick; i<m; i++) {
			x=now+numb[i];                
		if(used[i]==0&&x<=sum/4) {	
			used[i]=1;
			 if(x==sum/4)  
            {  
                if(dfs(step+1,0,left-numb[i],0))  
                    return 1;  
            }  
            else if(dfs(step,x,left-numb[i],i))  
                return 1;  
            used[i]=0;  
		}
	}
	return 0;
}
int my_comp(int a,int b){
	return a>b;
} 
int main() {
	int n;
	cin>>n;
	
	for(int p=0; p<n; p++) {
		cin>>m; 
		 sum=0;                      
		  memset(used,0,sizeof(used));  
		for(int q=0; q<m; q++) {
			cin>>numb[q];
			sum=sum+numb[q];
		}
	    sort(numb,numb+m,my_comp);//此处排序可以加速 
		if(sum%4!=0) ans[p]=0;
		else {
			if(dfs(0,0,sum,0)) ans[p]=1;
			else              ans[p]=0;       
		}
	}
	for(int k=0; k<n; k++) {
		if(ans[k]==1) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
