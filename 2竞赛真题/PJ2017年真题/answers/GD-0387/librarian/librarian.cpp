#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	int a[100000],b,c;
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<q;++i){
		cin>>b>>c;
		for(int j=0;j<n;++j){
			if(a[j]%(10*b)==c){
				cout<<a[j];
				break;
			}
			if(j==n-1){
				cout<<"-1";
			}
		}
	}
	return 0;
}
