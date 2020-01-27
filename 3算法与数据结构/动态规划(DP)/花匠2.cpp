//洛谷 花匠 1970 
//较简洁的一种算法  
#include<iostream>
using namespace std;
int a[100001],ans=1,d=0;
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i+1]>a[i]&&d!=1){
            ans++;
            d=1;//d是判断类型a或b 
        }
        if(a[i+1]<a[i]&&d!=2){
            ans++;
            d=2;
        }
    }
    cout<<ans;
    return 0;
}

