#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,q;
long long A[1005];
struct yxc{
	long long len,e;
}B[1005];
long long hh[12]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	for(int i=1;i<=q;i++){
		cin>>B[i].len>>B[i].e;
	}
	sort(A+1,A+n+1);
	for(int i=1;i<=q;i++){//cout<<B[i].len<<' '<<B[i].e<<endl;
		bool dodo=0;
		for(int l=1;l<=n;l++){//cout<<A[l]%hh[B[i].len]<<endl;
			if(A[l]%hh[B[i].len]==B[i].e){
				cout<<A[l]<<endl;
				dodo=1;
				break;
			}
		}
		if(!dodo){
			cout<<-1<<endl;
		}
	}
	return 0;
}
