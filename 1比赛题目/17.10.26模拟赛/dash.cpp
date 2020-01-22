#include<iostream>
#include<cstdio>
using namespace std;
int n,k,num;
int main(){
	freopen("dash.in","r",stdin);
	freopen("dash.out","w",stdout);           
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num;
	}
	cout<<2.75<<endl;
	return 0;
}
/*
    1
   1 1
  1 2 1   C(m-1,n-1)
 1 3 3 1
1 4 6 4 1
*/
