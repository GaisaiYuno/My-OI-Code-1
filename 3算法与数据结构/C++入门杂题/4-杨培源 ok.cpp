//度度熊的午饭时光
#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>

  
   
   
 


#define maxn 1200
using namespace std;

int no[1005][120];
long long s[maxn],c[maxn];
long long f[maxn];
bool ans[maxn][maxn]= {false};



const long long INF=0x3f3f3f3f;  
int check(int ii,int jj)//字典序比较函数   
{  
    int t1=no[ii][0];  
    int t2=no[jj][0];  
    for(int i=1,j=1;i<=t1&&j<=t2;i++,j++)  
    {  
        if(no[ii][i]!=no[jj][j])  
            return no[ii][i]-no[jj][j];  
   }  
   return 0;  
} 



int main() {
	int t,b,n;
	cin>>t;
	for(int a=1; a<=t; a++) {
		long long cost;
		cin>>b>>n;
		for(int k=1; k<=n; k++) {
			cin>>s[k]>>c[k];
		}
		cost=0;
		memset(ans,false,sizeof(ans));
		memset(f,0,sizeof(f));
	
	
		
		for(int i=1; i<=n; i++) {
			for(int v=b; v>=c[i]; v--) {
				if(f[v-c[i]]+s[i]>f[v]) {
					f[v]=f[v-c[i]]+s[i];
					ans[i][v]=true;
				
				}
			}
		}
	 
	 
		
		   
	       long long dexsum=INF;  
               int k=0,mark=0; 
	for(int jj=b;jj>=0;jj--)  
       {  
            if(f[jj]==f[b])
            {  
  	  
	            
                long long sum=0;//序号和  
                int top=1;  
                int i=n,j=b;  
                while(i>=1&&j>=0)  
                {    
                    if(ans[i][j])//物品i在j里  
                   {  
                      no[k][top++]=i;  
                       sum+=i;  
                        j-=c[i];  //读完了物品i，找下一个背包状态     
                    }    
                    i--;     
               }  
               no[k][0]=top-1;//个数  
              sort(no[k]+1,no[k]+1+no[k][0]);  
               if(dexsum>sum){  
                    dexsum=sum;  
                   mark=k;//第k组  
               }  
               else if(dexsum==sum&&check(k,mark)<0){  
                   dexsum=sum;  
                    mark=k;//第k组  
               }  
                k++;  
            } 
}
	
	
	
	
        long long val=0;
        int top=no[mark][0];  
        sort(no[mark]+1,no[mark]+1+no[mark][0]);  
        for(int i=1;i<=top;i++)  
        {  
          //val+=s[no[mark][i]];  
            cost+=c[no[mark][i]];  
        }  
        printf("Case #%d:\n",a);  
      //printf("%lld %lld\n",val,cost); 
	printf("%lld %lld\n",f[b],cost);  
        for(int i=1;i<top;i++)  
            printf("%d ",no[mark][i]);  
        if(top>=1)  
            printf("%d\n",no[mark][top]);  
	

	}
	return 0;
}

