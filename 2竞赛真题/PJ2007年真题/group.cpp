//group
#include<iostream>
#include<cstdio> 
#include<algorithm>
#define maxn 30000 
using namespace std;
int n,w,l,r,ans;
int a[maxn];
int main(){
	//freopen("group.in","r",stdin);
	//freopen("group.out","w",stdout);
	cin>>w>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	r=n;
    while(l<=r){
    	if(a[l]+a[r]<=w){
    		ans++;
			l++;
			r--; 
		}
		else{
			ans++;
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
