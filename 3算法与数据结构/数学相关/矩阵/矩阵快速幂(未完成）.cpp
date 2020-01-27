#include<iostream>
#include<cstdio>
#include<cstring>
#define size 1000 
using namespace std;
int n,k; 
int m[size][size];
void multi_m(int x[size][size],int y[size][size],int ans[size][size]){
	int tmp[size][size];
	for(int m=0;m<n;m++){  
        for(int s=0;s<n;s++){  
           tmp[m][s]=0;
            for(int u=0;u<n;u++){  
                tmp[m][s]+=x[m][u]*y[u][s];  
            }
        }                
    }
	//print(tmp);  
	for(int m=0;m<size;m++){
		for(int s=0;s<size;s++) ans[m][s]=tmp[m][s];
	}
}
void fast_pow(int p) {//¿ìËÙÃÝ 
    int t[size][size];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) t[i][j]=m[i][j];
	}
	while(p>0) {
		if(p%2==1) {
			multi_m(m,t,m) ;
		}
		p/=2;
		multi_m(t,t,t);
	}
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>m[i][j];
	}
	fast_pow(k);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<m[i][j];
	}
	return 0;
}
