#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
int a[1001];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,qn,b,f,x,y;
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<q;++i){
		cin>>qn>>b;
		f=-1;
		for(int j=0;j<n;++j){
			x=a[j];y=b;
			if(x<b)continue;
			f=x;
			for(int k=0;k<qn;++k){
				if(x%10!=y%10){
					f=-1;
					break;
				}
				x/=10;
				y/=10;
			}
			if(f>-1)break;
		}
		cout<<f<<endl;
	}
	return 0;
}
