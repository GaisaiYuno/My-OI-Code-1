#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int a[1001],b,c,x,y,n,ans=10000001;
	cin>>x>>y;
	for(int j=1;j<=x;j++){
	cin>>a[j];
	}
	cin>>b>>c;
	for(int j=1;j<=x;j++){
		if((a[j]==c||a[j]%10==c||a[j]%100==c||a[j]%1000==c||a[j]%10000==c||a[j]%100000==c||a[j]%1000000==c||a[j]%10000000==c)&&a[j]<=ans)
			ans=a[j];
		}
	if(ans=10000001){
	cout<<-1;
    }
	else{
    cout<<ans;
    }
	return 0;
}
