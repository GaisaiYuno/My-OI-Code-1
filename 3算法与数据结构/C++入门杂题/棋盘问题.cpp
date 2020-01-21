//Âå¹È ÆåÅÌÎÊÌâ
#include<iostream>
using namespace std;
long long ans1,ans2,n,m;
int main(){
	cin>>n>>m;
	ans1=0;
	ans2=(1+n)*n*(1+m)*m/4;
	for(int i=1;i<=n;i++){
        ans1+=(n-i+1)*(m-i+1);
    }
    cout<<ans1<<' '<<ans2-ans1;
    return 0;
} 

