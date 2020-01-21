//洛谷 多项式输出 
#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 105
using namespace std;
int n,b;
int main(){
    cin>>n;
    for(int i=n;i>=0;i--){
        cin>>b;
        if(b!=0){
            if(i!=n&&b>0)cout<<"+";
            if(b<0)cout<<"-";
            if(i>1&&abs(b)!=1)cout<<abs(b)<<"x^"<<i;
            else if(i==0)cout<<abs(b);
            else if(i==1&&abs(b)!=1)cout<<abs(b)<<"x";
            else if(i==1&&abs(b)==1)cout<<"x";
            else cout<<"x^"<<i;
            //
        }
    }
    return 0;//结束
}
