//洛谷 平面上的最接近点对 
//未分治优化 O(n^2) 
#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 100000
using namespace std;
int n;
int x[maxn];
int y[maxn];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    double tmp=0;
    double ans=(double)(x[0]-x[1])*(x[0]-x[1])+(double)(y[0]-y[1])*(y[0]-y[1]);
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            tmp=(double)(x[j]-x[k])*(x[j]-x[k])+(double)(y[j]-y[k])*(y[j]-y[k]);
            if(tmp<=ans) ans=tmp;
        } 
    }
    printf("%.4f",sqrt(abs(ans)));
    return 0;
} 
