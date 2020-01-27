//prime
#include<iostream>
#include<cstdio> 
using namespace std;
int n,p;
/*bool is_prime(int x){
	if(x%2==0) return false;
	for(int i=3;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}*/
int main(){  
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    cin>>n; 
    for(int i=2;i<=n;i++){ 
        if (n%i==0){
            cout<<n/i;
            return 0;
        }
    } 
}
