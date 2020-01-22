#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n,q,temp,ans;
int arr[1005];
int brr[1005][2];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=q;i++){
		brr[i][0]=1;
		cin>>temp>>brr[i][1];
		for(int j=temp;j>0;j--){
			brr[i][0]*=10;
		}
	}
	for(int i=1;i<=q;i++){
		ans=-1;
		for(int j=1;j<=n;j++){
			if(arr[j]%brr[i][0]==brr[i][1]){
				if(ans==-1){
					ans=arr[j];
				}else{
					if(arr[j]<ans){
						ans=arr[j];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
